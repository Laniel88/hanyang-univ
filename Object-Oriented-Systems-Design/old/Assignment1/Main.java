import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int remainingMoney = 0;

        while(true) {// Accept console input
            System.out.println("Input your money and number of lottery tickets: ");
            int N = sc.nextInt();   // user money
            int M = sc.nextInt();  // number of tickets which will be issued for customers
            if (N == 0 || M == 0) break;

            if((N + remainingMoney) - M * 10 < 0)
                continue;
            else
                remainingMoney = (N + remainingMoney) - M * 10;

            LotteryGenerator lotteryGenerator = new LotteryGenerator();
            LotteryChecker lotteryChecker = new LotteryChecker();

            int[] winningNumbers = lotteryGenerator.generateWinningNumbers();
            System.out.print("Round Winning Number : ");
            for (int i = 0; i < 6; i++)
                System.out.print(winningNumbers[i] + " ");
            System.out.println("+ " + winningNumbers[6]);

            int[] rankCount = {0, 0, 0, 0};
            for (int i = 0; i < M; i++) {
                int[] trialNumbers = lotteryGenerator.generateTicketNumbers();
                int rank = lotteryChecker.checkRank(winningNumbers, trialNumbers);

                System.out.print("Lottery number : ");
                for (int trialNumber : trialNumbers) {
                    System.out.print(trialNumber + " ");
                }
                String result = (rank == 0) ? "Lose" : "Winner (" + rank + "th place)";
                System.out.println(result);

                if (rank != 0) rankCount[rank-1]++;
            }

            System.out.println("Remaining money : " + remainingMoney);
            System.out.println("1st place: " + rankCount[0]);
            System.out.println("2nd place: " + rankCount[1]);
            System.out.println("3rd place: " + rankCount[2]);
            System.out.println("4th place: " + rankCount[3]);
        }

        System.out.println("End of program");

    }
}