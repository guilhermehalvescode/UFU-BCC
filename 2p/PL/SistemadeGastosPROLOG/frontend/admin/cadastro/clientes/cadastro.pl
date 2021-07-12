:- use_module(library(http/html_write)).
:- use_module(library(http/html_head)).

:- ensure_loaded(temp(bootstrap)).
:- use_module('./backend/db/schemas/cliente.pl').
:- use_module('./backend/db/schemas/endereco.pl').

clientesCadastro(post, Pedido):-
    reply_html_page(
        bootstrap,
        [ \metasCadCliente, \linksCadCliente, title('Controle de Gastos de Clientes | Cliente')],
        [ \navbarCadCliente, \pageCadCliente(Pedido) ]).

clientesCadastro(get, _Pedido):-
    reply_html_page(
        bootstrap,
        [ \metasCadCliente, \linksCadCliente, title('Controle de Gastos de Clientes | Cliente')],
        [ \navbarCadCliente, \pageCadCliente ]).

metasCadCliente -->
    html(meta([name(viewport), content('width=device-width, initial-scale=1.0, shrink-to-fit=no')], [])).
    
linksCadCliente -->
    html([link([rel(stylesheet), href('https://cdn.jsdelivr.net/npm/reset-css@5.0.1/reset.min.css')], []),
    link([rel(stylesheet), href('https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css'), 
    integrity('sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z'), crossorigin('anonymous')], []),
    link([rel(stylesheet), href('/css/admin/cadastros/clientes/cadastro.css')], [])]).

navbarCadCliente --> 
    html(nav([class('navbar navbar-expand-lg navbar-light bg-light')], 
    [button([class('navbar-toggler'), type(button), 'data-toogle'(collapse), 'data-target'('#header'), 'aria-controls'(header),
    'aria-expanded'(false), 'aria-label'('Toggle navigation')], [span([class('navbar-toggler-icon')], [])]), 
    div([class('collapse navbar-collapse'), id(header)],
    [div([class('navbar-nav')], [
        a([class('nav-link active'), href('/admin/cadastros/funcionarios')], ['Cadastros']), 
        a([class('nav-link'), href('/admin/material')], ['Material']), 
        a([class('nav-link'), href('/admin/serviceorder')], ['Ordem de Servico']), 
        a([class('nav-link'), href('/admin/consultas')], ['Consultas']), 
        a([class('nav-link'), href('/admin/about')], ['Sobre']), 
        a([class('nav-link'), href('/admin/help')], ['Ajuda'])
    ])])])).

