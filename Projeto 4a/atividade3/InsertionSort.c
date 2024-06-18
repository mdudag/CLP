// Discente Maria Eduarda Guedes Alves

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void vetRound(int vet[], int n);
void printVet(int vet[], int n);
void InsertionSort(int vet[], int n);

int main() {
    double tGasto=0;
    clock_t t=0;
    int n=1;

    for (; tGasto<60000 ;) {
        n*=10; 
        int vet[n];
        vetRound(vet, n);

        t = clock();
        InsertionSort(vet, n);
        t = clock()-t;

        tGasto += ((double)t) / CLOCKS_PER_SEC * 1000;
        printVet(vet, n);
        printf("\nTempo gasto nesta chamada: %.6lf ms", tGasto);
        system("pause");
    }

    return 0;
}

void vetRound(int vet[], int n) {
    srand(time(NULL));

    for (int i=0; i<n; i++) {
        vet[i] = 1 + rand() % N;
    }
}

void printVet(int vet[], int n) {
    printf("[ ");
    for (int i = 0; i<n; i++)
        printf("%d ", vet[i]);
    printf("]\n");
}

void InsertionSort(int vet[], int n) {
    int i, j, pivo;

    for (i=1; i<n; i++) {
        pivo = vet[i];

        for (j = i-1; j>=0 && vet[j] > pivo; j--) {
            vet[j+1] = vet[j];
        }
        vet[j+1] = pivo;
    }
}
