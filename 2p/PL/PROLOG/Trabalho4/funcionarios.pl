:- load_files(db, [if(not_loaded), silent(true)]).

:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/html_write)).
:- use_module(library(http/http_parameters)).
:- use_module(library(http/html_head)).
:- use_module(library(http/http_server_files)).

server(Port) :- 
    http_server(http_dispatch, [port(Port)]).

:- initialization(server(8000)).


:- http_handler(css(.), serve_files_in_directory(css), [prefix]).
:- http_handler(root(.), home, []).
:- http_handler(root(cadfun), cadastro(Method), [
                    method(Method), 
                    methods([post])]).

home(_Pedido) :-
    reply_html_page([\html_root_attribute(lang, 'pt-BR'), \metas, \links, title('Controle de Gastos de Clientes | Funcionario')], 
                    [\navbar, \page, \scripts]).

cadastro(post, Pedido) :- 
    reply_html_page([title('Controle de Gastos de Clientes | Funcionario')],
                    [\resposta(Pedido)]).

resposta(Pedido) -->
    {
        catch(
            http_parameters(Pedido, [
                nome(Nome, [atom, length > 0]),
                user(User, [atom, length > 0]),
                password(Pass, [atom, length > 0]),
                func(Func, [number, integer]),
                address(Rua, [atom, length > 0]),
                addressnum(Numrua, [number, integer]),
                comp(Complemento, [atom, length > 0]),
                bairro(Bairro, [atom, length > 0]),
                city(City, [atom, length > 0]),
                cep(Cep, [atom, length > 0]),
                tel1(Tel1, [atom, length > 0]),
                tel2(Tel2, [atom, length > 0])
            ]), 
        _E, fail), !,
        (funcao:funcao(Func, Dsfun, true),
        cadastra_funcionario(CdFun, Nome, User, Pass, Func, Rua, Numrua, 
            Complemento, Bairro, City, Cep, Tel1, Tel2))
    },
    html([
        p('Seu codigo e ~w' - CdFun),
        p('Seu nome e ~w' - Nome),
        p('Seu usuario e ~w' - User),
        p('Sua senha e ~w' - Pass),
        p('Sua funcao e ~w' - Dsfun),
        p('Seu endereco e ~w, ~w' - [Rua, Numrua]),
        p('O complemento e ~w' - Complemento),
        p('Sua cidade e ~w' - City),
        p('Seu bairro e ~w' - Bairro),
        p('Seu CEP e ~w' - Cep),
        p('Seu primeiro telefone e ~w' - Tel1),
        p('Seu segundo telefone e ~w' - Tel2)
        ]).

resposta(_Pedido) -->
    html([h1('Erro'),
        p('Formulario com parametros errados!')
        ]).

metas -->
    html(meta([name(viewport), content('width=device-width, initial-scale=1.0, shrink-to-fit=no')], [])).

links -->
    html([link([rel(stylesheet), href('https://cdn.jsdelivr.net/npm/reset-css@5.0.1/reset.min.css')], []),
    link([rel(stylesheet), href('https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css'), 
    integrity('sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z'), crossorigin('anonymous')], []),
    \html_requires(css('cadastro.css'))]).

navbar --> 
    html(nav([class('navbar navbar-expand-lg navbar-light bg-light')], 
    [button([class('navbar-toggler'), type(button), 'data-toogle'(collapse), 'data-target'('#header'), 'aria-controls'(header),
    'aria-expanded'(false), 'aria-label'('Toggle navigation')], [span([class('navbar-toggler-icon')], [])]), 
    div([class('collapse navbar-collapse'), id(header)],
    [div([class('navbar-nav')], 
    [a([class('nav-link'), href('./cadastros')], ['Cadastros']), 
     a([class('nav-link'), href('./material')], ['Material']), 
     a([class('nav-link'), href('./ordemservico')], ['Ordem de Servico']), 
     a([class('nav-link'), href('./consultas')], ['Consultas']), 
     a([class('nav-link'), href('./sobre')], ['Sobre']), 
     a([class('nav-link'), href('./ajuda')], ['Ajuda'])
    ])])])).

