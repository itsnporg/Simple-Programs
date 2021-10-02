
public class BubbleSort{

  static void bubble(int a[],int n){

    for(int i=0;i<n-1;i++){

      for(int j=0;j<n-1-i;j++){
        // it is for swapping
        //
        if(a[j]>a[j+1]){
          int temp = a[j];
          a[j] = a[j+1];
          a[j+1] = temp;
        }
      }

    }
  }

  // print the array elements 

  static void print(int a[], int n){

    for(int i=0;i<n;i++){
      System.out.print(a[i]+" ");
    }
  }
  public static void main(String[] args){

    int a[] = {3,4,5,6,2,1,34,6,8,6};
    int n = a.length;
    System.out.println("\nBefore\n");
    print(a,n);
    System.out.println("\nAfter\n");
    bubble(a,n);
    print(a,n);
}
}
