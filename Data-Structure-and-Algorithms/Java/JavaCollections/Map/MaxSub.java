// max sub array 

// author: Nishant Banjade 

public class MaxSub{

  static void sum(int a[]){
    
    int k = Integer.MAX_VALUE; // FOR K 
    int s1 = Integer.MAX_VALUE;
    int sum = 0;
    int s2 = 0;


    for(int i=0; i<a.length; i++){

      if(a[i] < s1){
        if(a[i] < 0){
          k = Math.min(a[i],s1);
        }
      }

      if(a[i] > k){
        sum+=a[i];
      }

      if(a[i]<k){

        if(a[i] <0){
          continue;
        }

    
    }

    s2+=a[i];
    
  }
    
  if(sum>s2){
    System.out.println(sum);
  }
  else{
    System.out.println(s2);
  }
  }


  public static void main(String[] args){
    int a[] = {1,2,3,-7,4,5};
    sum(a);

    
  }
}
