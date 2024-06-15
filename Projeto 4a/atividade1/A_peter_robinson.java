// Discente Maria Eduarda Guedes Alves

package atividade1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class A_peter_robinson {
    public static void main(String[] args) {
        BufferedReader f = null;
        String linha, num[];
        int m, n;

        try {
            f = new BufferedReader(new FileReader("A_peter_robinson_file.txt"));
            
            System.err.println();
            while ((linha = f.readLine()) != null) {
                num = linha.split(" ");
                m = Integer.parseInt(num[0]);
                n = Integer.parseInt(num[1]);

                System.out.printf("A(%d, %d) = %d\n", m, n, A(m, n));
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

    private static int A(int m, int n) {
        if      (m==0)        return n+1;
        else if (m>0 && n==0) return A(m-1, 1);
        else if (m>0 && n>0)  return A(m-1, A(m, n-1));
        else {
            System.out.println("Foi informado algum valor invalido!");
            System.exit(-1);
            return -1; 
        }
    }
}
