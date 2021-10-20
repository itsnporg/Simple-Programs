public class Kth{

static  int Gcd(int a, int b){

  if(b==0){
    return a;
  }

  else{
   return  Gcd(b,a%b);
  }
 }

  public static void main(String[] args){

    System.out.println(Gcd(8,4));

    int a[] = {2,4,6,8};

    int res = 0;
    for(int i=0;i<a.length;i++){

      res = Gcd(res,a[i]);

    }

    System.out.println(res);
    

    }
}
