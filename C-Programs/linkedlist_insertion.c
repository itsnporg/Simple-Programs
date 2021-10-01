#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * InsertionAtFirst(struct Node * head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;

    return ptr;
}

struct Node * InsertionAtIndex(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data=data;

    struct Node * p = head;
    int i=0;
    while(i!=index-1){
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node * InsertionAtEnd(struct Node * head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data=data;

    struct Node * p = head;
    while(p->next!=NULL){
        p = p->next;
    }

    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node * InsertionAfterNode(struct Node * head, struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head; 
}

void traversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 41;
    third->next = NULL;

    printf("Before Insertion : \n");
    traversal(head);
    
    printf("\nAfter Insertion : \n");
    // head = InsertionAtFirst(head, 99);
    // head = InsertionAtIndex(head, 99, 2);
    // head = InsertionAtEnd(head,99);
    head = InsertionAfterNode(head, second, 99);
    traversal(head);
    return 0; 
}