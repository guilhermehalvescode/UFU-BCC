:- module(
    ordem_servico, 
    [ ordem_servico/6 ]).

:- use_module(library(persistency)).
:- use_module(chave, []).

:- persistent 
    ordem_servico(cd_ordem_servico:positive_integer,
        funcionario_cd_funcionario:positive_integer,
        cliente_cd_cliente:positive_integer,
        dt_ordem_servico:atom,
        vl_total:nonneg,
        bool_fechado:boolean).

arquivo_da_tabela(Arquivo):-
    db_attach(Arquivo, []), 
    at_halt(db_sync(gc(always))).

insere(CdOrderS, CdFunc, CdClient, Desc, Valor, Fechado) :-
    chave:pk(ordem_servico, CdOrderS),
    with_mutex(ordem_servicos, 
        assert_ordem_servico(CdOrderS, CdFunc, CdClient, Desc, Valor, Fechado)).

remove(CdOrdemS, CdFun) :- 
    with_mutex(ordem_servicos, 
        retract_ordem_servico(CdOrdemS, CdFun, _CdClient, _Desc, _Valor, _Fechado)).

atualiza(CdOrderS, CdFunc, CdClient, Desc, Valor, Fechado) :-
    with_mutex(ordem_servicos,
        retractall_ordem_servico(CdOrderS, _CdFunc, _CdClient, _Desc, _Valor, _Fechado),
        assert_ordem_servico(CdOrderS, CdFunc, CdClient, Desc, Valor, Fechado)).

