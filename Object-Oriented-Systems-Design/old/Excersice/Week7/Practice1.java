package Week7;

import java.util.Scanner;

public class Practice1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[][] snail = drawSnail(n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                System.out.print(snail[i][j] + "\t");
            }
            System.out.println();
        }
    }
    public static  int[][] drawSnail(int n){
        int [][] snail = new int[n][n];

        int col = -1;
        int row = 0;
        int top = 1;
        int cnt = 1;

        for(int i = n; i >=0; i--) {
            for(int j=0; j<n; j++) {
                col = col + top;
                snail[row][col] = cnt;
                cnt++;
            }
            n--;

            for(int j=0; j<n; j++) {
                row = row + top;
                snail[row][col] = cnt;
                cnt++;
            }
            top = top * (-1);
        }
        return snail;
    }

}