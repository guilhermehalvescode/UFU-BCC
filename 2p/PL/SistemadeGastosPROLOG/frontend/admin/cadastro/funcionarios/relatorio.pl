:- use_module(library(http/html_write)).
:- use_module(library(http/html_head)).

:- ensure_loaded(temp(bootstrap)).
:- use_module('./backend/db/schemas/funcionario.pl').
:- use_module('./backend/db/schemas/funcao.pl').

funcionarios(_):-
    reply_html_page(
        bootstrap,
        [ \metasRelFun, \linksRelFun, title('Controle de Gastos de Clientes | Funcionario')],
        [ \navbarRelFun, \pageRelFun ]).

metasRelFun -->
    html(meta([name(viewport), content('width=device-width, initial-scale=1.0, shrink-to-fit=no')], [])).
    
linksRelFun -->
    html([link([rel(stylesheet), href('https://cdn.jsdelivr.net/npm/reset-css@5.0.1/reset.min.css')], []),
    link([rel(stylesheet), href('https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css'), 
    integrity('sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z'), crossorigin('anonymous')], []),
    link([rel(stylesheet), href('/css/admin/cadastros/funcionarios/relatorio.css')], [])]).

navbarRelFun --> 
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

pageRelFun -->
    html(div([class('main-content')],
            [h5('Funcionario'), 
            \navpageRelFun,
            div([class('row info')], [
                div([class('col-lg-10 col-md-10')], [
                    div([class(dropdown), style('padding: 20px 0 0;')], [
                        button([class('btn btn-secondary dropdown-toogle'), type(button), id('dropdownMenuButton'), 'data-toggle'(dropdown)], 'Funcionarios'),
                        div([class('dropdown-menu')], [
                            a([class('dropdown-item'), href('/admin/cadastros/funcionarios')], 'Funcionarios'),
                            a([class('dropdown-item'), href('/admin/cadastros/clientes')], 'Clientes'),
                            a([class('dropdown-item'), href('/admin/cadastros/funcoes')], 'Funcoes')
                        ])
                    ]),
                    table([class(table)], [
                        thead([
                            th([style('text-align: center;')], 'Funcionario'),  
                            th([style('text-align: center;')], 'Usuario'),    
                            th([style('text-align: center;')], 'Funcao')    
                        ]),
                        tbody(\rendertableFun)
                    ])
                ]),
                \buttonsRelFun
            ])])).

navpageRelFun --> 
    html(nav([class('navbar navbar-expand-lg navbar-light bg-light')], 
    [button([class('navbar-toggler'), type(button), 'data-toogle'(collapse), 'data-target'('#page'), 'aria-controls'(page),
    'aria-expanded'(false), 'aria-label'('Toggle navigation')], [span([class('navbar-toggler-icon')], [])]), 
    div([class('collapse navbar-collapse'), id(page)],
    [div([class('navbar-nav')], 
    [a([class('nav-link active'), href('/admin/cadastros/funcionarios')], ['Relatorio']), 
    a([class('nav-link'), href('/admin/cadastros/funcionarios/cadastro')], ['Cadastro']) 
    ])])])).

buttonsRelFun --> 
    html(div([class('buttons col-lg-2 col-md-2 lado')], [
        button([class('btn btn-light'), disabled(disabled)], 'Confirmar'),
        button([class('btn btn-light'), disabled(disabled)], 'Cancelar'),
        button([class('btn btn-light')], '+ Incluir'),
        button([class('btn btn-light')], 'Alterar'),
        button([class('btn btn-light')], '- Excluir'),
        button([class('btn btn-light')], '? Ajudar')
    ])).

rendertableFun -->
    {
        findall(tr([td(Nome), td(User), td(Func)]),
            (funcionario:funcionario(_, CdFunc, _, Nome, _, User, _),
            funcao:funcao(CdFunc, Func, _)), HTML)
    },
    html(HTML).