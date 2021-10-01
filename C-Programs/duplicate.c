#include <stdio.h>
#define N 10
int main(){
    int a[N] = {8, 5, 3, 2, 1, 5, 8, 2, 6, 9};
    for (int i = 0; i < N - 1;i++){
        int count = 1;
        if(a[i] != -1){
            for (int j = i+1; j < N; j++){
                if(a[i] == a[j]){
                    count++;
                    a[j] = -1;
                }
            }
            if (count > 1)
                printf("%d %d\n", a[i], count);
        }
    }
}