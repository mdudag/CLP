% Discente Maria Eduarda Guedes Alves

ack(M, N, 0, R) :- M>=0, N>=0, R is M+N.
ack(M, 0, 1, R) :- M>=0, R is 0.
ack(M, 0, 2, R) :- M>=0, R is 1.
ack(M, N, 2, R) :- M>=0, N>=0, R is M^N.
ack(M, N, P, R) :- M>=0, N>=0, P>2, R is P.
ack(M, N, P, R) :- M>=0, N>0, P>0, 
    			   ack(M, N-1, P, Temp), 
                   ack(M, Temp, P-1, R).



% Utilizei essa função que encontrei para calcular as possibilidades
main :-
    I = 9,
    findall([M, N, P], (between(0, I, M), between(0, I, N), between(0, I, P)), Combinations),
    process_combinations(Combinations).

% Processar todas as combinações de valores
process_combinations([]).
process_combinations([[M, N, P] | Rest]) :-
    (ack(M, N, P, R) -> 
        format('ack(~d, ~d, ~d): ~d\n', [M, N, P, R]);
        true),
    process_combinations(Rest).
:- main.

% Consulta: main.
