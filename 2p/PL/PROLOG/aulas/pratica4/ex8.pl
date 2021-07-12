tipotermo(Termo, Tipo) :-
    (atom(Termo), Tipo = atomo);
    (number(Termo), Tipo = numero);
    (atomic(Termo), Tipo = constante);
    (var(Termo), Tipo = variavel, !);
    (termosimples(Termo), Tipo = termo_simples);
    (termocomplexo(Termo), Tipo = termo_complexo).

tipotermo(_, Tipo) :-
    Tipo = termo, !.
termosimples(Termo) :-
    functor(Termo, _, A),
    A =:= 0.

termocomplexo(Termo) :-
    nonvar(Termo),
    functor(Termo, _, A),
    A > 0.
