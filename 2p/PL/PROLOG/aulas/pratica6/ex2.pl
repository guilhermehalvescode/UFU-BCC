:- module(paises, []).

:- use_module(library(persistency)).

:- persistent
    pais(id:positive_integer,
        nome:atom,
        id_mar:nonneg),
    mar(id:nonneg,
        nome:atom),
    populacao(id:positive_integer,
        quantidade:atom),
    fronteira(id:positive_integer,
        id_pais:positive_integer).

:- initialization(db_attach('tbl_paises.pl', [])).

/* 
%
Que país, banhado pelo mediterrâneo, faz fronteira com um 
país que faz fronteira com um país cuja população excede a 
população da Índia?
findall(Pais, (paises:pais(IdPais, Pais, IdMar), 
    paises:mar(IdMar, mediterrâneo), %Um pais do banhado pelo mediterraneo
    paises:fronteira(IdPais, Z), %Que faz fronteira com Z
    paises:fronteira(Z, IdOutro), %Que Z faz fronteira com outro
    paises:populacao(IdOutro, PopOutro), %Que a população desse outro
    paises:pais(IdIndia, india, _IdMar), %Seja maior que
    paises:populacao(IdIndia, PolIndia), %A população 
    PopOutro > PopIndia), Qual). %Da Índia
 */