#include <stdio.h>

int main(){
    int c[3][3],a[3][3],b[3][3],i=0,k=0,j=0,sum=0; 
printf("Enter first matrix a : \n");
for (i=0;i<3;i++){
    for(j=0;j<3;j++){
        scanf("%d",&a[i][j]);
    }
}
printf("Enter first matrix b : \n");
for (i=0;i<3;i++){
    for(j=0;j<3;j++){
        scanf("%d",&b[i][j]);
    }
}
for (i=0;i<3;i++){
    for (j=0;j<3;j++){
            for (k = 0; k < 3; k++){
                sum += a[i][j] * b[j][k];
                // *(*c(i)+k) += *(*a(i)+k) + *(*b(i)+k);
            }
                c[i][j] = sum;
                sum =0;
    }
}

printf("MULTIPLICATION = \n");
for (i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("%d\t",c[i][j]);
    }
    printf("\n");
}


return 0;
}