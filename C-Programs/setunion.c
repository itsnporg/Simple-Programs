// Program to find the union of 2 sets using array

/*
1. Make 3 arrays to hold set A, set B and result Set C(size of c must be sum of size of a and b).
2. Take data in array A and B using loop.
3. Now enter all the elements of A and B into Set c.
4. Check either the number in the Set c is repeated or not . If repeated remove it before printing.


*/
#include<stdio.h>
#include<conio.h>

int main(){
	
	int a[5],b[5],c[10], i, j, k=0;
	
	printf(" Enter the elements of set A: \n");
	for(i=0;i<5;i++){
		printf(" Enter the elements %d of set A: \n",i);
		scanf("%d",&a[i]);
	}
	printf(" Enter the elements of set B: \n");
	for(j=0;j<5;j++){
		printf(" Enter the elements %d of set B: \n",j);
		scanf("%d",&b[j]);
	}
	
	for(i=0;i<5;i++){
		c[i]=a[i];
	}
	
	
	for(j=0;j<5;j++){
		c[5+j]=b[j];
	}
	printf("C is before removing duplicate");
	
	for(i=0;i<10;i++){
		printf("%d\t",c[i]);
	}
	
	printf(" The Union of above 2 sets is: \n");
	
	for(i=0;i<10;i++){
		k=0;
		for(j=i+1;j<10;j++){
			if(c[i]==c[j]){
				k=1;
				break;
			}
		}
		if(k==0){
		
		printf("%d\t",c[i]);
	}
	}

	
	
	
	return 0;
	
}
