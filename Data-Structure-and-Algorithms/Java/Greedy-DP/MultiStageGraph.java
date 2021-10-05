public class MultiStageGraph{

  public static void main(String[] args){

    int INF = 0;
    int p[] = new int[8];
    int graph[][] =new int[][]{
        {INF, 1, 2, 5, INF, INF, INF, INF},
        {INF, INF, INF, INF, 4, 11, INF, INF},
        {INF, INF, INF, INF, 9, 5, 16, INF},
        {INF, INF, INF, INF, INF, INF, 2, INF},
        {INF, INF, INF, INF, INF, INF, INF, 18},
        {INF, INF, INF, INF, INF, INF, INF, 13},
        {INF, INF, INF, INF, INF, INF, INF, 2}};

    int N = 8;
    int min;
    int cost[] = new int[8];
    cost[N-1] = 0;
    int d[] = new int[8];

    for(int i=N-2; i>=0;i--){
      min = Integer.MAX_VALUE;

      for(int k=i; k<N;k++){
      
        if(graph[i][k]!=INF && graph[i][k]<min){
          min = graph[i][k]+cost[k]; 
          d[i] = k;
        }

        cost[i] = min;

      }
    
      
      
    }

    System.out.println("Cost:");
    for(int i=0;i<N;i++){
      System.out.print(cost[i]+" ");
    }

    System.out.println("\n Distance ");

    for(int i=0;i<N;i++){
      System.out.print(d[i]+" ");
    }

    int stage = 4;
    p[1]=1;
    p[stage] = N;

    for(int i=2;i<stage;i++){
      
      p[i] =d[p[i]]; 

    }

    System.out.println("\nPath");
    for(int i=0;i<=stage;i++){
      System.out.print(p[i]+" ");
    }

  }
}
