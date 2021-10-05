package module;

public class PaySys {
    private String name;
    private double minimalTransferRate;
    private double transferRate;
    private double amount;

    public PaySys(String name, double minimalTransferRate, double transferRate, double amount) {
        this.name = name;
        this.minimalTransferRate = minimalTransferRate;
        this.transferRate = transferRate;
        this.amount = amount;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getMinimalTransferRate() {
        return minimalTransferRate;
    }

    public void setMinimalTransferRate(double minimalTransferRate) {
        this.minimalTransferRate = minimalTransferRate;
    }

    public double getTransferRate() {
        return transferRate;
    }

    public void setTransferRate(double transferRate) {
        this.transferRate = transferRate;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }
}
