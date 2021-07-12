:- use_module(library(http/html_write)).
:- use_module(library(http/html_head)).
:- use_module(library(http/http_parameters)).

:- ensure_loaded('./template/bootstrap.pl').

:- use_module('./backend/db/schemas/funcionario.pl').

login(post, Pedido) :-
    reply_html_page(
      bootstrap,
      [\metas, \links, title('Login')],
      [ \log(Pedido) ]).

login(get, _Pedido) :-
    reply_html_page(
        bootstrap,
        [ \metas, \links, title('Login') ],
        [ \log ]).

metas -->
  html(meta([name(viewport), content('width=device-width, initial-scale=1.0, shrink-to-fit=no')], [])).

links -->
  html([link([rel(stylesheet), href('https://cdn.jsdelivr.net/npm/reset-css@5.0.1/reset.min.css')], []),
  link([rel(stylesheet), href('https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css'), 
  integrity('sha384-JcKb8q3iqJ61gNV9KGb8thSsNjpSL0n8PARn9HuZOnIxN0hoP+VmmDGMN5t9UJ0Z'), crossorigin('anonymous')], []),
  link([rel(stylesheet), href('/css/login.css')], [])]).


log(Pedido) -->
  {
        catch(
            http_parameters(Pedido, [
                user(User, [atom, length > 0]),
                pass(Pass, [atom, length > 0])
            ]), 
        _E, fail),
        funcionario:funcionario(_, _, _, Nome, Pass, User, Admin), !,
        (Admin -> Route = '/admin'; Route = '')
  },
  html(div([class('main-content')],[
    form([method('POST'), action('/')], [
      img([class('logo img-thumbnail'), src('/img/logo.png'), alt('Logo Sistema')], []),
      p(['Bem vindo ~w' - Nome]),
      div([class(buttons)], [
        a([href(Route +'/home')], 'Home')
      ])
    ])
  ])).

log(_Pedido) -->
  html(div([class('main-content')],[
    form([method('POST'), action('/')], [
      img([class('logo img-thumbnail'), src('/img/logo.png'), alt('Logo Sistema')], []),
      p(['Usuario ou senha incorretos!']),
      div([class('form-group row')], [
        label([for('staticEmail'), class('col-md-2 col-form-label')], 'Usuario:'),
        div([class('col-md-10')], [
          input([name(user),type(text), required, class('form-control'), id('staticEmail'), placeholder('Digite usuario')], [])
        ])
      ]),
      div([class('form-group row')], [
        label([for('inputPassword'), class('col-md-2 col-form-label')], 'Senha:'),
        div([class('col-md-10')], [
          input([name(pass), type(password), class('form-control'), id('inputPassword'), placeholder('Digite a senha'), required], [])
        ])
      ]),
      div([class(buttons)], [
        button([type(submit), class('btn btn-primary')], 'Ok')
      ])
    ])
  ])).

log -->
  html(div([class('main-content')],[
    form([method('POST'), action('/')], [
      img([class('logo img-thumbnail'), src('/img/logo.png'), alt('Logo Sistema')], []),
      div([class('form-group row')], [
        label([for('staticEmail'), class('col-md-2 col-form-label')], 'Usuario:'),
        div([class('col-md-10')], [
          input([name(user),type(text), required, class('form-control'), id('staticEmail'), placeholder('Digite usuario')], [])
        ])
      ]),
      div([class('form-group row')], [
        label([for('inputPassword'), class('col-md-2 col-form-label')], 'Senha:'),
        div([class('col-md-10')], [
          input([name(pass), type(password), class('form-control'), id('inputPassword'), placeholder('Digite a senha'), required], [])
        ])
      ]),
      div([class(buttons)], [
        button([type(submit), class('btn btn-primary')], 'Ok')
      ])
    ])
  ])).