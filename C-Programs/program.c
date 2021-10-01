#include <stdio.h>

int main()
{
    int num, n=1, option;
    float c_total=0, phy_total=0, c=0, d=0;
    printf("How many students?");
    scanf("%d", &num);
    for (int i=1; i<=num; i++){
        int a=0, b=0;
        printf("Enter the marks obtained by student %d in the following subjects:\n", i);
        printf("C Programming: ");
        scanf("%d", &a);
        printf("Physics: ");
        scanf("%d", &b);
        c_total += a;
        phy_total += b;
        if (c<a)
            c=a;
        if (d<b)
            d=b;
        }
        while (n=1){
        printf("\n\n******************************\n");
        printf("Select an operation\n");
        printf("1. Print highest marks\n");
        printf("2. Print average\n");
        printf("3. Exit\n");
        printf("******************************\n");
        scanf("%d", &option);
        
        if (option == 1){
            printf("C highest: %.2f\n", c);
            printf("Physics highest: %.2f", d);
        }else if (option == 2){
            printf("Average in C: %.2f\n", c_total/num);
            printf("Average in Physics: %.2f", phy_total/num);
        }else if (option == 3){
            printf("Goodbye");
            break;
        }else{
            printf("Invalid choice");
        }
    }

    return 0;
}
