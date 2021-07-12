soma_acum([], [], _).

soma_acum([H|Hs], [NovaSoma|L], Soma) :-
    NovaSoma is H + Soma,
    soma_acum(Hs, L, NovaSoma).

soma_acum(L, L1) :-
    soma_acum(L, L1, 0).    