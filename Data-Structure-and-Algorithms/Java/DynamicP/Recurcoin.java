class Recurcoin{

  // n is the amount and array is the notes 
  // we need to find the minimum notes that sums the n
  static int mincoin(int n, int a[]){

    if(n==0) return 0;

    int ans = Integer.MAX_VALUE;

    for(int i=0; i<a.length; i++){
      if(n-a[i] >= 0){

        int sub = mincoin(n-a[i],a);
        
        if(sub!=Integer.MAX_VALUE && sub+1 < ans){
          ans = sub+1;
          
      }
      
    }
  }
    return ans;
  }

  public static void main(String[] args){
    int n = 18;
    int a[] = {5,7,1};

    System.out.println(mincoin(n,a));
  }

}
