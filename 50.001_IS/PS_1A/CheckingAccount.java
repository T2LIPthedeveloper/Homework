public class CheckingAccount extends Account {
    public CheckingAccount() {
        super();
    }

    public CheckingAccount(int id, double balance) {
        super(id, balance);
    }

    @Override
    public void withdraw(double amount) {
        if (this.getBalance() <= -5000)
            System.out.println("over limit");
        else
            super.withdraw(amount);
    }
}
