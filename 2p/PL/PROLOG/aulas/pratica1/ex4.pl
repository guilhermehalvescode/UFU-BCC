/*  Ex.4  Escreva regras para os relacionamentos
 filho, filha ,irmao, irma, irmaos, tio, tia, 
 primo,prima e avó. */


%definição de filho
filho(X, Y) :-
    man(X),
    parent(Y, X).

%definição de filha
filha(X, Y) :-
    woman(X),
    parent(Y, X).

%definição de irmao
irmao(X, Y) :-
    filho(X, Z),
    parent(Z, Y),
    dif(X, Y).

%definição de irmã
irma(X, Y) :-
    filha(X, Z),
    parent(Z, Y),
    dif(X, Y).

%definição de irmãos
irmaos(X, Y) :- 
    parent(Z, X), 
    parent(Z, Y),
    dif(X, Y).

%definição de tio
tio(X, Y) :-
    irmao(X, Z),
    parent(Z, Y).


%definição de tia
tia(X, Y) :-
    irma(X, Z),
    parent(Z, Y).

%definição de primo
primo(X, Y) :-
    man(X),
    tio(Z, X),
    parent(Z, Y).

primo(X, Y) :-
    man(X),
    tia(Z, X),
    parent(Z, Y).

%definição de prima
prima(X, Y) :-
    woman(X),
    tio(Z, X),
    parent(Z, Y).

prima(X, Y) :-
    woman(X),
    tia(Z, X),
    parent(Z, Y).
%definição de avó
avoM(X, Y) :-
    mother(X, Z),
    parent(Z, Y).