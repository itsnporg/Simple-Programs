class Hamiltonian{

  final int V = 5;
  int path[];

  boolean isSafe(int v, int graph[][], int path[], int pos)
  {

    // previous vertex
    if(graph[path[pos-1]][v]==0)
      return false;
    // no duplicates are allowed
    for(int i=0; i<pos; i++)
      if(path[i] == v)
        return false;
    return true;
  }

  // utility for hamiltonian 
  boolean hcyc(int graph[][], int path[], int pos){
    
    if(pos==V){
      if(graph[path[pos-1]][path[0]]==1)
        return true;
      else
        return false;
    }

    for(int v = 1; v<V; v++){

      if(isSafe(v, graph, path, pos))
      {
        path[pos] = v;

        if(hcyc(graph,path,pos+1) == true)
          return true;

        path[pos] = -1;

    }
  }
  return false;
  }

  int hamcyc(int graph[][]){

    path = new int[V];
    for(int i=0; i<V; i++)
      path[i] = -1;

    path[0] = 0;

    if(hcyc(graph,path,1)==false){

      return 0;
    }
    print(path);

    return 1;
  }


  void print(int path[]){
    
    System.out.println("Solution ");

    for(int i=0; i<V; i++){
      System.out.print(path[i]+" ");
    }

    System.out.println(path[0]+" ");
  }
  public static void main(String[] args){
    Hamiltonian h = new Hamiltonian();

     int graph1[][] = {{0, 1, 0, 1, 0},
            {1, 0, 1, 1, 1},
            {0, 1, 0, 0, 1},
            {1, 1, 0, 0, 1},
            {0, 1, 1, 1, 0},
        };

     h.hamcyc(graph1);
  }
}

