remove(X,[X|L], L).
remove(X, [H|L], [H|L1]):-
    remove(X,L,L1).

arranjo(0, _, []).
arranjo(N, Xs, [Y|Zs]):-
    remove(Y,Xs,Ys),
    Z is N - 1,
    arranjo(Z, Ys, Zs).