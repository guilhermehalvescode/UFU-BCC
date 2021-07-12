:- module(
    funcao, 
    [ funcao/3 ]).

:- use_module(library(persistency)).
:- use_module(chave, []).

:- persistent 
    funcao(cd_funcao:positive_integer,
        ds_funcao:atom,
        tp_visivel:boolean).

:- initialization( ( db_attach('./backend/db/tables/tbl_funcao.pl', []),
    at_halt(db_sync(gc(always))) )).

insere(CdFuncao, Ds_funcao, TpVis) :-
    with_mutex(funcoes, 
        (chave:pk(funcao, CdFuncao),
        assert_funcao(CdFuncao, Ds_funcao, TpVis))).

remove(CdFuncao) :- 
    with_mutex(funcoes, 
        retract_funcao(CdFuncao, _Ds_funcao, _TpVis)).

atualiza(CdFuncao, Ds_funcao, TpVis) :-
    with_mutex(funcoes,
        retractall_funcao(CdFuncao, _Ds_funcao, _TpVis),
        assert_funcao(CdFuncao, Ds_funcao, TpVis)).
 