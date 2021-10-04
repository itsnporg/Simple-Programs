public class LCM {
    public static void main(String[] args) {

        int n1,n2,LCM;
        Scanner s = new Scanner(System.in);
        
        System.out.print("Enter the integer 1: ");
        n1 = s.nextInt();

        System.out.print("Enter the integer 2: ");
        n2 = s.nextInt();
        
        LCM = (n1 > n2) ? n1 : n2;
        
        while(true) {
            if( LCM % n1 == 0 && LCM % n2 == 0 ) {
                System.out.printf("The Least Common Multiplier of %d and %d : %d", n1, n2, LCM);
                break;
            }
            ++LCM;
        }
    }
}