% Discente Maria Eduarda Guedes Alves

ack(M, N, 0, R) :- R is M+N.
ack(M, 0, 1, 0) :- M>0.
ack(M, 0, 2, M) :- M>0.
ack(M, N, 2, R) :- M>0, N>0, R is M^N.
ack(M, N, P, R) :- P>2, R is P.
ack(M, N, P, R) :- M>0, N>0, P>0, 
    			   ack(M, N-1, P, Temp), 
                   ack(M, Temp, P-1, R).

% Exemplo de consulta
% ack(2, 3, 2, R), write('Ack(2, 3, 2) = '), write(R), nl.
