// Discente Maria Eduarda Guedes Alves

package atividade3;

import java.util.Random;
import java.util.Scanner;

public class InsertionSort {
    private static final int N = 100;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double tGasto=0;
        long t;
        int n=1;

        for (; tGasto<60000; ) {
            n *= 10;
            int[] vet = new int[n];
            vetRound(vet, n);

            t = System.currentTimeMillis();
            InsertionSort(vet, n);
            t = System.currentTimeMillis() - t;

            tGasto += t;

            System.out.println();
            printVet(vet, n);
            System.out.printf("Tempo gasto nesta chamada: %.6f ms\n", tGasto);

            System.out.println("Pressione Enter para continuar...");
            scan.nextLine();
        }
        scan.close();
    }

    private static void vetRound(int vet[], int n) {
        Random rand = new Random();

        for (int i = 0; i < n; i++) {
            vet[i] = 1 + rand.nextInt(N);
        }
    }

    private static void printVet(int vet[], int n) {
        System.out.print("[ ");
        for (int i = 0; i < n; i++)
            System.out.print(vet[i] + " ");
        System.out.println("]");
    }

    private static void InsertionSort(int vet[], int n) {
        int i, j, pivo;

        for (i = 1; i < n; i++) {
            pivo = vet[i];

            for (j = i - 1; j >= 0 && vet[j] > pivo; j--) {
                vet[j + 1] = vet[j];
            }
            vet[j + 1] = pivo;
        }
    }
}
