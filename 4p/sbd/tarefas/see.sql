DROP SCHEMA see;
CREATE SCHEMA see;
SET search_path TO see;
-- DERIVADOS DE ENTIDADES REGULARES
CREATE TABLE modalidade (
  idmod SERIAL PRIMARY KEY NOT NULL,
  nomemod VARCHAR(50) UNIQUE NOT NULL
);
-- tipos enumeráveis da categoria
CREATE TYPE tipocat AS ENUM('I', 'C');
CREATE TYPE genero AS ENUM('M', 'F');
CREATE TABLE categoria(
  idcat SERIAL PRIMARY KEY NOT NULL,
  nomecat VARCHAR(50) NOT NULL,
  tipocat tipocat NOT NULL,
  generocat genero NOT NULL,
  idmod INT,
  
  CONSTRAINT idmod
    FOREIGN KEY (idmod)
      REFERENCES modalidade(idmod)
);

CREATE TABLE empresa (
  idemp SERIAL PRIMARY KEY NOT NULL,
  cnpj VARCHAR(14) UNIQUE NOT NULL,
  nomeemp VARCHAR(50) NOT NULL,
  enderecoemp VARCHAR(255) NOT NULL
);

CREATE TABLE pessoa(
  idpes SERIAL PRIMARY KEY,
  cpf VARCHAR(11) UNIQUE,
  nomepes VARCHAR(50) NOT NULL,
  datanas DATE NOT NULL
);

-- DERIVADOS DE MAPEAMENTO DE ESPECIALIZAÇÃO
CREATE TABLE pateve(
  valorpat REAL,
  idemp INT PRIMARY KEY,
  
  CONSTRAINT idemp
    FOREIGN KEY (idemp)
      REFERENCES empresa(idemp)
);

CREATE TABLE patcom(
  idemp INT PRIMARY KEY,
  
  CONSTRAINT idemp
    FOREIGN KEY (idemp)
      REFERENCES empresa(idemp)
);

CREATE TABLE competidor(
  idcompetidor SERIAL PRIMARY KEY
);

CREATE TABLE atleta(
  idpes INT PRIMARY KEY,
  idcompetidor INT UNIQUE,

  CONSTRAINT idpes
    FOREIGN KEY (idpes)
      REFERENCES pessoa(idpes),
  CONSTRAINT idcompetidor
    FOREIGN KEY (idcompetidor)
      REFERENCES competidor(idcompetidor)
);

CREATE TABLE funcionario(
  idpes INT PRIMARY KEY,

  CONSTRAINT idpes
    FOREIGN KEY (idpes)
      REFERENCES pessoa(idpes)
);

CREATE TABLE l0c4l(
  idloc SERIAL PRIMARY KEY,
  enderecoloc VARCHAR(255),
  capacidadeloc INT CHECK (capacidadeloc >= 0),
  idpes INT,
  
  CONSTRAINT idpes
    FOREIGN KEY (idpes)
      REFERENCES funcionario(idpes)
);

CREATE TYPE fase AS ENUM('0', '1', '2', '3', '4', '5', '6' , '7', '8', '9', 'F');


CREATE TABLE competicao (
  idcom SERIAL PRIMARY KEY NOT NULL,
  fase fase,
  datacom DATE,
  horacom TIME WITH TIME ZONE,
  capacidadecom INT CHECK (capacidadecom >= 0 AND capacidadecom <= 100),
  idcat INT,
  idloc INT,

  CONSTRAINT idcat
    FOREIGN KEY (idcat)
      REFERENCES categoria(idcat),
  CONSTRAINT idloc
    FOREIGN KEY (idloc)
      REFERENCES l0c4l(idloc)
);

CREATE TABLE arbitro(
  idpes INT PRIMARY KEY,
  idcoo INT,

  CONSTRAINT idpes
    FOREIGN KEY (idpes)
      REFERENCES pessoa(idpes),
  CONSTRAINT idcoo
    FOREIGN KEY (idcoo)
      REFERENCES arbitro(idpes)
);

-- DERIVADOS DE MAPEAMENTO UNIÃO



CREATE TABLE equipe(
  idequ SERIAL PRIMARY KEY NOT NULL,
  nomeequ VARCHAR(50) NOT NULL,
  idcompetidor INT,
  
  CONSTRAINT idcompetidor
    FOREIGN KEY (idcompetidor)
      REFERENCES competidor(idcompetidor)
);

-- DERIVADOS DE MAPEAMENTO DE RELACIONAMENTO NxM

CREATE TABLE inscricao(
  idcat INT,
  idcompetidor INT,

  CONSTRAINT idcat
    FOREIGN KEY (idcat)
      REFERENCES categoria(idcat),
  CONSTRAINT idcompetidor
    FOREIGN KEY (idcompetidor)
      REFERENCES competidor(idcompetidor),

  PRIMARY KEY (idcat, idcompetidor)
);

CREATE TABLE patrocinio(
  idemp INT,
  idcompetidor INT,

  CONSTRAINT idemp
    FOREIGN KEY (idemp)
      REFERENCES empresa(idemp),
  CONSTRAINT idcompetidor
    FOREIGN KEY (idcompetidor)
      REFERENCES competidor(idcompetidor),

  PRIMARY KEY (idemp, idcompetidor)
);

CREATE TABLE modloc(
  idloc INT,
  idmod INT,

  CONSTRAINT idloc
    FOREIGN KEY (idloc)
      REFERENCES l0c4l(idloc),
  CONSTRAINT idmod
    FOREIGN KEY (idmod)
      REFERENCES modalidade(idmod),

  PRIMARY KEY (idloc, idmod)
);

CREATE TABLE participacao(
  idcom INT,
  idcompetidor INT,
  escore INT,
  unidade INT,

  CONSTRAINT idcom
    FOREIGN KEY (idcom)
      REFERENCES competicao(idcom),
  CONSTRAINT idcompetidor
    FOREIGN KEY (idcompetidor)
      REFERENCES competidor(idcompetidor),
  
  PRIMARY KEY (idcom,idcompetidor)
);

CREATE TABLE modarb(
  idmod INT,
  idpes INT,
  CONSTRAINT idmod
    FOREIGN KEY (idmod)
      REFERENCES modalidade(idmod),
  CONSTRAINT idpes
    FOREIGN KEY (idpes)
      REFERENCES arbitro(idpes),

  PRIMARY KEY (idmod,idpes)
);

CREATE TABLE atlequi(
  idequ INT,
  idpes INT,
  CONSTRAINT idequ
    FOREIGN KEY (idequ)
      REFERENCES equipe(idequ),
  CONSTRAINT idpes
    FOREIGN KEY (idpes)
      REFERENCES atleta(idpes),

  PRIMARY KEY (idequ,idpes)
);