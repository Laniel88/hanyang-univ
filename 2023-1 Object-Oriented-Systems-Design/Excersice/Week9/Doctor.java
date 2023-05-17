package Week9;

import Week6.Excercise1.Person;

import java.util.Date;

public class Doctor extends Person {
    private String hospital;

    public Doctor(String _name, Date _born, Date _died, String hospital) {
        super(_name, _born, _died);
        this.hospital = hospital;
    }

    void examination(Patient p) {
        System.out.println("I haven't decided my major yet.");
    }

    public String getHospital() {
        return hospital;
    }

    public void setHospital(String hospital) {
        this.hospital = hospital;
    }

    @Override
    public String toString() {
        return "[Doctor] " + super.toString() + " Affiliation : " + this.hospital;
    }

    public boolean equals(Doctor d) {
        return super.equals(d) && this.hospital.equals(d.hospital);
    }
}
