public class Subset{

  static int count = 0;

  static void sub_sum(int list[], int sum, int start, int target)
  {

    if(target == sum)
    {
      count++;


      if(start<list.length)
        sub_sum(list,sum-list[start-1],start,target);
    }

    else
    {

      for(int i=start; i<list.length; i++){
        sub_sum(list, sum+list[i], i+1,target);
      }
    }
  }

  public static void main(String[] args){
    int list[] = {1,1,1,1,1};

    sub_sum(list,0,0,3);
    System.out.println(count);
  }
}
