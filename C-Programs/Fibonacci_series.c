#include<stdio.h>

int main() {
  int a = 0, b = 1, c = 0, terms;
  int i, n;
  int n1 = 0, n2 = 1;
  int nxtNumber = 0;
  
  printf("Enter the number of terms: ");
  scanf("%d", &n);

  for (i = 0; i <= n; i++)
  {
    printf("%d, ", nxtNumber);
    n1 = n2;
    n2 = nxtNumber;
    nxtNumber = n1 + n2;
  }
   printf("%d.",nxtNumber);
   printf("\n\nThank you for your trying our feature.");

    return 0;
}
