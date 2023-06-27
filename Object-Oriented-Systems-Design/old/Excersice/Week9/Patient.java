package Week9;

import Week6.Excercise1.Person;

import java.util.Date;

public class Patient extends Person {
    private String department;

    public Patient(String _name, Date _born, Date _died, String department) {
        super(_name, _born, _died);
        this.department = department;
    }

    public String toString() {
        return "[Patient] " + super.toString() + " Department : " + this.department;
    }
    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }
}
