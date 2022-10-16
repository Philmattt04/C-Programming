//
//  mathieu_prog6.c
//  Programming 1
//
//  Created by Philippe Mathieu on 10/10/22.
/* This program implements a menu driven program that displays a menu, menu options, and the menu option choices
 using function prototypes and definitions, input/output parameters, and file input & ouput
 */

#include <stdio.h> //for printf & scanf
#include <ctype.h> //for toupper & tolower

// Function paramaters
void Greeting(void); //welcome the user to the purchasing app
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

int main()
{
    char choiceInMain;
    FILE *inPtr, * outPtr;
    double balanceInMain;
    printf("\nGetting the balance from the file\n\n");
    //Opens the file to display the balance
    inPtr = fopen("/Users/philsterr/Desktop/COP2220/COP2220 Projects/Programming 1/COP 2220/accountBalance.txt", "r");
    fscanf(inPtr, " %lf", &balanceInMain);
    
    //Function calls
    ViewBalance(balanceInMain);
    Greeting();
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

void Greeting() //Greets the user to the purchasing app
{
    printf("Welcome to the Café Express!");
    printf("\nWe serve delicious drinks and snacks!\n");
}


void ViewBalance(double balance) //Displays the balance from the file
{
    printf("\nYour current account balance is $%.2f\n\n", balance);
}

void OptionListPtr(char* choicePtr) //Displays the list of options
{
    printf("\n************************************************\n");
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

 double ProcessOption(char choice, double balance)
//Inputs the choice from the user and the balance
//Uses conditions to process choices 's', 'o', 'b' or 'a'
{
     if(choice == 's')
     {
         printf("\nDisplay the menu");
         DisplayMenu(); //calls the DisplayMenu function if the user selects 'S' or 's'

     }
     else if(choice == 'o')
     {
         printf("\n-----------------------------------------------------------------\n");
         printf("\nComplete an order if there is enough money\n");
         
     }
     else if (choice == 'b')
     {
         printf("\n-----------------------------------------------------------------\n");
         printf("\nDisplay the account balance\n");

     }
     else if (choice == 'a')
     {
         printf("\n-----------------------------------------------------------------\n");
         printf("\nAdd money to the account\n");
     }
     else
     {
         printf("\n-----------------------------------------------------------------\n");
         printf("\nThat is not a valid option\n");
     }
     return balance;
}
void DisplayMenu() //Displays the menu once the user asks to display it
{
    printf("\n-----------------------------------------------------------------");
    printf("\nHere are the drink and snack options: ");
    printf("\n1. Hot coffee           $2.35\n");
    printf("\n2. Iced coffee          $2.35\n");
    printf("\n3. Hot Latte            $4.68\n");
    printf("\n4. Iced Latte           $4.68\n");
    printf("\n5. Butter Croissant     $3.50\n");
    printf("\n6. Almond Croissant     $4.50\n");
    printf("\n7. Blueberry muffin top $3.25\n\n");
}

