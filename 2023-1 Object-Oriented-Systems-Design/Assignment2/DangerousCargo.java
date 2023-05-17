public class DangerousCargo extends HeavyCargo{
    public DangerousCargo(int ID, int weight) {
        super(ID, weight);
    }

    @Override
    double consumption() {
        return 4.0;
    }
}
