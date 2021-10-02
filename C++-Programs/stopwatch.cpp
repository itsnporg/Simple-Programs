#include<process.h>
#include<iostream>
#include<dos.h>

int h=0,m=0,s=0,ms=0;
char ch=’p’;

void main()
{
void watch();
watch();

while(1)
{
if(kbhit())
ch=getch();
if(ch==’s’||ch==’S’)
break;
if(ch==’e’||ch==’E’)
exit(0);
}

while(1)
{
watch();
delay(10);

if(kbhit())
ch=getch();
if(ch==’r’||ch==’R’)
{
h=m=s=ms=0;
watch();

while(1)
{
if(kbhit())
ch=getch();
if(ch==’s’||ch==’S’)
break;
if(ch==’e’||ch==’E’)
exit(0);
}
}
else
if(ch==’p’||ch==’P’)
while(1)
{
if(kbhit())
ch=getch();
if(ch==’s’||ch==’S’)
break;
if(ch==’e’||ch==’E’)
exit(0);
if(ch==’r’||ch==’R’)
{
ch=’c’;
h=m=s=ms=0;
watch();
}
}
else
if(ch==’e’||ch==’E’)
exit(0);

if(ms!=99)
ms++;
else
{
ms=0;
if(s!=59)
s++;
else
{
s=0;
if(m!=59)
m++;
else
{
m=0;
h++;
}
}
}
}
}

void watch()
{
clrscr();
cout<<“nnnnntttt#############”;
cout<<“ntttt# Stopwatch #”;
cout<<“ntttt#############”;
cout<<“nntttt  “<<h<<“:”<<m<<“:”<<s<<“:”<<ms;

cout<<“nnnnnnnnntttttttPress Key”;
cout<<“nttttttt———“;
cout<<“nttttttts -> Start”;
cout<<“ntttttttp -> Pause”;
cout<<“ntttttttr -> Reset”;
cout<<“nttttttte -> Exit”;
}

