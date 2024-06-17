// Discente Maria Eduarda Guedes Alves

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ack(int m, int n, int p);

int main(void) {
    int i=3, m, n, p, R, ok=0;
    double tEmMilSeg=0, tGasto;
    clock_t t;

    for (m=0; m<i && !ok; m++) {
        for (n=0; n<i && !ok; n++) {
            for (p=0; p<i && !ok; p++) {

                t = clock();
                R = ack(m, n, p);  
                t = clock()-t;

                tGasto = ((double)t) / CLOCKS_PER_SEC * 1000;  // Tempo gasto em milissegundos
                tEmMilSeg += tGasto;

                printf("\nTempo gasto nesta chamada: %.6lf ms", tGasto);
                printf("\nTempo acumulado: %.6lf ms", tEmMilSeg);
                printf("\nack(%d, %d, %d): %d\n", m, n, p, R);

                if (tEmMilSeg >= 60000) ok=1;       // Se passar de menos de 1 minuto
            }
        }

        if (m+1 == i && !ok) i++;
    }

    return 0;
}

int ack(int m, int n, int p) {
    if ((m>=0) && (n>=0) && (p>=0)) {
        if      (p==0)              return m+n;
        else if ((n==0) && (p==1))  return 0;
        else if ((n==0) && (p==2))  return 1;
        else if ((n==0) && (p>2))   return p;
        else if ((n>0)  && (p>0))   return ack(m,  ack(m, n-1, p), p-1);
        else {
            printf("Foi informado algum valor invalido!\n\n");
            exit(-1);
        }
    }
    else {
        printf("Foi informado algum valor invalido!\n\n");
        exit(-1);
    }
}
