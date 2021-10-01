/*Nisham Ghimire, CS, Roll- 22 */

//function
/* 1.program to identify whether the given number is a perfect number or not using a
function. 28 is a perfect number.   */

#include <stdio.h>

int perfect (int s){
    int b = 1, sum = 0;
    while (b<s){
        if ((s % b) == 0){
            sum = sum + b;
        }
            b++;
    }
        return sum;
}

int main(){
    int num, x;
    printf("Enter an integer value\t");
    scanf("%d", &num);
    x = perfect(num);
    if(x==num)
        printf("The number %d is a perfect number\n", num);
    else
        printf("The number %d is not a perfect number\n", num);
    return 0;
}

/* 2.Program to calculate GCD of two given Integers*/
#include <stdio.h>

int gcd(int, int); //declaration

int main() //main
{
    printf("The GCD of 10 and 16 is %d\n",gcd(10,16)); //call
}

int gcd(int u , int v) //function
{
    int temp;
    while(v != 0) //loop
    {
        temp = u % v;
        u = v;
        v= temp;
    }
    return u; //return
}

/* 3. Given a number, write a program using a while loop to reverse the digits of the
number. For example, the number 12345 should be written as 54321 */
#include <stdio.h>

int reverse (int f){
    int remainder,rev=0;
    while (f!=0){
        remainder = f % 10;
        rev = rev * 10 + remainder;
        f = f / 10;
        }
        return rev;
    }

void main(){
    int n;
    printf("Enter a Number\t");
    scanf("%d", &n);
    printf("Reversed number = %d\n\n",reverse(n));
}

/* 4. Write a program that computes and prints a table of factorials for any given m.
Write a function for the calculation and printing of factorials. */
#include <stdio.h>

int factorial(int n){
    int fact = 1;
    for (int i = 1;i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

void main(){
    int num;
    printf("Enter number = ");
    scanf("%d",&num);
    printf("Factorial of %d = %d \n",num,factorial(num));
}

//recurssion
/*  1. Write a recursive program to find the factorial of a given number.*/
#include <stdio.h>

int factorial (int n){
    if(n<=1)
        return 1;
    else
        return n*factorial(n-1);
}

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    printf("Factorial of the given number is : %d \n",factorial(n));
    return 0;
}

/* 2.Write a recursive program to find a GCD of two numbers. */
#include<stdio.h>  

int gcd(int n1, int n2){  
    if(n1 == 0) return n2;  
    if(n2 == 0) return n1;  

    if(n1 > n2)  
        return gcd(n1%n2, n2);  
    else  
        return gcd(n1, n2%n1);  
}  

void main() {  
    int num1, num2;  
    printf("Enter 2 positive integer numbers:  ");  
    scanf("%d %d", &num1, &num2);  
    printf("GCD of %d and %d is %d.\n", num1, num2, gcd(num1, num2));  
}  

/*3. Write a recursive program to find the sum of n natural numbers.  */
#include <stdio.h>

int sum(int num){
    if (num != 0)
        return num + sum(num - 1);
    else
        return num;
}

void main(){
    int n;
    printf("Enter a positive number: ");
    scanf("%d", &n);
    printf("Sum = %d",sum(n));   
}

//array
/* 1. Write a C program to store N numbers in a one-dimensional array and
calculate its average with the help of the function. */
#include <stdio.h>

float avg(int a[],int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];  //sum
    }
    return (sum / n);  //returing average
}

int main() {
    int num,array[100];
    printf("Enter numbes  of datas you want to enter (1 to 100): ");
    scanf("%d", &num);  //number of data

    printf("Enter %d numbers:   ", num);
    for (int i = 0; i < num; i++){   //taking input
    scanf("%d", &array[i]);
        }

    printf("Average of the given datas: %.2f", avg(array,num));
    }

/*2. Write a C program to convert a binary number to decimal with the help of
the function int to decimal (char bits[20], int length) where bits is the
character array to represent bits of binary numbers and length is the
number of bits in the binary number. */ 
#include <stdio.h>
#include <math.h>

int todecimal(char binary[],int length){
    int decimal = 0,i,j=0;
    for (i = length - 1; i >= 0; --i,j++)
    {
        if (binary[i] == '1'){
            decimal += pow (2, j);
            printf("One discovered at : %d\n", j);
        }
    }
    return decimal;
}

void main ()
{
    char binary [20];
    int x;
    printf ("Input the binary number:  "); //take binary num as string
    scanf ("%s", binary);

    int length = 0;
    while (binary [length] != '\0')  //calculate binary num length
    ++length;

    // printf("length is %d ", length);

    x = todecimal(binary, length);
    printf ("%s to decimal = %d\n",binary,x);
}

