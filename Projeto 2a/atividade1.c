// Atividade 1: Analisador Lexico de Binarios
//    Discente: Maria Eduarda Guedes Alves 
    
#include <stdio.h>

int main(void) {
    FILE *f; 
    char c, token[100];
    int i=0, j;

    f = fopen("C:/Users/maria/OneDrive/Documentos/_UESC/Aulas/Conceitos de LP/Projeto 2a/file1.txt", "r");    
    
    // Verificando se o arquivo foi aberto corretamente
    if (!f) {                       
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    printf("\n========== Analisador Lexico de Binarios ==========\n");

    Q0: 
        c = fgetc(f);

        // Pegando a palavra   
        if (c!='\n' && c!=EOF) {
            token[i] = c;
            ++i; goto Q0;
        }
        token[i] = '\0';

        j=0;
        
    Q1: 
        if (token[j]=='0' || token[j]=='1') {
            ++j; goto Q1;
        }
        else if (token[j]=='\0') {
            printf("\n%s\t- Reconhecida!", token); 
            i=0; goto FIM;
        }
        else goto ERRO;

    ERRO: 
        printf("\n%s\t- Nao reconhecida.\n\n", token);
        fclose(f); return 1; 

    FIM: 
        if (c==EOF) {
            printf("\n\n");
            fclose(f); return 0;
        }
        goto Q0;
}
