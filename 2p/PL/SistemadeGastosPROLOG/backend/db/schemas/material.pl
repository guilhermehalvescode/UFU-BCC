:- module(
    material, 
    [ material/3 ]).

:- use_module(library(persistency)).
:- use_module(chave, []).

:- persistent 
    material(cd_material:positive_integer,
        nm_material:atom,
        tp_visivel:boolean).

arquivo_da_tabela(Arquivo):-
    db_attach(Arquivo, []),
    at_halt(db_sync(gc(always))).

insere(CdMat, Nome, TpVis) :-
    chave:pk(material, CdMat),
    with_mutex(materiais, 
        assert_material(CdMat, Nome, TpVis)).

remove(CdMat) :- 
    with_mutex(materiais, 
        retract_material(CdMat, _Nome, _TpVis)).

atualiza(CdMat, Nome, TpVis) :-
    with_mutex(materiais,
        retractall_material(CdMat, _Nome, _TpVis),
        assert_material(CdMat, Nome, TpVis)).

listar(Lista) :-
    findall(Nome, 
        material:material(_CdFuncao, Nome, _TpVis), Lista).
 