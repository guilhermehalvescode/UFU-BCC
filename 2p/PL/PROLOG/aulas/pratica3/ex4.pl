intercala3([],Y,Y).
intercala3(X,[],X).
intercala3([X|Xs],[Y|Ys],[junta(X,Y)|Z]) :-
    intercala3(Xs, Ys, Z).