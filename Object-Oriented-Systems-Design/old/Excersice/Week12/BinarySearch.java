package Week12;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class BinarySearch {
    public static void main(String[] args) {
        int[] targets = readTargetsFromFile();
        int[] sequence = readSequenceFromFile();

        for (int target : targets) {
            int index = binarySearch(sequence, target);
            System.out.println("target: " + target + " index: " + index);
        }
    }

    private static int[] readTargetsFromFile() {
        int[] targets = new int[100];
        BufferedReader reader = null;

        try {
            reader = new BufferedReader(new FileReader("input.txt"));
            String line;
            int count = 0;

            while ((line = reader.readLine()) != null && count < 100) {
                targets[count] = Integer.parseInt(line.trim());
                count++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        return targets;
    }

    private static int[] readSequenceFromFile() {
        int[] sequence = new int[100000];
        BufferedReader reader = null;

        try {
            reader = new BufferedReader(new FileReader("input.txt"));
            String line;
            int count = 0;

            // Skip the first 100 lines
            for (int i = 0; i < 100; i++) {
                reader.readLine();
            }

            while ((line = reader.readLine()) != null && count < 100000) {
                sequence[count] = Integer.parseInt(line.trim());
                count++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        return sequence;
    }

    private static int binarySearch(int[] sequence, int target) {
        int left = 0;
        int right = sequence.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (sequence[mid] == target) {
                return mid;
            }

            if (sequence[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1; // Target not found
    }
}
