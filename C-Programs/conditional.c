#include <stdio.h>
void main() {
    int a,b;
    printf("Enter two numbers : ");
    scanf("%d %d",&a,&b);
    (a>b?printf("%d is greater.",a):printf("%d is greater.",b));
}