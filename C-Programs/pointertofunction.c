#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* multiply(int *a, int *b){
    int *c = malloc(sizeof(int));
  *c = *a * *b;
return c;
}

int main(){
int a= 3, b = 5;
int* (*p)(int* ,int*) = multiply;
int *k = (*p)(&a,&b);
printf("Product = %d",*k);
return 0;
}