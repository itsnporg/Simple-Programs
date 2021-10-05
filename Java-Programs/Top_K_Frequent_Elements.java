import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Top_K_Frequent_Elements {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
                new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) {
                nums[i] = Integer.parseInt(s[i + 1]);
            }
            int k = Integer.parseInt(br.readLine().trim());
            Solution9 obj = new Solution9();
            int[] ans = obj.topK(nums, k);
            for (int i = 0; i < ans.length; i++) System.out.print(ans[i] + " ");
            System.out.println();
        }
    }
}
// } Driver Code Ends


class Solution9 {

    static class pair{
        int x,y;
        pair(int x, int y){
            this.x=x;
            this.y=y;
        }
    }

    public int[] topK(int[] nums, int k) {
        // Code here
        int[] hs=new int[k];
        HashMap<Integer,Integer> hm=new HashMap<>();
        ArrayList<pair> temp=new ArrayList<>();

        for (int i = 0; i < nums.length; i++) {
            hm.put(nums[i], hm.getOrDefault(nums[i],0)+1);
        }
    for(Map.Entry<Integer,Integer> i : hm.entrySet())
        temp.add(new pair(i.getKey(),i.getValue()));
    Collections.sort(temp,(a,b)->(b.y==a.y? b.x-a.x:b.y-a.y));


        for (int i = 0; i < k; i++) {
            hs[i]=temp.get(i).x;
        }
        return hs;
    }
}
