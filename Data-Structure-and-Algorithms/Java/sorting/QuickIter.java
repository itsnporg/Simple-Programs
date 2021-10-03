public class QuickIter{

  static void swap(int a[], int i, int j){

    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }

  static int partition(int a[], int l, int h){

    int pivot = a[l];
    int i = l;
    int j = h;

    do {


    
    do{i++;}while(i<h && a[i]<=pivot);
    do{j--;}while(a[j]>pivot);

    if(i<j)swap(a, i, j);
    
  }while(i<j);

    swap(a,l,j);
    return j;

  }

  static void quicks(int a[], int l, int h){
    int j;
    if(l<h){
      j = partition(a, l, h);
      quicks(a, l, j);
      quicks(a, j+1, h);
    }
  }


  static void print(int a[], int n){
    for(int i=0;i<n;i++){
      System.out.println(a[i]);
    }
  }
  
  public static void main(String[] args){

    int a[] = {5,6,7,3,1,3,5,7};
    int n = a.length;
    quicks(a, 0, n);
    print(a, n);

    
    
  }
}
