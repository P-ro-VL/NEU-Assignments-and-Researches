package src.Chapter6;

import java.util.ArrayList;
import java.util.List;

public class StringToInteger {

    public static void main(String[] args) {
        String[] rawNumbers = {"123", "242", "23.45", "ghijk"};

        List<Integer> parsedNumbers = new ArrayList<>();

        for(String str : rawNumbers) {
            try {
                parsedNumbers.add(Integer.parseInt(str));
            }catch (NumberFormatException ex) {
                System.out.println(str + " không phải là một số nguyên.");
            }
        }

        System.out.println("Dãy số nguyên thu được: " + parsedNumbers);
    }
}
