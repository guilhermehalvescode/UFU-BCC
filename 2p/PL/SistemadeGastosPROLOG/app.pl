:- use_module(library(http/http_dispatch)).

:- use_module(library(http/http_path)).

:- use_module(library(http/http_server_files)).

:- use_module(library(http/http_log)).

:- initialization( servidor(8000) ).


:- multifile user:file_search_path/2.


user:file_search_path(dir_css, './css').
user:file_search_path(dir_js,  './js').
user:file_search_path(dir_img, './img').

user:file_search_path(temp, './template').


user:file_search_path(frontend,  './frontend').
user:file_search_path(service,  frontend('service-order')).
user:file_search_path(admin,  frontend(admin)).


user:file_search_path(cadastro,  admin(cadastro)).
user:file_search_path(clientes,  cadastro(clientes)).
user:file_search_path(funcionarios,  cadastro(funcionarios)).
user:file_search_path(funcoes,  cadastro(funcoes)).

user:file_search_path(consultas,  admin(consultas)).

user:file_search_path(material,  admin(material)).
user:file_search_path(estoque,  material(estoque)).
user:file_search_path(material,  material(material)).
user:file_search_path(servico,  material(servico)).

user:file_search_path(backend,  './backend').

user:file_search_path(schemas,  db(schemas)).
user:file_search_path(tables,  db(tables)).

:- load_files([ server,
                routes,
                backend(db),
                temp(bootstrap),
                %carregando pages padrões 
                frontend(login),
                frontend(home),
                frontend(about),
                frontend(help),
                /* service(cadastro),
                service(relatorio),*/
                %carregando admin
                admin(home),
                admin(about),
                admin(help),
                clientes(cadastro),
                clientes(relatorio),
                funcionarios(cadastro),
                funcionarios(relatorio),
                funcoes(cadastro),
                funcoes(relatorio)
                /* consultas(mensal),
                consultas(servicos),
                estoque(cadastro),
                estoque(relatorio),
                material(cadastro),
                material(relatorio),
                servico(cadastro),
                servico(relatorio) */
              ],
	          [ silent(true)
	          ]).
