public class Insertion{
  

  static void insert(int a[], int n){

    for(int i=1;i<n;i++){
      // we assume the first element is already inserted

      int j = i-1;
      int x = a[i];
      while(j>-1 && a[j] > x){

        if(a[j]>a[j+1]){
          a[j+1] = a[j];
        }

        j--;
      }

      a[j+1] =x;
      
    }
  }
  static void print(int a[], int n){

    for(int i=0;i<n;i++){
      System.out.print(a[i]+" ");
    }
  }

  public static void main(String[] args){

    int a[] = {3,5,6,5,1,2,1,7,8,6,32,12};
    int n = a.length;

    insert(a,n);
    print(a,n);
  }
}

