// Discente Maria Eduarda Guedes Alves

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int A(int m, int n);

int main(void) {
    int i=5, m, n, R, ok=0;
    double tEmMilSeg=0, tGasto;
    clock_t t;

    for (m=0; m<i && !ok; m++) {
        for (n=0; n<i && !ok; n++) {
            t = clock();
            R = A(m, n);  
            t = clock()-t;

            tGasto = ((double)t) / CLOCKS_PER_SEC * 1000;  // Tempo gasto em milissegundos
            tEmMilSeg += tGasto;

            printf("\nTempo gasto nesta chamada: %.6lf ms", tGasto);
            printf("\nTempo acumulado: %.6lf ms", tEmMilSeg);
            printf("\nA(%d, %d): %d\n", m, n, R);

            if (tEmMilSeg >= 60000) ok=1;       // Se passar de menos de 1 minuto
            
        }
    }

    return 0;
}

int A(int m, int n) {
    if ((m>=0) && (n>=0)) {
        if      (m==0) return n+1;
        else if (m>0 && n==0) return A(m-1, 1);
        else if (m>0 && n>0)  return A(m-1, A(m, n-1));
    }
    else {
        printf("Foi informado algum valor invalido!\n\n");
        exit(-1);
    }
}
