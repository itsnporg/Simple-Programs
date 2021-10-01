                                            // Source code                          -Prasiddhi Dahal, 11


// 1Write a program to convert Celsius to Fahrenheit//
#include <stdio.h>
int main()
{
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit", celsius, fahrenheit);
    return 0;
}






// 2Write a program that calculates the area of triangle
#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, s, area;
    printf("Enter sides of a triangle\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    s = (a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("Area of the triangle = %.2lf\n", area);
    return 0;
}










//3Write a program to calculate area of circle and its circumference
#include<stdio.h>
int main(){
	float radius, area, circumference;
	printf("Enter the radius of Circle : ");
	scanf("%f", &radius);
	area = 3.14 * radius * radius;
	circumference= 2 * 3.14 * radius;
	printf("Area of Circle : %f", area);
    printf("circumference of circle: %f",circumference);
	return 0;
}


//4Write a program that reads the marks in each subject and calculates the percentage//
#include <stdio.h>
int main()
{
    float eng, phy, chem, math, comp; 
    float percentage;
    printf("Enter marks of five subjects: \n");
    scanf("%f%f%f%f%f", &eng, &phy, &chem, &math, &comp);
    percentage = (eng + phy + chem + math + comp) / (float)500.0 * 100;
    printf("Percentage = %.2f", percentage);
    return 0;
}

//5 write a program that reads a number and identifies whether the given number is odd or even
#include <stdio.h>
int main() 
{
    int n;
    printf ("enter a number :");
    scanf("%d",&n);
    if( n % 2==0)
    printf ("%d is a even",n );
    else
{
    printf ("%d is a odd",n );
    }
    return 0;
}

//6write a program to find largest among two numbers
#include <stdio.h>  
int main() 
{  
    int a, b;  
    printf("Please Enter Two different values\n");  
    scanf("%d %d", &a, &b);  
    if(a > b) 
    {
        printf("%d is Largest\n", a);          
    } 
    else if (b > a)
    { 
        printf("%d is Largest\n", b);  
    } 
    return 0;  
} 

//7write a program to read the marks of a subject and print the equivalent grade
#include<stdio.h>
void main()
{
    int marks;
    printf("Enter your marks ");
    scanf("%d",&marks);
    if(marks<0 || marks>100)
    {
        printf("Wrong Entry"); }
    else if(marks<50){
        printf("Grade F"); }
    else if(marks>=50 && marks<60){
        printf("Grade D");}
    else if(marks>=60 && marks<70){
        printf("Grade C");}
    else if(marks>=70 && marks<80){
        printf("Grade B");}
    else if(marks>=80 && marks<90) {
        printf("Grade A");}
    else{
        printf("Grade A+");}
    }

//8write a program to check whether the program is odd or even using switch
Source code
#include <stdio.h>
int main()
{
    int num;
    printf("Enter any number to check even or odd: ");
    scanf("%d", &num);
    switch(num % 2)
    {
        case 0: 
            printf("Number is Even");
            break;
        case 1: 
            printf("Number is Odd");
            break;
    }
    return 0;
}

//9write a program to design a simple calculator using switch statement
#include <stdio.h>
int main() {
    char operator;
    double first, second;
    printf("Enter an operator (+, -, *,): ");
    scanf("%c", &operator);
    printf("Enter two operands: ");
    scanf("%lf %lf", &first, &second);
    switch (operator) {
    case '+':
        printf("%.1lf + %.1lf = %.1lf", first, second, first + second);
        break;
    case '-':
        printf("%.1lf - %.1lf = %.1lf", first, second, first - second);
        break;
    case '*':
        printf("%.1lf * %.1lf = %.1lf", first, second, first * second);
        break;
    case '/':
        printf("%.1lf / %.1lf = %.1lf", first, second, first / second);
        break;
    default:
        printf("Error! operator is not correct");
    }
return 0;
}

// 10write a program to check whether the alphabet is vowel or consonant
#include <stdio.h>
int main()
{
    char ch;
    printf("Enter any alphabet: ");
    scanf("%c", &ch);
    switch(ch)
    {
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
        default: 
            printf("Consonant");
    }return 0;
}

                                                 //END












