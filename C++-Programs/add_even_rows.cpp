#include <iostream>
using namespace std;

int main(){

/**This Program adds even emements of an array

    2  4
    6  8  -> 2nd row
    10 11
    5  13 -4th row
 
 Sum of even rows is: 6 + 8 + 5 + 13 = 32
 
*/

    int row, column, sum = 0;

    cout << "Enter the number of rows of array:";
    cin >> row;
    cout << "Enter the number of columns of array:";
    cin >> column;

    int arr1[row][column];

/* This if condition checks if the size row or column entered by user is 0. If yes, it terminates the program directly */
    if (column == 0 || row == 0) {
        cout << "Invalid value of row or column";
    } else {

        cout << "Enter the elements:\n";
        // Enters values into array
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cin >> arr1[i][j];
            }
        }

        // Displays the matrix
        cout << "\nDisplaying matrix\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << arr1[i][j] << "\t";
            }
            cout << endl;
        }

        //Sums the elements of even rows of the matrix
        for (int i = 1; i < row;) {
            for (int j = 0; j < column; j++) {
                sum = sum + arr1[i][j];
            }
            i += 2;
        }
        cout << "\nSum of elements of even rows is: " << sum;
    }
    return 0;
}