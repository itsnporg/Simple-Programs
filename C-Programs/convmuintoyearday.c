#include <stdio.h>
int main(){
    int min ;
     double days, years, d, e;
     printf("Enter minutes to convert : ");
     scanf("%d",&min);
     d = (24 * 60);
     e = (60 * 24 * 365);
     days =  min /  d;
     years = min / e;
     printf("%d is = %f days and %f years",min,days,years);
    return 0;
}