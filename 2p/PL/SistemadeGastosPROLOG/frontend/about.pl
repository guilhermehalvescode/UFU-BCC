:- use_module(library(http/html_write)).
:- use_module(library(http/html_head)).

:- ensure_loaded('./template/bootstrap.pl').

about(_Pedido) :-
    reply_html_page(
        bootstrap,
        [ \metasAbout, \linksAbout, title('Controle de Gastos de Clientes') ],
        [ \navbarAbout, \about ]).

metasAbout -->
  html(meta([name(viewport), content('width=device-width, initial-scale=1.0, shrink-to-fit=no')], [])).

linksAbout -->
  html([link([rel(stylesheet), href('https://cdn.jsdelivr.net/npm/reset-css@5.0.1/reset.min.css')], []),
  link([rel(stylesheet), href('https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css'), 
  integrity('sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z'), crossorigin('anonymous')], []),
  link([rel(stylesheet), href('/css/about.css')], [])]).

navbarAbout --> 
    html(nav([class('navbar navbar-expand-lg navbar-light bg-light')], 
    [button([class('navbar-toggler'), type(button), 'data-toogle'(collapse), 'data-target'('#navbarNavAltMarkup'), 'aria-controls'('navbarNavAltMarkup'),
    'aria-expanded'(false), 'aria-label'('Toggle navigation')], [span([class('navbar-toggler-icon')], [])]), 
    div([class('collapse navbar-collapse'), id('navbarNavAltMarkup')],
    [div([class('navbar-nav')], [
        a([class('nav-link'), href('/serviceorder')], ['Ordem de Servico']), 
        a([class('nav-link active'), href('/about')], ['Sobre']), 
        a([class('nav-link'), href('/help')], ['Ajuda'])
    ])])])).

about -->
  html(div([class('main-content')], [
      p(['Trabalho de conclusao de Curso submetido a Universidade Regional de Blumenau para obtencao dos creditos na disciplina Trabalho de Conclusao de Curso II no curso de Sistemas de informacao - Bacharelado.']),
      p(['Desenvolvido por: Emerson da Silva Albino']),
      p(['Orientador: Wilson Pedro Carli.'])
  ])).