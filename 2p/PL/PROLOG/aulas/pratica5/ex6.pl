numera_linhas(ArqEntrada, ArqSaida) :-
    open(ArqEntrada, read, StreamIn),
    open(ArqSaida, write, StreamOut),
    convert(StreamIn, List),
    atom_codes(Atom, List),
    write(StreamOut, Atom),
    close(StreamIn), !,
    close(StreamOut).

convert(StreamIn, [H|T], Cont) :-
    get_code(StreamIn, Code), Code =\= -1,
    contLinhas(Code, H, Cont),
    convert(StreamIn, T, Cont).

convert(StreamIn, [], _) :-
    get_code(StreamIn, H), 
    H =:= -1. 

convert(StreamIn, [H|T]) :-
    convert(StreamIn, [H|T], 48).

contLinhas(Code, Res, Cont) :-
    Code =:= 10,
    NovoCont is Cont + 1, 
    Res is NovoCont.

contLinhas(Code, Code, _).
