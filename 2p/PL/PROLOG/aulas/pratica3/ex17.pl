insere(X,[], [X]).
insere(X,[H|L], [X,H|L]).
insere(X, [H|L], [H|L1]):-
    insere(X,L,L1).