package Week11.Practice1;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            System.out.print("Enter the first number: ");
            int a = scanner.nextInt();
            System.out.print("Enter the second number: ");
            int b = scanner.nextInt();
            System.out.println("[Result] Two integers are " + (isCoprime(a, b) ? "coprime." : "not coprime."));
        } catch (InputMismatchException e) {
            System.out.println("[InputMismatchException] Invalid input ; Please enter integers");
        } catch (MyException e) {
            System.out.println(e.getMessage());
        }
    }

    public static boolean isCoprime(int a, int b) throws MyException {
        if (a <= 1 || b <= 1)
            throw new MyException("One of the numbers is less than or equal to 1 ; Numbers should be greater than 1");
        else if (a == b)
            throw new MyException("The numbers are the same ; Numbers should be different");
        else if (a > 10000 && b > 10000)
            throw new MyException("Both numbers are larger than 10000 ; Numbers should be less than or equal to 10000");

        // Calculate the greatest common divisor (GCD) of a and b
        int gcd = calculateGCD(a, b);
        return gcd == 1;
    }

    private static int calculateGCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return calculateGCD(b, a % b);
    }
}

