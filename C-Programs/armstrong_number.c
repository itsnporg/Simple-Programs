//Armstrong number means the sum of all digits 
// e.g for 125=1^3+2^3+5^3=134
#include<stdio.h>
#include<math.h>
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    int sum=0;
    int n=num;
    for(int i=0;n>0;i++){
        int rem=n%10;
        sum+=rem*rem*rem;
        n=n/10;
    }
    printf("Armstrong number of %d is %d\n",num,sum);
}