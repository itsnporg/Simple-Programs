/* Circular Queue implementation */

#include <iostream>
using namespace std;
#define MAX_SIZE 5

template <class T>
class Queue {
private:
	// Variables
	T q[MAX_SIZE];
	int front = -1, rear = -1;
public:
	// Checks whether the queue is empty or not?
	bool isEmpty()
	{
		return (front == -1 && rear == -1);
	}

	// Checks whether the queue is full or not?
	bool isFull()
	{
		return (rear + 1) % MAX_SIZE == front;
	}

	// Inserts an element in the queue at the rear end
	void enqueue(T x)
	{
		cout << "Enqueuing..." << x << endl;
		if (isFull()) {
			cout << "Error: " << x << " cannot be added. Queue is full!" << endl;
			return;
		}

		if (isEmpty()) {
			front = rear = 0;
		}
		else {
			rear = (rear + 1) % MAX_SIZE;
		}
		q[rear] = x;
	}

	// Removes an element in Queue from the front end
	T dequeue()
	{
		T d = 0;
		cout << "Dequeuing..." << endl;
		if (isEmpty()) {
			cout << "Error: Queue is Empty" << endl;
		}
		else if (front == rear) {
			d = q[front];
			rear = front = -1;
		}
		else {
			d = q[front];
			front = (front + 1) % MAX_SIZE;
		}
		return d;
	}

	// Returns the front element of the queue
	T disFront()
	{
		if (front == -1) {
			cout << "Error: cannot return front from empty queue" << endl;
			return -1;
		}
		return q[front];
	}

	// Displays the queue
	void display()
	{
		if (isEmpty()) {
			cout << "Queue is empty. Nothing to display";
			return;
		}
		else {
			int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
			cout << "Queue: ";
			for (int i = 0; i < count; i++) {
				int index = (front + i) % MAX_SIZE;
				cout << q[index] << " ";
			}
		}
		cout << endl;
	}
};

int main() {
	Queue<char> Q;

	char choice, value, d;
	char op;
	while (1) {
		cout << "Choose:(1) for enqueue\t(2) for dequeue\t(3) to display the queue" << endl;
		cin >> op;
		if (op == '1') {
			cout << "Enter the number to enqueue: ";
			cin >> value;
			Q.enqueue(value);
		}
		else if (op == '2') {
			d = Q.dequeue();
			if (d) {
				cout << d << " is dequeued" << endl;
			}
		}
		else if (op == '3') {
			Q.display();
		}
		else {
			continue;
		}
		cout << "\nDo you want to continue? (y/n)";
		cin >> choice;

		if (choice == 'n' || choice == 'N') {
			break;
		}
	}
	
	return 0;
}

