CREATE SCHEMA ACADEMICO;
SET search_path TO ACADEMICO;

CREATE TABLE CURSO (
  idcur SERIAL PRIMARY KEY NOT NULL,
  nomecur VARCHAR(50) UNIQUE NOT NULL
);

-- tipo alu: Mestrado, Doutorado, Pos-Doutorado
CREATE TABLE ALUNO (
  idalu SERIAL PRIMARY KEY NOT NULL,
  nomealu VARCHAR(50) NOT NULL,
  tipoalu CHAR(1) NOT NULL CHECK (tipoalu IN ('M', 'D', 'P')),
  idcurso INT NOT NULL,
  CONSTRAINT fk_idcurso_aluno
    FOREIGN KEY(idcurso)
      REFERENCES CURSO(idcur)
);

CREATE TABLE DISCIPLINA (
  iddis SERIAL PRIMARY KEY NOT NULL,
  nomedis VARCHAR(50) NOT NULL
);

CREATE TABLE PRE_REQUISITO (
  iddis INT NOT NULL,
  idpre INT NOT NULL,
  PRIMARY KEY (iddis, idpre),
  CONSTRAINT fk_iddis_pre
    FOREIGN KEY(iddis)
      REFERENCES DISCIPLINA(iddis),
  CONSTRAINT fk_idpre_pre
    FOREIGN KEY(idpre)
      REFERENCES DISCIPLINA(iddis),
  CHECK(iddis != idpre)
);

CREATE TABLE PROFESSOR (
  idprof SERIAL PRIMARY KEY NOT NULL,
  nomepro VARCHAR(50) NOT NULL
);

CREATE TABLE TURMA (
  idtur SERIAL PRIMARY KEY NOT NULL,
  iddis INT NOT NULL,
  ano INT NOT NULL CHECK (ano >= 0),
  semestre INT NOT NULL CHECK (semestre IN (1, 2)),
  codtur VARCHAR(10) NOT NULL,
  UNIQUE(iddis, ano, semestre, codtur),
  CONSTRAINT fk_iddis_turma
    FOREIGN KEY(iddis)
      REFERENCES DISCIPLINA(iddis)
);

CREATE TABLE TURPRO (
  idtur INT NOT NULL,
  idprof INT NOT NULL,
  PRIMARY KEY(idtur, idprof),
  CONSTRAINT fk_idtur_turpro
    FOREIGN KEY (idtur)
      REFERENCES TURMA(idtur),
  CONSTRAINT fk_idprof_turpro
    FOREIGN KEY (idprof)
      REFERENCES PROFESSOR(idprof)
);

CREATE TABLE HISTORICO (
  idalu INT NOT NULL,
  idtur INT NOT NULL,
  nota INT NOT NULL CHECK (nota >= 0 AND nota <= 100),
  PRIMARY KEY(idalu, idtur),
  CONSTRAINT fk_idalu_hist
    FOREIGN KEY (idalu)
      REFERENCES ALUNO(idalu),
  CONSTRAINT fk_idtur_hist
    FOREIGN KEY (idtur)
      REFERENCES TURMA(idtur)
);