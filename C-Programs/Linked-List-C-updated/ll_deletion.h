#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

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