unificavel([], _, []).
unificavel([H|T], Termo, [H|Z]) :- 
    \+(\+ (H = Termo)),
    unificavel(T, Termo, Z).

unificavel([H|T], Termo, Z) :-
    \+ H = Termo, 
    unificavel(T, Termo, Z).