//array`
/*1. Write a program to evaluate transpose of n by n matrix with the help of
function void transpose (int matrix[][20], int n) where matrix is the matrix to
be transformed and n is the dimension of the matrix.*/
// C Program to find transpose of a matrix
#include <stdio.h>

// This function stores transpose of A[][] in B[][]
void transpose(int N,int A[N][N])
{
    int B[N][N];
    for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			B[i][j] = A[j][i];
        }
    }
	printf("Result matrix is \n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
		printf("%d ", B[i][j]);
        }
		printf("\n");
	}
}

int main()
{
    int N;
    printf("Enter size for matrix (NxN): ");
    scanf("%d",&N);
    int A[N][N];  //giving size

    for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
        scanf("%d", &A[i][j]);
    }
    transpose(N, A);
    return 0;
}


/* 2. Write a C program for matrix addition with the help of function add (int
a[][20], int b[][20], int n, int m) where a and b are the matrix to be added and
n and m are dimensions of a and b. */
#include <stdio.h>

void add(int A[10][10],int B[10][10],int N,int M){
	printf("SUM of  matrix is \n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
		printf("%d ", (A[i][j]+B[i][j]));
        }
		printf("\n");
	}
}

int main()
{
    int A[10][10],B[10][10],N,M;
    printf("Enter size for matrix (NxM): "); //asking size
    scanf("%d %d",&N,&M);

    //taking matrix datas for N x M of A[][] & B[][]
    printf("Enter values for A[%d][%d]\n", N, M);
    for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
        scanf("%d", &A[i][j]);
    }
    printf("Enter values for B[%d][%d]\n", N, M);
    for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
        scanf("%d", &B[i][j]);
    }

    add(A, B, N, M);
    return 0;
}

/*3. Write a C program to determine the determinant of a square matrix with the
help of function int determinant (int a[][], n) where a is the matrix whose
determinant is to be found and n is the dimension of a square matrix.*/
#include <stdio.h>
#include <stdlib.h>

int determinant(int** a, int n) {
    if(n == 1) return a[0][0];
    else if(n == 2) return (a[0][0] * a[1][1]) - (a[1][0] * a[0][1]);
    else{
        int **newArr = (int**) malloc((n-1) * sizeof(int));
        int i, j;
        for(i = 0; i < n-1; i++) {
        newArr[i] = (int*) malloc((n-1) * sizeof(int));
    }
    int new_m, new_n, mn_index, det = 0;
    int row, column;
    for(mn_index = 0; mn_index < n; mn_index++) {
        new_m = 0;
        for(row = 1; row < n; row++) {
        new_n = 0;
            for(column = 0; column < n; column++) {
                if(column == mn_index)
                continue;
                else
                newArr[new_m][new_n] = a[row][column];
                new_n++;
            }
    new_m++;
        }       
    if(mn_index%2 == 0)
        det += a[0][mn_index] * determinant(newArr, new_m);
    else
        det -= a[0][mn_index] * determinant(newArr, new_m);
    }
    return det;
        }
}

int main() {
    int n, i, j;
    printf("Enter the size of square matrix: ");
    scanf("%d", &n);
    int** matrix = (int**) malloc(n * sizeof(int*));
    for(i = 0; i < n; i++)
        matrix[i] = (int*) malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    printf("The determinant of the matrix is: %d", determinant(matrix, n));
}

//sorting 
/* 1. Write a program to arrange the numbers (array) in ascending order using
bubble sort. */
#include <stdio.h>

int main(){
    //declations
const int n = 10;
int temp,i=0,j=0,m=0;
int A[10] ={4,5,2,77,34,64,90,45,65,101};
    //before sorting display
printf("Before Sorting : ");
for(i=0;i<n;i++){
printf("%d ",A[i]);
}
printf("\n");
    //sorting process
for( i=0; i<(n-1); i++){
printf("pass %d : ",i+1);
for( j=0; j<(n-1-i);j++){
if ( A[j] > A[j+1]){
temp = A[j];
A[j] = A[j+1];
A[j+1]= temp;
}
}
    //printing pass while sorting
for(m=0; m<n; m++){
printf("%d ",A[m]);
}
printf("\n");
}
    //after sorting display 
printf("\nSorted array is : ");
for(i=0;i<n;i++){
printf("%d ",A[i]);
}
return 0;
}

// Structure
/*1. Write a program that defines a structure called STUDENT with suitable
attributes and reads the data for 5 students. Your program should display
the records in ascending order according to the name of the students.*/
#include <stdio.h>
#include <string.h>

typedef struct{
    char name[30];
    int roll;
    float marks;
}okay;

