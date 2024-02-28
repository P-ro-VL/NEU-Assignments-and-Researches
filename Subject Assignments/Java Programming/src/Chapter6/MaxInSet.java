package src.Chapter6;

import java.util.*;

public class MaxInSet {

    public static void main(String[] args) {
        Set<Integer> numbers = new HashSet<>(List.of(1, 2, 3, 4));

        System.out.println(findMax(numbers));
    }

    public static <T extends Comparable<T>> T findMax(Set<T> set) {
        if(set.isEmpty()) return null;
        Iterator<T> iterator = set.iterator();
        T max = iterator.next();

        for(T t : set) {
            if(t.compareTo(max) > 0) max = t;
        }
        return max;
    }
}
