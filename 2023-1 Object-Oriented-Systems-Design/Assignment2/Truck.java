import java.util.ArrayList;

public class Truck {
    final private int ID;
    private double fuel = 0;
    private final Warehouse currentWarehouse;
    private final int totalWeight;
    private final int maxNumOfAllCargoes;
    private final int maxNumOfHeavyCargoes;
    private final int maxNumOfDangerousCargoes;
    private final int maxNumOfLiquidCargoes;
    private final double fuelPerKm;

    ArrayList<Cargo> currentCargoes = new ArrayList<>();
    private int currentWeight = 0;
    private final int[] currentCnt = new int[4]; // Basic, Heavy, Dangerous, Liquid

    public Truck(int ID, Warehouse w,
                 int totalWeight, int maxNumOfAllCargoes, int maxNumOfHeavyCargoes,
                 int maxNumOfDangerousCargoes, int maxNumOfLiquidCargoes, double fuelPerKm) {
        this.ID = ID;
        this.currentWarehouse = w;
        this.totalWeight = totalWeight;
        this.maxNumOfAllCargoes = maxNumOfAllCargoes;
        this.maxNumOfHeavyCargoes = maxNumOfHeavyCargoes;
        this.maxNumOfDangerousCargoes = maxNumOfDangerousCargoes;
        this.maxNumOfLiquidCargoes = maxNumOfLiquidCargoes;
        this.fuelPerKm = fuelPerKm;
    }

    public ArrayList<Cargo> getCurrentCargoes() {
        return currentCargoes;
    }

    boolean sailTo(Warehouse w) {
        double distance = currentWarehouse.getDistance(w);

        double requiredFuel = fuelPerKm;
        for(Cargo cargo : currentCargoes) {
            requiredFuel += cargo.consumption() * cargo.getWeight();
        }
        requiredFuel *= distance;

        if(requiredFuel > fuel)
            return false;

        fuel -= requiredFuel;
        return true;
    }

    void reFuel(double amount) {
        fuel += amount;
    }

    boolean load(Cargo c) {
        if(!isValidLoad(c))
            return false;

        currentCargoes.add(c);

        if(c instanceof DangerousCargo) currentCnt[2]++;
        else if(c instanceof LiquidCargo) currentCnt[3]++;
        else if(c instanceof HeavyCargo) currentCnt[1]++;
        else currentCnt[0]++;

        currentWeight += c.getWeight();
        return true;
    }

    boolean unload(Cargo c) {
        if(currentCargoes.stream().noneMatch(cargo -> cargo.getID()==c.getID()))
            return false;

        if(c instanceof DangerousCargo) currentCnt[2]--;
        else if(c instanceof LiquidCargo) currentCnt[3]--;
        else if(c instanceof HeavyCargo) currentCnt[1]--;
        else currentCnt[0]--;
        currentWeight -= c.getWeight();

        currentCargoes.removeIf(cargo -> cargo.getID() == c.getID());
        return true;
    }

    public int getID() {
        return ID;
    }

    public Cargo getCargo(int cargoId) {
        return currentCargoes.stream().filter(cargo -> cargo.getID() == cargoId).
                findFirst().orElse(null);
    }

    public double getCurrentFuel() {
        return fuel;
    }

    boolean isValidLoad(Cargo c) {
        if(currentCnt[0] + currentCnt[1] + currentCnt[2] + currentCnt[3] + 1 > maxNumOfAllCargoes)
            return false;
        else if(c instanceof HeavyCargo && currentCnt[1] + currentCnt[2] + currentCnt[3] + 1 > maxNumOfHeavyCargoes)
            return false;
        else if(c instanceof DangerousCargo && currentCnt[2] + 1 > maxNumOfDangerousCargoes)
            return false;
        else if(c instanceof LiquidCargo && currentCnt[3] + 1 > maxNumOfLiquidCargoes)
            return false;
        else
            return currentWeight + c.getWeight() <= totalWeight;
    }
}
