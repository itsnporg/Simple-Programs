#include<stdio.h> 
#include<conio.h> 
void main()
{
int a=10, b=10,x,y; 
x = (++a*++a - ++a);  //{(12*12)-13}
y = (++b*b++ - b++);   // {(11*12)-12}
printf("value of a= %d and value of x= %d\n",a,x); 
printf("value of b= %d and value of y= %d\n",b,y); 
getch();
}