pageCadCliente(Pedido) -->
    {
        catch(
            http_parameters(Pedido, [
                rzsocial(Rzsocial, [atom, length > 0]),
                nome(Nome, [atom, length > 0]),
                type(Tipo, [atom, length > 0]),
                cod(Cnpj, [atom, length > 0]),
                email(Email, [atom, length > 0]),
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
        cadastra_cliente(CdCliente, Rzsocial, Nome, Tipo, Cnpj, Email, Rua, Numrua, 
            Complemento, Bairro, City, Cep, Tel1, Tel2)
    },
    html(div([class('main-content')],
            [h5('Cliente'), 
            \navpageCadCliente,
            div([class('row info')], [
                div([class('col-lg-10 col-md-10')], [
                    div([class(dropdown), style('padding: 20px 0 0;')], [
                        button([class('btn btn-secondary dropdown-toogle'), type(button), id('dropdownMenuButton'), 'data-toggle'(dropdown)], 'Clientes'),
                        div([class('dropdown-menu')], [
                            a([class('dropdown-item'), href('/admin/cadastros/funcionarios')], 'Funcionarios'),
                            a([class('dropdown-item'), href('/admin/cadastros/clientes')], 'Clientes'),
                            a([class('dropdown-item'), href('/admin/cadastros/funcoes')], 'Funcoes')
                        ])
                    ]),
                    h6('Cadastro Realizado com sucesso!'),
                    h6('O codigo cadastrado e ~w!' - CdCliente),
                    form([method('post'), action('./cadastro')], [
                        div([class('form-group')], [
                            label([for(rzsocial)], 'Razao Social'),
                            input([name(rzsocial), type(text), class('form-control'), id(rzsocial), placeholder('')], [])
                        ]),
                        div([class('form-group')], [
                            label([for(nome)], 'Nome'),
                            input([name(nome), type(text), class('form-control'), id(nome), placeholder('')], [])
                        ]),
                        div([class('form-group')], [
                            label([for(usuario)], 'Tipo Pessoa'),
                            select([name(type)], [
                                option([value(juridica)], 'Juridica'),
                                option([value(fisica)], 'Fisica')
                            ])
                        ]),
                        div([class('form-group')], [
                            label([for(cod)], 'CNPJ/CPF'),
                            input([name(cod), type(text), class('form-control'), id(cod), placeholder('')], [])
                        ]),
                        div([class('form-group')], [
                            label([for(inputState)], 'E-mail'),
                            input([name(email), type(email), class('form-control'), id(inputState), placeholder('')], []),
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
                \buttonsCadCliente
            ])])).

pageCadCliente(_Pedido) -->
    html(div([class('main-content')],
            [h5('Cliente'), 
            \navpageCadCliente,
            div([class('row info')], [
                div([class('col-lg-10 col-md-10')], [
                    div([class(dropdown), style('padding: 20px 0 0;')], [
                        button([class('btn btn-secondary dropdown-toogle'), type(button), id('dropdownMenuButton'), 'data-toggle'(dropdown)], 'Clientes'),
                        div([class('dropdown-menu')], [
                            a([class('dropdown-item'), href('/admin/cadastros/funcionarios')], 'Funcionarios'),
                            a([class('dropdown-item'), href('/admin/cadastros/clientes')], 'Clientes'),
                            a([class('dropdown-item'), href('/admin/cadastros/funcoes')], 'Funcoes')
                        ])
                    ]),
                    h5('Nao foi possivel realizar o cadastro!'),
                    form([method('post'), action('./cadastro')], [
                        div([class('form-group')], [
                            label([for(rzsocial)], 'Razao Social'),
                            input([name(rzsocial), type(text), class('form-control'), id(rzsocial), placeholder('')], [])
                        ]),
                        div([class('form-group')], [
                            label([for(nome)], 'Nome'),
                            input([name(nome), type(text), class('form-control'), id(nome), placeholder('')], [])
                        ]),
                        div([class('form-group')], [
                            label([for(usuario)], 'Tipo Pessoa'),
                            select([name(type)], [
                                option([value(juridica)], 'Juridica'),
                                option([value(fisica)], 'Fisica')
                            ])
                        ]),
                        div([class('form-group')], [
                            label([for(cod)], 'CNPJ/CPF'),
                            input([name(cod), type(text), class('form-control'), id(cod), placeholder('')], [])
                        ]),
                        div([class('form-group')], [
                            label([for(inputState)], 'E-mail'),
                            input([name(email), type(email), class('form-control'), id(inputState), placeholder('')], []),
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
                \buttonsCadCliente
            ])])).

pageCadCliente -->
    html(div([class('main-content')],
            [h5('Cliente'), 
            \navpageCadCliente,
            div([class('row info')], [
                div([class('col-lg-10 col-md-10')], [
                    div([class(dropdown), style('padding: 20px 0 0;')], [
                        button([class('btn btn-secondary dropdown-toogle'), type(button), id('dropdownMenuButton'), 'data-toggle'(dropdown)], 'Clientes'),
                        div([class('dropdown-menu')], [
                            a([class('dropdown-item'), href('/admin/cadastros/funcionarios')], 'Funcionarios'),
                            a([class('dropdown-item'), href('/admin/cadastros/clientes')], 'Clientes'),
                            a([class('dropdown-item'), href('/admin/cadastros/funcoes')], 'Funcoes')
                        ])
                    ]),
                    form([method('post'), action('./cadastro')], [
                        div([class('form-group')], [
                            label([for(rzsocial)], 'Razao Social'),
                            input([name(rzsocial), type(text), class('form-control'), id(rzsocial), placeholder('')], [])
                        ]),
                        div([class('form-group')], [
                            label([for(nome)], 'Nome'),
                            input([name(nome), type(text), class('form-control'), id(nome), placeholder('')], [])
                        ]),
                        div([class('form-group')], [
                            label([for(usuario)], 'Tipo Pessoa'),
                            select([name(type)], [
                                option([value(juridica)], 'Juridica'),
                                option([value(fisica)], 'Fisica')
                            ])
                        ]),
                        div([class('form-group')], [
                            label([for(cod)], 'CNPJ/CPF'),
                            input([name(cod), type(text), class('form-control'), id(cod), placeholder('')], [])
                        ]),
                        div([class('form-group')], [
                            label([for(inputState)], 'E-mail'),
                            input([name(email), type(email), class('form-control'), id(inputState), placeholder('')], []),
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
                \buttonsCadCliente
            ])])).

navpageCadCliente --> 
    html(nav([class('navbar navbar-expand-lg navbar-light bg-light')], 
    [button([class('navbar-toggler'), type(button), 'data-toogle'(collapse), 'data-target'('#page'), 'aria-controls'(page),
    'aria-expanded'(false), 'aria-label'('Toggle navigation')], [span([class('navbar-toggler-icon')], [])]), 
    div([class('collapse navbar-collapse'), id(page)],
    [div([class('navbar-nav')], 
    [a([class('nav-link'), href('/admin/cadastros/clientes')], ['Relatorio']), 
    a([class('nav-link active'), href('/admin/cadastros/clientes/cadastro')], ['Cadastro']) 
    ])])])).

buttonsCadCliente --> 
    html(div([class('buttons col-lg-2 col-md-2 lado')], [
        button([class('btn btn-light'), disabled(disabled)], 'Confirmar'),
        button([class('btn btn-light'), disabled(disabled)], 'Cancelar'),
        button([class('btn btn-light')], '+ Incluir'),
        button([class('btn btn-light')], 'Alterar'),
        button([class('btn btn-light')], '- Excluir'),
        button([class('btn btn-light')], '? Ajudar')
    ])).
