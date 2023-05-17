package Week3;

import java.util.Scanner;

public class Practice2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int percentage = scanner.nextInt();

        double gpa = percentage * 4.0 / 100;
        System.out.println("("+ percentage + "/100)*4=" + Math.round(gpa));

        scanner.close();
    }
}
