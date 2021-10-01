#include <stdio.h>
#define N 10

int main() {
int a[N] = {3,5,34,22,1,33,-45,-3,-6,9};
int min=a[0];
int max=a[0];
for (int i = 1; i < N-1;i++){
    if(min > a[i]){
        min = a[i];
    }
    else if (max < a[i]){
        max = a[i];
    }
        }
        printf("min = %d, max = %d", min, max);
}