public class Merge{

  static void merge(int a[], int b[], int m, int n){
    int i = 0,j=0,k=0;
   int c[] = new int[30];

    while(i<m && j<n){
      if(a[i]<b[j])
        c[k++] = a[i++];
      else
        c[k++] = b[j++];
    }

    // from where it started
    for(;i<m;i++){
      c[k++] = a[i];
    }

    for(;j<n;j++){
      c[k++] = a[j];
    }

    for( i=0;i<(m+n);i++){
      System.out.print(c[i]+" ");
    }
  }
  public static void main(String[] args){

    int a[] = {2,10,18,20,23};
    int m = a.length;
    int b[] = {4,9,19,25};
    int n = b.length;

    merge(a,b,m,n);

  

  }
}
