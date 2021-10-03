// Program for printing Minimum Cost
// Simple Path between two given nodes
// Directed and weighted graph
#include <bits/stdc++.h>
using namespace std;
// Defining number of vertices in the Graph
// Infinite value(INF)
#define V 5
#define INF INT_MAX
// Defining Function to do DFS
int minimumCostSimple346(int u, int destination346,
bool visited321[], int graph321[][V])
{
// To check if destination was found or not
// so the cost will be 0
if (u == destination346)
return 0;
// Current Node marked as visited
visited321[u] = 1;
int ans = INF;
// Traversing through all the adjacent nodes
for (int i = 0; i < V; i++) {
if (graph321[u][i] != INF && !visited321[i]) {
// cost of the further path
int curr = minimumCostSimplePath346(i,
destination346, visited321, graph321);
// Checking if the destination was reached or not
if (curr < INF) {
// Taking the minimum cost path
ans = min(ans, graph321[u][i] + curr);
}
}
}
// unmarking the current node
// to make it available for other
// simple paths
visited321[u] = 0;
// Minimum COst returned
return ans;
}
// Driver Code
int main()
{
// Graph Initialization
int graph321[V][V];
for (int i = 0; i < V; i++) {
for (int j = 0; j < V; j++) {
graph321[i][j] = INF;
}
}
// marking all nodes as unvisited
bool visited321[V] = { 0 };
// Edges initialized
graph321[0][1] = -7;
graph321[0][3] = -2;
graph321[1][2] = -11;
graph321[2][0] = -3;
graph321[3][3] = 3;
graph321[4][3] = 2;
// source and destination
int s = 0, t = 2;
// Source marked as visited
visited321[s] = 1;
cout << minimumCostSimplePath346(s, t,
visited321, graph321);
return 0;
}