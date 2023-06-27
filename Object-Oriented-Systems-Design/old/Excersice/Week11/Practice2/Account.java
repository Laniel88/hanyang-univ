package Week11.Practice2;

import java.util.Scanner;

public class Account {
    private String ID;
    private int account_num;
    int balance;

    public Account() {
        this.ID = "NULL";
        account_num = 0;
        balance = 0;
    }

    public String toString() {
        if(ID.equals("NULL")) return "uninitialized";
        return "[Bank Account Info]\n" +
                " ID : " + ID + "\n" +
                " accountNum : " + account_num + "\n" +
                " balance : " + balance + "\n";
    }

    public void setID(String ID) {
        if (ID.matches("[A-Za-z][0-9]{3}")) {
            this.ID = ID;
        } else {
            throw new IllegalArgumentException("Invalid ID format. ID must start with a letter and be followed by three digits.");
        }
    }

    public void setAccountNum(int accountNum) {
        if (String.valueOf(accountNum).length() == 5) {
            this.account_num = accountNum;
        } else {
            throw new IllegalArgumentException("Invalid account number format. Account number must be of five digits.");
        }
    }

    public void setBalance(int balance) {
        if (balance > 1000) {
            this.balance = balance;
        } else {
            throw new IllegalArgumentException("Invalid initial balance. Initial balance must be above $1000.");
        }
    }

    public void enterData() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter CustomerID: ");
        String ID = scanner.nextLine();

        System.out.print("Enter AccountNumber: ");
        int accountNum = scanner.nextInt();

        System.out.print("Enter InitialBalance: ");
        int balance = scanner.nextInt();

        try {
            setID(ID);
            setAccountNum(accountNum);
            setBalance(balance);
            System.out.println(this);
        } catch (IllegalArgumentException e) {
            System.out.println("[Invalid Input] " + e.getMessage());
            enterData();
        } catch (Exception e) {
            System.out.println("[Unknown Error] " + e.getMessage());
            enterData();
        }
    }


}
