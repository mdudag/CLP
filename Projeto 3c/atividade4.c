# Discente Maria Eduarda Guedes Alves

#include <stdio.h>
#include <stdlib.h>

void erro();
int opr(char c, FILE *f);
int push(char c, FILE *f, int t);
int pop(char c, FILE *f);

int main(void) {
    FILE *f = fopen("C:/Users/maria/OneDrive/Documentos/_UESC/Aulas/Conceitos de LP/Projeto 3c/file.txt", "r");
    char c;

    if (!f) {
        printf("\nERRO ao abrir o arquivo!");
        exit(-1);
    }

    c=fgetc(f);
    printf("\nINT 0 4\n");

    while (c!=EOF) {
        if (push(c, f, 0));
        else if (pop(c, f));
        
        c=fgetc(f);
        if (c == 'X' || c == 't') {
            
            while (c!='\n' && c!=EOF) {
                c=fgetc(f);
            }

            printf("STO 0 3\n\n");

            if (c=='\n') printf("INT 0 4\n"); 
        }
    }

    fclose(f); return 0;
}

void erro() {
    printf("erro\n");
    exit(-1);
}

int opr(char c, FILE *f) {
    if (c=='A' && 
        (c=fgetc(f))=='D' && 
        (c=fgetc(f))=='D') {

        printf("OPR 0 2\n");    
    }
    else if (c=='S' && 
            (c=fgetc(f))=='U' && 
            (c=fgetc(f))=='B') {

        printf("OPR 0 3\n");    
    }
    else if (c=='M' && 
            (c=fgetc(f))=='U' && 
            (c=fgetc(f))=='L') {

        printf("OPR 0 4\n");    
    }
    else if (c=='D' && 
            (c=fgetc(f))=='I' && 
            (c=fgetc(f))=='V') {

        printf("OPR 0 5\n");    
    }
    else erro();

    return 1;
}

// PUSH(n)
int push(char c, FILE *f, int t) {
    if (c=='P' && 
        (c=fgetc(f))=='U' && 
        (c=fgetc(f))=='S' && 
        (c=fgetc(f))=='H' && 
        (c=fgetc(f))=='(') {

        if (t==0) {
            c=fgetc(f);
            printf("LIT 0 %c\n", c); 
        }
        else {
            if ((c=fgetc(f))=='x' && 
                (c=fgetc(f))==' ') {
                
                c=fgetc(f);
                opr(c,f);

                if ((c=fgetc(f)) != ' ' || 
                    (c=fgetc(f)) != 'y') {
                        erro();
                }
            } 
        }

        if ((c=fgetc(f))!=')') erro();
        return 1; 
    }

    return 0;
}

// y=POP(); x=POP(); PUSH(x OPR y)
int pop(char c, FILE *f) {
    if (c=='y' && 
        (c=fgetc(f))=='=' && 
        (c=fgetc(f))=='P' && 
        (c=fgetc(f))=='O' && 
        (c=fgetc(f))=='P' && 
        (c=fgetc(f))=='(' && 
        (c=fgetc(f))==')' &&
        (c=fgetc(f))==';' &&
        (c=fgetc(f))==' ' &&
        (c=fgetc(f))=='x' && 
        (c=fgetc(f))=='=' && 
        (c=fgetc(f))=='P' && 
        (c=fgetc(f))=='O' && 
        (c=fgetc(f))=='P' && 
        (c=fgetc(f))=='(' && 
        (c=fgetc(f))==')' &&
        (c=fgetc(f))==';' &&
        (c=fgetc(f))==' ') {

        c=fgetc(f);
        push(c,f,1);
        return 1;
    }

    return 0;
}
