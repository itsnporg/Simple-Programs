public class RobinKarp {

  public final static int d = 256;

  // q is the prime number 
  static void search(String pat, String txt, int q){

    int M = pat.length();
    int N = txt.length();

    int i, j;

    int p = 0; // hash for the pattern
    int t = 0; // hash for text
    int h = 1;

    for ( i = 0; i < M-1; i++ )
      h = (h*d)%q;  // hashing 

    // calculate the hash value for the pattern and the text;
    // for window of text 
    for (i = 0; i < M; i++)
    {
      p = (d*p + pat.charAt(i))%q;
      t = (d*t + txt.charAt(i))%q; 
    }

    // slide the patter over the text one by one 

    for (i=0; i<= N-M; i++){

      if(p==t)
      {

        // check for the characters 

        for( j = 0; j < M; j++ )
        {

          if(txt.charAt(i+j) != pat.charAt(j))
            break;
        }

        if(j == M)
          System.out.println("Pattern found at the index "+i);
      }

      // check for the next window and remove the leading 

      if( i<N-M ){
        t = (d*(t - txt.charAt(i)*h)+ txt.charAt(i+M))%q;

        if(t<0)
          t = (t+q);
      }


    }
    
  }

  public static void main(String[] args){

    String txt = "Ninininininisnishnishant";
    String pat = "nishant";

    int q = 101;
    search(pat,txt,q);
  }
}
