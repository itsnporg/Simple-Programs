public class Bellmanford{

  static void bell(int graph[][], int V, int E, int src){

    int dis[] = new int[V]; // it will store the distances
    // fill it 

    for(int i=0;i<V;i++){
      dis[i] = Integer.MAX_VALUE;
      
    }

    dis[src] = 0;
    // source vertex is zero 
    
    // now the main part , relaxation 

    // for vertex
    for(int i=0;i<V-1;i++){

      // edge (0,1)(0,2) 
      for(int j=0; j<E; j++){


        if(dis[graph[j][0]]!=Integer.MAX_VALUE && dis[graph[j][0]]+graph[j][2]< dis[graph[j][1]])

          dis[graph[j][1]] = dis[graph[j][0]]+graph[j][2];

        
      }

    }

    // for detecting the negative edges 
    for(int i=0;i<E;i++){

      int x=  graph[i][0];
      int y = graph[i][1];

      int weight = graph[i][2];

      if(dis[x]!=Integer.MAX_VALUE && dis[x]+weight < dis[y])
        System.out.println("Graph Contains negative weight  Cycle ");

    }

    System.out.println("Vertices Distance from Source");

    for(int i=0;i<V;i++){
      System.out.println(i+"\t\t"+dis[i]);

    }
  }

  public static void main(String[] args){

    int V= 5;
    int E=  8;

    int graph[][] = { { 0, 1, -1 }, { 0, 2, 4 },
                    { 1, 2, 3 }, { 1, 3, 2 },
                    { 1, 4, 2 }, { 3, 2, 5 },
                    { 3, 1, 1 }, { 4, 3, -3 } };
    bell(graph,V,E,0);
  }
}
