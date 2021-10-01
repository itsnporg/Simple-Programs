#include <iostream>
using namespace std;
int main() {
    int A[10] = {88,45,546,21,-54,-25,-78,-511,54,654};
    int max = INT_MIN;
    for (int x : A)
    {
        if (x > max)
            max = x;
    }
    cout << "Max number is : "<< max << endl;
    return 0;
    }

/*
    FOR MIN


    #include <iostream>
using namespace std;
int main() {
    int A[10] = {88,45,546,21,-54,-25,-78,-511,54,654};
    int max = INT_MAX;
    for (int x : A)
    {
        if (x < max)
            max = x;
    }
    cout << "Max number is : "<< max << endl;
    return 0;
    }


*/