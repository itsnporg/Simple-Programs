public class Single{

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

    for(;j<=h;j++){
      c[k++] = a[j];
    }

    for(i=l;i<=h;i++){
      a[i]=c[i];
    }
  }

  public static void main(String[] args){

    int a[] = {3,4,6,7,3,1,3,4,45,6};
    int l=0;
    int h=a.length;

    int mid = (l+h)/2; 
    merge(a,l,mid,h);

    for(int i=0;i<h;i++){
      System.out.print(a[i]+" ");
    }

    
  }
}
