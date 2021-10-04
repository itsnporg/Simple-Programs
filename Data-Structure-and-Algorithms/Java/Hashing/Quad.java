public class Quad{

  static int max=  10;

  static int hash(int key){
    return key%max;
  }

  static int prob(int H[], int key){
    int i=0;
    int index = hash(key);

    while(H[(index+(i*i))%max]!=0){
      i++;
    }
    return (index+(i*i))%max;
  }

  static void insert(int H[], int key){

    int index = hash(key);

    while(H[index]!=0){
      index = prob(H,key);
    }

    H[index] = key;
  }

  static int search(int H[], int key){
    int index = hash(key);
    int i=0;

    while(H[(index+(i*i))%max]!=key){
      i++;
    }
    return (index+(i*i))%max;
  }

  public static void main(String[] args){

    int H[] = new int[max];

    for(int i=0;i<max; ++i){
      H[i] = 0;
    }
    
    insert(H,3);
    insert(H,5);
    insert(H,6);
    insert(H,12);
    insert(H,13);
    

    int x = 3;
    System.out.println(search(H,x));
  }
}
