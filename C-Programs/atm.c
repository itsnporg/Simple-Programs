#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct detail
{
    char name[20];
    int balance;
    char address[50];

} user;
void newAccount();
void checkBalance();
void withdraw();
void deposit();
void sendMoney();
void welcomeScreen();
void quit();

//*****************************************************************************
//------------------------------  Welcome Screen ------------------------------
//*****************************************************************************
void welcomeScreen()
{
    system("clear");
    printf("\n============================================================\n");
    printf("\n************************************************************\n");
    printf("\t\tWelcome to BS Bank");
    printf("\n************************************************************\n");
    printf("\n============================================================\n");
    printf(">>Enter 'N' to open new Bank Account\n");
    printf(">>Enter 'B' to check available balance\n");
    printf(">>Enter 'D' to deposit money\n");
    printf(">>Enter 'W' to withdraw money\n");
    printf(">>Enter 'S' to send money\n");

}

//*****************************************************************************
//------------------------------   New Account   ------------------------------
//*****************************************************************************
void newAccount()
{
    printf("\n************************************************************\n");
    printf("\t\tCreate new account\n");
    printf("\n************************************************************\n");
    printf("\nEnter your name:\n");
    scanf("%s",user.name);
    printf("Enter your address:");
    scanf("%s",user.address);
}
//*****************************************************************************
//------------------------------   Check Available balance   ------------------------------
//*****************************************************************************
int main()
{
    welcomeScreen();
   // system("mkdir temp/");
}
