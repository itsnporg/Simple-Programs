                //Program to calculate GCD of two given Integers
#include <stdio.h>

int gcd(int, int); //declaration

int main() //main
{
    printf("The GCD of 10 and 16 is %d\n",gcd(10,16)); //call
}

int gcd(int u , int v) //function
{
    int temp;
    while(v != 0) //loop
    {
        temp = u % v;
        u = v;
        v= temp;
    }
    return u; //return
}