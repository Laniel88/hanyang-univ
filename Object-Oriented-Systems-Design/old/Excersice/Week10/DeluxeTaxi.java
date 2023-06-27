package Week10;

public class DeluxeTaxi extends Taxi{
    double farePerKilometer;
    double baseDistance = 3;
    double baseFee = 5;

    public DeluxeTaxi(int carNum, double farePerKilometer) {
        super(carNum);
        this.farePerKilometer = farePerKilometer;
        assert farePerKilometer > baseFee / baseDistance;
    }


    @Override
    public String toString() {
        return "Deluxe"+ super.toString() +
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
