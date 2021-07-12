/*  Ex.1  Estender o programa Prolog para incluir os relacionamentos
 mother, man e woman.

 professor escolhi o termo parent, pois esse tem como significado
 a pessoa que tem um filho, independente de seu sexo.
 */
woman(ana).
woman(juliana).
woman(paula).
woman(fernanda).
woman(roberta).
woman(leticia).
woman(rubiula).
woman(barbie).

man(felipe).
man(joao).
man(cleber).
man(carlos).
man(antonio).
man(jefferson).

parent(cleber, paula).
parent(cleber, leticia).
parent(joao, carlos).
parent(joao, antonio).
parent(antonio, jefferson).
parent(antonio, barbie).

parent(carlos, ana).
parent(carlos, felipe).
parent(carlos, juliana).

parent(fernanda, paula).
parent(fernanda, leticia).
parent(roberta, carlos).
parent(roberta, antonio).
parent(rubiula, jefferson).
parent(rubiula, barbie).
parent(paula, ana).
parent(paula, felipe).
parent(paula, juliana).

father(X, Y) :- 
    man(X),
    parent(X, Y).

mother(X, Y) :- 
    woman(X), 
    parent(X, Y).
