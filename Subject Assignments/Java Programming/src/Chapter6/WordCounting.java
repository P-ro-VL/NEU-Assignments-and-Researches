package src.Chapter6;

import java.util.Map;
import java.util.TreeMap;

public class WordCounting {

    public static void main(String[] args) {
        Map<String, Integer> freq = new TreeMap<>();

        String str = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";

        for(String s : str.split(" ")) {
            if(freq.containsKey(s.toLowerCase())) {
                freq.put(s.toLowerCase(), freq.get(s.toLowerCase()) + 1);
            } else {
                freq.put(s.toLowerCase(), 1);
            }
        }

        System.out.println("Tần suất xuất hiện của các từ:");
        System.out.println("-------------------------------------");
        System.out.printf("| %15s | %15s |\n", "Từ", "Số lần");
        System.out.println("-------------------------------------");
        for (Map.Entry<String, Integer> entry : freq.entrySet()) {
            System.out.printf("| %15s | %15s |\n", entry.getKey(), entry.getValue() + "");
        }
        System.out.println("-------------------------------------");

    }
}
