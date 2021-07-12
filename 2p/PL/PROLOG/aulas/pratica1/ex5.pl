elfo_domestico(dobby).
bruxo(hermione).
bruxo('McGonagall').
bruxo(rita_skeeter).

magico(X) :- elfodomestico(X).
magico(X) :- feiticeiro(X).
magico(X) :- bruxo(X).

/*  A consulta não foi satisfeita.

?- magico(elfo_domestico).
ERROR: Unknown procedure: feiticeiro/1
ERROR: In:
ERROR:   [11] feiticeiro(elfo_domestico)
ERROR:   [10] magico(elfo_domestico) at c:/users/guilherme/documents/prog/prolog/aulas/pratica1/ex9.pl:7
ERROR:    [9] <user>
 */