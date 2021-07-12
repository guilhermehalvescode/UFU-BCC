:- module(
    chave,
    [ pk/2 ]
).

:- use_module(library(persistency)).


:- persistent
    chave(nome:atom,
          valor:positive_integer).


:- initialization( ( db_attach('./backend/db/tables/tbl_chave.pl', []),
                    at_halt(db_sync(gc(always))) )).


pk(Nome, Valor):-
  with_mutex(Nome,
              ( (chave(Nome, ValorAtual) ->
                    ValorAntigo = ValorAtual;
                    ValorAntigo = 0),
                Valor is ValorAntigo + 1,
                retractall_chave(Nome,_), 
                assert_chave(Nome, Valor)) ). 
