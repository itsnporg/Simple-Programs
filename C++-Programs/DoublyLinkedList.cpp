#include <iostream> 
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};
Node *head = NULL;

Node* GetNewNode(int data){
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

void InsertAtHead(int x){
    Node *newNode  = GetNewNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;
}

void Print(){
    Node *temp1 = head;
    while(temp1 != NULL){
        cout << temp1 -> data << " ";
        temp1 = temp1 -> next;
    }
   printf("\n");
}   

void ReversePrint(){
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    cout << "Reverse" << endl;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp ->  prev;
    }
   printf("\n");
}

int main(){
    Node *head = NULL;
    int x,n,i;
    cout <<"Enter how many numbers you want to insert" << endl;
    cin >>n;
    for(i = 1; i<= n; i++){
        cout << "Enter the number you want to insert" << endl;
        cin >>x;
        InsertAtHead(x);
        cout << "The numbers in the list are:- " << endl;
        Print();
        cout << "The elements in the reverse order are:- " << endl;
        ReversePrint();
    }
}








