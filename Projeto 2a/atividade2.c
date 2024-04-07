// Atividade 2: Analisador Lexico de Decimais   
//    Discente: Maria Eduarda Guedes Alves 
    
#include <stdio.h>

int main(void) {
    FILE *f; char c;

    f = fopen("C:/Users/maria/OneDrive/Documentos/_UESC/Aulas/Conceitos de LP/Projeto 2a/file2.txt", "r");    
    
    // Verificando se o arquivo foi aberto corretamente
    if (!f) {                       
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    printf("\n========== Analisador Lexico de Decimais ==========\n");

    Q0: 
        // Verificando se nao chegou em fim de arquivo
        if ((c = fgetc(f)) == EOF) {   
            printf("\n\n");
            fclose(f); return 0;
        }

        if (c=='0' || c=='1' || c=='2' || c=='3' || c=='4' ||
            c=='5' || c=='6' || c=='7' || c=='8' || c=='9') {
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