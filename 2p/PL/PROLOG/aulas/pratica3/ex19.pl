npermutacoes(0, 1).
npermutacoes(M, N) :-
    Z is M - 1,
    Z >= 0,
    npermutacoes(Z, Ns),
    N is Ns * M.

