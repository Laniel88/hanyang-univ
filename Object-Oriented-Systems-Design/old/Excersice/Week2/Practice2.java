package Week2;

public class Practice2 {
    public static void main(String[] args) {
        String input = "Walt Savitch";
        String output = null;

        output = pigLatin(input.split(" ")[0]) + " " + pigLatin(input.split(" ")[1]);

        System.out.println(output);

    }

    public static String pigLatin(String word) {
        return word.substring(1,2).toUpperCase() + word.substring(2).toLowerCase() + word.substring(0,1).toLowerCase() + "ay";
    }
}
