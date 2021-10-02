import java.util.Arrays;

public class soe {
    public static void main(String[] args)
    {
        int n=50,i,j;
        boolean b[]=new boolean[n+1];
        Arrays.fill(b,true);
        b[0]=b[1]=false;
        for(i=2;i<=(int)Math.sqrt(n);i++)
        {
            for(j=i<<1;j<=n;j+=i)
                b[j]=false;
        }
        for(i=0;i<=n;i++)
            if(b[i])
                System.out.print(i+" ");
    }    
}
