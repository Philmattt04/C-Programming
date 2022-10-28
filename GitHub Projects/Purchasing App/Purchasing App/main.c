//
//  mathieu_prog7.c
//  Programming 1
//
//  Created by Philippe Mathieu on 10/23/22.
// This program is the final product of the purchasing app using pointers, function calls and protoypes, and simple math from c.

#include <stdio.h> //for printf and scanf
#include <ctype.h> // for toupper and tolower

void Greeting(void);
//welcome the user to the purchasing app

void ViewBalance(double balance);
//input: double
//display the current account balance

void OptionListPtr(char* choicePtr);
//input/ output character parameter
//display the program options and get the users selection

double ProcessOption(char choice, double balance);
//input: a character (choice) and a double (balance) by copy
//uses conditions or switch to process the choice ‘s’,’o’,’b’,or ‘a’
// returns the updated balance if a purchase was made or money was added to the account

void DisplayMenu(void);
//display beverage/food options and prices

void OrderPricePtr(double* pricePtr);
//input output parameter the price of the item
//Inside the function block: declare the item number, use Display Menu function to display the prices
//ask and get the item number
//set the price of the item to the "value at" pricePtr

int CheckForEnoughMoney(double balance, double price);
//input: a double (balance) and a double (price) by copy
//return 1 if the balance is enough to cover the price
//return 0 if it is not enough

double Reload(double balance);
//reload the account balance
//input: a double (balance) by copy
//returns the updated balance


int main()
{
    Greeting();
    
    char choiceInMain;
    double balanceInMain;
    FILE * inPtr, * outPtr;
    inPtr = fopen("/Users/philsterr/Desktop/COP2220/COP2220 Projects/Programming 1/COP 2220/accountBalance.txt", "r");
    printf("\nGetting the balance from the file\n\n");
    fscanf(inPtr, " %lf", &balanceInMain);
    printf("Your current balance is $%.2f\n", balanceInMain);
    
    //Function calls
    OptionListPtr(&choiceInMain);

    choiceInMain = tolower(choiceInMain);
    while (choiceInMain != 'q')
    {
        // Calls fucntion ProcessOption and passes variables choiceInMain and balanceInMain
        balanceInMain = ProcessOption(choiceInMain, balanceInMain);
        // Calls function OptionListPtr and passes the "address of" choiceInMain
        OptionListPtr(&choiceInMain);
        // Changes the choice made by the user to a lowercase letter
        choiceInMain = tolower(choiceInMain);

    }
    printf("\nSaving the balance to the file\n\n");
    // Connects to the file
    outPtr = fopen("/Users/philsterr/Desktop/COP2220/COP2220 Projects/Programming 1/COP 2220/accountBalance.txt", "w");
    // Saves the file
    fprintf(outPtr, "%f", balanceInMain);
    printf("\nHave a great day!\n\n");
    fclose(inPtr);
    fclose(outPtr);
    
    return 0;
}

void Greeting()
{
    printf("Welcome to the Café Express!");
    printf("\nWe serve delicious drinks and snacks!\n");
}

void ViewBalance(double balance)
{
    printf("Your current balance is $%.2f\n", balance);

}

void OrderPricePtr(double* pricePtr)
//input output parameter the price of the item
//Inside the function block: declare the item number, use Display Menu function to display the prices
//ask and get the item number
//set the price of the item to the "value at" pricePtr
{
    int itemNumber;
    printf("\nEnter your selection: ");
    scanf(" %d", &itemNumber);
    switch (itemNumber) {
        case 1:
            printf("\nYou selected Hot coffee, the price is $2.35\n");
            *pricePtr = 2.35;
            break;
        case 2:
            printf("\nYou selected Iced coffee, the price is $2.35\n");
            *pricePtr = 2.35;
            break;
        case 3:
            printf("\nYou selected Hot Latte, the price is $4.68\n");
            *pricePtr = 4.68;
            break;
        case 4:
            printf("\nYou selected Iced Latte, the price is $4.68\n");
            *pricePtr = 4.68;
            break;
        case 5:
            printf("\nYou selected Butter Croissant, the price is $3.50\n");
            *pricePtr = 3.50;
            break;
        case 6:
            printf("\nYou selected Almond Croissant, the price is $4.50\n");
            *pricePtr = 4.50;
            break;
        case 7:
            printf("\nYou selected Blueberry muffin top, the price is $3.25\n");
            *pricePtr = 3.25;
            break;
        default:
            printf("\nThere is no item with that number\n");
            *pricePtr = 0.0;
    }
}

