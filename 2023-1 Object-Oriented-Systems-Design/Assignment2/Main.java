import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {

        // Generate a new Scanner object to access data from the input file in the directory indicated by "args[0]".
        Scanner in = new Scanner(new File(args[0]));

        List<Warehouse> warehouses = new ArrayList<>();

        // Your Implementation
        int N = in.nextInt(); in.nextLine();
        for(int i=0, cargoCnt=0, truckCnt=0; i < N; i++) {
            String[] input = in.nextLine().split(" ");
            int eventId = Integer.parseInt(input[0]);
            switch (eventId) {
                case 1 -> {
                    /* Create a cargo */

                    // Process input
                    int warehouseId = Integer.parseInt(input[1]);
                    int weight = Integer.parseInt(input[2]);

                    // Create a cargo in warehouse
                    Cargo cargo = null;
                    if (input.length > 3) {
                        if (input[3].equals("D"))
                            cargo = new DangerousCargo(cargoCnt++, weight);
                        else if (input[3].equals("L"))
                            cargo = new LiquidCargo(cargoCnt++, weight);
                        else
                            System.err.println("wrong special input");
                    } else {
                        if (weight > 1000)
                            cargo = new HeavyCargo(cargoCnt++, weight);
                        else
                            cargo = new BasicCargo(cargoCnt++, weight);
                    }
                    warehouses.get(warehouseId).addCargo(cargo);
                }
                case 2 -> {
                    /* Create a truck */

                    // process input
                    int warehouseId = Integer.parseInt(input[1]);
                    int maxTotalWeight = Integer.parseInt(input[2]);
                    int maxNumOfAllCargoes = Integer.parseInt(input[3]);
                    int maxNumOfHeavyCargoes = Integer.parseInt(input[4]);
                    int maxNumOfDangerousCargoes = Integer.parseInt(input[5]);
                    int maxNumOfLiquidCargoes = Integer.parseInt(input[6]);
                    double fuelPerKm = Double.parseDouble(input[7]);

                    // Create a truck in warehouse
                    Truck truck = new Truck(truckCnt++, warehouses.get(warehouseId),
                            maxTotalWeight, maxNumOfAllCargoes, maxNumOfHeavyCargoes,
                            maxNumOfDangerousCargoes, maxNumOfLiquidCargoes, fuelPerKm);
                    warehouses.get(warehouseId).incomingTruck(truck);
                }
                case 3 -> {
                    /* Create a warehouse */

                    // process input
                    int warehouseId = warehouses.size();
                    double xCoordinate = Double.parseDouble(input[1]);
                    double yCoordinate = Double.parseDouble(input[2]);

                    // Create a warehouse
                    Warehouse warehouse = new Warehouse(warehouseId, xCoordinate, yCoordinate);
                    warehouses.add(warehouseId, warehouse);
                }
                case 4 -> {
                    /* Load a cargo to a truck */

                    // process input
                    int truckId = Integer.parseInt(input[1]);
                    int cargoId = Integer.parseInt(input[2]);

                    // Find warehouse where truck is
                    Warehouse currentWarehouse = warehouses.stream().filter(warehouse -> warehouse.doesTruckExist(truckId)).findFirst().orElse(null);
                    assert currentWarehouse != null; // Truck with the given ID will always exist

                    // Check & load
                    Truck targetTruck = currentWarehouse.getTruck(truckId);
                    if (!currentWarehouse.doesCargoExist(cargoId)) break;
                    if (!targetTruck.load(currentWarehouse.getCargo(cargoId))) break;

                    // update changes
                    warehouses.get(currentWarehouse.getID()).updateTruck(targetTruck);
                    warehouses.get(currentWarehouse.getID()).removeCargo(cargoId);
                }
                case 5 -> {
                    /* Unload a cargo from a truck */

                    // process input
                    int truckId = Integer.parseInt(input[1]);
                    int cargoId = Integer.parseInt(input[2]);

                    // Find warehouse where truck is
                    Warehouse currentWarehouse = warehouses.stream().filter(warehouse -> warehouse.doesTruckExist(truckId)).findFirst().orElse(null);
                    assert currentWarehouse != null; // Truck with the given ID will always exist

                    // Check & unload
                    Truck targetTruck = currentWarehouse.getTruck(truckId);
                    Cargo targetCargo = targetTruck.getCargo(cargoId);
                    if (!targetTruck.unload(targetCargo)) break;

                    // update changes
                    warehouses.get(currentWarehouse.getID()).updateTruck(targetTruck);
                    warehouses.get(currentWarehouse.getID()).addCargo(targetCargo);
                }
                case 6 -> {
                    /* Truck moves to another warehouse */

                    // process input
                    int truckId = Integer.parseInt(input[1]);
                    int targetWarehouseId = Integer.parseInt(input[2]);

                    // Find warehouse where truck is
                    Warehouse currentWarehouse = warehouses.stream().filter(warehouse -> warehouse.doesTruckExist(truckId)).findFirst().orElse(null);
                    assert currentWarehouse != null; // Truck with the given ID will always exist

                    // sail to another warehouse
                    Truck targetTruck = currentWarehouse.getTruck(truckId);
                    if (!targetTruck.sailTo(warehouses.get(targetWarehouseId))) break;

                    // update changes
                    warehouses.get(currentWarehouse.getID()).outgoingTruck(targetTruck);
                    warehouses.get(targetWarehouseId).incomingTruck(targetTruck);
                }
                case 7 -> {
                    /* Refuel a truck */

                    // process input
                    int truckId = Integer.parseInt(input[1]);
                    double fuel = Double.parseDouble(input[2]);

                    // Find warehouse where truck is
                    Warehouse currentWarehouse = warehouses.stream().filter(warehouse -> warehouse.doesTruckExist(truckId)).findFirst().orElse(null);
                    assert currentWarehouse != null; // Truck with the given ID will always exist

                    // fuel
                    Truck targetTruck = currentWarehouse.getTruck(truckId);
                    targetTruck.reFuel(fuel);

                    // update changes
                    warehouses.get(currentWarehouse.getID()).updateTruck(targetTruck);
                }
            }
        }


        // Close the Scanner object.
        in.close();

        // Generate a new PrintStream object to output data to the file in the directory indicated by "args[1]"
        PrintStream out = new PrintStream(new File(args[1]));
        StringBuilder result = new StringBuilder();

        for(Warehouse warehouse : warehouses) {
           result.append("Warehouse ").append(warehouse.getID()).append(": (")
                   .append(formatD(warehouse.getX())).append(", ")
                   .append(formatD(warehouse.getY())).append(")\n");
           result.append(
                   Cargo.sortCargoes(warehouse.getCargoes())
                           .replaceAll("(?m)^", "  ")
           );
            for (Truck truck : warehouse.getCurrentTruck()) {
                result.append("  Truck ").append(truck.getID()).append(": ")
                        .append(formatD(truck.getCurrentFuel())).append("\n");
                result.append(
                        Cargo.sortCargoes(truck.getCurrentCargoes())
                                .replaceAll("(?m)^", "    ")
                );
            }

        }


        // Print the string to the output file.
        out.print(result);

        // Close the PrintStream object.
        out.close();
    }

    private static String formatD(double num) {
        DecimalFormat decimalFormat = new DecimalFormat("0.0");
        return decimalFormat.format(num);
    }
}