:- module(
    chave,
    [ pk/2,
      inicia_pk/2 ]
).

:- use_module(library(persistency)).


:- persistent
    chave(nome:atom,
          valor:positive_integer).


:- initialization((db_attach('./db/tables/tbl_chave.pl', []), 
                  at_halt(db_sync(gc(always))))).


pk(Nome, Valor):-
  with_mutex(Nome,
              ( (chave(Nome, ValorAtual) ->
                    ValorAntigo = ValorAtual;
                    ValorAntigo = 0),
                Valor is ValorAntigo + 1,
                retractall_chave(Nome,_), % remove o valor antigo
                assert_chave(Nome, Valor)) ). % atualiza com o novo

% Talvez você queira um valor inicial diferente de 1

inicia_pk(Nome, ValorInicial):-
  with_mutex(Nome,
            (chave(Nome, _) ->
                true; % Não inicializa caso a chave já exista
                assert_chave(Nome, ValorInicial)) ).