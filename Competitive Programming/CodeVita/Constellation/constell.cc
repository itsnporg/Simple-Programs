#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;
    char arr[3][n];
    vector<char> ans;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        //  end of constellations
        if(arr[0][i] == '#' && arr[1][i] == '#' && arr[2][i] == '#'){
            ans.push_back('#');
            continue;
        }
        //  blanks
        else if(arr[0][i] == '.' && arr[1][i] == '.' && arr[2][i] == '.'){
            continue;
        }
        //  U
        else if(arr[0][i] == '*' && arr[1][i] == '*' && arr[2][i] == '*' && arr[0][i+1] == '.' && arr[1][i+1] == '.' && arr[2][i+1] == '*' && arr[0][i+2] == '*' && arr[1][i+2] == '*' && arr[2][i+2] == '*') {
            ans.push_back('U');
            continue;
        }
        //  O
        else if(arr[0][i] == '*' && arr[1][i] == '*' && arr[2][i] == '*' && arr[0][i+1] == '*' && arr[1][i+1] == '.' && arr[2][i+1] == '*' && arr[0][i+2] == '*' && arr[1][i+2] == '*' && arr[2][i+2] == '*') {
            ans.push_back('O');
            continue;
        }   
        //  I
        else if(arr[0][i] == '*' && arr[1][i] == '.' && arr[2][i] == '*' && arr[0][i+1] == '*' && arr[1][i+1] == '*' && arr[2][i+1] == '*' && arr[0][i+2] == '*' && arr[1][i+2] == '.' && arr[2][i+2] == '*') {
            ans.push_back('I');
            continue;
        }
        //  E
        else if(arr[0][i] == '*' && arr[1][i] == '*' && arr[2][i] == '*' && arr[0][i+1] == '*' && arr[1][i+1] == '*' && arr[2][i+1] == '*' && arr[0][i+2] == '*' && arr[1][i+2] == '*' && arr[2][i+2] == '*') {
            ans.push_back('E');
            continue;
        }
        //  A
        else if(arr[0][i] == '.' && arr[1][i] == '*' && arr[2][i] == '*' && arr[0][i+1] == '*' && arr[1][i+1] == '*' && arr[2][i+1] == '.' && arr[0][i+2] == '.' && arr[1][i+2] == '*' && arr[2][i+2] == '*') {
            ans.push_back('A');
            continue;
        }
        else {
            i++;
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
}
