remove(X,[X|L], L).

remove(X, [H|L], [H|L1]):-
    remove(X,L,L1).