% Discente Maria Eduarda Guedes Alves

ackPR(0, N, R) :- N>=0, R is N+1.
ackPR(M, 0, R) :- M>0, M1 is M-1,
                  ackPR(M1, 1, R).
ackPR(M, N, R) :- M>0, N>0, M1 is M-1, N1 is N-1,
    		  	  ackPR(M, N1, Temp),
    		      ackPR(M1, Temp, R).



% Utilizei essa função que encontrei para calcular as possibilidades
main :-
    I = 5,
    findall([M, N], (between(0, I, M), between(0, I, N)), Combinations),
    process_combinations(Combinations).

% Processar todas as combinações de valores
process_combinations([]).
process_combinations([[M, N] | Rest]) :-
    (ackPR(M, N, R) -> 
        format('A(~d, ~d): ~d\n', [M, N, R]);
        true),
    process_combinations(Rest).
:- main.
