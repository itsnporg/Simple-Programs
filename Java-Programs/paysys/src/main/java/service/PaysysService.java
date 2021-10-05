package service;

import module.Card;
import org.omg.CORBA.INTERNAL;

public class PaysysService {
   private Integer allCard;
   private Card cards[];
   private  int cardIndex = 0;

    public PaysysService(Integer allCard) {
        this.allCard = allCard;
        this.cards =new Card[allCard];
    }
public  void addCard(Card card){
        this.cards[this.cardIndex++]=card;
    System.out.println("card added succesfully");
}


    public Integer getAllCard() {
        return allCard;
    }

    public void setAllCard(Integer allCard) {
        this.allCard = allCard;
    }

    public Card[] getCards() {
        return cards;
    }

    public void setCards(Card[] cards) {
        this.cards = cards;
    }

    public int getCardIndex() {
        return cardIndex;
    }

    public void setCardIndex(int cardIndex) {
        this.cardIndex = cardIndex;
    }

    public void addCard(Card card){
        this.cards[cardIndex++] = card;
        System.out.println("card added successfully!!!");
        }

    public void ListCard(){
        System.out.println("\t\t\t"+"List Card \t\t\t");
        int indexCard = 0;
        for (Card card: this.cards ) {
            if(card != null){
                System.out.println("\t\t\t"+ ++indexCard + " Card: " + "\t\t\t");
                System.out.println("OwnerName:" + "\t\tCardName"+ "\t\tCardNumber"+"\t\t\tAmount");
                System.out.println(card.getOwnername()+"\t\t\t"+card.getCardname()+"\t\t\t" + card.getCardNumber()+"\t\t\t"+card.getAmount());
            }
        }
    }

    public void fillBalance(int cardIndex,double balance){
        Card card=this.cards[cardIndex];
        card.setAmount(card.getAmount() + balance);
        System.out.println("card amount successfully!!!");
    }
    public void changePassword(int cardIndex,String previousPassword,String newPassword){
        Card card=this.cards[cardIndex];
        if (card.getPassword().equals(previousPassword)){
            card.setPassword(newPassword);
        }
        System.out.println("card password changed successfully!!!");
    }


}
