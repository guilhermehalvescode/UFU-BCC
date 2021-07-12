ocorrencias(_, [], X, X).

ocorrencias(X, [H|Hs], Acum, N) :-
    H =:= X,
    NovoAcum is Acum + 1,
    ocorrencias(X, Hs, NovoAcum, N).

ocorrencias(X, [_|Hs], Acum, N) :-
    ocorrencias(X, Hs, Acum, N).

ocorrencias(X, L, N) :-
    ocorrencias(X, L, 0, N).