page -->
    html(div([class('main-content')],
            [h5('Funcionario'), 
            \navpage,
            div([class('row info')], [
                div([class('col-lg-10 col-md-10')], [
                    div([class(search)], [
                        form([method(get)], [
                            label([for(type)], 'Pesquisar: '),
                            select([name(type), id(type)], [
                                option([value(material)], 'Funcionario'),
                                option([value(estoque)], 'Usuario'),
                                option([value(servico)], 'Funcao')
                            ]),
                            input([type(text)], []),
                            input([type(button), value('Buscar')], [])
                        ])
                    ]),
                    form([method('post'), action('/cadfun')], [
                        div([class('form-group')], [
                            label([for(nome)], 'Nome'),
                            input([name(nome), type(text), class('form-control'), id(nome), placeholder('')], [])
                        ]),
                        div([class('form-group')], [
                            label([for(usuario)], 'Usuario'),
                            input([name(user) ,type(text), class('form-control'), id(usuario), placeholder('')], [])
                        ]),
                        div([class('form-group')], [
                            label([for(senha)], 'Senha'),
                            input([name(password), type(password), class('form-control'), id(senha), placeholder('')], [])
                        ]),
                        div([class('form-group')], [
                            label([for(inputState)], 'Funcao'),
                            select([name(func), id('inputState'), class('form-control')], [
                                option([value(1), selected], 'Administrador'),
                                option([value(2)], 'Balconista'),
                                option([value(3)], 'Bolsista'),
                                option([value(4)], 'Gerente'),
                                option([value(5)], 'Motoboy')
                            ]),
                            hr([]),
                            div([class(row)], [
                                div([class(col)], [
                                    label([for(rua)], 'Rua'),
                                    input([name(address), type(text), class('form-control'), id(rua), placeholder('')], [])
                                ]),
                                div([class(col)], [
                                    label([for(numero)], 'Numero'),
                                    input([name(addressnum) ,type(number), class('form-control'), id(numero), placeholder('')], [])
                                ])
                            ]),
                            label([for(complemento)], 'Complemento'),
                            input([name(comp), type(text), class('form-control'), id(complemento), placeholder('')], []),
                            div([class(row)], [
                                div([class(col)], [
                                    label([for(bairro)], 'Bairro'),
                                    input([name(bairro), type(text), class('form-control'), id(bairro), placeholder('')], [])
                                ]),
                                div([class(col)], [
                                    label([for(cidade)], 'Cidade'),
                                    input([name(city), type(text), class('form-control'), id(cidade), placeholder('')], [])
                                ])
                            ]),
                            div([class(row)], [
                                div([class(col)], [
                                    label([for(cep)], 'CEP'),
                                    input([name(cep), type(text), class('form-control'), id(cep), placeholder('')], [])
                                ])
                            ]),
                            div([class(row)], [
                                div([class(col)], [
                                    label([for(telefone1)], 'Telefone 1'),
                                    input([name(tel1), type(text), class('form-control'), id(telefone1), placeholder('')], [])
                                ]),
                                div([class(col)], [
                                    label([for(telefone2)], 'Telefone 2'),
                                    input([name(tel2), type(text), class('form-control'), id(telefone2), placeholder('')], [])
                                ])
                            ])
                        ]),
                        button([type(submit), class('btn btn-light')], 'Submit')
                    ])
                ]),
                \buttons
            ])])).

navpage --> 
    html(nav([class('navbar navbar-expand-lg navbar-light bg-light')], 
    [button([class('navbar-toggler'), type(button), 'data-toogle'(collapse), 'data-target'('#page'), 'aria-controls'(page),
    'aria-expanded'(false), 'aria-label'('Toggle navigation')], [span([class('navbar-toggler-icon')], [])]), 
    div([class('collapse navbar-collapse'), id(page)],
    [div([class('navbar-nav')], 
    [a([class('nav-link'), href('./relatorio')], ['Relatorio']), 
     a([class('nav-link'), href('./cadastro')], ['Cadastro']) 
    ])])])).

buttons --> 
    html(div([class('buttons col-lg-2 col-md-2 lado')], [
        button([class('btn btn-light'), disabled(disabled)], 'Confirmar'),
        button([class('btn btn-light'), disabled(disabled)], 'Cancelar'),
        button([class('btn btn-light')], '+ Incluir'),
        button([class('btn btn-light')], 'Alterar'),
        button([class('btn btn-light')], '- Excluir'),
        button([class('btn btn-light')], '? Ajudar')
    ])).

scripts -->
    html([script([src('https://code.jquery.com/jquery-3.5.1.slim.min.js'), 
                  integrity('sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj'),
                  crossorigin('anonymous')], []), 
    script([src('https://cdn.jsdelivr.net/npm/popper.js@1.16.1/dist/umd/popper.min.js'), 
                  integrity('sha384-9/reFTGAW83EW2RDu2S0VKaIzap3H66lZH81PoYlFhbGU+6BZp6G7niu735Sk7lN'),
                  crossorigin('anonymous')], []), 
    script([src('https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js'), 
                  integrity('sha384-B4gt1jrGC7Jh4AgTPSdUtOBvfO8shuf57BaghqFfPlYxofvL8/KUEfYiJOMMV+rV'),
                  crossorigin('anonymous')], [])]).