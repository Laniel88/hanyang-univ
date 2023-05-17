package Week5;

import java.util.Scanner;
import java.util.StringTokenizer;

public class Practice {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input1 = sc.nextLine();
        String name2 = sc.nextLine();

        StringTokenizer st1 = new StringTokenizer(input1, "./ ");
        String name1 = st1.nextToken();
        int year1, month1, day1;
        year1 = Integer.parseInt(st1.nextToken());
        month1 = Integer.parseInt(st1.nextToken());
        day1 = Integer.parseInt(st1.nextToken());

        Student student1 = new Student(name1, year1, month1, day1);
        if (!student1.checkDate()) {
            System.out.println("Invalid input");
            sc.close();
            return;
        }


        Student student2 = new Student(name2, year1);


        System.out.printf("%s %d/%d/%d age: %d%n", student1.getName(), student1.getYear(), student1.getMonth(), student1.getDay(), student1.calculateAge());
        System.out.printf("%s %d/%d/%d age: %d%n", student2.getName(), student2.getYear(), student2.getMonth(), student2.getDay(), student2.calculateAge());

        if (student1.isOlder(student2)) {
            System.out.printf("%s is older than %s%n", student1.getName(), student2.getName());
        } else {
            System.out.printf("%s is older than %s%n", student2.getName(), student1.getName());
        }

        sc.close();
    }

}