package Week10;

public class GeneralTaxi extends Taxi {
    double farePerKilometer;
    double baseDistance = 3;
    double baseFee = 3;

    public GeneralTaxi(int carNum, double farePerKilometer) {
        super(carNum);

        this.farePerKilometer = farePerKilometer;
        assert farePerKilometer > baseFee / baseDistance;
    }

    @Override
    public String toString() {
        return "General"+ super.toString() +
                " fare/Km : " + farePerKilometer + "\n" +
                " baseDistance : " + baseDistance + "\n" +
                " baseFee : " + baseFee + "\n";
    }

    @Override
    double getPaid(double distance) {
        if(distance < baseDistance)
            return baseFee;
        else
            return baseFee + (distance - baseDistance) * farePerKilometer;
    }
}
