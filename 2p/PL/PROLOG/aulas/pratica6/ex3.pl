:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/html_write)).

:- multifile http:location/3.
:- dynamic http:location/3.

http:location(minha, '/minha', []).

server(Port) :-
    http_server(http_dispatch, [port(Port)]).

:- http_handler(minha(pagina), my_page, []).

my_page(_Req) :-
    reply_html_page(
        [title('Uma Página HTML com tabela')], 
            [h1('Como escrever uma página web'),
            p('Começe pelo início, desenvolva o
                meio e termine no fim'),
            p('Escreva sites para pessoas famosas:'),
            table([tr([th('Nome'), th('Sobrenome'), th('Cidade')]),
                    tr([td('Roberto'), td('Carlos Braga'), td('Cachoeiro de Itapemirim')]),
                    tr([td('Fernanda'), td('Barbosa'), td('Serra do Navio')]),
                    tr([td('Davi Alexandre'), td('Magalhães de Almeida'), td('Ribeirão Preto')])]),
            footer(p('Autor: seu nome aqui!'))]
        ).