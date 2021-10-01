#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
}*first=NULL;

void create(int a[], int n)
{
    int i;
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    struct Node *temp;
    int a[]={2, 5, 8, 6, 34};
    create(a, sizeof(a) / sizeof(int));

    display(first);
}