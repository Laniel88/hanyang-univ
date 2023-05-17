public class HeavyCargo extends Cargo {
    public HeavyCargo(int ID, int weight) {
        super(ID, weight);
    }

    @Override
    double consumption() {
        return 2.5;
    }
}
