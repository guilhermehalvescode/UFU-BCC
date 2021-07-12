s(Conta) --> as(Conta), bs(Conta). 

as(0) --> [].
as(suc(suc(Conta))) --> [a], as(Conta).

bs(0) --> [].
bs(suc(Conta)) --> [b], bs(Conta).

s(L, L1) :-
    s(_, L, L1).