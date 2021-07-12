ocorre([H|_], 0, H).

ocorre([_|T], N, X) :-
    N > 0,
    NovoN is N - 1,
    ocorre(T, NovoN, X).