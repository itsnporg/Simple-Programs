class KMP{

  void Search(String pat, String txt){

    int M = pat.length();
    int N = txt.length();

    int lps[] = new int[M];
    int j = 0;


    ComputeLPS(pat, M, lps);

    int i = 0;

    while(i<N){

      if(pat.charAt(j) == txt.charAt(i)) {
          
            j++;
            i++;
      }

      if(j==M) {
        System.out.println("Found Pattern at the index "+(i-j));
        j = lps[j-1];
      }
      else if(i < N && pat.charAt(j)!= txt.charAt(i)){

        if(j!=0)
          j = lps[j-1];
      

        else 
          i = i+1; 
      }
    }
  }


  void ComputeLPS(String pat,int M, int lps[])
  {

    int len =0;
    int i = 1;

    lps[0] = 0; // is always zero 

    while (i < M)
    {

      if(pat.charAt(i) == pat.charAt(len)) {
        len++;
        lps[i] = len;
        i++;
      }

      else 
      {

        if(len!=0) {
          len = lps[len-1];

        }
        else{

          lps[i] = len;
          i++;
        }
      }
    }
  }

  public static void main(String[] args){

    KMP k = new KMP();

    String txt = "ababcabcabababd";
    String pat = "ababd";

    k.Search(pat,txt);
    
  }
}
