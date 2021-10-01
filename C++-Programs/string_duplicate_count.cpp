#include <bits/stdc++.h>
using namespace std;

void Find_Duplicates(char *A){
    long int k=0;
    int x = 0, y = 0, i;

    for (i = 0; A[i] != '\0';i++){//to count total character}

        x = 1;
        x = x << A[i] - 97; //left shift to check for the character later (comparing)

        if((x&k)>0){ //bit wise AND --for checking if the character is already appeared
            cout << A[i] << " is a duplicate" << endl;
        }else{
            k = k | x; //bitwise OR --for we found the character so turning on
        }
    }
}

int main(){
    char A[] = "heartattack"; //given string
    Find_Duplicates(A);
}