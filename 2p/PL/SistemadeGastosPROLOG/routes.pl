:- use_module(library(http/http_dispatch)).
:- use_module(library(http/http_path)).

:- multifile http:location/3.
:- dynamic   http:location/3.


http:location(img, root(img), []).
http:location(home, root(home), []).
http:location(about, root(about), []).
http:location(help, root(help), []).
http:location(serviceorder, root(serviceorder), []).
http:location(admin, root(admin), []).
http:location(cadastros, admin(cadastros), []).

http:location(clientes, cadastros(clientes), []).
http:location(funcionarios, cadastros(funcionarios), []).
http:location(funcoes, cadastros(funcoes), []).


:- http_handler(css(.),
                serve_files_in_directory(dir_css), [prefix]).
:- http_handler(img(.),
                serve_files_in_directory(dir_img), [prefix]).
:- http_handler(js(.),
                serve_files_in_directory(dir_js),  [prefix]).
:- http_handler('/favicon.ico',
                http_reply_file(dir_img('favicon.ico'), []), []).

% Frontend

% Home %
:- http_handler(root(.),
                login(Metodo), [method(Metodo), methods([get, post])]).

:- http_handler(home(.), home, []).
:- http_handler(about(.), about, []).
:- http_handler(help(.), help, []).

% Admin %
:- http_handler(admin(home), homeAdmin, []).

:- http_handler(clientes(.), clientes, []).
:- http_handler(clientes(cadastro), 
                clientesCadastro(Metodo), [method(Metodo), methods([get, post])]).

:- http_handler(funcionarios(.), funcionarios, []).
:- http_handler(funcionarios(cadastro), 
                funcionariosCadastro(Metodo), [method(Metodo), methods([get, post])]).

:- http_handler(funcoes(.), funcoes, []).
:- http_handler(funcoes(cadastro), 
                funcoesCadastro(Metodo), [method(Metodo), methods([get, post])]).

:- http_handler(admin(about), aboutAdmin, []).
:- http_handler(admin(help), helpAdmin, []).
