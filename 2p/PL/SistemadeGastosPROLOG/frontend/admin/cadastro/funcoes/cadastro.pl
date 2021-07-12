:- use_module(library(http/html_write)).
:- use_module(library(http/html_head)).

:- ensure_loaded(temp(bootstrap)).
:- use_module('./backend/db/schemas/funcao.pl').

funcoesCadastro(post, Pedido):-
    reply_html_page(
        bootstrap,
        [ \metasCadFuncao, \linksCadFuncao, title('Controle de Gastos de Clientes | Funcao')],
        [ \navbarCadFuncao, \pageCadFuncao(Pedido) ]).

funcoesCadastro(get, _Pedido):-
    reply_html_page(
        bootstrap,
        [ \metasCadFuncao, \linksCadFuncao, title('Controle de Gastos de Clientes | Funcao')],
        [ \navbarCadFuncao, \pageCadFuncao ]).

metasCadFuncao -->
    html(meta([name(viewport), content('width=device-width, initial-scale=1.0, shrink-to-fit=no')], [])).
    
linksCadFuncao -->
    html([link([rel(stylesheet), href('https://cdn.jsdelivr.net/npm/reset-css@5.0.1/reset.min.css')], []),
    link([rel(stylesheet), href('https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css'), 
    integrity('sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z'), crossorigin('anonymous')], []),
    link([rel(stylesheet), href('/css/admin/cadastros/funcoes/cadastro.css')], [])]).

navbarCadFuncao --> 
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

pageCadFuncao(Pedido) -->
    {
        catch(
            http_parameters(Pedido, [
                func(Func, [atom, length > 0]),
                access(Acess, [boolean])
            ]), 
        _E, fail), !,
        cadastra_funcao(CdFuncao, Func, Acess)
    },
    html(div([class('main-content')],
            [h5('Funcionario'), 
            \navpageCadFuncao,
            div([class('row info')], [
                div([class('col-lg-10 col-md-10')], [
                    div([class(dropdown), style('padding: 20px 0 0;')], [
                        button([class('btn btn-secondary dropdown-toogle'), type(button), id('dropdownMenuButton'), 'data-toggle'(dropdown)], 'Funcoes'),
                        div([class('dropdown-menu')], [
                            a([class('dropdown-item'), href('/admin/cadastros/funcionarios')], 'Funcionarios'),
                            a([class('dropdown-item'), href('/admin/cadastros/clientes')], 'Clientes'),
                            a([class('dropdown-item'), href('/admin/cadastros/funcoes')], 'Funcoes')
                        ])
                    ]),
                    h6('Cadastro Realizado com sucesso!'),
                    h6('O codigo cadastrado e ~w!' - CdFuncao),
                    form([method('post'), action('./cadastro')], [
                        div([class('form-group row')], [
                            label([for('inputFuncao'), class('col-sm-2 col-form-label')], 'Funcao'),
                            div([class('col-sm-4')], [
                                input([name(func), type(text), class('form-control'), id('inputFuncao'), placeholder(''), required], [])
                            ])
                        ]),
                        div([
                            label([style('margin-right: 20px;')], 'Acesso a todo sistema'),
                            div([class('custom-control custom-radio custom-control-inline')], [
                                input([type(radio), id(yes), name(access), class('custom-control-input'), value(true)], []),
                                label([class('custom-control-label'), for(yes)], 'Sim')
                            ]),
                            div([class('custom-control custom-radio custom-control-inline')], [
                                input([type(radio), id(no), name(access), class('custom-control-input'), value(false)], []),
                                label([class('custom-control-label'), for(no)], 'Nao')
                            ])
                        ]),
                        button([type(submit), class('btn btn-light')], 'Submit')
                    ])
                ]),
                \buttonsCadFuncao
            ])])).

