#include <iostream>
using namespace std;

int main()
{
    int i, j, rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    for(i = 1; i <= rows; ++i)
    {
        for(j = 1; j <= i; ++j)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
