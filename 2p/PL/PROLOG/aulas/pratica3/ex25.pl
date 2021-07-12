sem_repeticao([], []).

sem_repeticao([H|Hs], Ys) :-
    sem_repeticao(Hs, Ys),
    member(H, Hs).

sem_repeticao([H|Hs], [H|Ys]) :-
    sem_repeticao(Hs, Ys).
