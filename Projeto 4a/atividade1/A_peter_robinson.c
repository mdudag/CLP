// Discente Maria Eduarda Guedes Alves

#include <stdio.h>
#include <stdlib.h>

int num(FILE *f, char *c);
int A(int m, int n);

int main(void) {
    FILE *f = fopen("A_peter_robinson_file.txt", "r");
    char c = fgetc(f);
    int m, n;

    if (!f) {
        printf("\nERRO ao abrir o arquivo!");
        exit(-1);
    }

    printf("\n");
    while (c!=EOF) {
        m = num(f, &c); c = fgetc(f);
        n = num(f, &c); c = fgetc(f);
        printf("A(%d, %d) = %d\n", m, n, A(m, n));
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

int A(int m, int n) {
    // printf("m: %d, n: %d\n", m, n);
    if      (m==0) return n+1;
    else if (m>0 && n==0) return A(m-1, 1);
    else if (m>0 && n>0)  return A(m-1, A(m, n-1));
    else {
        printf("Foi informado algum valor invalido!\n");
        exit(-1);
    }
}
