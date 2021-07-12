:- load_files([ routes,
                schemas(endereco),
                schemas(funcao),
                schemas(funcionario)
              ],
	          [ if(not_loaded), 
                silent(true) 
	          ]).
        
:- initialization(inicializa_tabelas).

tabela(endereco).
tabela(funcao).
tabela(funcionario).

inicializa_tabelas :-
    findall(Tabela, tabela(Tabela), Tabelas),
    liga_todos_arquivos(Tabelas).

liga_todos_arquivos([Tabela|Tabelas]) :-
    liga_arquivo(Tabela), !,
    liga_todos_arquivos(Tabelas).

liga_todos_arquivos([]).

liga_arquivo(Arquivo) :- !,
    atomic_list_concat(['tbl_', Arquivo, '.pl'], NomeArq),
    expand_file_search_path(tables(NomeArq), CaminhoArqTable),
    Arquivo:arquivo_da_tabela(CaminhoArqTable).


cadastra_funcionario(CdFun, Nome, Usuario, Senha, CdFuncao, Rua, Nr_casa, 
    Complemento, Bairro, Cidade, CEP, Tel1, Tel2) :-
        funcao:funcao(CdFuncao, _Func, TpVis),
        endereco:insere(CdEnd, Rua, Nr_casa, 
            Complemento, Bairro, Cidade, CEP, Tel1, Tel2),
        funcionario:insere(CdFun, CdFuncao, CdEnd, Nome, 
            Senha, Usuario, TpVis).