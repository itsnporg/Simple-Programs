#include<bits/stdc++.h>
using namespace std;
int getminVertex(vector<int> &weight,vector<bool> &visited,int n)
{
    int mini = -1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (mini == -1 || weight[i]<weight[mini]))
        {
            mini =i;
        }
    }
  return mini;
}
void prims(vector<vector<int>> a,int n,int e)
{
    vector<int> weight(n,INT_MAX);
    vector<int> parent(n);
    vector<bool> visited(n,false);
    parent[0]=-1;
    weight[0]=1;
    for(int i=0;i<n-1;i++)
    {
        int minvertex =getminVertex(weight,visited,n);
        visited[minvertex] =true;
        // explore all the neighbours of the minimum vertex and update 
        // parent and weight array after that
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && a[minvertex][j]!=0 )
            {
                if(weight[j] > a[minvertex][j])
                {
                    weight[j] = a[minvertex][j];
                    parent[j] =minvertex;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(parent[i]<i)
        {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
        
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<int>> mat(n,vector<int> (n));
    int x,y,weight;
    for(int i=0;i<e;i++)
    {
  
            cin>>x>>y>>weight;
            mat[x][y]=weight;
            mat[y][x]=weight;
            
    }
    prims(mat,n,e);
    

    return 0;
}