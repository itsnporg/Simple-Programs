#include<stdio.h>

int checkPalindrome(int number)
{
  int temp, remainder, rev=0;
  temp = number;
    
 while( number!=0 )
  {
     remainder = number % 10;
     rev = rev*10 + remainder;
     number /= 10;
  }

  if ( rev == temp ) return 0;
  else return 1;
}

int main()
{
  int number;

  printf("Enter the number: ");
  scanf("%d", &number);

  if(checkPalindrome(number) == 0)
  printf("%d is a palindrome number.\n",number);
  else
  printf("%d is not a palindrome number.\n",number);

  return 0;
}
