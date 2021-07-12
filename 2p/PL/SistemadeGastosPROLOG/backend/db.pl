/* FUNÇÃO (CONSULTAS E CRUD) */
cadastra_funcao(CdFuncao, Ds_funcao, TpVis) :-
    funcao:insere(CdFuncao, Ds_funcao, TpVis).

remove_funcao(CdFuncao) :-
    funcao:remove(CdFuncao).

atualiza_funcao(CdFuncao, Ds_funcao, TpVis) :-
    funcao:atualiza(CdFuncao, Ds_funcao, TpVis).

/* FUNÇÃO (CONSULTAS E CRUD) */

/* FUNCIONÁRIOS (CONSULTAS E CRUD) */
/* ENDEREÇO (CONSULTAS E CRUD) A tabela de endereçoes está subordinada a de funcionários e clientes */
cadastra_funcionario(CdFun, Nome, Usuario, Senha, CdFuncao, Rua, Nr_casa, 
    Complemento, Bairro, Cidade, CEP, Tel1, Tel2) :-
        funcao:funcao(CdFuncao, _, TpVis),
        endereco:insere(CdEnd, Rua, Nr_casa, 
            Complemento, Bairro, Cidade, CEP, Tel1, Tel2),
        funcionario:insere(CdFun, CdFuncao, CdEnd, Nome, 
            Senha, Usuario, TpVis).

remove_funcionario(CdFun) :-
    \+ ordem_servico:ordem_servico(_CdOrdemS, CdFun, _CdCliente, _DtOrdemS, _VlTot, _BoolF),
    funcionario:funcionario(CdFun, _CdFuncao, CdEnd, _Nome, _Senha, _Nick, _TpVis),
    endereco:endereco(CdEnd, _Nm_rua, _Nr_casa, _Complemento, _Nm_bairro, 
    _Nm_cidade, _Cep, _Tel1, _Tel2),
    funcionario:remove(CdFun),
    endereco:remove(CdEnd).

atualiza_funcionario(CdFun, Nome, Usuario, Senha, Func, Rua, Nr_casa, 
    Complemento, Bairro, Cidade, CEP, Tel1, Tel2) :- 
        funcao:funcao(CdFuncao, Func, TpVis),
        endereco:endereco(CdEnd, _, _, _, _, _, _, _, _),
        endereco:atualiza(CdEnd, Rua, Nr_casa, 
            Complemento, Bairro, Cidade, CEP, Tel1, Tel2),
        funcionario:atualiza(CdFun, CdFuncao, CdEnd, Nome, 
            Senha, Usuario, TpVis).

/* ENDEREÇO (CONSULTAS E CRUD) A tabela de endereçoes está subordinada a de funcionários e clientes */
/* FUNCIONÁRIOS (CONSULTAS E CRUD) */

/* FUNCIONÁRIOS (CONSULTAS E CRUD) */
/* ENDEREÇO (CONSULTAS E CRUD) A tabela de endereçoes está subordinada a de funcionários e clientes */
cadastra_cliente(CdCliente, RazaoS, Nome, Tipo, CodId, Email, Rua, Nr_casa, 
    Complemento, Bairro, Cidade, CEP, Tel1, Tel2) :-
        endereco:insere(CdEnd, Rua, Nr_casa, 
            Complemento, Bairro, Cidade, CEP, Tel1, Tel2),
        cliente:insere(CdCliente, CdEnd, RazaoS, Nome, Email, CodId, Tipo, false).

remove_cliente(CdCliente) :-
    \+ ordem_servico:ordem_servico(_CdOrdemS, _CdFun, CdCliente, _DtOrdemS, _VlTot, _BoolF),
    cliente:cliente(CdCliente, CdEnd, _RazaoS, _Nome, _Email, _CodId, _Tipo, _TpVis),
    endereco:endereco(CdEnd, _Nm_rua, _Nr_casa, _Complemento, _Nm_bairro, 
    _Nm_cidade, _Cep, _Tel1, _Tel2),
    cliente:remove(CdCliente),
    endereco:remove(CdCliente).

atualiza_cliente(CdCliente, RazaoS, Nome, Tipo, CodId, Email, Rua, Nr_casa, 
    Complemento, Bairro, Cidade, CEP, Tel1, Tel2, TpVis) :- 
        cliente:cliente(CdCliente, CdEnd, _RazaoS, _Nome, _Email, _CodId, _Tipo, _TpVis),
        endereco:atualiza(CdEnd, Rua, Nr_casa, 
            Complemento, Bairro, Cidade, CEP, Tel1, Tel2),
        cliente:atualiza(CdCliente, CdEnd, RazaoS, Nome, Email, CodId, Tipo, TpVis).

