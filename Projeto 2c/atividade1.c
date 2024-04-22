#include <stdio.h>

#define LETTER      0
#define DIGIT       1
#define OP_OR_PAREN 2
#define ERRO       99

#define LEFT_PAREN  3
#define RIGHT_PAREN 4
#define ADD_OP      5
#define SUB_OP      6
#define MULT_OP     7
#define DIV_OP      8
#define ID          9
#define INT_CONST  10

#define END_WORD   11

// ============================ ANALISADOR LEXICO ============================

int classChar;
char nextChar;
char lexeme[100];
int lenLex;
int nextToken;
char p[200];
int okLex=1;

int isLetter(char c) {
    int ok=0;
    
    if ((c>=65 && c<=90) ||
         (c>=97 && c<=122))
         ok=1;
    // printf("\nc: %c - cint: %d - ok: %d\n", c, c, ok);

    return ok;
}

int isDigit(char c) {
    int ok=0;
    
    if (c>=48 && c<=57)
         ok=1;
         
    return ok;
}

int isOpOrParen(char c) {
    int ok=0;
    
    if (c=='+' || c=='-' || c=='*' || c=='/' ||
        c=='(' || c==')')
         ok=1;
         
    return ok;
}

void getChar(FILE *f) {
    nextChar = fgetc(f);
    // printf("\nnextchar = %c\n", nextChar);
    getBlankSpace(f);

    if (nextChar != '\n' && 
        nextChar != EOF) {
        
        if (isLetter(nextChar)) {
            classChar = LETTER;
        }
        else if (isDigit(nextChar)) {
            classChar = DIGIT;
        }
        else if (isOpOrParen(nextChar)) {
            classChar = OP_OR_PAREN;
            // printf("\nop entrei\n");
        }
        else {
            classChar = ERRO;
        }
    }
    else if (nextChar == '\n') {
        // printf("Fim da palavra\n\n");
        classChar = END_WORD;
    }
    else {
        // printf("Fim da palavra\n\n");
        classChar = -1;
    }
}

void getBlankSpace(FILE *f) {
    while (nextChar == ' ') 
        nextChar = fgetc(f);
    // printf("\n%c\n", nextChar);
}

void addChar() {
    if (lenLex <= 98) {
        lexeme[lenLex++] = nextChar;
        lexeme[lenLex]   = '\0';
    }
    else {
        printf("\nErro! Lexema ultrapassou tamanho permitido.\n");
        exit(-1);
    }
}

int lex (FILE *f) {
    lenLex=0;
    // getBlankSpace(f);

    if (classChar == LETTER) {
        do {
            addChar(); getChar(f);
        } while (classChar == LETTER ||
                    classChar == DIGIT);

        nextToken = ID; 
    }
    else if (classChar == DIGIT) {
        do {
            addChar(); getChar(f);
        } while (classChar == DIGIT);
                    
        nextToken = INT_CONST;
    }
    else if (classChar == OP_OR_PAREN) {
        addChar();
        switch (nextChar) {
            case '(': nextToken = LEFT_PAREN;   break;
            case ')': nextToken = RIGHT_PAREN;  break;
            case '+': nextToken = ADD_OP;       break;
            case '-': nextToken = SUB_OP;       break;
            case '*': nextToken = MULT_OP;      break;
            case '/': nextToken = DIV_OP;       break;   
        }
        getChar(f);
    }
    else if (classChar == END_WORD) {
        nextToken = END_WORD;
        lexeme[0] = '\\';
        lexeme[1] = 'n';
        lexeme[2] = '\0';
    }
    else if (classChar == -1) {
        nextToken = EOF;
        lexeme[0] = 'E';
        lexeme[1] = 'O';
        lexeme[2] = 'F';
        lexeme[3] = '\0';
    }
    else {
        nextToken = ERRO;
        lexeme[0] = nextChar;
        lexeme[1] = '\0';
        okLex=0;
        printf("\nSimbolo rejeitado: %c!\np: ", nextChar);
    }

    printf("Next token is: %d,\tNext lexeme is %s\n", nextToken, lexeme);
    // printf("%s", lexeme);
    // system("pause");
    return nextToken;
}