pageCadFuncao(_Pedido) -->
    html(div([class('main-content')],
            [h5('Funcionario'), 
            \navpageCadFuncao,
            div([class('row info')], [
                div([class('col-lg-10 col-md-10')], [
                    div([class(dropdown), style('padding: 20px 0 0;')], [
                        button([class('btn btn-secondary dropdown-toogle'), type(button), id('dropdownMenuButton'), 'data-toggle'(dropdown)], 'Funcoes'),
                        div([class('dropdown-menu')], [
                            a([class('dropdown-item'), href('/admin/cadastros/funcionarios')], 'Funcionarios'),
                            a([class('dropdown-item'), href('/admin/cadastros/clientes')], 'Clientes'),
                            a([class('dropdown-item'), href('/admin/cadastros/funcoes')], 'Funcoes')
                        ])
                    ]),
                    h6('Nao foi possivel realizar o cadastro!'),
                    form([method('post'), action('./cadastro')], [
                        div([class('form-group row')], [
                            label([for('inputFuncao'), class('col-sm-2 col-form-label')], 'Funcao'),
                            div([class('col-sm-4')], [
                                input([name(func), type(text), class('form-control'), id('inputFuncao'), placeholder(''), required], [])
                            ])
                        ]),
                        div([
                            label([style('margin-right: 20px;')], 'Acesso a todo sistema'),
                            div([class('custom-control custom-radio custom-control-inline')], [
                                input([type(radio), id(yes), name(access), class('custom-control-input'), value(true)], []),
                                label([class('custom-control-label'), for(yes)], 'Sim')
                            ]),
                            div([class('custom-control custom-radio custom-control-inline')], [
                                input([type(radio), id(no), name(access), class('custom-control-input'), value(false)], []),
                                label([class('custom-control-label'), for(no)], 'Nao')
                            ])
                        ]),
                        button([type(submit), class('btn btn-light')], 'Submit')
                    ])
                ]),
                \buttonsCadFuncao
            ])])).

pageCadFuncao -->
    html(div([class('main-content')],
            [h5('Funcao'), 
            \navpageCadFuncao,
            div([class('row info')], [
                div([class('col-lg-10 col-md-10')], [
                    div([class(dropdown), style('padding: 20px 0 0;')], [
                        button([class('btn btn-secondary dropdown-toogle'), type(button), id('dropdownMenuButton'), 'data-toggle'(dropdown)], 'Funcoes'),
                        div([class('dropdown-menu')], [
                            a([class('dropdown-item'), href('/admin/cadastros/funcionarios')], 'Funcionarios'),
                            a([class('dropdown-item'), href('/admin/cadastros/clientes')], 'Clientes'),
                            a([class('dropdown-item'), href('/admin/cadastros/funcoes')], 'Funcoes')
                        ])
                    ]),
                    form([method('post'), action('./cadastro')], [
                        div([class('form-group row')], [
                            label([for('inputFuncao'), class('col-sm-2 col-form-label')], 'Funcao'),
                            div([class('col-sm-4')], [
                                input([name(func), type(text), class('form-control'), id('inputFuncao'), placeholder(''), required], [])
                            ])
                        ]),
                        div([
                            label([style('margin-right: 20px;')], 'Acesso a todo sistema'),
                            div([class('custom-control custom-radio custom-control-inline')], [
                                input([type(radio), id(yes), name(access), class('custom-control-input'), value(true)], []),
                                label([class('custom-control-label'), for(yes)], 'Sim')
                            ]),
                            div([class('custom-control custom-radio custom-control-inline')], [
                                input([type(radio), id(no), name(access), class('custom-control-input'), value(false)], []),
                                label([class('custom-control-label'), for(no)], 'Nao')
                            ])
                        ]),
                        button([type(submit), class('btn btn-light')], 'Submit')
                    ])
                ]),
                \buttonsCadFuncao
            ])])).

navpageCadFuncao --> 
    html(nav([class('navbar navbar-expand-lg navbar-light bg-light')], 
    [button([class('navbar-toggler'), type(button), 'data-toogle'(collapse), 'data-target'('#page'), 'aria-controls'(page),
    'aria-expanded'(false), 'aria-label'('Toggle navigation')], [span([class('navbar-toggler-icon')], [])]), 
    div([class('collapse navbar-collapse'), id(page)],
    [div([class('navbar-nav')], 
    [a([class('nav-link'), href('/admin/cadastros/funcoes')], ['Relatorio']), 
    a([class('nav-link active'), href('/admin/cadastros/funcoes/cadastro')], ['Cadastro']) 
    ])])])).

buttonsCadFuncao --> 
    html(div([class('buttons col-lg-2 col-md-2 lado')], [
        button([class('btn btn-light'), disabled(disabled)], 'Confirmar'),
        button([class('btn btn-light'), disabled(disabled)], 'Cancelar'),
        button([class('btn btn-light')], '+ Incluir'),
        button([class('btn btn-light')], 'Alterar'),
        button([class('btn btn-light')], '- Excluir'),
        button([class('btn btn-light')], '? Ajudar')
    ])).