/* max(X,Y,Y):- X =< Y.
max(X,Y,X):- X>Y. */

%corte verde
/* max(X,Y,Y):- X =< Y, !.
max(X,Y,X):- X>Y. */

%corte vermelho
max(X,Y,Y):- X =< Y, !.
max(X,_,X).