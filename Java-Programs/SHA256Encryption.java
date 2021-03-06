import java.io.*;
import java.util.*;
import java.math.*;
import java.security.*;

/* 
Accept any string and print its SHA256 hash value using Secure Hash Algorithm 2 (SHA-2) algorithum. It consists of six hashing algorithms from that here i used SHA-256 algorithm,
SHA-256 is a -bit ( byte) hashing algorithm which can calculate a hash code for an input of up to  bits. It undergoes  rounds of hashing and calculates a hash code that is a -digit hexadecimal number.

*/

public class SHA256Encryption
 {
  public static void main(String[] args)
	{
    try 
		{
            Scanner scanner = new Scanner(System.in);
            String word = scanner.nextLine();
            scanner.close();
            MessageDigest messageDigest = MessageDigest.getInstance( "SHA-256");
            messageDigest.update(word.getBytes("UTF-8"));
            byte[] byteHash = messageDigest.digest();
            for (byte b : byteHash)
            {
                System.out.format( "%02x", b );
            }

     } 
		catch ( Exception e )
		{
       e.printStackTrace();
    }
  }
}
