:- module(emprDep, []).

:- use_module(library(persistency)).

:- persistent 
    empresario(id:positive_integer,
        nome:atom,
        departamento:nonneg,
        salario:positive_integer),
    depto(departamento:nonneg,
        nomeDepto:atom,
        id_gerente:positive_integer).

:- initialization(db_attach('tbl_emprEdepto.pl', [])).

insereEmpresario(IdFunc, Nome, Dep, Salario) :-
    with_mutex(key, assert_empresario(IdFunc, Nome, Dep, Salario)).

removeEmpresario(IdFunc) :-
    with_mutex(key, retract_empresario(IdFunc, _Nome, _Dep, _Salario)).

insereDepto(Dep, NomeDep, IdGerente) :-
    emprDep:empresario(IdGerente, _Nome, Dep, _Sal),
    with_mutex(key, assert_depto(Dep, NomeDep, IdGerente)).

sincroniza :-
    db_sync(gc(always)).

%Escreva uma consulta em Prolog 
%respondendo “Que empregados possuem salário 
%superior ao de seu gerente?”
/* 
findall((Empr, Sal), 
    (emprDep:empresario(IdFunc, Empr, Dep, Sal), 
    emprDep:empresario(IdGerente, _NomeGerente, Dep, SalG), 
    emprDep:depto(Dep, _NomeDep, IdGerente), 
    Sal > SalG), L).
 */