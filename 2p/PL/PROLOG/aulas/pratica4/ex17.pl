/* 
classe(Numero, positivo) :- Numero >= 0.
classe(Numero, negativo) :- Numero < 0.

divide([], [], []).

divide([X|Xs], [X|Ps], N) :-
    classe(X, positivo),
    divide(Xs, Ps, N).

divide([X|Xs], P, [X|Ns]) :-
    classe(X, negativo),
    divide(Xs, P, Ns). 
*/

%Agora usando o corte

classe(Numero, positivo) :- Numero >= 0, !.
classe(Numero, negativo) :- Numero < 0.

divide([], [], []).

divide([X|Xs], [X|Ps], N) :-
    classe(X, positivo), !,
    divide(Xs, Ps, N).

divide([X|Xs], P, [X|Ns]) :-
    classe(X, negativo),
    divide(Xs, P, Ns).

