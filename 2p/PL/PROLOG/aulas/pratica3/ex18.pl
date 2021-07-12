remove(X,[X|L], L).
remove(X, [H|L], [H|L1]):-
    remove(X,L,L1).

permutacao([],[]).
permutacao(Xs,[Y|Zs]):-
    remove(Y,Xs,Ys),
    permutacao(Ys,Zs).
/* 
(a) permutacao([a,m,o,r]).
(b) permutacao([sergio,adriano,fabiola]).
*/