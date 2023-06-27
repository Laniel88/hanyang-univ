package Week10;

public abstract class Taxi {
    public int carNum; // ranges from 1000 to 9999
    private double distance; // total driving distance
    private double income; // total income

    public Taxi(int carNum) {
        this.carNum = carNum;
        this.distance = 0;
        this.income = 0;
    }

    public String toString() {
        return "Taxi information called\n" +
                " carNum : " + carNum + "\n" +
                " distance : " + distance + "\n" +
                " income : " + distance + "\n";
    }

    abstract double getPaid(double distance);

    public void doDrive(double dis) {
        distance += dis;
        income += getPaid(dis);
    }

    public boolean earnMore(Taxi t) {
        return this.income > t.getIncome();
    }


    public double getDistance() {
        return distance;
    }

    public double getIncome() {
        return income;
    }
}
