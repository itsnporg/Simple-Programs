#include <bits/stdc++.h>
using namespace std;


//This method allows to search in a 2D matrix in O(log(n)) time complexity the most efficient way to search in a 2D matrix 
//Time Complexity O(log(N))
//Space Complexity O(1)

/*NOTE: The matrix mst be row wise sorted for this operation*/

/*
Intuition :
Since a linear searching a 2D array needs a time complexity of  O(N^2) 
Binary search optimizes it to (log(n))

We need to find some way so that we can play around with a 2D matrix as if it was a 1D;

*/

bool search2DMatrix(vector<vector<int>> &A, int B)
{
    //Here since the size of 2d vector is not disclosed 
    // we need to first obtain the starting and ending point of vector
   
    int row = A.size();
    int col = A[0].size();
    int start = 0, end = row * col - 1;
    //here start is  the first index and end is last index
    while (start <= end)
    {
        //Finding the mid of 2D matrix 
        int mid = start + (end - start) / 2;

        //since it is a 2D matrix we need two indices to get the element
        //In this way we are playing with 2D matrix as 1D
        int x = mid / col;
        int y = mid % col;

        //next is normal binary search
        if (A[x][y] == B)
            return 1;
        if (B < A[x][y])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0;
}

int main()
{
    int row, col, toFInd, val;
    cin >> row >> col >> toFInd;
    vector<vector<int>> v;
    for (int i = 0; i < row; i++)
    {
        vector<int> temp;
        for (int j = 0; j < col; j++)
        {
            cin >> val;
            temp.push_back(val);
        }
        v.push_back(temp);
        temp.clear();
    }

    bool ans = search2DMatrix(v, toFInd);

    ans == true ? cout << "Found "<<toFInd : cout << "Not found";
}