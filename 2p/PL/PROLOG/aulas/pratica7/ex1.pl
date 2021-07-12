:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/html_write)).
:- use_module(library(http/http_parameters)).

server(Port) :- 
    http_server(http_dispatch, [port(Port)]).


:- http_handler(root(.), home, []).
:- http_handler(root(formulario), formulario(Method), [
                    method(Method), 
                    methods([post])]).

home(_Pedido) :-
    reply_html_page([title('Formulario')], 
                    [\page]).

formulario(post, Pedido) :- 
    reply_html_page([title('RespostaForm')],
                    [\resposta(Pedido)]).
        
page -->
    html([h1('Formulario'), 
        form([action('/formulario'), method('POST'), style('display:flex; flex-direction:column; width:20%')], 
        [input([type(number), name(id), id(integer), min(1), placeholder('Digite um inteiro'), required],[]), 
        input([type(text), name(nome), id(text), placeholder('Digite um texto'), required], []),
        input([type(number), name(idade), id(integer), min(1), placeholder('Digite uma idade'), required], []),
        button([type(submit)], ['Enviar'])])]).

resposta(Pedido) -->
    {
        catch(
            http_parameters(Pedido,
                [id(Id, [integer]),
                nome(Nome, [string]),
                idade(Idade, [integer])
            ]), 
        _E, fail), !     
    },
    html([
        p('Id e ~w' - Id),
        p('Texto e ~w' - Nome),
        p('Idade e ~w' - Idade)
        ]).

resposta(_Pedido) -->
    html([h1('Erro'),
        p('Formulario com parametros errados!')
        ]).