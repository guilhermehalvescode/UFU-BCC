minAcum([],X,X).

minAcum([H|T], Acum, Z) :-
    Acum > H,
    minAcum(T, H, Z).

minAcum([_|T], Acum, Z) :-
    minAcum(T, Acum, Z).

minAcum([H|T], Y) :-
    minAcum([H|T], H, Y).