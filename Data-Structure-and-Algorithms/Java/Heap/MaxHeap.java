public class MaxHeap{

  static void Insert(int H[], int n){

    int i = n, temp;
    // it stored the last element 
    temp = H[i];

    while(i>1 && temp>H[i/2]){
      H[i]=H[i/2];
      i = i/2;
    }
    H[i] = temp;

  }

  public static void main(String[] args){
    int H[] = {30,20,15,5,10,12,6,40};


    for(int i=2;i<=7;i++){
      Insert(H,i);
    }

    for(int i=1;i<=7;++i){
      System.out.print(H[i]+" ");
    }

  }
}

