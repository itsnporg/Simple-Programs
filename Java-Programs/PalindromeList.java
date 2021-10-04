 class PalindromeList{
     static class Node
     {
         int data;
         Node next;
         static Node newNode(int data)
         {
             Node temp = new Node();
             temp.data = data;
             temp.next = null;
             return temp;
         }
     };

     // Create new Node
    public static void main(String args[]){
        Node list=new Node().newNode(1);
        list.next=new Node().newNode(2);
        list.next.next=new Node().newNode(1);
        boolean check=isPalindrome(list);
        if(check==true)
            System.out.println("It is Palindrome");
        else
            System.out.println("It is not a Palindrome");
    }
    static Node left = null;
    public static boolean isPalindrome(Node head) {
        left = head;
        check(head);
        return value;
    }
    static boolean value = true;
    static void check(Node right){
        if(right == null){
            return;
        }

        check(right.next);

        if(right.data != left.data){
            value = false;
            return;
        }
        left = left.next;
    }
 }
 