double ProcessOption(char choice, double balance)
//input: a character (choice) and a double (balance) by copy
//uses conditions or switch to process the choice ‘s’,’o’,’b’,or ‘a’
// returns the updated balance if a purchase was made or money was added to the account
{
    int enough = 0;
    double price;
         if(choice == 's')
         {
             printf("\n-----------------------------------------------------------------\n");
             printf("\nDisplay the menu\n");
             DisplayMenu(); //calls the DisplayMenu function if the user selects 'S' or 's'

         }
         else if(choice == 'o')
         {
             printf("\n-----------------------------------------------------------------\n");
             printf("\nOrder an item and complete the purchase\n");
             DisplayMenu();
             
             OrderPricePtr(&price);
             
             enough = CheckForEnoughMoney(balance, price);
             while(enough == 0)
             {
                 balance = Reload(balance);
                 enough = CheckForEnoughMoney(balance, price);
             }
             if (price != 0)
             {
                 balance = balance - price;
                 printf("\n---------------Purchasing the item----------------");
                 printf("\nEnjoy your purchase!\n\n");
                 ViewBalance(balance);
             }
         }
         else if (choice == 'b')
         {
             printf("\n-----------------------------------------------------------------\n");
             printf("\nDisplay the account balance\n");
             ViewBalance(balance);

         }
         else if (choice == 'a')
         {
             printf("\n-----------------------------------------------------------------\n");
             printf("\nAdd money to the account\n");
             ViewBalance(balance);
             balance = Reload(balance);
             ViewBalance(balance);
         }
         else
         {
             printf("\n-----------------------------------------------------------------\n");
             printf("\nThat is not a valid option\n");
         }
         return balance;
}

void OptionListPtr(char* choicePtr)
//input/ output character parameter
//display the program options and get the users selection
{
    printf("\n*********************************************************\n");
    printf("\nWhat would you like to do?\n");
    printf("\nPlease select from the following options: \n");
    printf("\n'S' to view the snack and beverages available for purchase");
    printf("\n'O' to order coffee or a snack");
    printf("\n'B' to view your account balance");
    printf("\n'A' to add money to your account");
    printf("\n'Q' to quit");
    printf("\nEnter your selection: ");
    scanf(" %c", choicePtr);
}

void DisplayMenu() //Displays the menu once the user asks to display it
{
    printf("\n-----------------------------------------------------------------");
    printf("\nHere are the drink and snack options: \n");
    printf("\n1. Hot coffee           $2.35\n");
    printf("\n2. Iced coffee          $2.35\n");
    printf("\n3. Hot Latte            $4.68\n");
    printf("\n4. Iced Latte           $4.68\n");
    printf("\n5. Butter Croissant     $3.50\n");
    printf("\n6. Almond Croissant     $4.50\n");
    printf("\n7. Blueberry muffin top $3.25\n\n");
}


 int CheckForEnoughMoney(double balance, double price)
//input: a double (balance) and a double (price) by copy
//return 1 if the balance is enough to cover the price
//return 0 if it is not enough

{
 if(balance >= price)
 {
     ViewBalance(balance);
     return 1;
 }
 else
 {
     printf("\n----------------------------------------------");
     printf("\nYou do not have enough money in your account!\n");
     ViewBalance(balance);
     return 0;
 }
}

double Reload(double balance)
//reload the account balance
//input: a double (balance) by copy
//returns the updated balance
{
    double money;
    printf("\nEnter the amount you want to add: ");
    scanf("%lf", &money);
    balance = balance + money;
    return balance;
}
