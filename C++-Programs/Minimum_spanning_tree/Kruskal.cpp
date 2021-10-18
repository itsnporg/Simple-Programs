#include<bits/stdc++.h>
using namespace std;
class edge
{
    public:
    int src;
    int dest;
    int weight;
};
bool comapare(edge e1,edge e2)
{
    return (e1.weight <e2.weight);
}
// recursive function to get topmost parent 
int getparent(int v,int *parent)
{
   if(parent[v]==v)
   {
       return v;
   }
   return getparent(parent[v],parent);
}
edge *kruskal(edge *edges,int v,int e)
{
    // step-1 sorting the edges on the basis of weight in increasing order
    sort(edges,edges+e,comapare);
    // step-2 make a parent matrix
    int *parent = new int[v];
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
        // intitally every vertice is a parent of itself
    } 
    // step -3 create an ouput of edges (V-1)
    edge *output =new edge[v-1];
    int count =0;
    int i=0;
    while(count < (v-1))
    {
        // step-4 check the topmost parent of the currvertices
        edge curredge = edges[i];
        int SrcParent = getparent(curredge.src,parent);
        int DestParent = getparent(curredge.dest,parent);
        if(SrcParent != DestParent)
        {
            output[count] = curredge;
            count+=1;
            parent[SrcParent] =DestParent;
            // after marking the edge mark

        }
        i+=1;
    }
    return output;
}
int main()
{
    // enter the number of vertices and edges
    int v,e;
    cin>>v>>e;
    edge *edges = new edge[e];
    for(int i=0;i<e;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        edges[i].src =x;
        edges[i].dest =y;
        edges[i].weight =z;
    }
    edge *output =kruskal(edges,v,e);
    for(int i=0;i<v-1;i++)
    {
        if(output[i].src<output[i].dest)
        {
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else
        {
            cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
        }
        
    }
    return 0;
}