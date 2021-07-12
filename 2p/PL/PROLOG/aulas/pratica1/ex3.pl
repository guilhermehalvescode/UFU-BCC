/*  Ex.3  Escrever em Prolog as seguintes consultas:
 •Quem sao os netos de Joao? RES: grandfather(joao, Y).
 •Juliana e Ana tem o mesmo pai? RES: father(X, ana), father(X, juliana).
 */

% definição de avô
avo(X, Y) :-
    father(X, Z),
    parent(Z, Y).