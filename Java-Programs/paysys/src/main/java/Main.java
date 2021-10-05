import module.Card;
import service.PaysysService;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        Integer  allCard;
        PaysysService paysysService=new PaysysService(10);

        int stepCode=1;
        while(stepCode!=0){
            scanner=new Scanner(System.in);System.out.println("0->Exit();1->Add Card();2->ListCard(); 3=>Fill Balance();4=>Change Password();5=>delete password");
            stepCode=scanner.nextInt();
            switch (stepCode){

                case 1:
                    Card card=new Card();
                    scanner=new Scanner(System.in);
                    System.out.println("enter ownerName:");
                    card.setOwnername(scanner.nextLine());

                    System.out.println("enter cardname:");
                    card.setCardname(scanner.nextLine());

                    scanner=new Scanner(System.in);
                    System.out.println("enter password:");
                    card.setPassword(scanner.nextLine());

                    scanner=new Scanner(System.in);
                    System.out.println("enter Card Number:");
                    card.setCardNumber(scanner.nextInt());

                    paysysService.addCard(card);
                    break;

                case 2:
                    paysysService.ListCard();
                    break;
                case 3:
                    System.out.println("how much entered money");
                    double balance=scanner.nextDouble();
                    System.out.println(Main.getCardNumbers(paysysService));
                    int index=scanner.nextInt();
                    paysysService.fillBalance(--index,balance);
                    break;
                case 4:
                    System.out.println("enter old password");
                    String previouspassword=scanner.nextLine();
                    System.out.println("enter new password");
                    String newpassword=scanner.nextLine();
                    System.out.println(Main.getCardNumbers(paysysService));
                    int index1=scanner.nextInt();
                    paysysService.changePassword(--index1,previouspassword,newpassword);
                    break;
            }
        }
    }
    public static StringBuilder getCardNumbers(PaysysService paysysService){
        Scanner scanner=new Scanner(System.in);
        StringBuilder cardsNumber = new StringBuilder();
        Integer cardIndex = 0;
        System.out.println("enter Card number");
        Card []cards =paysysService.getCards();
        for (Card cardObj:cards ) {
            if(cardObj !=null) {
                Integer CardIndex;
                cardsNumber.append(++CardIndex).append(": ").append(cardObj.getCardname()).append("\n");
            }
        }
      return cardsNumber;
    }

}
