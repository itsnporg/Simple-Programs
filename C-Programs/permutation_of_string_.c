#include <stdio.h>

void perm(char[], int);

int main()
{
    char s[] = "abcd";
    perm(s, 0);
}

void perm(char s[], int k){
    static int a[10] = {0};
    static char result[10] = {0};
    if(s[k]=='\0'){
        result[k] == '\0';
    printf("%s\t", result);
    }
    else{
        for(int i = 0; s[i] != '\0';i++)
        {
            if(a[i] == 0){
                result[k] = s[i];
                a[i] = 1;
                perm(s, k+1);   
                a[i] = 0;    
            }
        }
    }
}
