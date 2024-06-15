% Discente Maria Eduarda Guedes Alves

ackPR(0, N, R) :- R is N+1.
ackPR(M, 0, R) :- M>0, M1 is M-1,
                  ackPR(M1, 1, R).
ackPR(M, N, R) :- M>0, N>0, M1 is M-1, N1 is N-1,
    		  	  ackPR(M, N1, Temp),
    		      ackPR(M1, Temp, R).

% Exemplo de Consulta: ackPR(2, 3, R), write('A(2, 3) = '), write(R), nl.
