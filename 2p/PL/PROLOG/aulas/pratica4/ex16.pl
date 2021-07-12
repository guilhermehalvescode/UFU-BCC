/* classe(Numero,positivo) :- Numero > 0.
classe(0,zero).
classe(Numero,negativo) :- Numero < 0.
 */
% o programa verifica se um numero é positivo ou negativo ou zero.

%programa melhorado
classe(Numero,positivo) :- Numero > 0, !.
classe(0,zero) :- !.
classe(Numero,negativo) :- Numero < 0.