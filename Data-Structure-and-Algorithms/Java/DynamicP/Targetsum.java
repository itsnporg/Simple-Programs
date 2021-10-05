class Targetsum{

 static int count  = 0;

  static void solve(int a[], int id, int sum, int t){
    // id = index, t = target sum

    if(id==a.length){
      if(sum==t)
        count++;
      return;
    }
    solve(a,id+1,sum+a[id],t);
    solve(a,id+1,sum-a[id],t);
  }

  public static void main(String[] args){
    int ap[] = {1,1,1,1,1};
    int t = 3;
    solve(ap,0,0,t);
    System.out.println(count);
  }
}
