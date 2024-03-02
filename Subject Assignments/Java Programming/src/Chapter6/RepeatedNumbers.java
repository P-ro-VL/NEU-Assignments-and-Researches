package src.Chapter6;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Cho một danh sách các số, hãy hiển thị ra những số nào bị lặp lại nhiều hơn 1 lần trong danh sách đó
 */
public class RepeatedNumbers {
    public static void main(String[] args) {
        List<Integer> numbers = new ArrayList<>(List.of(1, 2, 3, 4, 2, 3, 4, 4));

        List<Integer> frequency = new ArrayList<>(Collections.nCopies(Collections.max(numbers) + 1, 0));

        for(int i : numbers) {
            frequency.set(i, frequency.get(i) + 1);
        }

        System.out.println("Các số bị lặp lại nhiều hơn 1 lần là:");
        for (int i = 0; i < frequency.size(); i++) {
            if(frequency.get(i) > 1) {
                System.out.print(i + ", ");
            }
        }
    }
}
