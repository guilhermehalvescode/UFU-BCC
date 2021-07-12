duasVezes([],[]).

duasVezes([H|T],[H,H|C]) :-
    duasVezes(T, C).