#include<ll_insertion.h>
#include<ll_traversal.h>

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
    //head = InsertionAtFirst(head, 99);
    //head = InsertionAtIndex(head, 99, 2);
    //head = InsertionAtEnd(head,99);
    head = InsertionAfterNode(head, second, 99);
    traversal(head);
    return 0; 
}