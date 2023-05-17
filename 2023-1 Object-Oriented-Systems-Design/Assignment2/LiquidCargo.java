public class LiquidCargo extends HeavyCargo{
    public LiquidCargo(int ID, int weight) {
        super(ID, weight);
    }

    @Override
    double consumption() {
        return 3.5;
    }
}
