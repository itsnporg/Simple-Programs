#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s[n],e[n];
    for (int i=0;i<n;i++)
    cin>>s[i];
    for (int i=0;i<n;i++)
    cin>>e[i];
    vector<vector<int>> v;
    for (int i=0;i<n;i++)
    {
        v.push_back({s[i],e[i]});
    }
    
    int end=v[0][1];
    int take=1;
    for(int i=1;i<n;i++)
    {
        if(end<=v[i][0])
        {
             take++;
            end=v[i][1];
        }
    }
    cout<<take;
    return 0;
}