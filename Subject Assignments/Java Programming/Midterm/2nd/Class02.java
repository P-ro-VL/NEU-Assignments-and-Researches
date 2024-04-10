import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.function.*;

public class Order {
    private int maDonHang;
    private int maKhachHang;
    private double soTien;

    public Order(int maDonHang, int maKhachHang, double soTien) {
        this.maDonHang = maDonHang;
        this.maKhachHang = maKhachHang;
        this.soTien = soTien;
    }

    public int getMaDonHang() {
        return maDonHang;
    }

    public int getMaKhachHang() {
        return maKhachHang;
    }

    public double getSoTien() {
        return soTien;
    }

    public void setSoTien(double soTien) {
        this.soTien = soTien;
    }
}


public class Main {
    public static void main(String[] args) {
        /*
        Câu 2
        * */
        Supplier<Order> orderSupplier = () -> {
            Random random = new Random();
            int maDonHang = (int) (random.nextDouble() * 1000);
            int maKhachHang = (int) (random.nextDouble() * 1000);
            double soTien = random.nextDouble(0, 200);

            return new Order(maDonHang, maKhachHang, soTien);
        };
        List<Order> orders = new ArrayList<>();
        for(int i = 0; i < 10; i++)
            orders.add(orderSupplier.get());

        /*
        Câu 3
         */
        Consumer<Order> orderConsumer = (order) -> {
            System.out.println("Đơn hàng mã " + order.getMaDonHang() + " --------------");
            System.out.println("Mã khách hàng: " + order.getMaKhachHang());
            System.out.println("Số tiền: " + order.getSoTien());
            System.out.println("----------------");
        };
        orders.forEach((order) -> orderConsumer.accept(order));

        /*
        Câu 4
         */
        Function<Order, Order> orderFunction = (oldOrder) -> {
            oldOrder.setSoTien(oldOrder.getSoTien() + oldOrder.getSoTien()*0.1);
            return oldOrder;
        };
        orders.forEach((order) -> orderFunction.apply(order));
        orders.forEach((order) -> orderConsumer.accept(order));

        /*
         * Câu 5
         */
        Predicate<Order> orderPredicate = (order) -> {
            return order.getSoTien() > 100;
        };
        orders.stream().filter(orderPredicate).forEach((order) -> orderConsumer.accept(order));

        /*
        Câu 6
         */
        BinaryOperator<Double> orderBinaryOperator = (order1, order2) -> {
            return order1 + order2;
        };
        double sum = orders.stream().map((order) -> order.getSoTien()).reduce(orderBinaryOperator).get();
        System.out.println("Tổng tiền: " + sum);
    }
}