

public class BitCounting {
  
  public static int countBits(int n) {
    String bBits = Integer.toBinaryString(n);
    int count = 0;

    for (String b : bBits.split("")) {
      if (Integer.valueOf(b) == 1) {
        count++;
      }
    }

    return count;
  }

}