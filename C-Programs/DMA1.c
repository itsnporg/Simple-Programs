//Program to read and print N student details using structure and DMA
#include <stdio.h>
#include <stdlib.h>

struct data{
    char name[16];
    int roll;
}*ptr;

void main(){
    int N;
    printf("Enter number of students\t");
    scanf("%d", &N);

    //memory allocation
    ptr = (struct data *)malloc(N*sizeof(struct data));
    
    //input datas
    printf("Enter name and roll\n");
    for(int i=0;i<N;i++){
        scanf("%s %d", (ptr + i)->name, &(ptr + i)->roll);
    }
    //print datas
    for(int i=0;i<N;i++){
        printf("%s %d\n", (ptr + i)->name, (ptr + i)->roll);
    }
    //FREE memory
    free(ptr);
}