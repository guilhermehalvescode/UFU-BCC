:- module(
        cliente, 
        [ cliente/8 ]).

:- use_module(library(persistency)).
:- use_module(chave, []).

:- persistent 
    cliente(
        cd_cliente:positive_integer,
        endereco_cd_endereco:positive_integer,
        nm_razaosocial:atom,
        nm_fantasia:atom,
        ds_email:atom,
        cod_itendificacao:atom,
        tipo_cliente:atom,
        tp_visivel:boolean
      ).

:- initialization( ( db_attach('./backend/db/tables/tbl_cliente.pl', []),
                    at_halt(db_sync(gc(always))) )).

insere(CdCliente, CdEndereco, NmRazaoSocial, NmFantasia, DsEmail, CodIdentificacao, TipoCliente, TpVis) :-
    with_mutex(clientes,
        (chave:pk(cliente, CdCliente), 
        assert_cliente(CdCliente, CdEndereco, NmRazaoSocial, NmFantasia, DsEmail, CodIdentificacao, TipoCliente, TpVis))).

remove(CdCliente) :- 
    with_mutex(clientes, 
        retract_cliente(CdCliente, _CdEndereco, _NmRazaoSocial, _NmFantasia, _DsEmail, _CodIdentificacao, _TipoCliente, _TpVis)).

atualiza(CdCliente, CdEndereco, NmRazaoSocial, NmFantasia, DsEmail, CodIdentificacao, TipoCliente, TpVis) :-
    with_mutex(clientes,
        retractall_cliente(CdCliente, _CdEndereco, _NmRazaoSocial, _NmFantasia, _DsEmail, _CodIdentificacao, _TipoCliente, _TpVis),
        assert_cliente(CdCliente, CdEndereco, NmRazaoSocial, NmFantasia, DsEmail, CodIdentificacao, TipoCliente, TpVis)).

