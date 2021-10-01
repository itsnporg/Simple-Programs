#include <stdio.h>
#include <math.h>
#include <conio.h>
float StdDev(int array[],int);

int main(){
    system("cls");
    int n;
    printf("Enter Numbers you want to enter ");
    scanf("%d",&n);
    int array[n];
printf("Standard Deviation is %.2f",StdDev(array,n));
}

float StdDev(int array[],int n){
    float avg=0.00;
    int j,i,sum=0;
for(i=0;i<n;i++){
        printf("Enter n numbers ");
        scanf("%d",&array[i]);
        sum= sum + array[i];
        }
avg = (float)sum / n;
printf("Average of entered values is %.2f \n",avg);
float Variance, SD, Differ, Varsum=0;
for(j=0; j<n; j++)
    {
    Differ = array[j] - avg;
    Varsum += pow(Differ,2);
    }
Variance = Varsum / (float)n;
SD = sqrt(Variance);
return SD;
}