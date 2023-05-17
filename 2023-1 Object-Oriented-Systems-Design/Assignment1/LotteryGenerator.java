import java.util.ArrayList;
import java.util.Collections;

public class LotteryGenerator {
    public int[] generateWinningNumbers() {
        return getRandomNumbers(7);
    }

    public int[] generateTicketNumbers() {
        return getRandomNumbers(6);
    }

    private int[] getRandomNumbers(int n) {
        ArrayList<Integer> numbers = new ArrayList<>();
        for (int i = 1; i <= 20; i++)
            numbers.add(i);
        Collections.shuffle(numbers);

        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = numbers.get(i);

        return arr;
    }
}
