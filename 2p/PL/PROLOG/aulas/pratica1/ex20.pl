aluno(joao,poo).
aluno(pedro,poo).
aluno(maria,pl).
aluno(rui,pl).
aluno(manuel,pl).
aluno(pedro,pl).
aluno(rui,ed1).

estuda(joao).
estuda(maria).
estuda(manuel).

fazpl(X) :-
    aluno(X, pl),
    estuda(X).

% fazpl(Quem).