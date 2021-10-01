public class Mult{
    // a+(n-1)*d; 

static  void mul(int a,int b,int n){

    int k = a+(n-1)*(b-a);

    System.out.println(k);

  }
  public static void main(String[] args){
    int n = 4;

    int a = 2;
    int b = 3;

    mul(a,b,n);

  }
}
