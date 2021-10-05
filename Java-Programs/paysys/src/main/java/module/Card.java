package module;

public class Card {
    private String ownername;
    private String cardname;
    private double amount;
    private String password;
    private int CardNumber;

    public Card(String ownername, String cardname,String password,int cardNumber) {
        this.ownername = ownername;
        this.cardname = cardname;
        this.password = password;
        this.CardNumber=cardNumber;
    }

    public double getCardNumber() {
        return CardNumber;
    }

    public void setCardNumber(int cardNumber) {
        CardNumber = cardNumber;
    }

    public Card() {
    }

    public String getOwnername() {
        return ownername;
    }

    public void setOwnername(String ownername) {
        this.ownername = ownername;
    }

    public String getCardname() {
        return cardname;
    }

    public void setCardname(String cardname) {
        this.cardname = cardname;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}

