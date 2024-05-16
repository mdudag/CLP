// Maria Eduarda Guedes Alves

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializaVet(int **vet, int n) {
    *vet = (int*) malloc(n*(sizeof(int)));
    if(!*vet) {
        printf("erro");
        exit(-1);
    }

    for (int i=0; i<n; i++) {
        (*vet)[i] = i+1;
    }
}

void troca(int *a, int *b) {
    int aux = *a;

    *a = *b;
    *b = aux;
}

void printVet(int vet[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void perm(int vet[], int l, int r, int j, int k) {
    troca(&vet[j], &vet[k]);

    if (l == r) 
        printVet(vet, r + 1);

    for (int i = l; i <= r; i++) {
        perm(vet, l + 1, r, l, i);  
        troca(&vet[l], &vet[i]);    // desfazendo a troca para testar proxima possibilidade
    }
}

int main(void) {
    int n, *vet=NULL;
    clock_t t;

    printf("\n===== Consulta =====\n\nn = ");
    scanf("%d", &n);
    printf("\n");

    inicializaVet(&vet, n);

    t = clock();
    perm(vet, 0, n - 1, 0, 0);
    t = clock()-t;

    printf("\nTempo gasto: %.0lf ms\n", ((((double)t) / CLOCKS_PER_SEC)*1000));

    free(vet);
    printf("\n");
    return 0;
}
