#include <stdio.h>

typedef struct {
    char name[30];
    int roll;
    float marks;
} memb;

void sort(int n,memb *record);

int main(){
    int n;
    printf("Enter number of students\n");
    scanf("%d", &n);
        memb students[n];
        memb *record = NULL;
        
        record = students;

        printf("Enter Rollno, Name & marks\n");
        for (int i = 0; i < n; i++)
        {
        scanf("%d", &(record + i)->roll);
        scanf("%s", (record + i)->name);
        scanf("%f", &(record + i)->marks);
        }   
        sort(n, record);
        return 0;
}


void sort(int n,memb *record) {
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){

            if ((record + j)->marks < (record + j + 1)->marks){
                
                memb temp = record[j];
                record[j] = record[j+1];
                record[j+1] = temp;
        
            }
            printf("\n");
        }
    }
    printf("\nSorted data in descending order is : \n\n");
    for(int i=0;i<n;i++){
        printf("%d ...............\n", i+1);
        printf("Name of %d student : %s\n",i+1,(record + i)->name);
        printf("Roll  : %d\n", (record + i)->roll);
        printf("Marks : %.2f\n", (record + i)->marks);
    }
}