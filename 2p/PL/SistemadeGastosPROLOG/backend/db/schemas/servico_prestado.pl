:- module(
    servico_prestado, 
    [ servico_prestado/8 ]).

:- use_module(library(persistency)).
:- use_module(chave, []).

:- persistent 
   servico_prestado(cd_serv_prestado:positive_integer,
        cd_servico:positive_integer,
        cd_funcionario:positive_integer,
        cd_ordem_servico:positive_integer,
        qtd:nonneg,
        qtd_por_material:nonneg,
        val_total:nonneg,
        val_unitario:nonneg).

arquivo_da_tabela(Arquivo):-
    db_attach(Arquivo, []),
    at_halt(db_sync(gc(always))).

insere(CdServP, CdServ, CdFun, CdOrdemS, Qnt, VlUnit, VlTot, QntMat) :-
    chave:pk(servico_prestado, CdServP),
    with_mutex(servico_prestados, 
        assert_servico_prestado(CdServP, CdServ, CdFun, CdOrdemS, Qnt, VlUnit, VlTot, QntMat)).

remove(CdServP) :- 
    with_mutex(servico_prestados, 
        retract_servico_prestado(CdServP, _, _, _, _, _, _, _)).

atualiza(CdServP, CdServ, CdFun, CdOrdemS, Qnt, VlUnit, VlTot, QntMat) :-
    with_mutex(servico_prestados,
        retractall_servico_prestado(CdServP, _, _, _, _, _, _, _),
        assert_servico_prestado(CdServP, CdServ, CdFun, CdOrdemS, Qnt, VlUnit, VlTot, QntMat)).