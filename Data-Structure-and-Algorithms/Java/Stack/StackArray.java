public class StackArray{
  int Max = 100,top = -1;
  int a[] = new int[Max];


void push(int x){
    // check if it is full or not 
    if(isFull()){
      System.out.println("Stack is full");
    }
    else{
      top++;
      a[top] = x;
      System.out.println(x+" is pushed");
    }
  }
// Delete Operation 

boolean isEmpty(){

  if(top==-1){
    return true;
  }
  else{
    return false;
  }
}

boolean isFull(){
  if(top==Max-1){
    return true;
  }
  else{
    return false;
  }
}
int stackTop(){
  if(isEmpty()){
    return -1;
  }
  else{
    return a[top];
  }
}


void pop(){
  int x;
  if(isEmpty()){
    System.out.println("Stack Underflow!!");
  }
  else{
   x = a[top];
   top--;
   System.out.println(x+" is popped");
  }
}

void display(){
  if(top==-1){
    System.out.println("Stack is Empty");
  }
  else{
    for(int i=top;i>=0;i--){
      System.out.print(a[i]+" ");
    }
  }
}
/*
static boolean isEmpty(){

}
*/

void peak(int pos){
  int t = -1;

  if(top-pos+1 <0){
    System.out.println("Underflow");
  }
  else{
    t = a[top-pos+1];
    System.out.println(t+" is the required element");
  }
  }
  public static void main(String[] args){

  StackArray st = new StackArray();
   st.push(3);
   st.push(4);
   st.push(5);
   st.push(6);
   st.push(7);
   st.pop();
   
   st.display();

   System.out.println("\nTop element in an array is ");
   System.out.println(st.stackTop());
   System.out.println();
   st.peak(2);
  }
}
