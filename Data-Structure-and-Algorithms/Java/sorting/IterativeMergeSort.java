public class IterativeMergeSort{
  
  static void merge(int a[], int l, int mid, int h){
    
    int c[] = new int[100];

    int i = l;
    int j = mid+1;
    int k = l;

    while(i<=mid && j<h){
      if(a[i] < a[j]){

        c[k++] = a[i++];
      }
      else{
        c[k++] = a[j++];
      }
    }

    for(;i<=mid;i++){
      c[k++] = a[i];
    }

    for(; i<h;i++){
      c[k++] = a[j];
    }

    for(i = l;i<h;i++){
      c[i] = a[i];
    }
  }

  static void Msort(int a[], int n){

    int p,l,h,i,mid;

    for(p = 2;p<n;p = p*2){

      for(i = 0; p+i-1<n;i=p+i){
        l = i;
        h = p+i-1;
        mid = (l+h)/2;

        merge(a,l,mid,h);
      }
    }

    if(p/2<n){
      merge(a,0,p/2-1,n);
    }
  }
  public static void main(String[] args){

    int a[] = {4,5,6,7,8};
    int n = a.length;

    int l = 0;
    int h = a.length;
    int mid = (l+h)/2;
    Msort(a,n);

    for(int i=0;i<n;i++){
      System.out.print(a[i]+" ");
    }
  


  }
}
