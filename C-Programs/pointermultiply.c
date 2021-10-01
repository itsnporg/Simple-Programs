#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* multiply(int *a, int *b){
  int *c = malloc(sizeof(int));   //or static int c; and return &c
  *c = *a * *b;
return c;
}

int main(){
int a= 3, b = 5;
int *p = multiply (&a,&b);
printf("Product = %d",*p);
return 0;
}