import java.util.*;
public class PalindromeNumber {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long r,s=0,t;    
		long n=sc.nextLong(); 
		t=n;    
		while(n>0){    
		   r=n%10; 
		   s=(s*10)+r;    
		   n=n/10;    
		  }    
		  if(t==s)    
		   System.out.println("palindrome number ");    
		  else    
		   System.out.println("not palindrome");     
	}

}
