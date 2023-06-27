package Week9;

import java.util.Date;

public class Main {
    public static void main(String[] args) {
        // Create a Doctor, Physician, Patient object
        Doctor doctor = new Doctor("John Doe", new Date(70, 3, 1), null, "St. Mary's Hospital");
        Physician physician = new Physician("Bob Johnson", new Date(75, 8, 22), null, "St. Vincent's Hospital");
        Patient patient = new Patient("Jane Smith", new Date(80, 6, 15), null, "internal");

        // Test the toString() methods of the three classes
        System.out.println(doctor.toString());
        System.out.println(physician.toString());
        System.out.println(patient.toString());

        // Test the examination() method of the Physician class
        physician.examination(patient);

        // Test the equals() method of the Doctor class
        Doctor anotherDoctor = new Doctor("John Doe", new Date(70, 3, 1), null, "St. Mary's Hospital");
        System.out.println(doctor.equals(anotherDoctor)); // should print true
    }
}
