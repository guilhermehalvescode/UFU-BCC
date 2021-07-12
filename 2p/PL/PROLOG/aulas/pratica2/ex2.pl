prova(Formula) :-
    prova(Formula, Resposta),
    Resposta = verdade.

prova(verdade, verdade).
prova(falso, falso).

prova(nao(falso), verdade).
prova(nao(verdade), falso).
prova(nao(A), Resposta) :-
    prova(A, RespostaA),
    (RespostaA = verdade, Resposta = falso;
    RespostaA = falso, Resposta = verdade).

prova(e(falso, falso), falso).
prova(e(falso, verdade), falso).
prova(e(verdade, falso), falso).
prova(e(verdade, verdade), verdade).
prova(e(A, B), Resposta) :-
    (prova(A, RespostaA),
    prova(B, RespostaB)),
    ((RespostaA = verdade, RespostaB = verdade, Resposta = verdade);
    Resposta = falso).

prova(ou(falso, falso), falso).
prova(ou(falso, verdade), verdade).
prova(ou(verdade, falso), verdade).
prova(ou(verdade, verdade), verdade).
prova(ou(A, B), Resposta) :-
    (prova(A, RespostaA),
    prova(B, RespostaB)),
    ((RespostaA = verdade, RespostaB = verdade, Resposta = verdade;
    RespostaA = falso, RespostaB = verdade, Resposta = verdade;
    RespostaA = verdade, RespostaB = falso, Resposta = verdade);
    Resposta = falso).

prova(impl(falso, falso), verdade).
prova(impl(falso, verdade), verdade).
prova(impl(verdade, falso), falso).
prova(impl(verdade, verdade), verdade).
prova(impl(A, B), Resposta) :-
    (prova(A, RespostaA),
    prova(B, RespostaB)),
    ((RespostaA = verdade, RespostaB = verdade, Resposta = verdade;
    RespostaA = falso, RespostaB = verdade, Resposta = verdade;
    RespostaA = falso, RespostaB = falso, Resposta = verdade);
    Resposta = falso).

prova(equiv(falso, falso), verdade).
prova(equiv(falso, verdade), falso).
prova(equiv(verdade, falso), falso).
prova(equiv(verdade, verdade), verdade).
prova(equiv(A, B), Resposta) :-
    (prova(A, RespostaA),
    prova(B, RespostaB)),
    (RespostaA = verdade, RespostaB = verdade, Resposta = verdade;
    RespostaA = falso, RespostaB = verdade, Resposta = falso;
    RespostaA = falso, RespostaB = falso, Resposta = verdade;
    RespostaA = verdade, RespostaB = falso, Resposta = falso).