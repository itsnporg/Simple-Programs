#include<stdio.h>
#include<string.h>
void dec_to_hex(int);
int main(){
    int n;
    printf("Enter a decimal number(n): ");
    scanf("%d",&n);
    dec_to_hex(n);
}
void dec_to_hex(int n){
    char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int rem;
    char hexNum[10];
    int i=0;
    int num=n;
    for(i;num>0;i++){
        rem=num%16;
        num=num/16;
        hexNum[i]=(char)hex[rem];
        // strcat(hexNum,str_hex[rem]);
    }
    hexNum[i]='\0';
    for(int i=0,n=strlen(hexNum),ln=n;i<n/2;i++){
        char temp=hexNum[i];
        hexNum[i]=hexNum[n-i-1];
        hexNum[n-i-1]=temp;
    }

    printf("Hex value of dec(%d) is %s\n",n,hexNum);
}