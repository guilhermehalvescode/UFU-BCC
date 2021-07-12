intercala1([],Y,Y).
intercala1(X,[],X).
intercala1([X|Xs],[Y|Ys],[X,Y|Z]) :-
    intercala1(Xs, Ys, Z).