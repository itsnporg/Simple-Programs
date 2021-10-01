
import java.util.*;
import java.lang.*;
import java.io.*;

class Dijkstra{
  static final int V = 9;
  // utility function for the minumum distance value, 

  int minDis(int dist[], Boolean sptset[]){
    // initialize the min value 

    int min = Integer.MAX_VALUE, min_index = -1;

    for(int i = 0; i<V; i++){

      if(sptset[i]==false && dist[i]<=min){
        min = dist[i];
        min_index = i;
      }
    }
    return min_index;
  }

  
  void dijkstra(int graph[][], int src){

    int dist[] = new int[V];
    Boolean sptset[] = new Boolean[V];

    for(int i=0;i<V;++i){
      dist[i] = Integer.MAX_VALUE;
      sptset[i] = false;
    }

    // itself as zero 
    dist[src] = 0;
    // edge is V-1
    for(int i=0; i<V-1;i++){
        int u = minDis(dist, sptset);

        sptset[u] =true;


        for(int v = 0; v<V;v++){

          if(!sptset[v] && graph[u][v]!=0 && dist[u]!=Integer.MAX_VALUE && 
              dist[u]+graph[u][v]<dist[v]){
            dist[v] = dist[u]+graph[u][v];
              }
        }

    }
    printSolution(dist);
  }

  void printSolution(int dist[])
  {

    System.out.println("Vertex \t\t Distance from source");

    for(int i=0;i<V;i++){
      System.out.println(i+"\t\t "+dist[i]);
    }
  }

  public static void main(String[] args){
    int graph[][] = new int[][] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                      { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                      { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                      { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                      { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                                      { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    Dijkstra t = new Dijkstra();
    t.dijkstra(graph,0);
  }
}

