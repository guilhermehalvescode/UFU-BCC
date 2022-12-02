% sexo
%% homem
homem(ivo).
homem(rai).
homem(noe).
homem(ary).
homem(gil).

%% mulher
mulher(ana).
mulher(eva).
mulher(bia).
mulher(clo).
mulher(lia).
mulher(gal).

% pais
pai(ivo, eva).

pai(rai, noe).

pai(gil, rai).
pai(gil, clo).
pai(gil, ary).

pai(ary, gal).

% mães
mae(ana, eva).

mae(eva, noe).

mae(bia, rai).
mae(bia, clo).
mae(bia, ary).

mae(lia, gal).

gerou(X, Y) :-
    pai(X, Y).
    
gerou(X, Y) :-
    mae(X, Y).

filho(X, Y) :-
    gerou(Y, X), homem(X).

filha(X, Y) :-
    gerou(Y, X), mulher(X).

tio(X, Y) :-
    filho(X, Z), gerou(Z, W), gerou(W, Y), X \= W.

tia(X, Y) :-
    filha(X, Z), gerou(Z, W), gerou(W, Y), X \= W.

primo(X, Y) :-
   (tio(Z, Y) ; tia(Z, Y)), !, filho(X, Z).

prima(X, Y) :-
   (tio(Z, Y) ; tia(Z, Y)), !, filha(X, Z).

avo(X, Y) :-
    gerou(X, Z), gerou(Z, Y), homem(X).

avoh(X, Y) :-
    gerou(X, Z), gerou(Z, Y), mulher(X).
