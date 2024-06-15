// Discente Maria Eduarda Guedes Alves

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ackermann {
    public static void main(String[] args) {
        BufferedReader f = null;
        String linha, num[];
        int m, n, p;

        try {
            f = new BufferedReader(new FileReader("ackermann_file.txt"));

            System.err.println();
            while ((linha = f.readLine()) != null) {
                num = linha.split(" ");
                m = Integer.parseInt(num[0]);
                n = Integer.parseInt(num[1]);
                p = Integer.parseInt(num[2]);

                System.out.printf("Ack(%d, %d, %d) = %d\n", m, n, p, Ack(m, n, p));
            }
            System.err.println();
        } 
        catch (IOException e) {
            System.out.println("\nERRO ao abrir o arquivo!");
            e.printStackTrace();
        } 
        finally {
            if (f != null) {
                try { f.close(); } 
                catch (IOException e) {
                    System.out.println("Erro ao fechar o arquivo!");
                }
            }
        }
    }

    private static int Ack(int m, int n, int p) {
        if      (p == 0)       return m+n;
        else if (n==0 && p==1) return 0;
        else if (n==0 && p==2) return m;
        else if (p==2) {
            int val = 1;
            for (int i = 0; i < n; i++)
                val *= m;
            return val;
        }
        else if (p > 2)          return p;
        else if (n > 0 && p > 0) return Ack(m, Ack(m, n - 1, p), p - 1);
        else {
            System.out.println("Foi informado algum valor invalido!");
            return -1; 
        }
    }
}
