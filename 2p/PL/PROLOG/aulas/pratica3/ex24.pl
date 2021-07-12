fatorial(0, 1).
fatorial(M, N) :-
    Z is M - 1,
    Z >= 0,
    fatorial(Z, Ns),
    N is Ns * M.
narranjos(M,P,N) :-
    fatorial(M, ResM),
    Z is M - P,
    fatorial(Z, ResZ),
    N is ResM/ResZ.