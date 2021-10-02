package linklistapp;
public class LinkListApp { 
    public static void main(String[] args) {
        
        LinkList x=new LinkList();
        x.insertFirst(5);
        x.insertFirst(9);
        x.insertFirst(3);
        x.insertFirst(7);
        x.displayList();
        x.delete(1);
        x.displayList();
        Node k=x.find(2);
        k.displayNode();
         
    }

}

class Node {

    int data;
    Node next;

    Node(int item) {
        this.data = item;
        this.next = null;
    }

    void displayNode() {
        System.out.print(this.data + " ");
    }
}

class LinkList {

    private Node head;

    public LinkList() {//constructor
        head = null;
    }

    public boolean isEmpty() {
        return (this.head == null);
    }

    public void insertFirst(int i) {
        Node newNode = new Node(i);
        newNode.next = head;
        head = newNode;
    }

    public Node deleteFirst() {
        if (isEmpty()) {
            System.out.println("List is empty");
            return null;
        }
        Node temp = head;
        head = head.next;
        temp.next = null;
        return temp;
    }

    public void displayList() {
        if (isEmpty()) {
            System.out.println("List is empty");
            return;
        }
        Node current = head;
        while (current != null) {
            current.displayNode();
            current = current.next;
        }
        System.out.println();
    }

    public Node find(int key) {//metion node location
        Node current = head;
        int count = 1;
        while (current != null) {
            if (count == key) {
                Node temp=new Node(current.data);
                return temp;
            }
            current = current.next;
            count++;
        }
        System.out.println("Item not found");
        return null;
    }

    public void delete(int key) {
        if (isEmpty()) {
            System.out.println("List is empty");
            return;
        }
        Node current = head;
        Node previous = head;
        int count = 1;
        while (current != null) {
            if (count == key) {
                if (count == 1) {
                    head = head.next;
                } else {
                    previous.next = current.next;
                }
                System.out.println("Item deleted");
                return;
            }
            previous = current;
            current = current.next;
            count++;
        }
        System.out.println("Item not avaliable");
    }
}