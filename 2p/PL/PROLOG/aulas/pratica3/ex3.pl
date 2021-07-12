intercala2([],Y,Y).
intercala2(X,[],X).
intercala2([X|Xs],[Y|Ys],[[X,Y]|Z]) :-
    intercala2(Xs, Ys, Z).