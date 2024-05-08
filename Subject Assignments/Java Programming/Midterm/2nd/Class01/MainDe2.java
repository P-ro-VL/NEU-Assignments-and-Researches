import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.function.*;

public class MainDe2 {
    public static void main(String[] args) {

        //BÀI 1
        System.out.println("=====================BÀI 1=====================");
        //Tạo Supplier đọc dữ liệu từ file, trả về List
        Supplier<List<Student>> supplier = () -> {
            List<Student> students = new ArrayList<>();
            try {
                BufferedReader reader = new BufferedReader(new FileReader("students.txt"));

                reader.lines().forEach(line -> {
                    String[] arguments = line.split(",");

                    String name = arguments[0];
                    int age = Integer.parseInt(arguments[1]);
                    double score = Double.parseDouble(arguments[2]);

                    Student student = new Student();
                    student.name = name;
                    student.age = age;
                    student.score = score;

                    students.add(student);
                });
            }catch(Exception ex) {
                ex.printStackTrace();
            }
            return students;
        };

        // Tạo List từ Supplier
        List<Student> students = supplier.get();

        //BÀI 2
        System.out.println("=====================BÀI 2=====================");
        //Tạo Consumer
        Consumer printConsumer = student -> System.out.println(student);

        // Sử dụng Consumer
        students.stream()
                .limit(3)
                .forEach(printConsumer);

        //BÀI 3
        System.out.println("=====================BÀI 3=====================");
        //Tạo Function
        Function<Student, Integer> roundedScore = student -> {
            return (int) student.score;
        };

        //Sử dụng Function để biến đổi dữ liệu
        students.stream()
                .map(roundedScore)
                .limit(3)
                .forEach(printConsumer);

        //BÀI 4
        System.out.println("=====================BÀI 4=====================");
        //Tạo Predicate
        Predicate<Student> greaterThan9 = student -> student.score >= 9;

        //Sử dụng Predicate trên để lọc dữ liệu
        students.stream()
                .filter(greaterThan9)
                .limit(3)
                .forEach(printConsumer);

        //BÀI 5
        System.out.println("=====================BÀI 5=====================");
        //Tạo Comparator
        Comparator<Student> studentComparator = (st1, st2) -> st2.age - st1.age;

        //Sử dụng Comparator để sắp xếp danh sách sinh viên
        students.stream()
                .sorted(studentComparator)
                .limit(3)
                .forEach(printConsumer);
    }
}

class Student {
    String name;
    int age;
    double score;

    @Override
    public String toString() {
        return name + "," + age + "," + score;
    }
}