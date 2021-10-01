#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    const int *x =a;
    const int *y =b;
    return *x - *y;
}

int main(){
    int a[]={43,57,23,98,21,-23,-45};
    int Num_elements = sizeof(a) / sizeof(int);

    printf("BEFORE SORTING : \n");
    for(int i=0; i<Num_elements;i++){
        printf("%d ",*(a + i));
    }
    
    qsort(a,Num_elements,sizeof(int),compare);
    
    printf("\nAFTER SORTING : \n");
    for(int i=0; i<Num_elements;i++){
        printf("%d ",*(a + i));
}
}