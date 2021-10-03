https://www.hackerrank.com/challenges/the-time-in-words/problem


#include<stdio.h>


#include<stdlib.h>


#include<string.h>


#include<assert.h>


#include<math.h>


int main()


{


    int h,m;


    scanf("%d\n %d\n",&h,&m);


    char count[30][100]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fiveteen","sixteen","seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine"};


    if(m==0)


    printf("%s o' clock",count[h-1]);


    else if(m>30)


    {


        if(m==45)


        printf("quarter to %s",count[h]);


        else if(m==59)


        printf("one minute to %s",count[h]);


        else if(m!=45 && m!=59)


        printf("%s minutes to %s",count[60-m-1],count[h]);


    }


    else if(m<=30)


    {


        if(m==1)


        printf("one minute past %s",count[h-1]);


        else if(m==15)


        printf("quarter past %s",count[h-1]);


        else if(m==30)


        printf("half past %s",count[h-1]);


        else if(m!=15 && m!=30 && m!=1)


        printf("%s minutes past %s",count[m-1],count[h-1]);


    }


    return 0;


}

