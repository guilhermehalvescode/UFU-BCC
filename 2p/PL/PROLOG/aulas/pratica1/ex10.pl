palavra(artigo,um).
palavra(artigo,qualquer).
palavra(nome,criminoso).
palavra(nome,'mac lanche feliz').
palavra(verbo,come).
palavra(verbo,adora).


sentenca(Palavra1,Palavra2,Palavra3,Palavra4,Palavra5) :-
    palavra(artigo,Palavra1),
    palavra(nome,Palavra2),
    palavra(verbo,Palavra3),
    palavra(artigo,Palavra4),
    palavra(nome,Palavra5).

/* Ex.10  Qual  consulta  deve-se  colocar  a 
 fim  de  encontrar  quais  sentencas  a gramática pode
 gerar? */

% RES: sentenca(P1, P2, P3, P4, P5).