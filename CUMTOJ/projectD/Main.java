import java.util.Scanner;
public class Main {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        if (n <= 0) {
            return;
        }
        if (n == 1) {
            System.out.println(1);
            return;
        }
        if (n > 10000) {
            return;
        }
        int sum = 0;
        sum += n;
        while (true) {
            if (n % 2 == 0) {
            sum += n / 2;
            n = n / 2;
            } else if (n > 1 && n % 2 != 0) {
                n = n + 1;
                sum += n / 2 + 1;
                n = n / 2;
                } else {
                    break;
                }
        }
        System.out.println(sum);
    }
}