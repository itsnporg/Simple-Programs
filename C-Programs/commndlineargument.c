#include <stdio.h>
int main (int argc, char *argv[]) 
{
    int numofArg = argc;;
    char *arg1 = argv[0];
    char *arg2 = argv[1];
    printf("num of arg: %d\n",numofArg);
    printf("arg 1 is program name: %s\n",arg2);
    printf("arg 2 is command line argument: %s\n",arg2);
    return 0;
}