import java.math.BigInteger;
import java.util.Scanner;

public class RSA {

    public static int rawE = 5;

    public static BigInteger p = new BigInteger("932509952881983402669722345517650936567400152830940202218846698865653458831253491798411583414890890514636111101814497070529932191497442662144243673485883693356038633566297362938380968916276160064061900885398568777154291228802590944611568024625637796945634068410931218435920358388082477456940816104847"), //
            q = new BigInteger("245744487801939753867398535114079471026896449678285554684963687503988872575183497772710453977901202670796120117832711914660007957432805553270924099477547757371906533965025535897043612643234389213136529986750742945178890207250280041738991201122729497981523059193818563830721121521647188069444305434981"), //
            n = p.multiply(q),
            phiN = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE)),
            e = BigInteger.valueOf(rawE);

    public static void main(String[] args) {
        System.out.println("------- MÃ HÓA MÃ SINH VIÊN SỬ DỤNG RSA -------");
        System.out.println("Nhập mã sinh viên : ");

        // Nhập vào mã sinh viên
        Scanner scanner = new Scanner(System.in);
        BigInteger m = new BigInteger(scanner.nextLine());

        // Tìm giá trị e thỏa mãn UCLN(phiN, e) = 1 (e và phiN là hai số nguyên tố cùng nhau)
        for (rawE = 2; rawE < 1000; rawE++) {
            if (phiN.gcd(BigInteger.valueOf(rawE)).equals(BigInteger.ONE)) {
                e = BigInteger.valueOf(rawE);
                break;
            }
        }

        // Tìm nghịch đảo moduler của phiN và e
        BigInteger d = timD(phiN, e);

        // Mã hóa : m^e % n = c
        BigInteger encrypted = m.pow(rawE).mod(n),

                // Giải mã : c^d % n = m
                decrypted = encrypted.modPow(d, n);

        System.out.println("p = " + p.toString() + "; q = " + q.toString() + "; n = " + n.toString());
        System.out.println("phiN = " + phiN.toString());
        System.out.println("");
        System.out.println("PUBLIC KEY (e, n) = (" + e.toString() + "; " + n.toString() + ")");
        System.out.println("PRIVATE KEY (d, n) = (" + d.toString() + "; " + n.toString() + ")");
        System.out.println("");
        System.out.println("Encrypt(" + m.toString() + ") = " + encrypted.toString());
        System.out.println("Decrypt => " + decrypted.toString() + " " + (decrypted.equals(m) ? "(Trùng khớp)" : "(Không trùng khớp)"));
    }

    /**
     * Tìm nghịch đảo moduler của hai số phiN và e cho trước
     * @param phiN Số phiN
     * @param e Số e
     * @return d thỏa mãn e.d % phiN = 1
     */
    public static BigInteger timD(BigInteger phiN, BigInteger e) {
        for (long i = 10; i <= 1000000; i++) {
            BigInteger x = BigInteger.valueOf(i).multiply(phiN).add(BigInteger.ONE).divide(e),
                    y = e.multiply(x).mod(phiN);
            if (y.equals(BigInteger.ONE)) return x;
        }
        return BigInteger.ZERO;
    }

}
