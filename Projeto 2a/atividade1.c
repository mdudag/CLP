// Discente: Maria Eduarda Guedes Alves    
    
#include <stdio.h>
#define N 4

int main(void) {
    FILE *f; 
    char token[N], c;

    f = fopen("C:/Users/maria/OneDrive/Documentos/_UESC/Aulas/Conceitos de LP/Projeto 2a/arquivo.txt", "r");    
                                    // Abre arquivo
    if (!f) {                       // Verificando se o arquivo foi aberto corretamente
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    int i;
    Q0: 
        // Verificando se a linha nao e NULL
        if (!fgets(token, sizeof(token), f)) {
            fclose(f); return 0;
        }

        token[N-1] = '\0';  // Fim de string
        i=0;                // Contador para as posicoes da string
    Q1:
        c = token[i];
        ++i;

        if (c=='\0') goto Q0;   // Pula para Q0 se chegou no final da string
        else if (c=='0' || c=='1') {
            printf("\n%c - Reconhecida!", c); 
            goto Q1;
        } 
        else goto ERRO;

    ERRO: 
        printf("\n%c - Nao reconhecida.", c);
        fclose(f); return 1; 
}
