#include <stdio.h>

//declaration
void add();
int add2();
void add3(int,int);
int add4(int,int);

int main()
{
    //function call + print statements
    add();
    printf("the summ of add2() is %d\n",add2());
    add3(5,6);
    printf("the sum of add4() is %d\n",add4(10,12));
    return 0;
}

void add(){ //1.no arg, no return
    int a,b;
    printf("enter numbers ");
    scanf("%d%d",&a,&b);
    printf("summ is add() is %d \n",a+b);
}

int add2(){ //2.no arg, but return
    int a,b;
    printf("enter numbers ");
    scanf("%d%d",&a,&b);
    return a+b;
}

void add3(int a ,int b){ //3.arg but no return
    printf("the sum of add3() is %d\n",a+b);
}

int add4(int a, int b){ //4.arg and return
    return a+b;
}