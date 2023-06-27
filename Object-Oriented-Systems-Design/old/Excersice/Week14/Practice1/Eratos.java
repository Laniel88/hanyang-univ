package Week14.Practice1;

import java.util.ArrayList;

public class Eratos {
    public static ArrayList<Integer> sieve(int n) {
        ArrayList<Integer> primes = new ArrayList<>();
        boolean[] isComposite = new boolean[n];

        for (int i = 2; i < n; i++) {
            if (!isComposite[i]) {
                primes.add(i);
                for (int j = i * i; j < n; j += i) {
                    isComposite[j] = true;
                }
            }
        }

        return primes;
    }
}