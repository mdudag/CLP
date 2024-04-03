#include <stdio.h>

int main(void) {
    FILE *f; char c;

    f = fopen("C:/Users/maria/OneDrive/Documentos/_UESC/Aulas/Conceitos de LP/Projeto 2a/arquivo.txt", "r");    
                                    // Abre arquivo
    if (!f) {                       // Verificando se o arquivo foi aberto corretamente
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    Q0:
        c=fgetc(f);
        // printf("\n---- valor de %c ----", c);
        // if (c==EOF) {
        //     printf("\n---- fim de arquivo ----"); return 0;
        // }
        if (c=='0' || c=='1') {
            printf("\n%c - Reconhecida!", c); 
            goto Q0;
        }
        else goto ERRO;
        
    ERRO: 
        printf("\n%c - Nao reconhecida.", c);
        return 1;
    
    fclose(f);                      // Fecha arquivo    
    printf("\n\n");                  
    return 0;
}
