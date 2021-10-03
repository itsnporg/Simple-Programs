#include"ll.c"
#include<stdio.h>
#include<stdlib.h>

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

    printf("Linked List !!");
    int a=0,b=0,ele,index;
    printf("\nChoose the Operation you want to perform on the Linked List ");
    printf("\n1) Traversal");
    printf("\n1) Insertion");
    printf("\n1) Deletion");
    scanf("\n%d",&a);
    switch(a){
        case 1: 
            traversal(head);
            break;
        case 2:
            printf("\nChoose Which type of insertion you want to perform : ");
            printf("\n1)Insertion at beginning");
            printf("\n2)Insertion at an index");
            printf("\n3)Insertion at end");
            printf("\n4)Insertion after a node");
            scanf("%d",&b);
            switch(b){
                case 1:
                    printf("\nEnter the element : ");
                    scanf("%d",&ele);
                    InsertionAtFirst(head, ele);
                    break;
                case 2:
                    printf("\nEnter the element : ");
                    scanf("%d",&ele);
                    printf("\nEnter the index : ");
                    scanf("%d",&index);
                    InsertionAtIndex(head, ele, index);
                    break;
                case 3:
                    printf("\nEnter the element : ");
                    scanf("%d",&ele);
                    InsertionAtEnd(head, ele);
                    break;
                case 4:
                    printf("\nEnter the element : ");
                    scanf("%d",&ele);
                    //insertion after second node
                    InsertionAfterNode(head, second, ele);
                    break;
            break;
            }
        case 3:
            printf("\nChoose Which type of deletion you want to perform : ");
            printf("\n1)Deletion at beginning");
            printf("\n2)Deletion at an index");
            printf("\n3)Deletion at end");
            printf("\n4)Deleting a value");
            scanf("%d",&b);
            switch(b){
                case 1:
                    DeleteFromFirst(head);
                    break;
                case 2:
                    printf("\nEnter the index : ");
                    scanf("%d",&index);
                    DeleteFromIndex(head, index);
                    break;
                case 3:
                    DeleteFromEnd(head);
                    break;
                case 4:
                    printf("\nEnter the value : ");
                    scanf("%d",&ele);
                    DeleteaValue(head, ele);
                    break;
            break;
            }
        
    }
}

