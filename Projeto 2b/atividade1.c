// Discente Maria Eduarda Guedes Alves
// Simulacao de Automato

#include <stdio.h>
#include <string.h>

int lex(FILE *f, char *w) {
    char c = fgetc(f);
    
    int i;
    if (c != EOF) {
        for (i=0; c != '\n' && c != EOF; i++) {
            if (c=='a' || c=='b' || c=='c') {
                w[i]=c;
                c = fgetc(f);
            }
            else {
                printf("\n%c - Simbolo recusado\n", c);
                return 0;
            } 
        }
    }
    else return 0;

    w[i] = '\0';
    return 1;
}

void push(char *stack, int *top, char *token) {
    if (token=="S") {
        stack[++(*top)] = 'S';
        stack[(*top)+1] = '\0';
    }
    else if (token=="aSb") {
        stack[++(*top)] = 'b';
        stack[++(*top)] = 'S';
        stack[++(*top)] = 'a';
        stack[(*top)+1] = '\0';
        printf("p1");
    }
    else {
        stack[++(*top)] = 'c';
        stack[(*top)+1] = '\0';
        printf("p2");
    }
}

void pop(char *stack, int *top) { stack[(*top)--] = '\0'; }

void printWord(char *w, int i) {
    int j=0;
    
    for (; j<i; j++) {
        printf("%c", w[j]);
    }

    printf(".");

    for (; w[j] != '\0'; j++) {
        printf("%c", w[j]);
    }
    
    printf("\t");
}

void printStack(char *s, int top) {
    for (int i=top; i>=0; i--) {
        printf("%c", s[i]);
    }
    printf("\t");
}

int main(void) {
    FILE *f = fopen("C:/Users/maria/OneDrive/Documentos/_UESC/Aulas/Conceitos de LP/Projeto 2b/file.txt", "r");

    // Verificando se o arquivo foi aberto corretamente
    if (!f) {                       
        printf("Erro ao abrir arquivo!");
        return 1;
    }

    char stack[100], word[100];
    int top, i, it, wi, ok;

    Q0: 
        if (!lex(f, word)) goto FIM;
        i=0; top=-1; it=0; wi=0; ok=0;

        // Inicio da impressao da tabela
        printf("\n--------------------------------------------------------");
        printf("\n  i |\tQ |\t   .w |\tStack |\tdi |\tpi |");
        printf("\n  %d\tQ0\t", it);
        printWord(word, wi);
        printf("\td0");

        push(stack, &top, "S");
        goto Q1;

    Q1: 
        printf("\n  %d\tQ1\t", ++it);

        if (ok) ++wi, ++i;      // Se algum simbolo foi consumido
        printWord(word, wi);
        printStack(stack, top);

        ok=0;
        if (word[i]=='a' && stack[top]=='S') {
            printf("d1\t");

            pop(stack, &top); 
            push(stack, &top, "aSb");
        }
        else if (word[i]=='c' && stack[top]=='S') {
            printf("d2\t");

            pop(stack, &top); 
            push(stack, &top, "c");
        }
        else if ((word[i]=='a' && stack[top]=='a') ||
                 (word[i]=='b' && stack[top]=='b') ||
                 (word[i]=='c' && stack[top]=='c')) {

            ok=1;

            if      (word[i]=='a') printf("d3\t"); 
            else if (word[i]=='b') printf("d4\t"); 
            else if (word[i]=='c') printf("d5\t"); 
             
            pop(stack, &top); 

            if (word[i+1]=='\0') {              // Fim da palavra
                printf("\n  %d\tQ1\t", ++it);

                printWord(word, ++wi);
                printStack(stack, top);

                if (top==-1) goto Q0;           // Stack vazio     
                else         goto R;
            } 
        }
        else goto R;

        goto Q1;

    R:
        printf("\n\n%s - Palavra rejeitada.\n", word);
        goto FIM;
    
    FIM:
        fclose(f);
        printf("\n");
        return 0;
}
