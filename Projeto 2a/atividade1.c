// Atividade 1: Analisador Lexico de Binarios
//    Discente: Maria Eduarda Guedes Alves 
    
#include <stdio.h>

int main(void) {
    FILE *f; char c;

    f = fopen("CLP/Projeto 2a/file1.txt", "r");    
    
    // Verificando se o arquivo foi aberto corretamente
    if (!f) {                       
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    printf("\n========== Analisador Lexico de Binarios ==========\n");

    Q0: 
        // Verificando se nao chegou em fim de arquivo
        if ((c = fgetc(f)) == EOF) {   
            printf("\n\n");
            fclose(f); return 0;
        }

        if (c=='0' || c=='1') {
            printf("\n%c - Reconhecida!", c); 
            goto Q0;
        } 
        // Se chegou no fim da linha, ler proxima
        else if (c=='\n') {
            printf("\n");
            goto Q0;
        }      
        else goto ERRO;

    ERRO: 
        printf("\n%c - Nao reconhecida.\n\n", c);
        fclose(f); return 1; 
}
