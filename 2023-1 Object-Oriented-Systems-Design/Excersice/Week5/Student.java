package Week5;

import java.time.LocalDate;
import java.time.Period;
import java.util.Random;

public class Student {
    private final String name;
    private final int year, month, day;

    public Student(String name, int year, int month, int day) {
        this.name = name;
        this.year = year;
        this.month = month;
        this.day = day;
    }

    public Student(String name, int year) {
        this.name = name;
        this.year = year;

        Random rand = new Random();
        this.month = rand.nextInt(12) + 1;

        int maxDay = LocalDate.of(this.year, this.month, 1).lengthOfMonth();
        this.day = rand.nextInt(maxDay) + 1;
    }

    public String getName() {
        return name;
    }

    public int getYear() {
        return year;
    }

    public int getMonth() {
        return month;
    }

    public int getDay() {
        return day;
    }

    public boolean checkDate() {
        if(year < 0)
            return false;
        else if(month < 1 || month > 12)
            return false;
        else if(day < 0 || day > LocalDate.of(year, month, 1).lengthOfMonth())
            return false;
        else
            return true;
    }

    public int calculateAge() {
        Period age = Period.between(LocalDate.of(year, month, day), LocalDate.now());
        return age.getYears();
    }

    public boolean isOlder(Student stu) {
        LocalDate thisStudent = LocalDate.of(year, month, day);
        LocalDate otherStudent = LocalDate.of(stu.year, stu.month, stu.day);
        return thisStudent.isBefore(otherStudent);
    }

}
