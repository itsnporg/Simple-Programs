#include <stdio.h>
#include <stdlib.h>

struct item {
    char *itemname;
    int qty;
    float price;
    float amount;
};

void readitem(struct item * i);
void printitem(struct item *i);

int main()
{
    struct item itm;
    struct item *pItem;

    pItem = &itm;

    pItem -> itemname = (char *) malloc(30*sizeof(char));

    if (pItem == NULL)
        exit(-1);

        //read item
        readitem(pItem);
        //print item
        printitem(pItem);
        free(pItem->itemname);

    return 0;
}

void readitem(struct item * i)
{
    printf("Enter product name: ");
    scanf("%s", i -> itemname);

    printf("\n Enter price: ");
    scanf("%f", &i -> price);

    printf("\n Enter Quantity: ");
    scanf("%d", &i -> qty);

    i -> amount = (float)i -> qty * i -> price;

}

void printitem(struct item * i)
{
    printf("\n Name: %s", i-> itemname);
    printf("\n Price: %.2f",i->price);
    printf("\n Quantity: %d",i->qty);
    printf("\n Total Amount: %.2f",i->amount);
}