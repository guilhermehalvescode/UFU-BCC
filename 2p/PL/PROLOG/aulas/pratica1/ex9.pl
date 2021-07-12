/*  A consulta não foi satisfeita.

?- magico(Hermione).
Hermione = dobby ;
ERROR: Unknown procedure: feiticeiro/1
ERROR: In:
ERROR:   [11] feiticeiro(_8968)
ERROR:   [10] magico(_8992) at c:/users/guilherme/documents/prog/prolog/aulas/pratica1/ex9.pl:7
ERROR:    [9] <user>

 ÁRVORE DE BUSCA:  
 Call: (10) magico(_7252) ? creep
   Call: (11) elfo_domestico(_7252) ? creep
   Exit: (11) elfo_domestico(dobby) ? creep
   Exit: (10) magico(dobby) ? creep
 Hermione = dobby ;
   Redo: (10) magico(_7252) ? creep
   Call: (11) feiticeiro(_7252) ? creep
   ERROR: Unknown procedure: feiticeiro/1
 */