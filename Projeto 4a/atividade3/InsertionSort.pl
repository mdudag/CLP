% Discente Maria Eduarda Guedes Alves

% Caso base: lista vazia está ordenada
insertionSort([], []).

% Caso recursivo: ordena o corpo e insere o pivo na posição correta
insertionSort([Pivo|Corpo], ListaOrdenada) :-
    % Ordena o corpo da lista
    insertionSort(Corpo, CorpoOrdenado),
    % Insere o pivo na posição correta no corpo ordenado
    insert(Pivo, CorpoOrdenado, ListaOrdenada).

% Inserir um elemento em uma lista vazia
insert(Elemento, [], [Elemento]).

% Se o elemento for menor ou igual à cabeça da lista, insere o elemento antes da cabeça
insert(Elemento, [Cabeca|Corpo], [Elemento, Cabeca|Corpo]) :-
    Elemento =< Cabeca.

% Se o elemento for maior que a cabeça da lista, insere o elemento no corpo
insert(Elemento, [Cabeca|Corpo], [Cabeca|CorpoOrdenada]) :-
    Elemento > Cabeca,
    insert(Elemento, Corpo, CorpoOrdenada).

% Consulta: insertionSort([4, 3, 2, 1], ListaOrdenada).
