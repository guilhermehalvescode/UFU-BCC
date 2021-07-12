remove(X,[X|L], L).
remove(X, [H|L], [H|L1]):-
    remove(X,L,L1).

permutacao([],[]).
permutacao(Xs,[Y|Zs]):-
    remove(Y,Xs,Ys),
    permutacao(Ys,Zs).

%(a)
disjunto([],[]).

disjunto([H|Hs], [X|Xs]) :-
    \+ member(H, [X|Xs]),
    \+ member(X, [H|Hs]),
    disjunto(Hs, Xs).

%(b)
uniao([],L,L).
uniao(L, [], L).

uniao([H|T],L,U):-
    member(H, L),
    uniao(T,L,U).

uniao([X|T], K, [X|M]) :-
    uniao(T, K, M).

uniao(L, K, M) :-
    uniao(L, K, J),
    permutacao(M, J).

%(c)

