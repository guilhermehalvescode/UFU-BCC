:- module(
    endereco, 
    [ endereco/9 ]).

:- use_module(library(persistency)).
:- use_module(chave, []).

:- persistent 
    endereco(cd_endereco:positive_integer,
        nm_rua:atom,
        nr_casa:positive_integer,
        ds_complemento:atom,
        nm_bairro:atom,
        nm_cidade:atom,
        ds_cep:atom,
        tel1:atom,
        tem2:atom).

arquivo_da_tabela(Arquivo):-
    db_attach(Arquivo, []),
    at_halt(db_sync(gc(always))).

insere(CdEnd, Nm_rua, Nr_casa, Complemento, Nm_bairro, 
        Nm_cidade, Cep, Tel1, Tel2) :-
    chave:pk(endereco, CdEnd),
        with_mutex(enderecos, 
            assert_endereco(CdEnd, Nm_rua, Nr_casa, Complemento, Nm_bairro, Nm_cidade, Cep, Tel1, Tel2)).

remove(CdEnd) :- 
    with_mutex(enderecos, 
        retract_endereco(CdEnd, _, _, _, _, _, _, _, _)).

atualiza(CdEnd, Nm_rua, Nr_casa, Complemento, Nm_bairro, 
        Nm_cidade, Cep, Tel1, Tel2) :-
    with_mutex(enderecos,
        retractall_endereco(CdEnd, _, _, _, _, _, _, _, _),
        assert_endereco(CdEnd, Nm_rua, Nr_casa, Complemento, Nm_bairro, 
            Nm_cidade, Cep, Tel1, Tel2)).