void main() {

int n,i,j;

printf("Enter number of students\n");
scanf("%d", &n);
    okay student[n];
    okay temp;
    printf("Enter roll, name and marks of student \n ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &student[i].roll);
        scanf("%s", student[i].name);
        scanf("%f", &student[i].marks);
}
for(i=0; i<(n-1); i++){
    for(j=0; j<(n-1-i);j++){
        if (strcmp(student[j].name, student[j + 1].name) > 0){
                temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
        }       
    }     
}

printf("\nSorted data in ascending is : \n\n");
for(i=0;i<n;i++){
    printf("%d ...............\n", i+1);
    printf("Name of %d is %s\n",i+1,student[i].name);
    printf("Roll  = %d\n", student[i].roll);
    printf("Marks = %.2f\n", student[i].marks);
}
}

/*2. Consider a plane graph. Write a program that uses the function to return a
distance between the given point and the origin. */
#include <stdio.h>
#include <math.h>

struct points {
    int x;
    int y;
} two;

float dist(struct points two){
    return (sqrt(pow(two.x, 2) + pow(two.y, 2)));
};

int main() {
    printf("Enter 1st coordinate points : ");
    scanf("%d %d", &two.x,&two.y);
    printf("\nThe distance between the points and origin is: %.2f units.",dist(two));
}

/*3. Define a structure data type named date containing three integer members a
day, month, and year. Write a program that would assign values to the individual
members and display the date in the following form: April 29, 2002 */
#include <stdio.h>

struct date {
    int days;
    int month;
    int year;
} asked;

void display(struct date asked);

int main(){
    printf("Enter date: \n");
    printf("(In integer form)\n");
    printf("Enter month : ");
    scanf("%d",&asked.month);
    printf("Enter day : ");
    scanf("%d",&asked.days);
    printf("Enter year : ");
    scanf("%d",&asked.year);
    display(asked);
}

void display(struct date asked){
    switch(asked.month){
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;
    }
    printf(" %d, %d",asked.days%32,asked.year);
}

/*4. Define a structure data type named time containing three members integer
hour, integer minute and integer second. Develop a program that would assign
value to the individual members and display the time in the following form:
16:40:51 */
#include <stdio.h>

struct time
{
    int hour;
    int minute;
    int second;
}t;

void main() 
{
    printf("\n Enter Hour : ");
    scanf("%d",&t.hour);
    printf("\n Enter Minute: ");
    scanf("%d",&t.minute);
    printf("\n Enter Second : ");
    scanf("%d",&t.second);

    printf("\n Time is %d:%d:%d",t.hour%24,t.minute%60,t.second%60);
}

/* • Pointer
1. Write a program that swaps two variables. Use functions and pointers.*/
#include <stdio.h>

void swap(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
};

void main(){
    int number1, number2;
    printf("Enter value for number1 : ");
    scanf("%d", &number1);
    printf("Enter value for number2 : ");
    scanf("%d", &number2);
    printf("Before Swapping: num1 is: %d, num2 is: %d\n",number1,number2);

    swap(&number1, &number2);
    printf("After Swapping: num1 is: %d, num2 is: %d\n",number1,number2);
    
}

/*2. Solve the matrix multiplication Programming using pointers. */
#include <stdio.h>

#define ROW 3
#define COL 3

void input(int mat[][COL]);
void print(int mat[][COL]);
void multiply(int mat1[][COL], int mat2[][COL], int res[][COL]);


void main()
{
    int mat1[ROW][COL];
    int mat2[ROW][COL];
    int product[ROW][COL];

    //input
    printf("Enter elements in first matrix of size %dx%d\n", ROW, COL);
    input(mat1);

    printf("Enter elements in second matrix of size %dx%d\n", ROW, COL);
    input(mat2);


    //function_call_multiply
    multiply(mat1, mat2, product);


    //function_call_print
    printf("Product of both matrices is : \n");
    print(product);
}

//input function
void input(int mat[][COL])
{
    int row, col;

    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            scanf("%d", (*(mat + row) + col));
        }
    }
}

//print function
void print(int mat[][COL])
{
    int row, col;

    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            printf("%d ", *(*(mat + row) + col));
        }

        printf("\n");
    }
}

//multiply_function
void multiply(int mat1[][COL], int mat2[][COL], int res[][COL])
{
    int row, col, i;
    int sum;


    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            sum = 0;

            for (i = 0; i < COL; i++)
            {
                sum += (*(*(mat1 + row) + i)) * (*(*(mat2 + i) + col));
            }
            //store_result_of_product
            *(*(res + row) + col) = sum;
        }
    }
} 

//End