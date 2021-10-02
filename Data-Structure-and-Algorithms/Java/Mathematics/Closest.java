public class Closest{

  static void close(int n, int m)
  {
    int a = n/m;
    int x = a*m;
    int y = (a+1)*m;


    int n2 = (n*m)>0?(m*(a+1)):(m*(a-1));

    if(Math.abs(n-x)<Math.abs(n-n2))
      System.out.println(x);
    else{
      System.out.println(n2);
    }


  }
  public static void main(String[] args){

    close(13,4);
    close(-15,6);
  }
}
