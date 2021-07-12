:- module(
        funcionario, 
        [ funcionario/7 ]).

:- use_module(library(persistency)).
:- use_module(chave, []).

:- persistent 
    funcionario(cd_funcionario:positive_integer,
        funcao_cd_funcao:positive_integer,
        endereco_cd_endereco:positive_integer,
        nm_funcionario:atom,
        ds_senha:atom,
        nick:atom,
        tp_visivel:boolean).

arquivo_da_tabela(Arquivo):-
    db_attach(Arquivo, []),
    at_halt(db_sync(gc(always))).

insere(CdFun, CdFuncao, CdEnd, Nome, Senha, Nick, TpVis) :-
    chave:pk(funcionario, CdFun),
    with_mutex(funcionarios, 
        assert_funcionario(CdFun, CdFuncao, CdEnd, Nome, Senha, Nick, TpVis)).

remove(CdFun) :- 
    with_mutex(funcionarios, 
        retract_funcionario(CdFun, _CdFuncao, _CdEnd, _Nome, _Senha, _Nick, _TpVis)).

atualiza(CdFun, CdFuncao, CdEnd, Nome, Senha, Nick, TpVis) :-
    with_mutex(funcionarios,
        retractall_funcionario(CdFun, _CdFuncao, _CdEnd, _Nome, _Senha, _Nick, _TpVis),
        assert_funcionario(CdFun, CdFuncao, CdEnd, Nome, Senha, Nick, TpVis)).