segmento(L, L2) :-
    append(L, _, L2).

segmento(L, [_|Hs]) :-
    segmento(L, Hs).