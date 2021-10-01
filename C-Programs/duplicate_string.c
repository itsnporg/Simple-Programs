#include <stdio.h>
#include <stdlib.h>
void Find_Duplicates(char *A){
    long int H;//variable to set each character's bit
    int x=0,y=0,i;

    for(i=0;A[i]!='\0';i++){//loop through the given string
        x = 1;//Start from least significant bit
        x = x << A[i] - 97;//leftshift by this no. of times

        if((x & H) > 0){//perform bitwise AND (if set before - duplicate)
            printf("%c is a duplicate", A[i]);
            printf("\n");
        }else{
            H = H | x;//perform bitwise OR (if not set before - set now)
        }
    }
}
int main(){
    char A[] = "finding";//our given string

    Find_Duplicates(A);
}