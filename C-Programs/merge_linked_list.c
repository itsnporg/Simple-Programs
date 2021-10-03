// C program to merge a linked list into another at
// alternate positions
#include <stdio.h>
#include <stdlib.h>
 
// A nexted list node
struct Node
{
    int data;
    struct Node *next;
};
 
/* Function to insert a node at the beginning */
void push(struct Node ** head_ref, int new_data)
{
    struct Node* new_node =
           (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}
 
/* Utility function to print a singly linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
 
// Main function that inserts nodes of linked list q into p at
// alternate positions. Since head of first list never changes
// and head of second list  may change, we need single pointer
// for first list and double pointer for second list.
void merge(struct Node *p, struct Node **q)
{
     struct Node *p_curr = p, *q_curr = *q;
     struct Node *p_next, *q_next;
 
     // While therre are available positions in p
     while (p_curr != NULL && q_curr != NULL)
     {
         // Save next pointers
         p_next = p_curr->next;
         q_next = q_curr->next;
 
         // Make q_curr as next of p_curr
         q_curr->next = p_next;  // Change next pointer of q_curr
         p_curr->next = q_curr;  // Change next pointer of p_curr
 
         // Update current pointers for next iteration
         p_curr = p_next;
         q_curr = q_next;
    }
 
    *q = q_curr; // Update head pointer of second list
}
 
// Driver program to test above functions
int main()
{
     struct Node *p = NULL, *q = NULL;
     push(&p, 3);
     push(&p, 2);
     push(&p, 1);
     printf("First Linked List:\n");
     printList(p);
 
     push(&q, 8);
     push(&q, 7);
     push(&q, 6);
     push(&q, 5);
     push(&q, 4);
     printf("Second Linked List:\n");
     printList(q);
 
     merge(p, &q);
 
     printf("Modified First Linked List:\n");
     printList(p);
 
     printf("Modified Second Linked List:\n");
     printList(q);
 
     getchar();
     return 0;
}