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