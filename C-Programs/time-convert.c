//convert seconds to hour,minute and second
#include<stdio.h>

int main(void)
{
    long minute,hour,second,inputsec,hourRemainder,minuteRemainder;
   
    printf("enter numbers in seconds ");
    scanf("%ld",&inputsec);

    hour= inputsec/3600;
    hourRemainder=inputsec%3600;

    minute = hourRemainder/60;
    minuteRemainder=hourRemainder%60;

    second=minuteRemainder;

    printf("hour=%ld\nminute=%ld\nsecond=%ld",hour,minute,second);


}
