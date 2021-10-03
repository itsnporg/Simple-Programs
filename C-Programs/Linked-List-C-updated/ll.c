#include "ll.h"
#include<stdio.h>
#include<stdlib.h>

// Traversal
void traversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

//Insert Related Functions
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

//Deletion related functions
struct Node * DeleteFromFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

struct Node * DeleteFromIndex(struct Node * head, int index){
    struct Node * p;
    struct Node * q;
    
    p = head;
    q = head->next;
    
    int i=0;
    
    while(i!=index-1){
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);

    return head;
    // while()
}

struct Node * DeleteFromEnd(struct Node * head){
    struct Node * p;
    struct Node * q;
    p = head;
    q = head->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

struct Node * DeleteaValue(struct Node * head, int value){
    struct Node * p = head;
    struct Node * q = head->next;

    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }

    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    else{
        printf("Value not found !!");
    }

    return head;
}