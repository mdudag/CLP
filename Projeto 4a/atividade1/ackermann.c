// Discente Maria Eduarda Guedes Alves

#include <stdio.h>
#include <stdlib.h>

int Ack(int m, int n, int p);
int num(FILE *f, char *c);

int main(void) {
    FILE *f = fopen("ackermann_file.txt", "r");
    char c = fgetc(f);
    int m, n, p;

    if (!f) {
        printf("\nERRO ao abrir o arquivo!");
        exit(-1);
    }

    printf("\n");
    while (c!=EOF) {
        m = num(f, &c); c = fgetc(f);
        n = num(f, &c); c = fgetc(f);
        p = num(f, &c); c = fgetc(f);

        printf("Ack(%d, %d, %d) = %d\n", m, n, p, Ack(m, n, p));
    }

    printf("\n");
    fclose(f); return 0;
}

int num(FILE *f, char *c) {
    int a=0,  sinal=1;

    if (*c=='-') {
        sinal=-1;
        *c=fgetc(f);
    }
    
    while(*c != ' ' && *c != '\n' && *c != EOF) {
        a = a*10 + (*c - '0');
        *c=fgetc(f);
    }

    return sinal*a;
}

int Ack(int m, int n, int p) {
    if      (p==0)         return m+n;
    else if (n==0 && p==1) return 0;
    else if (n==0 && p==2) return m;
    else if (p==2) {
        int val=1;
        for (int i=0; i<n; i++) 
            val *= m;
        return val;
    }
    else if (p>2)          return p;
    else if (n>0 && p>0)   return Ack(m,  Ack(m, n-1, p), p-1);
    else {
        printf("Foi informado algum valor invalido!\n");
        exit(-1);
    }
}
