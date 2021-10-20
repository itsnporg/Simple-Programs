#include <stdio.h>    
     
int main()    
{         
    int arr[] = {1,2,3,2,3,4,4,6,7,7,2,3,4,9,0,1,0};        
    int length = sizeof(arr)/sizeof(arr[0]);        
    int fr[length];    
    int visited = -1;    
        
    for(int i = 0; i < length; i++){    
        int count = 1;    
        for(int j = i+1; j < length; j++){    
            if(arr[i] == arr[j]){    
                count++;        
                fr[j] = visited;    
            }    
        }    
        if(fr[i] != visited)    
            fr[i] = count;    
    }    
              
    printf(" Element | Frequency\n");        
    for(int i = 0; i < length; i++){    
        if(fr[i] != visited){    
            printf("    %d", arr[i]);    
            printf("    |  ");    
            printf("  %d\n", fr[i]);    
        }    
    }        
    return 0;    
}

