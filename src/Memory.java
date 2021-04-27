import java.lang.Runtime;
import java.text.DecimalFormat;
import java.text.NumberFormat;

public class Memory {
    public static void main(String[] args) {
        double a, b, c;
        long used, heap, total = 0;
        int i;
        Runtime runtime;
        NumberFormat formatter = new DecimalFormat("#0.0");

        System.out.println("VANILLA\n");

        used = 0;
        for (i = 0; i < 15; i++) {
            runtime = Runtime.getRuntime();
            heap = runtime.totalMemory() - runtime.freeMemory();
            used += heap;
            total += used;
            System.out.println("Iteration " + (i + 1) + ": " + formatter.format(used / 1e+6) + " MB");
        }

        System.out.println("\n\nLOGIC STATEMENTS\n");

        used = 0;
        for (i = 0; i < 15; i++) {
            a = Math.floor(Math.random() * 10);
            b = Math.floor(Math.random() * 10);
            c = Math.floor(Math.random() * 10);

            if (a == b && a == c || a != b || a != c && a == b) {
                runtime = Runtime.getRuntime();
                heap = runtime.totalMemory() - runtime.freeMemory();
            } else {
                runtime = Runtime.getRuntime();
                heap = runtime.totalMemory() - runtime.freeMemory();
            }

            used += heap;
            total += used;
            System.out.println("Iteration " + (i + 1) + ": " + formatter.format(used / 1e+6) + " MB");
        }

        System.out.println("\n\nARITHMETIC OPERATIONS\n");

        used = 0;
        for (i = 0; i < 15; i++) {
            a = (((Math.floor(Math.random() * 10) + 3) * 8) / 4) - (6 % Math.sin(Math.PI / 23));
            b = Math.cos((a * -1) / Math.sin(5 + 2));
            c = Math.sqrt(((b % 3) + (a + 5) - b)) / Math.pow(4, 3 * (2 * 9));

            runtime = Runtime.getRuntime();
            heap = runtime.totalMemory() - runtime.freeMemory();
            used += heap;
            total += used;
            System.out.println("Iteration " + (i + 1) + ": " + formatter.format(used / 1e+6) + " MB");
        }

        System.out.println("\n\nTOTAL USAGE: " + formatter.format(total / 1e+6) + " MB");
    }
}