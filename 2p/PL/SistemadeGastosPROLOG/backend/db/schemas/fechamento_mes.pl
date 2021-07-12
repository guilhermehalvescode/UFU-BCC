:- module(
        fechamento_mes, 
        [ fechamento_mes/9 ]).

:- use_module(library(persistency)).
:- use_module(chave, []).

:- persistent 
    fechamento_mes(
        cd_fechamento_mes:positive_integer,
        cliente_cd_cliente:positive_integer,
        dt_emissao:atom,
        vl_emissao:atom,
        vl_juros:atom,
        dt_pagamento:atom,
        pago:boolean,
        nr_notafiscal:atom,
        boll_fechado:boolean
      ).

arquivo_da_tabela(Arquivo):-
    db_attach(Arquivo, []),
    at_halt(db_sync(gc(always))).

insere(CdFechamentoMes, CdCliente, DtEmissao, VlMensal, VlJuros, DtPagamento, Pago, NrNotafiscal, BoolFechado) :-
    chave:pk(fechamento_mes, CdFechamentoMes),
    with_mutex(fechamento_mess, 
        assert_fechamento_mes(CdFechamentoMes, CdCliente, DtEmissao, VlMensal, VlJuros, DtPagamento, Pago, NrNotafiscal, BoolFechado)).

remove(CdFechamentoMes) :- 
    with_mutex(fechamento_mess, 
        retract_fechamento_mes(CdFechamentoMes, _CdCliente, _DtEmissao, _VlMensal, _VlJuros, _DtPagamento, _Pago, _NrNotafiscal, _BoolFechado)).

atualiza(CdFechamentoMes, CdCliente, DtEmissao, VlMensal, VlJuros, DtPagamento, Pago, NrNotafiscal, BoolFechado) :-
    with_mutex(fechamento_mess,
        retractall_fechamento_mes(CdFechamentoMes, _CdCliente, _DtEmissao, _VlMensal, _VlJuros, _DtPagamento, _Pago, _NrNotafiscal, _BoolFechado),
        assert_fechamento_mes(CdFechamentoMes, CdCliente, DtEmissao, VlMensal, VlJuros, DtPagamento, Pago, NrNotafiscal, BoolFechado)).