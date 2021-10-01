  class Floyd{

    final static int INF = 9999,V = 4;

    void floydWarshal(int graph[][]){

      int dist[][] = new int[V][V];

      int i,j,k;

      for(i=0;i<V;i++){
        
      
        for(j=0;j<V;j++){

        
          dist[i][j] = graph[i][j];

        }
      }


      for(k =0; k<V; k++){

        for(i=0;i<V;i++){

          for(j=0;j<V;j++){

            if(dist[i][k]+dist[k][j]<dist[i][j]){
              
            
              dist[i][j] = dist[i][k]+dist[k][j];
              
          }
        }
      }
    }
    printfld(dist);

    }

   

  void printfld(int dist[][]){

    for(int i=0;i<V;++i){
      for(int j=0;j<V;++j){

        if(dist[i][j]==INF)
          System.out.print("0\t");
        else
         System.out.print(dist[i][j]+"\t");
      }
      System.out.println();
      
      
      
      
    }
  }
  public static void main(String[] args)
  {

    int graph[][] = { {0,   5,  INF, 10},
                          {INF, 0,   3, INF},
                          {INF, INF, 0,   1},
                          {INF, INF, INF, 0}
                        };

    Floyd f = new Floyd();
    f.floydWarshal(graph);
  }
}
