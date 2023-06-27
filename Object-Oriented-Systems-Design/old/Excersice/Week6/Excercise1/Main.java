package Week6.Excercise1;

import Week6.Excercise1.util.AgeCalculator;
import java.util.Date;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Person person1 = new Person("John", randomDate(), null);
        Person person2 = new Person("Jane", randomDate(), new Date(2100, 1, 1));

        int age1 = AgeCalculator.calAge(person1);
        int age2 = AgeCalculator.calAge(person2);

        System.out.println(person1.toString());
        System.out.println(person2.toString());
        System.out.println();
        System.out.println("John's age : " + age1);
        System.out.println("Jane's age : " + age2);
        if (AgeCalculator.isOlder(person1, person2) == 1) {
            System.out.println(person1.getName() + " is older than " + person2.getName());
        } else if (AgeCalculator.isOlder(person1, person2) == -1) {
            System.out.println(person2.getName() + " is older than " + person1.getName());
        } else {
            System.out.println(person1.getName() + " and " + person2.getName() + " are of the same age");
        }
    }

    private static Date randomDate() {
        Random random = new Random();
        int year = 1900 + random.nextInt(100);
        int month = 1 + random.nextInt(12);
        int day = 1 + random.nextInt(28);
        return new Date(year, month, day);
    }
}
