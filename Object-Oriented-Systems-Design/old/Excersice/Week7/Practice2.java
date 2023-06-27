package Week7;

import java.util.*;

public class Practice2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        List<Integer> numbers = Arrays.asList(1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8);
        Collections.shuffle(numbers);

        int[][] arr = new int[4][4];
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                arr[i][j] = numbers.get(i*4+j);
            }
        }

        char[][] board = new char[4][4];
        for (int i=0; i<4; i++) {
            for (int j = 0; j < 4; j++) {
                board[i][j] = '*';
            }
        }


        int opened = 0;
        do {
            System.out.print("Enter Coordinate: ");

            int[] num = new int[4];
            for (int i=0; i<4; i++) {
                num[i] = scan.nextInt() - 1;
            }

            int n1 = arr[num[0]][num[1]];
            int n2 = arr[num[2]][num[3]];

            if (n1 == n2) {
                System.out.println(n1 + " == " + n2);
                board[num[1]][num[0]] = (char) (n1 + '0');
                board[num[3]][num[2]] = (char) (n1 + '0');
                opened += 2;
            } else {
                System.out.println(n1 + " != " + n2);
            }

            System.out.print("\t");
            for (int i=0; i<4; i++)
                System.out.print(i + 1 + "\t");
            System.out.println();

            for (int i=0; i<4; i++) {
                System.out.print(i + 1 + "\t");
                for (int j=0; j<4; j++)
                    System.out.print(board[i][j] + "\t");
                System.out.println();
            }
        } while (opened != 16);
    }
}
