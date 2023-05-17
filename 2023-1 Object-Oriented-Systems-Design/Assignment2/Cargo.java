import java.util.ArrayList;
import java.util.Comparator;

public abstract class Cargo {
    final private int ID;
    final private int weight;

    public Cargo(int ID, int weight) {
        this.ID = ID;
        this.weight = weight;
    }

    abstract double consumption();

    static String sortCargoes(ArrayList<Cargo> cargoes) {
        // Sort cargoes by ID
        cargoes.sort(Comparator.comparingInt(Cargo::getID));

        // Categorize cargoes by type
        ArrayList<Cargo> basicCargoes = new ArrayList<>();
        ArrayList<Cargo> heavyCargoes = new ArrayList<>();
        ArrayList<Cargo> dangerousCargoes = new ArrayList<>();
        ArrayList<Cargo> liquidCargoes = new ArrayList<>();

        for (Cargo cargo : cargoes) {
            if (cargo instanceof BasicCargo) {
                basicCargoes.add(cargo);
            } else if (cargo instanceof HeavyCargo) {
                if (cargo instanceof DangerousCargo)
                    dangerousCargoes.add(cargo);
                else if (cargo instanceof LiquidCargo)
                    liquidCargoes.add(cargo);
                else
                    heavyCargoes.add(cargo);

            }
        }

        // Prepare the result StringBuilder
        StringBuilder result = new StringBuilder();

        // Append the categorized cargoes if they exist
        if (!basicCargoes.isEmpty()) {
            result.append("BasicCargo: ");
            for (Cargo cargo : basicCargoes) {
                result.append(cargo.getID()).append(" ");
            }
            result.append("\n");
        }

        if (!heavyCargoes.isEmpty()) {
            result.append("HeavyCargo: ");
            for (Cargo cargo : heavyCargoes) {
                result.append(cargo.getID()).append(" ");
            }
            result.append("\n");
        }

        if (!dangerousCargoes.isEmpty()) {
            result.append("DangerousCargo: ");
            for (Cargo cargo : dangerousCargoes) {
                result.append(cargo.getID()).append(" ");
            }
            result.append("\n");
        }

        if (!liquidCargoes.isEmpty()) {
            result.append("LiquidCargo: ");
            for (Cargo cargo : liquidCargoes) {
                result.append(cargo.getID()).append(" ");
            }
            result.append("\n");
        }

        return result.toString();
    }

    public int getID() {
        return ID;
    }

    public int getWeight() {
        return weight;
    }
}
