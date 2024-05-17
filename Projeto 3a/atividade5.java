// Maria Eduarda Guedes Alves

import java.util.Scanner;

public class atividade5 {

    public static void inicializaVet(int vet[]) {
        for (int i = 0; i < vet.length; i++) 
            vet[i] = i + 1;
    }

    public static void troca(int[] vet, int a, int b) {
        int aux = vet[a];
        vet[a] = vet[b];
        vet[b] = aux;
    }

    public static void printVet(int vet[]) {
        for (int i: vet) 
            System.out.print(i + " ");
        System.out.println();
    }

    public static void perm(int vet[], int l, int r, int j, int k) {
        troca(vet, j, k);

        if (l == r) 
            printVet(vet);

        for (int i = l; i <= r; i++) {
            perm(vet, l + 1, r, l, i);
            troca(vet, l, i);           // desfazendo a troca para testar a próxima possibilidade
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("\n===== Consulta =====\n\nn = ");
        int n = scanner.nextInt();
        System.out.println();
        scanner.close();

        int vet[] = new int[n];
        inicializaVet(vet);

        long startTime = System.currentTimeMillis();
        perm(vet, 0, n - 1, 0, 0);
        long endTime = System.currentTimeMillis();

        System.out.printf("\nTempo gasto: %d ms\n\n", (endTime - startTime));
    }
}
