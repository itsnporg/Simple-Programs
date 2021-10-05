public class Arm{
  static void Arm(int n){

    int r = 0,s = 0;
    int temp = n;
    while(n!=0){

      r = n%10;
      s+=Math.pow(r,3);
      n/=10;
    }


    if(s==temp){
      System.out.println("Yes");
    }
    else{
      System.out.println("No");
    }
  }

  public static void main(String[] args){

    Arm(153);
    Arm(1);
    Arm(353);
  }
}
