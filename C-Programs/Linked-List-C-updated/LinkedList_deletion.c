#include<ll_traversal.h>
#include<ll_deletion.h>

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