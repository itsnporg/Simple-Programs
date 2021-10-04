#include <stdio.h>
int main()
{
    char str[100];
	int start, middle, end, length = 0;

	printf("Input a string.\n");
	gets(str);

	while (str[length] != '\0')
    	length++;

	end = length - 1;
 	middle = length/2;

  	for (start = 0; start < middle; start++)
  	{
    	if (str[start] != str[end])
    	{
      		printf("Entered string is not a palindrome.\n");
      		break;
   		}
    	
		end--;
  	}
  	
  	if (start == middle)
    	printf("Entered string is palindrome.\n");

 	return 0;
}
