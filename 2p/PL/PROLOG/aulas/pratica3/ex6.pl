superconjunto(_,[]).
superconjunto(Y,[X|Xs]) :-
    member(X, Y),
    superconjunto(Y, Xs).