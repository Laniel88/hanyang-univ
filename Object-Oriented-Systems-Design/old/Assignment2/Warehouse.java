import java.util.ArrayList;

public class Warehouse {
    final private int ID;
    final private double X, Y;

    private final ArrayList<Cargo> cargoes = new ArrayList<>();
    private final ArrayList<Truck> history = new ArrayList<>();
    private final ArrayList<Truck> current = new ArrayList<>();

    public Warehouse(int ID, double X, double Y) {
        this.ID = ID;

        this.X = X;
        this.Y = Y;
    }

    public double getDistance(Warehouse other) {
        return Math.sqrt(Math.pow(other.getX()-X, 2) + Math.pow(other.getY()-Y, 2));
    }
    public void incomingTruck(Truck t) {
        current.add(t);
    }
    public void outgoingTruck(Truck t) {
        current.removeIf(truck -> truck.getID() == t.getID());
        history.add(t);
    }

    public void addCargo(Cargo cargo) {
        cargoes.add(cargo);
    }

    public boolean doesCargoExist(int cargoId) {
        return cargoes.stream().anyMatch(cargo -> cargo.getID() == cargoId);
    }
    public Cargo getCargo(int cargoId) {
        return cargoes.stream().filter(cargo -> cargo.getID() == cargoId).
                findFirst().orElse(null);
    }

    public void removeCargo(int cargoId) {
        cargoes.removeIf(cargo -> cargo.getID() == cargoId);
    }


    public boolean doesTruckExist(int truckId) {
        return current.stream().anyMatch(truck -> truck.getID() == truckId);
    }

    public Truck getTruck(int truckId) {
        return current.stream().filter(truck -> truck.getID() == truckId).
                findFirst().orElse(null);
    }

    public void updateTruck(Truck updatedTruck) {
        current.removeIf(truck -> truck.getID() == updatedTruck.getID());
        current.add(updatedTruck);
    }

    public int getID() {
        return ID;
    }

    public double getX() {
        return X;
    }

    public double getY() {
        return Y;
    }

    public ArrayList<Cargo> getCargoes() {
        return cargoes;
    }

    public ArrayList<Truck> getCurrentTruck() {
        return current;
    }

    public ArrayList<Truck> getHistory() {
        return history;
    }

}


