--DROP SCHEMA uni;
CREATE SCHEMA uni;
SET search_path TO uni;
 
/*
MEER - https://whimsical.com/uni-eer-KL8d8md3T7YoTKvKyGHhh9
*/
 
CREATE TABLE bloco (
 idbloc SERIAL PRIMARY KEY NOT NULL,
 nome VARCHAR(50) NOT NULL
);
 
CREATE TABLE sala (
 idsal SERIAL PRIMARY KEY NOT NULL,
 num INT NOT NULL CHECK (num > 0),
 cap INT NOT NULL CHECK (cap > 0),
 idbloc INT NOT NULL, -- bloco em que sala está
 CONSTRAINT bloco_sala
   FOREIGN KEY (idbloc)
     REFERENCES bloco(idbloc)
);
 
CREATE TABLE faculdade (
 idfacul SERIAL PRIMARY KEY NOT NULL,
 sigla VARCHAR(50) UNIQUE NOT NULL,
 orcamento DECIMAL(10, 2) NOT NULL CHECK (orcamento >= 0),
 idpes INT NOT NULL, -- diretor da faculdade
 idbloc INT NOT NULL, -- bloco da faculdade
 CONSTRAINT bloco_faculdade
   FOREIGN KEY (idbloc)
     REFERENCES bloco(idbloc)
);
 
CREATE TABLE pessoa (
 idpes SERIAL PRIMARY KEY NOT NULL,
 nome VARCHAR(50) NOT NULL,
 data_nasc DATE NOT NULL,
 idfacul INT NOT NULL,
  CONSTRAINT vinculo -- pessoa é vínculada a uma instituição
   FOREIGN KEY (idfacul)
     REFERENCES faculdade(idfacul)
);
 
CREATE TABLE professor (
 idpes INT PRIMARY KEY NOT NULL,
 salario DECIMAL(10, 2),
 CONSTRAINT pessoa
   FOREIGN KEY (idpes)
     REFERENCES pessoa(idpes)
);
 
ALTER TABLE faculdade ADD
 CONSTRAINT diretor
   FOREIGN KEY (idpes)
     REFERENCES professor(idpes);
 
CREATE TABLE tecnico_adm (
 idpes INT PRIMARY KEY NOT NULL,
  CONSTRAINT pessoa
   FOREIGN KEY (idpes)
     REFERENCES pessoa(idpes)
);
 
CREATE TABLE aluno (
 idpes INT PRIMARY KEY NOT NULL,
 cra DECIMAL(10, 2) CHECK (cra > 0 AND cra < 100),
 CONSTRAINT pessoa
   FOREIGN KEY (idpes)
     REFERENCES pessoa(idpes)
);
 
-- telefones dos alunos
CREATE TABLE telefone (
 idpes INT NOT NULL,
 telefone VARCHAR(11),
 CONSTRAINT dono_numero
   FOREIGN KEY(idpes)
     REFERENCES aluno(idpes),
 PRIMARY KEY (idpes, telefone)
);
 
CREATE TABLE disciplina (
 iddisc SERIAL PRIMARY KEY NOT NULL,
 sigla VARCHAR(50) NOT NULL,
 nome VARCHAR(50) NOT NULL,
 nro_cred INT NOT NULL CHECK(nro_cred > 0)
);
 
CREATE TABLE requisito_disciplina (
 iddisc INT NOT NULL,
 iddiscreq INT NOT NULL,
 CONSTRAINT disciplina
   FOREIGN KEY (iddisc)
     REFERENCES disciplina(iddisc),
 CONSTRAINT requisito
   FOREIGN KEY (iddiscreq)
     REFERENCES disciplina(iddisc),
 PRIMARY KEY(iddisc, iddiscreq),
 CHECK (iddisc != iddiscreq) -- disciplina não pode ser req dela mesma
);
CREATE TABLE turma (
 idturma SERIAL PRIMARY KEY NOT NULL,
 identific VARCHAR(50) NOT NULL,
 semestre INT NOT NULL CHECK (semestre IN (1, 2)),
 ano INT NOT NULL CHECK (ano > 1950),
 iddisc INT NOT NULL,
 idsal INT NOT NULL,
 CONSTRAINT turma_disciplina
   FOREIGN KEY (iddisc)
     REFERENCES disciplina(iddisc),
 CONSTRAINT local_turma
   FOREIGN KEY (idsal)
     REFERENCES sala(idsal)
);
CREATE TABLE professor_turma (
 idpes INT NOT NULL,
 idturma INT NOT NULL,
 CONSTRAINT prof_disciplina
   FOREIGN KEY (idpes)
     REFERENCES professor(idpes),
 CONSTRAINT turma_lecionada
   FOREIGN KEY (idturma)
     REFERENCES turma(idturma),
 PRIMARY KEY(idpes, idturma)
);
 
CREATE TABLE facul_disciplina (
 idfacul INT NOT NULL,
 iddisc INT NOT NULL,
 
 CONSTRAINT facul_oferece
   FOREIGN KEY (idfacul)
     REFERENCES faculdade(idfacul),
 CONSTRAINT disciplina_oferecida
   FOREIGN KEY (iddisc)
     REFERENCES disciplina(iddisc),
 PRIMARY KEY (idfacul, iddisc)
);
 
 
CREATE TABLE matricula (
 idpes INT NOT NULL,
 idturma INT NOT NULL,
 nota INT NOT NULL CHECK (nota >= 0 AND nota <= 100),
 faltas INT NOT NULL CHECK (faltas >= 0),
 CONSTRAINT aluno_mat
   FOREIGN KEY (idpes)
     REFERENCES aluno(idpes),
 CONSTRAINT turma_mat
   FOREIGN KEY (idturma)
     REFERENCES turma(idturma),
 PRIMARY KEY(idpes, idturma)
);
 
CREATE TABLE ic (
 idaluno INT NOT NULL,
 idprof INT NOT NULL,
 nome VARCHAR(50) NOT NULL,
 CONSTRAINT aluno_ic
   FOREIGN KEY(idaluno)
     REFERENCES aluno(idpes),
 CONSTRAINT prof_ic
   FOREIGN KEY(idprof)
     REFERENCES professor(idpes),
 PRIMARY KEY(idaluno, idprof)
 -- PROFESSOR SÓ PODE TER NO MÁXIMO 8 ICS
);
