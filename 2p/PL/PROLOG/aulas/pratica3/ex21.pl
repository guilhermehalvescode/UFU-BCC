fatorial(0, 1).
fatorial(M, N) :-
    Z is M - 1,
    Z >= 0,
    fatorial(Z, Ns),
    N is Ns * M.
ncombinacoes(M,P,N) :-
    fatorial(M, ResM),
    fatorial(P, ResP),
    Z is M - P,
    fatorial(Z, ResZ),
    N is ResM/(ResZ * ResP).