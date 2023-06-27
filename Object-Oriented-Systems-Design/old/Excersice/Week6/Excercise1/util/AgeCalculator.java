package Week6.Excercise1.util;

import Week6.Excercise1.Person;

import java.time.LocalDate;
import java.time.Period;

public class AgeCalculator {

    public static int calAge(Person p) {
        LocalDate birthDate = LocalDate.of(p.getBorn().getYear(), p.getBorn().getMonth(), p.getBorn().getDate());
        LocalDate currentDate = LocalDate.now();
        Period period = Period.between(birthDate, currentDate);
        return period.getYears();
    }

    public static int isOlder(Person p1, Person p2) {
        int age1 = calAge(p1);
        int age2 = calAge(p2);
        if (age1 > age2) {
            return 1;
        } else if (age1 == age2) {
            return 0;
        } else {
            return -1;
        }
    }
}
