public class Linear{

  static int max = 10;

  static int hash(int key){

    return key%max;
  }

  static int probe(int H[], int key){
    
    int index = hash(key);

    int i=0;
    while(H[(key+i)%max]!=0){
      i++;
    }
    return (key+i)%max;
  }

  static void insert(int H[], int key){
    int index = hash(key);

    while(H[index]!=0){
      index = probe(H,key);
    }
    H[index]= key;
  }

  static int search(int H[], int key){
    int index = hash(key);
    int i = 0;
    
    while(H[(index+i)%max]!=key){
      i++;
    }
    return (index+i)%max;
  }

  public static void main(String[] args){
    int H[] = new int[max];
    for(int i=0;i<max;i++){
      H[i] = 0;
    }

    insert(H,2);
    insert(H,5);
    insert(H,6);
    insert(H,2);

    int x = 5;
    System.out.println(search(H,9));
  }
}
