#include <stdio.h>
#include <stdlib.h>

struct node { //structure to store data and pointer to next structure
    int data;
    struct node *next;
    };

int main(){
    struct node *head, *newnode, *temp;
    head = 0; //since no data ahead of it
    int choice = 1, count=0;
    while(choice==1){

    newnode = (struct node *)malloc(sizeof(struct node)); //allocate memory to the newnodes
    printf("Enter data ");
    scanf("%d",&newnode->data); //storing data to new node
    newnode->next = 0; //since it's the last entry so zero

    if(head==0){ //for the first entry put the data to head
        head = temp = newnode; //also the data to temp to create a link
    }
    else{ //if already exists
        temp->next = newnode; //put new adress to the end of 2nd last entry node
        temp = newnode; //and move to the last node-(with the link )
    }
    printf("Do you want to continue? (0,1)"); //ask
    scanf("%d",&choice); //to add more
    }

    temp = head;  //for printing the data from here --point to the first
    while(temp!=0) //iteretint till the end
    {
        printf("%d ", temp->data); //print
        temp=temp->next; //point to next
        count++; //counting totals
    }
    printf("\n\nTotal entries = %d\n\n", count);
}