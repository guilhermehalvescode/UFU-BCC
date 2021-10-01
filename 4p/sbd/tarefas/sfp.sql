/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*      Esquema:  sfp     
 */
/*    DBMS name:  PostgreSQL                   
 */
/*       Vers~A£o:  prova sbd 2020/2 em 2021   
 */
/* ------------------------------------------------------------ */
--ROLLBACKBEGIN TRANSACTION;
--DROP SCHEMA sfp CASCADE;
CREATE SCHEMA sfp;

SET
    search_path TO sfp;

SET
    CONSTRAINTS ALL DEFERRED;

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*    TABELAS DERIVADAS DE ENTIDADES REGULARES DO EER           */
/* ------------------------------------------------------------ */
CREATE TABLE AGENCIA (
    idage SERIAL CONSTRAINT agencia_pk PRIMARY KEY,
    nomeage VARCHAR(50) CONSTRAINT nomeage_sk UNIQUE,
    tipoage CHAR(1) CONSTRAINT tipoage_ck CHECK(tipoage IN (’ P ’, ’ M ’, ’ E ’, ’ F ’)),
    orcamentoage DECIMAL(12, 2)
);

CREATE TABLE PROJETO (
    idpro SERIAL CONSTRAINT projeto_pk PRIMARY KEY,
    nomepro VARCHAR(50),
    datapro DATE,
    duracaopro INT,
    idage INT,
    idpes INT
);

CREATE TABLE PESSOA (
    idpes SERIAL CONSTRAINT pessoa_pk PRIMARY KEY,
    cpf CHAR(11) NOT NULL CONSTRAINT cpf_pes_sk UNIQUE,
    nomepes VARCHAR(40),
    titulopes CHAR(1) CONSTRAINT titulopes_ck CHECK(titulopes IN (’ N ’, ’ G ’, ’ M ’, ’ D ’)) 5
);

CREATE TABLE ATIVIDADE (
    idati SERIAL CONSTRAINT idequ_equ_pk PRIMARY KEY,
    descricaoati VARCHAR(50),
    idpro INT,
    idatisuper INT
);

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*    TABELAS DERIVADAS DE ESPECIALIZACOES DO EER               */
/* ------------------------------------------------------------ */
CREATE TABLE FUNCIONARIO (
    idpes INT CONSTRAINT funcionario_pk PRIMARY KEY,
    salariofun DECIMAL (10, 2)
);

CREATE TABLE BOLSISTA (
    idpes INT CONSTRAINT bolsista_pk PRIMARY KEY,
    valorbol DECIMAL (10, 2)
);

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*    TABELAS DERIVADAS DE UNIAO DO EER                         */
/* ------------------------------------------------------------ */
/* NAO HA */
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*    TABELAS DERIVADAS DE RELACIONAMENTO MxN DO EER            */
/* ------------------------------------------------------------ */
CREATE TABLE PESATI (
    idpes INT NOT NULL,
    idati INT NOT NULL,
    CONSTRAINT pesati_pk PRIMARY KEY (idpes, idati)
);

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/*                    CHAVES ESTRANGEIRAS                       */
/* ------------------------------------------------------------ */
ALTER TABLE
    PROJETO
ADD
    CONSTRAINT idage_projeto_fkFOREIGN KEY (idage) REFERENCES AGENCIA DEFERRABLE;

ALTER TABLE
    PROJETO
ADD
    CONSTRAINT idpes_projeto_fkFOREIGN KEY (idpes) REFERENCES FUNCIONARIO DEFERRABLE6;

ALTER TABLE
    ATIVIDADE
ADD
    CONSTRAINT idpro_atividade_fkFOREIGN KEY (idpro) REFERENCES PROJETO DEFERRABLE;

ALTER TABLE
    ATIVIDADE
ADD
    CONSTRAINT idatisuper_atividade_fkFOREIGN KEY (idatisuper) REFERENCES ATIVIDADE DEFERRABLE;

ALTER TABLE
    FUNCIONARIO
ADD
    CONSTRAINT idpes_funcionario_fkFOREIGN KEY (idpes) REFERENCES PESSOA DEFERRABLE;

ALTER TABLE
    BOLSISTA
ADD
    CONSTRAINT idpes_bolsista_fkFOREIGN KEY (idpes) REFERENCES PESSOA DEFERRABLE;

ALTER TABLE
    PESATI
ADD
    CONSTRAINT idpes_pesati_fkFOREIGN KEY (idpes) REFERENCES PESSOA DEFERRABLE;

ALTER TABLE
    PESATI
ADD
    CONSTRAINT idati_pesati_fkFOREIGN KEY (idati) REFERENCES ATIVIDADE DEFERRABLE;

COMMIT;