import java.util.*;
import java.io.*;
import java.lang.*;

class ArrayRot{
  static void swap(int a, int b){
    a = a^b;
    b = a^b;
    a = a^b;
  }

  public static void main(String[] args) {
   Scanner sc= new Scanner(System.in);
  int t = sc.nextInt();
  while(t-->0){

    int n = sc.nextInt();

    int a[] = new int[n+1];

    for(int i=0; i<n; i++){
      a[i] = sc.nextInt();
    }

    int b[] = new int[n+1];

    for(int i=0; i<n; i++){
      b[i] = sc.nextInt();
    }

    // rotate the b
    //
    int temp = b[0];
    for(int i=0; i<n-1; i++){

      b[i] = b[i+1];
    }
    b[n-1] =temp;

    int c[] = new int[n+1];
    for(int i=0; i<n;i++){

      c[i] = (a[i]+b[i])%n;
    }

    for(int i=0;i<n;i++){
      System.out.print(c[i]+" ");
    }

  }
}
}
