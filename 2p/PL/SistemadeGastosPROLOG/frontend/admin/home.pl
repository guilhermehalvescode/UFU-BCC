:- use_module(library(http/html_write)).
:- use_module(library(http/html_head)).

:- ensure_loaded('./template/bootstrap.pl').

homeAdmin(_Pedido) :-
    reply_html_page(
        bootstrap,
        [ \metasHomeAdmin, \linksHomeAdmin, title('Controle de Gastos de Clientes') ],
        [ \navbarHomeAdmin, \homeAdmin ]).

metasHomeAdmin -->
  html(meta([name(viewport), content('width=device-width, initial-scale=1.0, shrink-to-fit=no')], [])).

linksHomeAdmin -->
  html([link([rel(stylesheet), href('https://cdn.jsdelivr.net/npm/reset-css@5.0.1/reset.min.css')], []),
  link([rel(stylesheet), href('https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css'), 
  integrity('sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z'), crossorigin('anonymous')], []),
  link([rel(stylesheet), href('/css/admin/home.css')], [])]).

navbarHomeAdmin --> 
    html(nav([class('navbar navbar-expand-lg navbar-light bg-light')], 
    [button([class('navbar-toggler'), type(button), 'data-toogle'(collapse), 'data-target'('#navbarNavAltMarkup'), 'aria-controls'('navbarNavAltMarkup'),
    'aria-expanded'(false), 'aria-label'('Toggle navigation')], [span([class('navbar-toggler-icon')], [])]), 
    div([class('collapse navbar-collapse'), id('navbarNavAltMarkup')],
    [div([class('navbar-nav')], [
        a([class('nav-link'), href('/admin/cadastros/funcionarios')], ['Cadastros']), 
        a([class('nav-link'), href('/admin/material')], ['Material']), 
        a([class('nav-link'), href('/admin/serviceorder')], ['Ordem de Servico']), 
        a([class('nav-link'), href('/admin/consultas')], ['Consultas']), 
        a([class('nav-link'), href('/admin/about')], ['Sobre']), 
        a([class('nav-link'), href('/admin/help')], ['Ajuda'])
    ])])])).

homeAdmin -->
  html(div([class('main-content')], [
      img([class('logo img-fluid'), src('/img/logo.png'), alt('Logo Sistema')], [])
  ])).