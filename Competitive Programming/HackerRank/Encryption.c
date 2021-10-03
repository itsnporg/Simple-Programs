https://www.hackerrank.com/challenges/encryption/submissions/code/216927428

#include<stdio.h>
#include<math.h>
int main()
{
        char s[82];
        scanf("%s",s);
        int i,c,r,n,j,k,sq;
        for(i=0;s[i];++i)
         sq=sqrt(i);
         if(sq*sq==i)
         {
                c=r=sq;
         }
         else
         {       
                r=sq;
                c=sq+1;
                if(r*c<i)
                {
                    r=sq+1;c=sq+1;
                }
         }
        

        for(j=0;j<c;++j)
        {       
         for(k=0;k<r;++k)
         {
            if(j+k*c<i)
                  printf("%c",s[j+k*c]);
                }
         printf(" ");
        }  

}
