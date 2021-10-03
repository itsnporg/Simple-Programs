class Stack {
    private int arr[];
    private int top;
    private int capacity;

    // Initializing a stack
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    // Insert elements into stack
    public void push(int x) {
        if (isFull()) {
            System.out.println("Stack OverFlow");
            return;
        }
        System.out.println("Inserting " + x);
        arr[++top] = x;
    }

    // Remove element from stack
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack is Empty");
            return -1;
        }
        return arr[top--];
    }

    // Check if the stack is empty
    public Boolean isEmpty() {
        if (top == -1)
            return true;
        else
            return false;
    }

    // Check if the stack is full
    public Boolean isFull() {
        if (top == capacity - 1)
            return true;
        else
            return false;
    }

    public void printStack() {
        for (int i = 0; i <= top; i++) {
            System.out.println(arr[i]);
        }
    }

}

public class StackDataStructure {
    public static void main(String[] args) {
        Stack stack = new Stack(5);

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);

        stack.pop();
        System.out.println("\nAfter popping out");

        stack.printStack();

    }
}