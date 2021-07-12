:- module(
    material_servico, 
    [ material_servico/2 ]).

:- use_module(library(persistency)).
:- use_module(chave, []).

:- persistent 
    material_servico(cd_material:positive_integer,
        cd_servico:positive_integer).

arquivo_da_tabela(Arquivo):-
    db_attach(Arquivo, []),
    at_halt(db_sync(gc(always))).

insere(CdServ, CdMat) :-
    with_mutex(matserv, 
        assert_material_servico(CdServ, CdMat)).

remove(CdServ, CdMat) :- 
    with_mutex(matserv, 
        retract_material_servico(CdServ, CdMat)).
