package Week9;

import java.util.Date;

public class Physician extends Doctor {
    public Physician(String _name, Date _born, Date _died, String hospital) {
        super(_name, _born, _died, hospital);
    }

    @Override
    void examination(Patient p) {
        if(p.getDepartment().equals("internal"))
            System.out.println("I'll take care of you!");
        else
            System.out.println("Sorry, but it's not my major.");
    }
}
