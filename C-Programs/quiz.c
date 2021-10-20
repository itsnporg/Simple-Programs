#include<stdio.h>
#include<conio.h>

    //Developer's World................

    int noOfQuestions=3;    //set how many questions will be there in quiz

    int noOfOptions=3;      //set how many options will be provided


    //...................................................
int main(){
    char userName[25];
    printf("Enter your name: ");
    gets(userName);
    game:
    printf("\n\n \
        \tWelcome %s\n\n \
        \tLet's start the quiz\n \
******************************************************\n\n",userName);
    //fflush(stdin);
    int points=0;
    char questions[][100]=
    {"Q)Who is current CEO of Microsoft?",                              //q1
    "Q)What is value of mass of electron?",                                  //q2
    "Q)Who Propounded Schrodinger equation?"};                              //q3
    char options[][3][50]=  //💀💀💀⚡⚡If you have 4 options on each question change 3 to 4 and so on
    {
        {"1)Sundar Pichai","2)Bill gates","3)Satya Nadella"},//q1
        {"1)9.1×10^-23Kg","2)9.1×10^-27Kg","3)9.1×10^-31Kg"},                          //q2
        {"1)Henry Schrodinger","2)Erwin Schrodinger","3)Charles Schrodinger"}               //q3
    };
    int answers[]={3,3,2};
    for(int qnsNo=0;qnsNo<noOfQuestions;qnsNo++){
        int userAns=0;
        printf("%s\n",questions[qnsNo]);
        for(int option=0;option<noOfOptions;option++){
            printf("  %s\n",options[qnsNo][option]);
        }
        printf("Choose correct option: ");
        scanf("%d",&userAns);
        printf("\n\t");
        if(userAns==answers[qnsNo]){
            printf("Correct Answer!! :)");
            points+=10;
        }
        else if(userAns<1 || userAns>noOfOptions){
            printf("Those are not the availble options");
        }
        else{
            printf("Wrong Answer!! :(");
        }
        printf("\n........................................................\n\n");
    }
    printf("Congratulations %s !!,You scored %d points\n\n",userName,points);
    printf(
"1.Replay\n\
2.Quit\n\
Choose:/>");
    int replay;
    scanf("%d",&replay);
    if(replay==1){
        goto game;
    }
}