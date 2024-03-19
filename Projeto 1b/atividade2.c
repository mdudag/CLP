#include <stdio.h>

#define levmax 3
#define amax 2047
#define stacksize 500

typedef enum {
    LIT, OPR, LOD, STO, CAL, INT, JMP, JPC
} fct;

typedef struct {
    fct f;
    int l;  
    int a;
} instruction;

int p, b, t;
long long int  s[stacksize];
instruction i;

int base(int l) {
    int b1=b;

    while(l>0) {
        b1=s[b1]; l--;   
    }

    return b1;
}

void printVal() {
    printf("\n PC: %d "
           "| IR: f=%d, l=%d, a=%d "
           "| BP: %d "
           "| SP: %d ", p, i.f, i.l, i.a, b, t);

    printf("| Stack: [");
    for (int i=0; i<=t; i++)
        printf("\t%lld", s[i]);
    printf("\t]");
}

int main(void) {
    // Criando instruções
    instruction code[] = {{INT, 0, 4},
                          {LIT, 0, 1},
                          {STO, 0, 3},
                          {LOD, 0, 3},
                          {LOD, 0, 4},
                          {LIT, 0, 1},
                          {OPR, 0, 2},
                          {LOD, 0, 5},
                          {OPR, 0, 4},
                          {OPR, 0, 2},
                          {STO, 0, 3},
                          {LIT, 0, 100},
                          {LOD, 0, 6},
                          {OPR, 0, 3},
                          {JPC, 0, 19},
                          {LOD, 0, 3},
                          {STO, 0, 4},
                          {LOD, 0, 6},
                          {JMP, 0, 5},
                          {OPR, 0, 0}};
    
    printf("\n  start pL/0\n");

    t=-1; b=0; p=0;    
    s[0]=0; s[1]=0; s[2]=0;

    do {
        i = code[p];

        // Impressão antes da execução da instrução
        // printVal();
        
        p++;   

        switch (i.f) {
            case LIT: t=t+1; s[t]=i.a; break;

            case OPR:
                switch (i.a) {
                    case 0:  t=b-1; p=s[t+2]; b=s[t+1];  break;    // Return operation
                    case 1:  s[t]=-s[t];                 break;    // NEG
                    case 2:  t=t-1; s[t] = s[t]+s[t+1];  break;    // ADD
                    case 3:  t=t-1; s[t] = s[t]-s[t+1];  break;    // SUB
                    case 4:  t=t-1; s[t] = s[t]*s[t+1];  break;    // MUL
                    case 5:  t=t-1; s[t] = s[t]/s[t+1];  break;    // DIV
                    case 6:  s[t] = (s[t]%2 == 0)? 0: 1; break;    // ODD
                    case 8:  t=t-1; s[t] = s[t]==s[t+1]; break;    // EQL
                    case 9:  t=t-1; s[t] = s[t]!=s[t+1]; break;    // NEQ            
                    case 10: t=t-1; s[t] = s[t]<s[t+1];  break;    // LSS
                    case 11: t=t-1; s[t] = s[t]>=s[t+1]; break;    // GEQ                    
                    case 12: t=t-1; s[t] = s[t]>s[t+1];  break;    // GTR 
                    case 13: t=t-1; s[t] = s[t]<=s[t+1]; break;    // LEQ
                    default: printf("\nERROR"); break;
                }
                break;
            
            case LOD: t=t+1; s[t]=s[base(i.l) + i.a]; break;

            case STO:
                s[base(i.l) + i.a] = s[t]; 
                // printf("%d\n", s[t]);
                t=t-1; break;

            case CAL:
                s[t+1] = base(i.l);
                s[t+2] = b; s[t+3] = p;
                b=t+1; p=i.a; break;

            case INT: t=t+i.a; break;
            case JMP: p=i.a; break;

            case JPC:
                if (!s[t]) {
                    p=i.a; t=t-1;
                }
                break;

            default: printf("\nERROR"); break;
        }

        // Impressão após execução da instrução
        printVal();
        // printf("\n\n----------------------------------------------------");
        // system("pause");
    } while(p!=0);

    printf("\n\n  end pL/0\n\n");
    return 0;
}