/* ENDEREÇO (CONSULTAS E CRUD) A tabela de endereçoes está subordinada a de funcionários e clientes */
/* FUNCIONÁRIOS (CONSULTAS E CRUD) */

/* ORDEM SERVIÇO (CONSULTAS E CRUD) */
/* SERVICO PRESTADO (CONSULTAS E CRUD) */
cadastra_ordem_servico(CdFun, CdClient, CdServ, Qnt, DtOrdemS, ValorUnit, VlTot, QntMat, BoolF) :-
    funcionario:funcionario(CdFun, _CdFuncao, _, _Name, _Senha, _Nick, TpVis),
    cliente:cliente(CdClient, _, _NmRazao, _Nmfant, _DsEmail, _CodId, _Tipo, _TpVis),
    servico:servico(CdServ, _NmServ, TpVis),
    ordem_servico:insere(CdOrderS, CdFun, CdClient, DtOrdemS, VlTot, BoolF),
    servico_prestado:insere(_CdSP, CdServ, CdFun, CdOrderS, Qnt, ValorUnit, VlTot, QntMat).

remove_ordem_servico(CdOrderS, CdFun) :-
    \+ servico_prestado:servico_prestado(_CdSP, _Serv, CdFun, CdOrderS, _QntSer, _VlUnit, _VlTotal, _QntMat),
    \+ estoque:estoque(_CdEst, CdFun, CdOrderS, _CdMat, _QntMatSoma, _QntMatSub),
    ordem_servico:remove(CdOrderS, CdFun).

atualiza_ordem_servico(CdFun, CdClient, CdServ, Qnt, DtOrdemS, ValorUnit, VlTot, QntMat, BoolF) :- 
    funcionario:funcionario(CdFun, _CdFuncao, _, _Name, _Senha, _Nick, TpVis),
    cliente:cliente(CdClient, _, _NmRazao, _Nmfant, _DsEmail, _CodId, _Tipo, _TpVis),
    servico:servico(CdServ, _NmServ, TpVis),
    ordem_servico:atualiza(CdOrderS, CdFun, CdClient, DtOrdemS, VlTot, BoolF),
    servico_prestado:atualiza(_CdSP, CdServ, CdFun, CdOrderS, Qnt, ValorUnit, VlTot, QntMat).

listar_ordem_servico(Lista) :-
    findall((Data, Cliente, Func, Total),
        (ordem_servico:ordem_servico(_CdOrderS, CdFunc, CdClient, Data, Total, _BoolF),
        funcionario:funcionario(CdFunc, _CdFuncao, _, Func, _Senha, _Nick, _),
        cliente:cliente(CdClient, _, _NmRazao, Cliente, _DsEmail, _CodId, _Tipo, _)), Lista).

listar_ordem_servico_cad(Lista) :-
    findall((Qnt, Serv, ValUnit, Tot, QntServ),
    (ordem_servico:ordem_servico(CdOrderS, CdFunc, _CdClient, _Data, Tot, _BoolF),
    servico_prestado:servico_prestado(_CdServP, CodServ, CdFunc, CdOrderS, Qnt, ValUnit, Tot, QntServ),
    servico:servico(CodServ, Serv, _TpVis)), Lista).
/* SERVICO PRESTADO (CONSULTAS E CRUD) */
/* ORDEM SERVIÇO (CONSULTAS E CRUD) */

/* SERVIÇO (CONSULTAR E CRUD) */
cadastra_servico(CdMat, CdServ, Nome, TpVis) :-
    material:material(CdMat, _Nm, _TpVis),
    material_servico:insere(CdMat, CdServ),
    servico:insere(CdServ, Nome, TpVis).

remove_servico(CdServ) :-
    material_servico:material_servico(CdMat, CdServ),
    material_servico:remove(CdMat, CdServ),
    servico:remove(CdServ).

atualiza_servico(CdMat, CdServ, Nome, TpVis) :-
    material:material(CdMat, _Nm, _TpVis),
    material_servico:atualiza(CdMat, CdServ),
    servico:atualiza(CdServ, Nome, TpVis).

listar_servicos(Lista) :-
    servico:listar(Lista).
/* SERVIÇO (CONSULTAR E CRUD) */

/* MATERIAL (CONSULTAR E CRUD) */
cadastra_material(CdMat, Nome, TpVis) :-
    material:insere(CdMat, Nome, TpVis).

remove_material(CdServ) :-
    \+ estoque:estoque(_, _, _, CdServ, _, _),
    \+ material_servico:material_servico(CdServ, _),
    material:remove(CdServ).

atualiza_material(CdMat, Nome, TpVis) :-
    material:material(CdMat, _Nm, _TpVis),
    material:atualiza(CdMat, Nome, TpVis).

listar_materiais(Lista) :-
    material:listar(Lista).
/* MATERIAL (CONSULTAR E CRUD) */


