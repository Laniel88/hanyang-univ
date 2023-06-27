package Week3;

import java.util.Scanner;

public class Practice1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String[] numbers = scanner.nextLine().split(",");
        int dividend = Integer.parseInt(numbers[0].trim());
        int divisor = Integer.parseInt(numbers[1].trim());
        int quotient = dividend / divisor;
        int remainder = dividend % divisor;

        System.out.println("dividend: " + dividend);
        System.out.println("divisor: " + divisor);
        System.out.println("quotient: " + quotient);
        System.out.println("remainder: " + remainder);

        scanner.close();
    }
}
