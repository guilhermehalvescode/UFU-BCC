somaUm([],[]).
somaUm([H|Hs],[Z|Zs]) :-
    Z is H + 1,
    somaUm(Hs, Zs).