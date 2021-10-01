#include <stdio.h>

float avg(int a[],int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];  //sum
    }
    return (sum / n);  //returing average
}

int main() {
    int num,array[100];
    printf("Enter numbes  of datas you want to enter (1 to 100): ");
    scanf("%d", &num);  //number of data

    printf("Enter %d numbers:   ", num);
    for (int i = 0; i < num; i++){   //taking input
    scanf("%d", &array[i]);
        }

    printf("Average of the given datas: %.2f", avg(array,num));
    }