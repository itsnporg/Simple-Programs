#include <stdio.h>



const int ASCII_DIFFERENCE = 32;

int main (void)
{
    int UPPERCASE;

  string name = get_string("Input: ");
  printf("Output: ");

  for(int i =0; i < name[i] != '\0' ; i++)
  {
    // checking lowercase by comparing ASCII
    if(name[i] >= 'a' && name[i] <= 'z')
    {
         printf("%c" , name[i]- ASCII_DIFFERENCE);
    }
    
   
  }
 
}