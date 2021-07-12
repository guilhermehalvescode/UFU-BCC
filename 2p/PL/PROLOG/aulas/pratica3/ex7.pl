duplicada(L, L1) :-
    append(L1, L1, L).
    
duplicada(Z, [_|T]):-
    duplicada(Z, T).
duplicada(X) :-
    duplicada(X, X).