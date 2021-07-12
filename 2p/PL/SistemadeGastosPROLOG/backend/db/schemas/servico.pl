:- module(
    servico, 
    [ servico/3 ]).

:- use_module(library(persistency)).
:- use_module(chave, []).

:- persistent 
    servico(cd_servico:positive_integer,
        nm_servico:atom,
        tp_visivel:boolean).

arquivo_da_tabela(Arquivo):-
    db_attach(Arquivo, []),
    at_halt(db_sync(gc(always))).

insere(CdServ, Nome, TpVis) :-
    chave:pk(servico, CdServ),
    with_mutex(servicos, 
        assert_servico(CdServ, Nome, TpVis)).

remove(CdServ) :- 
    with_mutex(servicos, 
        retract_servico(CdServ, _Nome, _TpVis)).

atualiza(CdServ, Nome, TpVis) :-
    with_mutex(servicos,
        retractall_servico(CdServ, _Nome, _TpVis),
        assert_servico(CdServ, Nome, TpVis)).

listar(Lista) :-
    findall(Nome, 
        servico:servico(_CdFuncao, Nome, _TpVis), Lista).
 