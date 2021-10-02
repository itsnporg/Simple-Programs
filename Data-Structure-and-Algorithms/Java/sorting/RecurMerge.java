public class RecurMerge{

  static void merge(int a[], int l, int mid, int h){

    int i = l;
    int j = mid+1;
    int k = l;

    int c[] = new int[100];
    while(i<=mid && j<=h){

      if(a[i]<a[j]){
        c[k++] = a[i++];
        
      }
      else{
        c[k++] = a[j++];
      }

    }

    for(;i<=mid;i++){
      c[k++] = a[i];
    }

    for(; j<=h;j++){
      c[k++] = a[j];
    }

    for(i=l;i<=h;i++){
      a[i] = c[i];
    }
  }

  static void mergeS(int a[], int l,int r){

    if(l<r){

      int mid = l+(r-l)/2;
      mergeS(a,l,mid);

      mergeS(a,mid+1,r);

      merge(a,l,mid,r);
    }
  }

  
  public static void main(String[] args){

    int a[] = {5,6,3,1,3,6,8,8};
    int l = 0;
    int h = a.length;

    int mid  = l+(h-l)/2;

    mergeS(a,l,h-1);

    for(int i=0;i<h;i++){
      System.out.print(a[i]+" ");
    }
  }
}
