public class Double{
  
  static int max = 10;

  static int hash1(int key){
    return key%max;
  }

  static int hash2(int key){
    int r = 7; // get prime number 
    return (r - (key%r));

  }

  static int probe(int H[], int key){

    int index = hash1(key);
    int ind = hash2(key);
    int i=0; 
    while(H[(index+i*(ind))%max]!=0){
      i++;
    }
    return (index+i*(ind))%max;
  }

  static void insert(int H[], int key){
    int index = hash1(key);

    while(H[index]!=0){
      index = probe(H,key);
    }

    H[index] = key;

  }

  static int search(int H[], int key){
    int i = 0;

    int index = hash1(key);
    int ind = hash2(key);

    while(H[(index+i*(ind))%max]!=key){
      i++;
    }

    return (index+i*(ind))%max;
  }

  public static void main(String[] args){
    int H[] = new int[max];

    for(int i=0;i<max; ++i){
      H[i] = 0;


    }

    insert(H,3);
    insert(H,5);
    insert(H,25);

    System.out.println(search(H,25));
  }
}
