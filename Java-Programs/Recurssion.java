public class Recurssion {
    static int n1=0, n2=1,n3=0;
    static void fibonaci(int count){
        if(count>0){
            n3 = n1+n2;
            n1=n2;
            n2=n3;
            System.out.print(" "+n3);
            fibonaci(count-1);
        }
    }
    static int factorial(int n){
        if(n==1 || n==0){
            return 1;
        }
        else{
           return n*factorial(n-1);
        }
    }
    static int factorial_Alternative(int n){
        if(n==1 || n==0){
            return 1;
        }
        else{
            int product =1;
            for(int i=1;i<=n;i++){
               product *= i;
            }
            return product;
        }
    }
    public static void main(String[] args) {
//        Code For Factorial using Recurssion
        int x=5;
        System.out.println("The factorial of given value is "+factorial(x));
        System.out.println("The factorial of given value is "+factorial_Alternative(x));

//          Code for Fibonacci Series using Recurrsion
        int count=10;
        System.out.print(n1+" "+n2);
        fibonaci(count-2);
    } 
}
