:- module(
    estoque, 
    [ estoque/6 ]).

:- use_module(library(persistency)).
:- use_module(chave, []).

:- persistent 
    estoque(cd_estoque:positive_integer,
        cd_func:positive_integer,
        cd_ordem_servico:positive_integer,
        cd_material:positive_integer,
        qnt_soma:nonneg,
        qnt_sub:nonneg).

arquivo_da_tabela(Arquivo):-
    db_attach(Arquivo, []),
    at_halt(db_sync(gc(always))).

insere(CdEst, CdFun, CdOrdemS, CdMat, QntSoma, QntSub) :-
    chave:pk(estoque, CdEst),
        with_mutex(estoques, 
            assert_estoque(CdEst, CdFun, CdOrdemS, CdMat, QntSoma, QntSub)).

remove(CdEst) :- 
    with_mutex(estoques, 
        retract_estoque(CdEst, _, _, _, _, _, _, _, _)).

atualiza(CdEst, CdFun, CdOrdemS, CdMat, QntSoma, QntSub) :-
    with_mutex(estoques,
        retractall_estoque(CdEst, _, _, _, _, _, _, _, _),
        assert_estoque(CdEst, CdFun, CdOrdemS, CdMat, QntSoma, QntSub)).
