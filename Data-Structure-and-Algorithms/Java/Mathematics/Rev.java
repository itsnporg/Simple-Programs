public class Rev{

  public static void main(String[] args){

    int n = 345;

    int temp = n;

    int r = 0,s =0;


    while(n!=0){
      r = n%10;
      s = s*10+r;
      n =n/10;
    }

    System.out.println(s);
  }
}
