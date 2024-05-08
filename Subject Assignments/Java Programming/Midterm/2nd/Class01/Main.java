import java.io.*;
import java.util.*;
import java.util.function.*;

public class Main {
    public static void main(String[] args) {

        //BÀI 1
        System.out.println("=====================BÀI 1=====================");
        //Tạo Supplier đọc dữ liệu từ file, trả về List
        Supplier<List<Integer>> integerSupplier = () -> {
            try {
                List<Integer> numbers = new ArrayList<>();

                BufferedReader fileReader = new BufferedReader(new FileReader("numbers.txt"));
                String line = fileReader.readLine();
                String[] arguments = line.split(", ");
                for(String s : arguments) {
                    numbers.add(Integer.parseInt(s));
                }

                return numbers;
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        };

        Supplier<List<String>> lineSupplier = () -> {
            List<String> lines = new ArrayList<>();
            try {
                BufferedReader reader = new BufferedReader(new FileReader("strings.txt"));

                reader.lines().forEach(line -> lines.add(line));
            }catch(Exception ex) {
                ex.printStackTrace();
            }
            return lines;
        };

        // Tạo List từ Supplier
        List<Integer> numbers = integerSupplier.get();
        List<String> lines = lineSupplier.get();

        //BÀI 2
        System.out.println("=====================BÀI 2=====================");
        //Tạo Consumer
        Consumer numberConsumer = (number) -> System.out.println(number);
        Consumer stringConsumer = (line) -> System.out.println(line);

        // Sử dụng Consumer
        numbers.stream().limit(3).forEach(numberConsumer);
        lines.stream().limit(3).forEach(stringConsumer);

        //BÀI 3
        System.out.println("=====================BÀI 3=====================");
        //Tạo Function
        Function<Integer, Double> sqrtFunction = (number) -> Math.sqrt(number);
        Function<String, Character> charFunction = (line) -> line.charAt(0);

        //Sử dụng Function để biến đổi dữ liệu
        numbers.stream().map(sqrtFunction).limit(3).forEach(numberConsumer);
        lines.stream().map(charFunction).limit(3).forEach(stringConsumer);

        //BÀI 4
        System.out.println("=====================BÀI 4=====================");
        //Tạo Predicate
        Predicate<Integer> evenNumberPredicate = (number) -> number % 2 == 0;
        Predicate<String> longStringPredicate = (line) -> line.length() > 30;

        //Sử dụng Predicate trên để lọc dữ liệu
        numbers.stream().filter(evenNumberPredicate).limit(3).forEach(numberConsumer);
        lines.stream().filter(longStringPredicate).limit(3).forEach(stringConsumer);

        //BÀI 5
        System.out.println("=====================BÀI 5=====================");
        //Tạo Operator
        BinaryOperator<Integer> addOperator = (a, b) -> a + b;
        UnaryOperator<String> firstCharOperator = (line) -> line.charAt(0) + "";

        //Sử dụng Operator trên để xử lý dữ liệu
        Optional<Integer> sumOptional = numbers.stream()
                .reduce(addOperator);
        if(sumOptional.isPresent()) {
            int sum = sumOptional.get();
            System.out.println(sum);
        }

        lines.stream()
                .map(firstCharOperator)
                .limit(10)
                .forEach(character -> System.out.print(character));
    }
}

//class Student {
//    String name;
//    int age;
//    double score;
//}