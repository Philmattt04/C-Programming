//
//  mathieu_prog5.c
//  Programming 1
//
//  Created by Philippe Mathieu on 10/3/22.
// This program implements a menu driven program that displays a menu, menu options, and the menu option choices

#include <stdio.h> // for printf & scanf
#include <ctype.h> // for toupper & tolower

// function prototypes
void Greeting(void);
// greets the user to the purchansing app

char OptionList(void);
// displays the the program options and gets the user's selection

void ProcessOption(char choice);
// the user inputs their choice
// displays a message based on the user's choice
// calls the DisplayMenu function if the user selects 'S' or 's'

void DisplayMenu(void);
// displays menu options and prices


int main()
{
    char choiceInMain = '\0';
    Greeting(); //fucntion call greeting the user
    choiceInMain = OptionList(); //calls the function OptionList
    choiceInMain = tolower(choiceInMain); //changes the choiceInMain to a lowercase letter
    
    if(choiceInMain == 'q')
    {
        printf("\nHave a great day!\n"); //sends the user a goodbye message when user selects 'q' or 'Q'
        return 0;
    }
    
    ProcessOption(choiceInMain);
    
    while (choiceInMain != 'q') //while loop that operates the OptionList function
                                //when the user does not select 'q'
    {
        choiceInMain = OptionList(); //calls the function OptionList
        choiceInMain = tolower(choiceInMain); //changes the choiceInMain to a lowercase letter
        
        if(choiceInMain == 'q') //if user inputs 'q' or 'Q' the program will stop
        {
            continue;
        }
        ProcessOption(choiceInMain); //calls the function ProcessOption
    }
    printf("\nHave a great day!\n"); //sends the user a goodbye message when user selects 'q' or 'Q'
    return 0;
}

// the user inputs their choice
// displays a message based on the user's choice
void ProcessOption(char choice)
{
    if(choice == 's')
    {
        printf("\nDisplay the menu");
        DisplayMenu(); //calls the DisplayMenu function if the user selects 'S' or 's'

    }
    else if(choice == 'o')
    {
        printf("\nComplete an order if there is enough money");
        
    }
    else if (choice == 'b')
    {
        printf("\nDisplay the account balance");

    }
    else if (choice == 'a')
    {
        
        printf("\nAdd money to the account");
    }
    else
    {
        printf("\nThat is not a valid option");
    }

}

// greets the user to the purchansing app
void Greeting()
{
    printf("Welcome to the Café Express!");
    printf("\nWe serve delicious drinks and snacks!\n");

}
// displays the the program options and gets the user's selection
char OptionList()
{
    char option;
    printf("\n-----------------------------------------------------------------");
    printf("\n'S' to view the snack and beverages available for purchase");
    printf("\n'O' to order coffee or a snack");
    printf("\n'B' to view your account balance");
    printf("\n'A' to add money to your account");
    printf("\n'Q' to quit");
    printf("\nEnter your selection: \n");
    scanf(" %c", &option);
    return option;
}
// displays menu options and prices
void DisplayMenu()
{
    printf("\n-----------------------------------------------------------------");
    printf("\nHere are the drink and snack options: ");
    printf("\n1. Water:          $1.50");
    printf("\n2. Orange Juice:   $2.35");
    printf("\n3. Iced Coffee:    $2.50");
    printf("\n4. Iced Tea:       $3.00");
    printf("\n5. Strawberry Banana Smoothie: $3.50");
    printf("\n6. Chocolate Chip Cookie:  $0.99");
    printf("\n7. Grilled Cheese:  $5.25\n");
}
