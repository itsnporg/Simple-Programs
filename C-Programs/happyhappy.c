                                    // Operators and expressions                         --Nisham Ghimire
                                    //                                                   --Roll: 22 ,CS


// 1. Write a program to convert Celsius to Fahrenheit.

#include <stdio.h>
int main(){
    float C, f;
    printf("Input temperature in Celsius scale: ");
    scanf("%f", &C);
    f = (C * 9 / 5) + 32;
    printf("%.2f C = %.2f F \n", C, f);
    return 0;
} 
// ---1


// 2. Write a program that calculates the area of a circle and circumference. 

#include<stdio.h>
int main() {
    float radius, area, circumference;
    printf("Enter the radius of Circle : ");
    scanf("%f", &radius);
    area = 3.14 * radius * radius;
    circumference = 2 * 3.14 * radius;
    printf("Area of Circle : %.2f \n", area);
    printf("Circumference of Circle : %.2f \n",circumference);
    return (0);
}
// ---2


// 3. Write a program that calculates the area of a triangle.

#include<stdio.h>
    void main(){
    float base,height;
    printf("Enter base and height of triangle : ");
    scanf("%f %f",&base,&height);
    printf("Area of triangle : %.2f \n",0.5*base*height);
} 
// ---3


// 4. Write a program that reads the marks in each subject and calculates the
// percentage.

#include <stdio.h>
int main()
{
    int marks1,marks2,marks3,marks4,marks5,avg;
    printf("Enter your marks ");
    scanf("%d %d %d %d %d",&marks1,&marks2,&marks3,&marks4,&marks5);
    avg = (marks1 + marks2 + marks3 + marks4 + marks5) / 5;
    if(marks1>100 || marks2 >100 || marks3 > 100 || marks4 > 100 || marks5 >100)
    {
        printf("Your marks is greater than hundred which is not possible!!");
    }
    else if(marks1<50 || marks2 < 50 || marks3 <50 || marks4 < 50 || marks5 <50)
    {
        printf("Sorry you are fail!");
    }
    else if(avg>=50 && avg<55)
    {
        printf("Grade D");
    }
    else if(avg>=55 && avg<60)
    {
        printf("Grade C-");
    }
    else if(avg>=60 && avg<65)
    {
        printf("Grade C");
    }
    else if(avg>=65 && avg<70)
    {
        printf("Grade C+");
    }
    else if(avg>=70 && avg<75)
    {
        printf("Grade B-");
    }
    else if(avg>=75 && avg<80)
    {
        printf("Grade B");
    }
    else if(avg>=80 && avg<85)
    {
        printf("Grade B+");
    }
    else if(avg>=85 && avg<90)
    {
        printf("Grade A-");
    }
    else
    {
        printf("Grade A");
    }
    return 0;
}
// ---4



                                        // CONDITIONAL STATEMENT


// 1. Write a program that reads a number and identifies whether the given number is even or
// odd.

#include <stdio.h>
void main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    if(num % 2 == 0){
    printf("%d is even.", num);
    }
    else{
    printf("%d is odd.", num);
}
// ---1


// 2. Write a program to find the largest number among two numbers.

#include <stdio.h>
void main() {
    int a,b;
    printf("Enter two numbers : ");
    scanf("%d %d",&a,&b);
    (a>b?printf("%d is greater.",a):printf("%d is greater.",b));
}
// ---2


// 3. Write a program to read the mark of a subject and prints the equivalent grade.

#include<stdio.h>
void main(){
    int marks;
    printf("Enter your marks ");
    scanf("%d",&marks);
    if(marks<0 || marks>100)
    {
    printf("Wrong Entry");
    }
        else if(marks<50)
    {
    printf("Grade F");
    }
    else if(marks>=50 && marks<60)
    {
    printf("Grade D");
    }
    else if(marks>=60 && marks<70)
    {
    printf("Grade C");
    }
    else if(marks>=70 && marks<80)
    {
    printf("Grade B");
    }
    else if(marks>=80 && marks<90)
    {
    printf("Grade A");
    }
    else
    {
    printf("Grade A+");
    }
} 
// ---3


// 4. Write a program to check whether number is EVEN or ODD using switch.

#include <stdio.h>
void main()
{
    int number,a;
    printf("Enter a positive integer number: ");
    scanf("%d",&number);
    a= number%2;
    switch(a){
    case 0:
    printf("%d is an EVEN number.\n", number);
    break;
    case 1:
    printf("%d is an ODD number.\n", number);
    break;
}
// ---4


// 5. Write a program to design calculator with basic operations using switch.

#include <stdio.h>
void main() {
    char operator;
    float number1, number2;
    printf("Enter an operator: ");
    scanf("%c", &operator);
    printf("Enter two numbers: ");
    scanf("%f %f", &number1, &number2);
    switch (operator) {
    case '+':
    printf("%.1f + %.1f = %.1f \n", number1, number2, number1 + number2);
    break;
    case '-':
    printf("%.1f - %.1f = %.1f \n", number1, number2, number1 - number2);
    break;
    case '*':
    printf("%.1f * %.1f = %.1f \n", number1, number2, number1 * number2);
    break;
    case '/':
    printf("%.1f / %.1f = %.1f \n", number1, number2, number1 / number2);
    break;
    default:
    printf("Entered operator is not specified.\n");
    }
}
// ---5


// 6. Write a program to check whether a character is VOWEL or CONSONANT
// using switch.

#include <stdio.h>
void main(){
    char x;
    printf("Enter any alphabet: ");
    scanf("%c",&x);
    switch(x){
    case 'a':
    printf("Vowel");
    break;
    case 'e':
    printf("Vowel");
    break;
    case 'i':
    printf("Vowel");
    break;
    case 'o':
    printf("Vowel");
    break;
    case 'u':
    printf("Vowel");
    break;
    case 'A':
    printf("Vowel");
    break;
    case 'E':
    printf("Vowel");
    break;
    case 'I':
    printf("Vowel");
    break;
    case 'O':
    printf("Vowel");
    break;
    case 'U':
    printf("Vowel");
    break;
    default:
    printf("Consonant");
}
// ---6

                                        //The END
