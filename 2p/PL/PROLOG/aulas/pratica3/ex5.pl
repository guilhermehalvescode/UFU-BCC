subconjunto([],_).
subconjunto([X|Xs],Y) :-
    member(X, Y),
    subconjunto(Xs, Y).