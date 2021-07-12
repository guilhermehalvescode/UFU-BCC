s(Conta) --> as(Conta), bs(Conta), cs(Conta), ds(Conta). 

as(0) --> [].
as(suc(suc(Conta))) --> [a], as(Conta).

bs(0) --> [].
bs(suc(Conta)) --> [b], bs(Conta).

cs(0) --> [].
cs(suc(Conta)) --> [c], cs(Conta).

ds(0) --> [].
ds(suc(suc(Conta))) --> [d], ds(Conta).

s(L, L1) :-
    s(_, L, L1).
