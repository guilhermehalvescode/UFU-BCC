remove(X,[X|L], L).
remove(X, [H|L], [H|L1]):-
    remove(X,L,L1).

permutacao([],[]).
permutacao(Xs,[Y|Zs]):-
    remove(Y,Xs,Ys),
    permutacao(Ys,Zs).

subconjunto([], []).

subconjunto([H|T], [H|Cs]) :-
    subconjunto(T, Cs).

subconjunto(L, [_|Cs]) :-
    subconjunto(L, Cs), !.

subconj(S, C) :-
    permutacao(S, Lista),
    subconjunto(Lista, C).
    