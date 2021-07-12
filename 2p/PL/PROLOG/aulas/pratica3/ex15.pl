prodEsc([],[], 0).

prodEsc([X|Xs], [Y|Ys], Soma) :-
    prodEsc(Xs, Ys, SomaOutra),
    Soma is SomaOutra + (X * Y).
