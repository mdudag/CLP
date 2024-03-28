// -----> Maria Eduarda Guedes Alves

// p-code.cpp :  cpp.sh
//
// C conventions
// 0 == FALSE
//
#include <stdio.h>

#define levmax 3
#define amax 2047

// enum fct {LIT, OPR, LOD, STO, CAL, INT, JMP, JPC};
typedef enum {
  LIT, OPR, LOD, STO, CAL, INT, JMP, JPC
} fct;

typedef struct tinstruction {
  fct    f;
  int    l; // l: 0..levmax; // Level buffer
  int    a; // a: 0..amax;   // Address buffer
}instruction;

// -----> Maria Eduarda Guedes Alves

  // main e fib(5) iterativo
  instruction code[2048] = {{INT, 0,  5},      // == funcao main ==           posicao
                            {LIT, 0,  5},          // n = 5
                            {STO, 0,  3},
                            
                            {LOD, 0,  3},          // n -> funcao fib
                            {STO, 0,  8},
                            
                            {CAL, 0,  9},          // call main                  5
                            
                            {LOD, 0, 12},          // fib(5)
                            {STO, 0,  4},
                            {OPR, 0,  0},      // == fim main ==                 8
                            
                            {INT, 0,  8},      // == funcao fib ==               9     
                            {LIT, 0,  3},          // i = 3
                            {STO, 0,  4},          
                            {LIT, 0,  0},          // f1 = 0
                            {STO, 0,  5},
                            {LIT, 0,  1},          // f2 = 1
                            {STO, 0,  6},
                            
                            {LOD, 0,  3},          // n
                            {LIT, 0,  1},          // 1
                            {OPR, 0,  8},          // n == 1?

                            {JPC, 0, 41},          // jpc 1                      19 

                            {LOD, 0,  3},          // n
                            {LIT, 0,  2},          // 2
                            {OPR, 0,  8},          // n == 2?

                            {JPC, 0, 44},          // jpc 2                      23

                            {LOD, 0,  4},          // i                          24
                            {LOD, 0,  3},          // n
                            {OPR, 0, 12},          // i > n?

                            {JPC, 0, 46},          // jpc 3                      27

                            {LOD, 0,  5},          // f1
                            {LOD, 0,  6},          // f2
                            {OPR, 0,  2},          // f1 + f2
                            {STO, 0,  7},          // f = f1 + f2

                            {LOD, 0,  6},          // f2
                            {STO, 0,  5},          // f1 = f2
                            {LOD, 0,  7},          // f
                            {STO, 0,  6},          // f2 = f

                            {LOD, 0,  4},          // i
                            {LIT, 0,  1},          // 1
                            {OPR, 0,  2},          // i + 1
                            {STO, 0,  4},          // i = i + 1

                            {JMP, 0, 24},          // jmp                        40

                            {LOD, 0,  5},          // f1                         41
                            {STO, 0,  7},          // f = f1
                            {OPR, 0,  0},                                     // 43

                            {LOD, 0,  6},          // f2                      // 44
                            {STO, 0,  7},          // f = f2
                            {OPR, 0,  0}};     // == fim fib ==               // 46

//procedure interpret;
// const stacksize = 500;

#define stacksize 5012

 // p, b, t: integer; {program-, base-, topstack-registers}
int p, // program-register
    b, // base-register
    t; // topstack-register
 
instruction i;            //: instruction; {instruction register}
int         s[stacksize]; //: array [1..stacksize] of integer; {datastore}

int base(int l){ //l: integer)
  int b1; //

  b1 = b; // {find base l levels down}
  while (l > 0) {
    b1 = s[b1];
    l  = l - 1;
  }
  return b1;
}//end-int-base

// Determina se seu argumento é impar
int odd(int x){ return (  ((x%2)==1) ); }

