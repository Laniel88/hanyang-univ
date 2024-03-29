package Week3;

import java.util.Scanner;

public class Practice3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter name of item 1: ");
        String name1 = scanner.nextLine();
        System.out.println("Enter quantity of item 1: ");
        int quantity1 = scanner.nextInt();
        System.out.println("Enter price of item 1: ");
        double price1 = scanner.nextDouble();
        scanner.nextLine();

        System.out.println("Enter name of item 2: ");
        String name2 = scanner.nextLine();
        System.out.println("Enter quantity of item 2: ");
        int quantity2 = scanner.nextInt();
        System.out.println("Enter price of item 2: ");
        double price2 = scanner.nextDouble();
        scanner.nextLine();

        System.out.println("Enter name of item 3: ");
        String name3 = scanner.nextLine();
        System.out.println("Enter quantity of item 3: ");
        int quantity3 = scanner.nextInt();
        System.out.println("Enter price of item 3: ");
        double price3 = scanner.nextDouble();

        double subtotal = quantity1 * price1 + quantity2 * price2 + quantity3 * price3;
        double tax = subtotal * 0.0625;
        double total = subtotal + tax;

        System.out.println("Your bill:\n");
        System.out.printf("%-30s%-10s%-10s%-10s\n", "ITEM", "QUANTITY", "PRICE", "TOTAL");
        System.out.printf("%-30s%-10d%-10.2f%-10.2f\n", name1, quantity1, price1, quantity1*price1);
        System.out.printf("%-30s%-10d%-10.2f%-10.2f\n", name2, quantity2, price2, quantity2*price2);
        System.out.printf("%-30s%-10d%-10.2f%-10.2f\n\n", name3, quantity3, price3, quantity3*price3);
        System.out.printf("%-50s%-10.2f\n", "SUBTOTAL", subtotal);
        System.out.printf("%-50s%-10.2f\n", "6.25% SALES TAX", tax);
        System.out.printf("%-50s%-10.2f\n", "TOTAL", total);

        scanner.close();
    }
}
