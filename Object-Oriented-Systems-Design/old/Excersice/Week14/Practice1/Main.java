package Week14.Practice1;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Input max number: ");
        int n = scanner.nextInt();

        ArrayList<Integer> primes = Eratos.sieve(n);
        Iterator<Integer> iterator = primes.iterator();

        // Using Iterator
        while (iterator.hasNext()) {
            System.out.print(iterator.next() + " ");
        }

        /* // Using for loop
        for (Integer prime : primes) {
            System.out.print(prime + " ");
        } */
    }
}