void pcodevhw(){ // begin 
  printf("\n start pl/0");
  printf("\n p   b   t     f   l   a                 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14");
  printf("\n === === ===   === === ===             === === === === === === === === === === === === === === ===");
  t = -1; // topstack-register
  b = 0;  // base-register
  p = 0;  // program-register

  // OBS: s[0] must not be used
  s[1] = 0; 
  s[2] = 0; 
  s[3] = 0;

  do {
  i = code[p]; 
  //printf("\n %3d %3d %3d - %3d %3d %3d", p, b, t, i.f, i.l, i.a);
  printf("\n %3d %3d %3d   ", p, b, t);
  p = p + 1;
  // switch case i.f-BEGIN
  switch  (i.f) { // with i do case f of
    case LIT : { t = t + 1; s[t] = i.a; printf("LIT %3d %3d", i.l, i.a); } break;
    case OPR :
              printf("OPR %3d %3d", i.l, i.a);
  //             switch case i.a-BEGIN
              switch (i.a) { // case a of {operator}
                case  0: { // return
                            t = b - 1; 
                            p = s[t + 3]; 
                            b = s[t + 2];
                          }
                          break;
        
                case  1: { //
                            s[t] = -s[t];
                          }
                          break;
        
                case  2: { //  ADD     : PUSH( POP()+POP() )
                            t    = t - 1; 
                            s[t] = s[t] + s[t + 1];
                          }
                          break;
        
                case  3: { // SUBSTRACT: PUSH( POP()-POP() )
                            t    = t - 1; 
                            s[t] = s[t] - s[t + 1];
                          }
                          break;
        
                case  4: { // MULTIPLY: PUSH( POP()*POP() )
                            t    = t - 1; 
                            s[t] = s[t] * s[t + 1];
                          }
                          break;
        
                case  5: { // DIVIDE  : PUSH( POP()/POP() )
                            t    = t - 1; 
                            s[t] = s[t] / s[t + 1];
                          }
                          break;
        
                case  6: { // 
                            s[t] = odd(s[t]); //s[t] = ord(odd(s[t]));
                          }
                          break;
        
                case  8: { // EQUAL
                            t    = t - 1; 
                            s[t] = (s[t] == s[t + 1]);
                          }
                          break;
        
                case  9: { // NOT.EQUAL
                            t    = t - 1; 
                            s[t] = (s[t] != s[t + 1]);
                          }
                          break;
        
                case 10: { // LESS THAN
                            t    = t - 1; 
                            s[t] = (s[t] < s[t + 1]);
                          }
                          break;
        
                case 11: { // GREATER EQUAL THAN
                            t    = t - 1; 
                            s[t] = (s[t] >= s[t + 1]);
                          }
                          break;
        
                case 12: { // GREATER THAN
                            t = t - 1; 
                            s[t] = (s[t] > s[t + 1]);
                          }
                          break;
        
                case 13: { // LESS EQUAL THAN
                            t    = t - 1; 
                            s[t] = (s[t] <= s[t + 1]);
                          }
                          break;
              } // end;
  //         switch case i.a-END
          break;

  case LOD : { // LOAD
                printf("LOD %3d %3d", i.l, i.a);
                t    = t + 1; 
                s[t] = s[base(i.l) + i.a];
              }
              break;

  case STO : { // STORE
                printf("STO %3d %3d", i.l, i.a);
                s[base(i.l)+i.a] = s[t]; 
                t            = t - 1;
              }
              break;

  case CAL :
              { // {generate new block mark}
                printf("CAL %3d %3d", i.l, i.a);
                s[t + 1] = base(i.l); 
                s[t + 2] = b; 
                s[t + 3] = p;
                b        = t + 1; 
                p        = i.a;
              }
              break;

  case INT : t = t + i.a;printf("INT %3d %3d", i.l, i.a); break;
  case JMP : p = i.a;    printf("JMP %3d %3d", i.l, i.a); break;
  case JPC : if (s[t] != 0) { p = i.a; }  t = t - 1; printf("JPC %3d %3d", i.l, i.a); break;
  } // end {with, case}
  // switch case i.f-END

  // print stack
  printf("      s[] : ");
  for (int h=0; h<=t; h++) { printf(" %3d", s[h]); }
  // printf("\n");
  // system("pause");
  } while ( p != 0 );

  printf("\n === === ===   === === ===             === === === === === === === === === === === === === === ==="); 
  printf("\n p   b   t     f   l   a                 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14");
  printf("\n end pl/0");
}//end-void-pcmachine() {interpret};

int main(){

	// Aqui vc preenche as instrucoes no vetor code
    // code[ 0].f = OPR; code[ 0].l = 0; code[ 0].a = 0;

	// Aqui vc chama a P-code machine para interpretar essas instrucoes
	pcodevhw();
	return 0;
}