// It is the index based sorting algorithm 
// O(n) swap for all
// O(n^2) comparision

public class Selection{

 
  static void swap(int a[], int i,int k){

       int temp = a[i];
       a[i] = a[k];
       a[k] = temp;
      }

  static void sel(int a[], int n){
    
    for(int i = 0; i <n; i++){


      for(int j= i; j <n; j++){
          int k = i;



        if(a[j]<a[k]){
          k = j;
        }
      
        swap(a,i,k);

    }

    
  }
  }
  static void print(int a[] , int n){
    for(int i=0;i<n;i++){
      System.out.print(a[i]+" ");
    }
  }
  public static void main(String[] args){

    int a[] = {4,5,2,1,6};
    int n = a.length;
    
    sel(a,n);

    print(a,n);
  }
}
