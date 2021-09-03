-- Codificação em SQL/DDL feita a partir do 
-- DEER do exercício anterior

CREATE SCHEMA SFP;
SET search_path TO SFP;

CREATE TABLE FUNCIONARIO (
  idfun SERIAL NOT NULL PRIMARY KEY,
  fk_pes INT NOT NULL,
  sal_mensal DECIMAL(10, 2) NOT NULL CHECK (sal_mensal > 0)
);

CREATE TABLE BOLSISTA (
  idbols SERIAL NOT NULL PRIMARY KEY,
  fk_pes INT NOT NULL,
  bolsa_mensal DECIMAL(10, 2) NOT NULL CHECK (bolsa_mensal > 0)
);

CREATE TABLE PESSOA (
  idpes SERIAL NOT NULL PRIMARY KEY,
  cpf VARCHAR(11) NOT NULL UNIQUE,
  nome VARCHAR(50) NOT NULL,
  titulacao CHAR(1) CHECK (titulacao IN (NULL, 'G', 'M', 'D')),
  fk_func INT,
  fk_bols INT
);

ALTER TABLE PESSOA ADD CONSTRAINT fk_func_pes FOREIGN KEY(fk_func) REFERENCES FUNCIONARIO(idfun); 
ALTER TABLE PESSOA ADD CONSTRAINT fk_bols_pes FOREIGN KEY(fk_bols) REFERENCES BOLSISTA(idbols);
ALTER TABLE BOLSISTA ADD CONSTRAINT fk_pes_bols FOREIGN KEY(fk_pes) REFERENCES PESSOA(idpes);
ALTER TABLE FUNCIONARIO ADD CONSTRAINT fk_pes_func FOREIGN KEY(fk_pes) REFERENCES PESSOA(idpes);

CREATE TABLE AGENCIA (
  idagencia SERIAL NOT NULL PRIMARY KEY,
  nome VARCHAR(50) NOT NULL UNIQUE,
  orc_anual DECIMAL(10, 2) NOT NULL CHECK (orc_anual > 0),
  tipo CHAR(1) CHECK(tipo IN ('P', 'M', 'E', 'F'))
);

CREATE TABLE PROJETO (
  idproj SERIAL NOT NULL PRIMARY KEY,
  nome VARCHAR(50) NOT NULL,
  data_ini DATE NOT NULL,
  dur_meses INT CHECK (dur_meses > 0),
  fk_fin INT NOT NULL,
  fk_fun INT NOT NULL,
  CONSTRAINT fk_fin_proj
    FOREIGN KEY (fk_fin)
      REFERENCES AGENCIA(idagencia),
  CONSTRAINT fk_coord_proj
    FOREIGN KEY (fk_fun)
      REFERENCES FUNCIONARIO(idfun)
);

CREATE TABLE ATIVIDADE (
  idativ SERIAL NOT NULL PRIMARY KEY,
  nome VARCHAR(50) NOT NULL,
  fk_proj INT NOT NULL,
  fk_ativ_pai INT,
  CONSTRAINT fk_proj
    FOREIGN KEY (fk_proj)
      REFERENCES PROJETO(idproj)
);

ALTER TABLE ATIVIDADE ADD CONSTRAINT fk_ativ_hieraquia FOREIGN KEY (fk_ativ_pai) REFERENCES ATIVIDADE(idativ); 

CREATE TABLE PES_PART_PROJ (
  fk_pes INT NOT NULL,
  fk_ativ INT NOT NULL,
  PRIMARY KEY (fk_pes, fk_ativ),
  CONSTRAINT fk_partic_pes
    FOREIGN KEY(fk_pes)
      REFERENCES PESSOA(idpes),
  CONSTRAINT fk_partic_ativ
    FOREIGN KEY (fk_ativ)
      REFERENCES ATIVIDADE(idativ)
);