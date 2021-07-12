maisculas(ArqEntrada, ArqSaida) :-
    open(ArqEntrada, read, StreamIn),
    open(ArqSaida, write, StreamOut),
    convert(StreamIn, List),
    atom_codes(Atom, List),
    write(StreamOut, Atom),
    close(StreamIn), !,
    close(StreamOut).

convert(StreamIn, [H|T]) :-
    get_code(StreamIn, Code), Code =\= -1,
    to_upper(Code, H),
    convert(StreamIn, T).

convert(StreamIn, []) :-
    get_code(StreamIn, H), 
    H =:= -1. 

to_upper(Code, Res) :-
    Code > 96, Code < 123,
    Res is Code - 32.

to_upper(Code, Code).