// ============================ ANALISADOR SINTATICO ============================

// <expr> → <term> {(+ | -) <term>}
int expr(FILE *f, int lenP) {
    
    // printf("next: %d", nextToken);
    p[lenP] = '1';
    // printf("\n1: lenP: %d", lenP);
    int newLenP = term(f, lenP+1);

    if (okLex) {
        if (nextToken == ADD_OP ||
            nextToken == SUB_OP) {
            
            if (nextToken == ADD_OP) p[lenP] = '2';
            else                     p[lenP] = '3';

            lex(f);
            if (okLex) {
                newLenP = term(f, newLenP);
            }
        }
    }


    // printf("\n1: newlenP: %d", newLenP);

    return newLenP;
}

// <term> → <factor> {(* | /) <factor>}
int term(FILE *f, int lenP) {
    // printf("\n2: lenP: %d", lenP);
    p[lenP] = '4';
    int newLenP = factor(f, lenP+1);
    // printf("\n2: newlenP: %d", newLenP);
    if (okLex) {
        if (nextToken == MULT_OP ||
            nextToken == DIV_OP) {
            
            if (nextToken == MULT_OP) p[lenP] = '5';
            else                      p[lenP] = '6';

            lex(f);
            if (okLex) {
                newLenP = factor(f, newLenP);
            }

        }
    }


    return newLenP;
}

// <factor> → id | int_constant | ( <expr> )
int factor(FILE *f, int lenP) {
    // printf("\n3: lenP: %d", lenP);
    int newLemP = lenP;
    // printf("\nnewlenP: %d", newLemP);
    if (nextToken == ID ||
        nextToken == INT_CONST) {
        
        newLemP = lenP+1;    
        if (nextToken == ID) p[lenP] = '7';
        else                 p[lenP] = '8';

        lex(f); 
        // printf("nex: %c", nextChar);
    }
    else if (nextToken == LEFT_PAREN) {
        p[lenP] = '9';
        lex(f);
        if (okLex) {
            newLemP = expr(f, lenP+1);

            if (okLex) {
                if (nextToken == RIGHT_PAREN) {
                    lex(f);
                }
                else {
                    printf("%c\nErro Sintatico!\n", nextChar); 
                    okLex=0;
                }
            }

        }
    }
    else {
        printf("%c\nErro Sintatico!\n", nextChar); 
        okLex=0;
    }

    // printf("\nlenP+1: %d", lenP);

    return newLemP;
}

void printP() {
    for (int i=0; p[i] != '\0'; i++) {
        printf("p%c ", p[i]);
    }
}


int main(void) {
    FILE *f = fopen("file.txt", "r");

    if (!f) {
        printf("\nErro ao abrir arquivo!\n");
        exit(-1);
    }

    int lenP;

    Q0:
        lenP=0;
        classChar = ERRO;
        printf("\n\n========================================================\n");
        getChar(f);
        goto Q1;

    Q1:
        // printf("\nentrei\n\n");
        lex(f);
        if (okLex) {
            lenP = expr(f, lenP);

            if (okLex && (nextToken==EOF || nextToken==END_WORD)) {
                printf(" - Expressao Aceita!\np: ");
                p[lenP] = '\0';
                printP();
            }
            else {
                printf("\nErro Sintatico!\np: ");
                p[lenP] = '\0';
                printP(); 
                goto FIM;
            }

            
        }
        else {
            p[lenP] = '\0';
            printP();
            goto FIM;
        }

        
        if (nextToken == EOF || 
                 nextToken == ERRO)       goto FIM;
        else if      (nextToken == END_WORD) {
            goto Q0;
        }
        else                            goto Q1;

    FIM:
        fclose(f);
        return 0;
}
