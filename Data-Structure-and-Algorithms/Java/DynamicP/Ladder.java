
public class Ladder{
static int a[] = new int[100];

  static int fib(int n){

  
    if(n<=1){
      return n;
    }

    if(a[n]!=0){
      return a[n];
    }

    else{

      a[n] = fib(n-1)+fib(n-2);
    }
    return a[n];

  }

  public static void main(String[] args){
    System.out.println(fib(3));
  }
}
