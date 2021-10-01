#include <stdio.h>
int gcd(int,int);
int main(){
    printf("gcd = %d",gcd(10,16));
}
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}