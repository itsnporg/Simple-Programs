#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void traversal(struct Node * ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

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

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    struct Node * fifth;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));
    fifth = (struct Node *) malloc(sizeof(struct Node));

    head->data = 5;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 12;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = fifth;

    fifth->data = 19;
    fifth->next = NULL;

    printf("\nLinked List before deleteion : \n");

    traversal(head);

    // head = DeleteFromFirst(head);
    // head = DeleteFromIndex(head, 3);
    // head = DeleteFromEnd(head);
    head = DeleteaValue(head, 12);
    printf("\nLinked list after deletion : \n");
    traversal(head);
    return 0; 
}