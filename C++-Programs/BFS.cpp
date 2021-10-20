///breadth first search in cpp

/*some test cases
input(nodes,edges)   
7 7
                  
1 2                  
1 3                  
2 4                  
2 5                 
2 6                  
2 7                  -
7 3     
out put
1 2 3 4 5 6 7              */

#include<bits/stdc++.h>
using namespace std;

const int n=1e5+2;
bool visited[n];
vector<int>ad[n];
int main(){
	
for(int i=0;i<n;i++){
    visited[i]=0;
}

 int nodes,edges;
cin>>nodes>>edges;

int x,y;
for(int i=0;i<edges;i++){
cin>>x>>y;
   ad[x].push_back(y);
   ad[y].push_back(x);

}
 queue<int>q;
 q.push(1);
 visited[1]=true;

while(!q.empty()){
int nodd=q.front();
q.pop();
cout<<nodd<<endl;
vector<int>::iterator it;
for(it=ad[nodd].begin();it!=ad[nodd].end();it++){
  if(!visited[*it]){
      visited[*it]=1;
      q.push(*it);
  }
}
}
    return 0;
}
