:- use_module(library(http/html_write)).
:- use_module(library(http/html_head)).

:- ensure_loaded('./template/bootstrap.pl').

helpAdmin(_Pedido) :-
    reply_html_page(
        bootstrap,
        [ \metasHelpAdmin, \linksHelpAdmin, title('Controle de Gastos de Clientes') ],
        [ \navbarHelpAdmin, \adminHelp , \scriptHelpAdmin]).

metasHelpAdmin -->
  html(meta([name(viewport), content('width=device-width, initial-scale=1.0, shrink-to-fit=no')], [])).

linksHelpAdmin -->
  html([link([rel(stylesheet), href('https://cdn.jsdelivr.net/npm/reset-css@5.0.1/reset.min.css')], []),
  link([rel(stylesheet), href('https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css'), 
  integrity('sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z'), crossorigin('anonymous')], []),
  link([rel(stylesheet), href('/css/help.css')], []),
  script([src('https://use.fontawesome.com/65acd3825f.js')], [])]).

navbarHelpAdmin --> 
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
        a([class('nav-link active'), href('/admin/help')], ['Ajuda'])
    ])])])).

adminHelp -->
  html(div([class('main-content')], [
      img([class('logo img-fluid'), src('/img/logo.png'), alt('Logo Sistema')], []),
      p(['Este aplicativo, visa maior agilidade e confiabilidade entre os envolvidos.']),
      p(['Para maiores dificuldades com este aplicativo, utilize a opcao de ajuda conforme a respectiva tela.']),
      div([class('pergunta_container')], [
          div([class('pergunte_title')], [
              p([class(pergunta)], 'Funcionario'),
              i([class('fa fa-2x fa-chevron-down fa-xs'), 'aria-hidden'(true)], [])
          ]),
          div([class('resposta_container')], [
              p([class(resposta)], 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce et bibendum justo, eget egestas nisl.')
          ])
      ]),
      div([class('pergunta_container')], [
          div([class('pergunte_title')], [
              p([class(pergunta)], 'Cliente'),
              i([class('fa fa-2x fa-chevron-down fa-xs'), 'aria-hidden'(true)], [])
          ]),
          div([class('resposta_container')], [
              p([class(resposta)], 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce et bibendum justo, eget egestas nisl.')
          ])
      ]),
      div([class('pergunta_container')], [
          div([class('pergunte_title')], [
              p([class(pergunta)], 'Funcao'),
              i([class('fa fa-2x fa-chevron-down fa-xs'), 'aria-hidden'(true)], [])
          ]),
          div([class('resposta_container')], [
              p([class(resposta)], 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce et bibendum justo, eget egestas nisl.')
          ])
      ]),
      div([class('pergunta_container')], [
          div([class('pergunte_title')], [
              p([class(pergunta)], 'Material'),
              i([class('fa fa-2x fa-chevron-down fa-xs'), 'aria-hidden'(true)], [])
          ]),
          div([class('resposta_container')], [
              p([class(resposta)], 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce et bibendum justo, eget egestas nisl.')
          ])
      ]),
      div([class('pergunta_container')], [
          div([class('pergunte_title')], [
              p([class(pergunta)], 'Servico'),
              i([class('fa fa-2x fa-chevron-down fa-xs'), 'aria-hidden'(true)], [])
          ]),
          div([class('resposta_container')], [
              p([class(resposta)], 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce et bibendum justo, eget egestas nisl.')
          ])
      ]),
      div([class('pergunta_container')], [
          div([class('pergunte_title')], [
              p([class(pergunta)], 'Estoque'),
              i([class('fa fa-2x fa-chevron-down fa-xs'), 'aria-hidden'(true)], [])
          ]),
          div([class('resposta_container')], [
              p([class(resposta)], 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce et bibendum justo, eget egestas nisl.')
          ])
      ]),
      div([class('pergunta_container')], [
          div([class('pergunte_title')], [
              p([class(pergunta)], 'Ordem de Servico'),
              i([class('fa fa-2x fa-chevron-down fa-xs'), 'aria-hidden'(true)], [])
          ]),
          div([class('resposta_container')], [
              p([class(resposta)], 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce et bibendum justo, eget egestas nisl.')
          ])
      ]),
      div([class('pergunta_container')], [
          div([class('pergunte_title')], [
              p([class(pergunta)], 'Lancamento Mensal'),
              i([class('fa fa-2x fa-chevron-down fa-xs'), 'aria-hidden'(true)], [])
          ]),
          div([class('resposta_container')], [
              p([class(resposta)], 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce et bibendum justo, eget egestas nisl.')
          ])
      ]),
      div([class('pergunta_container')], [
          div([class('pergunte_title')], [
              p([class(pergunta)], 'Consulta de Servicos'),
              i([class('fa fa-2x fa-chevron-down fa-xs'), 'aria-hidden'(true)], [])
          ]),
          div([class('resposta_container')], [
              p([class(resposta)], 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Fusce et bibendum justo, eget egestas nisl.')
          ])
      ])
  ])).

scriptHelpAdmin -->
    html(script([src('/js/help.js')], [])).