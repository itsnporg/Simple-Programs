/* As a part of CS50 assignment a simple Credit card validator written in C
   by Rahul Kumar Chaurasiya

   This is a pretty neat and simple Program written in C that takes the Card Number as an input and checks whether the Card entered is Valid or Not. For the cards like MasterCard, American-Express And Visa, the output will be 'This is a valid American Express Card' if the Card is American-Express and the Numbers are entered properly and so on. For Cards other than those which are mentioned above, it only shows the validity of the card i.e is it Valid Or Invalid. The Program uses Luhn's Algorithm to check the validity of the card.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void myInput(char *s) //Custom function for string input
{
	int i=0;
	char ch;
	while(1)
	{
		ch=fgetc(stdin);
		if(ch=='\n'){
			fflush(stdin);
			break;
		}
		s[i++]=ch;
	}
	s[i]='\0';
}
int checkLength(char *S) // Checks string's length
{
	if(strlen(S)<13 || strlen(S)>16)return 0;
	else return 1;
}
int check(char *S)  //checks whether characters other than digits are present or not
{
	int i;
	for(i=0;S[i]!='\0';i++)
	{
		if(S[i]<48 || S[i]>57)
			return 0;
	}
	return 1;
}
char *cardName(char *S,int l) // Specifies card name according to their length and first digit
{
	if((l>=13 && l<=16) && S[0]-'0'==4) return "This is a valid VISA card\n";
	int firstDigit=(S[0]-'0')*10+(S[1]-'0');
	if(l==15 && (firstDigit==34 || firstDigit==37)) return "This is a valid American Express Card\n";
	else if(l==16 && (firstDigit>50 && firstDigit<56))return "This is a valid MASTERCARD\n";
	else return "VALID\n";
}
int main()
{
	char S[25];
	do
	{
		printf("Number:");
		myInput(S);
	}while(!check(S));  // loop continue until the entered no length is <13 & >16
	if(!checkLength(S))
	{
		printf("INVALID\n");
		exit(0);
	}
	int i;
	int sum1=0;
	int num;
	for(i=strlen(S)-2;i>=0;i-=2)
	{
		num=(S[i]-'0')*2;
		if(num/10==0)
			sum1+=num;
		else
			sum1+=num/10+num%10;
	}
	for(i=strlen(S)-1;i>=0;i-=2)
	{
		num=S[i]-'0';
		sum1+=num;
		
	}
	if(sum1%10==0)
	{
		char *card=cardName(S,strlen(S));
		printf("%s",card);
	}
	else
		printf("INVALID\n");
}
