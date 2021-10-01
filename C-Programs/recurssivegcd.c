#include<stdio.h>  

int gcd(int n1, int n2){  
    if(n1 == 0) return n2;  
    if(n2 == 0) return n1;  

    if(n1 > n2)  
        return gcd(n1%n2, n2);  
    else  
        return gcd(n1, n2%n1);  
}  

void main() {  
    int num1, num2;  
    printf("Enter 2 positive integer numbers:  ");  
    scanf("%d %d", &num1, &num2);  
    printf("GCD of %d and %d is %d.\n", num1, num2, gcd(num1, num2));  
}  
