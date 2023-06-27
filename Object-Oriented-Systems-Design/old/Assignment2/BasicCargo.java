public class BasicCargo extends Cargo {
    public BasicCargo(int ID, int weight) {
        super(ID, weight);
    }

    @Override
    double consumption() {
        return 1.5;
    }


}
