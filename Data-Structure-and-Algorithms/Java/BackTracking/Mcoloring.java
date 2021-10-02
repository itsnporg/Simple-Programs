public class Mcoloring{
  final int V = 4;

  int color[];
  
  // check for safety 

  boolean isSafe(int v, int graph[][], int color[], int c){

    for(int i = 0; i<V; i++){
      
      if(graph[v][i]==1 && c == color[i])
        return false;
      
    }
    return true;
  }


  boolean graphColor( int graph[][], int m, int color[], int v )
  {
    if(v == V)
      return true;


    for(int c = 1; c<=m; c++){

      if(isSafe(v, graph, color, c)){

        color[v] = c;
      
      // recur 

      if(graphColor(graph, m, color, v+1))

        return true;

      // if not matched 

      color[v] = 0;


      
    }
  }
    return false;
  }

  boolean gcoloring(int graph[][], int m){
    // initialize the color as 0

    color = new int[V];

    for(int i=0; i<V; i++)
    {

      color[i] = 0;
    }

    if(!graphColor(graph,m,color,0)){
      return false;
    }

    print(color);
    return true;
  }


  void print(int color[]){
    for(int i=0;i<V;i++){
      System.out.print(" "+color[i]+" ");
      
    }
    System.out.println();
  }

  public static void main(String[] args){

    Mcoloring l = new Mcoloring();

     int graph[][] = {
            { 0, 1, 1, 1 },
            { 1, 0, 1, 0 },
            { 1, 1, 0, 1 },
            { 1, 0, 1, 0 },
        };
        int m = 3; // Number of colors
        l.gcoloring(graph, m);
  }


}
