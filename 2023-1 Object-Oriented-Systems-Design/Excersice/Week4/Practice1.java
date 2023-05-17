package Week4;

import java.util.Scanner;

public class Practice1 {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Input string S: \n");
        String str = scanner.nextLine();
        scanner.close();

        String longestPalindrome = "";

        for(int i=0; i<str.length(); i++) {
            for(int j=i+1; j<=str.length(); j++) {
                String subStr = str.substring(i, j);
                if(isPalindrome(subStr) && subStr.length() > longestPalindrome.length()) {
                    longestPalindrome = subStr;
                }
            }
        }

        System.out.println("Longest Palindrome: " + longestPalindrome);
    }

    public static boolean isPalindrome(String str) {
        for(int i=0; i<str.length()/2; i++) {
            if(str.charAt(i) != str.charAt(str.length()-1-i)) {
                return false;
            }
        }
        return true;
    }
}
