import java.util.ArrayList;
public class PrimsAlgorithm 
{
	public static boolean added[];
	public static ArrayList<Edge> mst;
    	public static IndexedPriorityQueue<Integer> pq;
	public static int cost[];
	public static int fromVertex[];
	public static void primsMST(WeightedGraph G)
	{
		added=new boolean[G.V];
		mst=new ArrayList<Edge>();
		pq=new IndexedPriorityQueue<Integer>(G.V);
		cost=new int[G.V];
		fromVertex=new int[G.V];
		
		for(int i=0;i<G.V;i++)
			cost[i]=Integer.MAX_VALUE;
		cost[0]=0;
		pq.insert(0,0);
		while(pq.isEmpty()==false)
		{
			int min=pq.delMin();
			Edge e=new Edge(min,fromVertex[min],cost[min]);
			mst.add(e);
			visit(G,min);
		}
		printPrims(G.V);
	}

	public static void visit(WeightedGraph G, int v)
	{
		added[v]=true;
		int len=G.adj.get(v).size();
		for(int i=0;i<len;i++)
		{
			Edge e=G.adj.get(v).get(i);
			if(added[e.otherEnd(v)]==false)
			{
				if(e.weight<cost[e.otherEnd(v)])
				{
					cost[e.otherEnd(v)]=e.weight;
					fromVertex[e.otherEnd(v)]=v;
					if(pq.contains(e.otherEnd(v)))
					   pq.changeKey(e.otherEnd(v), e.weight);
						
					else
						pq.insert(e.otherEnd(v), e.weight);
				}
			}
		}
	}
	public static void printPrims(int v)
	{
		int len=mst.size();
		System.out.println("Edges with their weights in mst:");
		for(int i=1;i<len;i++)
		{
			Edge e=mst.get(i);
			System.out.println(e.end1+" "+e.end2+" "+e.weight);
		}
		
	}
	public static void main(String[] args) 
	{
		WeightedGraph G=new WeightedGraph();
		primsMST(G);

	}

}

