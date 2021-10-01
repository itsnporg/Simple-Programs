#include <stdio.h>
void main(){
int cid;
float unit,amt;
char name[30];
printf("CUSTOMER ID AND UNIT \t ");
scanf("%d %f",&cid,&unit);
 if(unit <= 20)
    {
        amt = amt + (unit * 12);
    }
    if(unit >= 21 && unit <41)
    {
        amt = amt + (unit * 15);
    }
    if(unit >= 60)
    {
        amt = amt + (unit * 20);
    }
if(amt < 100){
    amt = 100;
}
if (amt > 900){
    amt = (0.15*amt)+amt;
}
printf("Enter your name \t");
scanf("%s",name);
printf("Bill for %s is : \n",name);
printf("Electricity bill = %.2f Rupees for %.2f units of CID %d \n",amt,unit,cid);
}