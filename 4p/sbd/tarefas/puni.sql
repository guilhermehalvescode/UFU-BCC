SET search_path TO uni;
TRUNCATE aluno, bloco, disciplina, facul_disciplina, 
	faculdade, ic, matricula, pessoa, professor_turma,
	requisito_disciplina, sala, tecnico_adm, telefone,
	turma CASCADE;
START TRANSACTION;
SET search_path TO uni;
SET CONSTRAINTS ALL DEFERRED;
/* BLOCOS */
INSERT INTO bloco VALUES 
  (1, '1B'),
  (2, '1C'),
  (3, '1D'),
  (4, '2F'),
  (5, '2G');

/* FACULDADES */
INSERT INTO faculdade VALUES
  (1, 'FACOM', 120000.70, 1, 1),
  (2, 'FAGEN', 300000.70, 5, 2),
  (3, 'FAMAT', 100000.70, 3, 3);

/* SALAS */
INSERT INTO sala VALUES 
  (1, 201, 40, 1),
  (2, 202, 20, 1),
  (3, 203, 30, 1),
  (4, 100, 10, 2),
  (5, 101, 20, 2),
  (6, 301, 30, 3),
  (7, 302, 40, 3),
  (8, 110, 50, 4),
  (9, 111, 40, 4),
  (10, 112, 70, 4),
  (11, 100, 25, 5);

/* PESSOAS */
INSERT INTO pessoa VALUES
  (1, 'Gina Maira', '18-06-1975', 1), -- prof facom
  (2, 'André Backes', '17-06-1980', 1), -- prof facom
  (3, 'Zhang', '18-11-1986', 3), -- prof famat
  (4, 'Mário', '30-11-1973', 3), -- prof famat
  (5, 'Janaína', '04-06-1975', 2), -- prof fagen
  (6, 'Jefferson', '12-04-1973', 1), -- tec facom
  (7, 'Guilherme Alves', '04-04-2002', 1), -- aluno facom
  (8, 'Heitor Freitas', '06-06-2000', 1), -- aluno facom
  (9, 'João Pedro', '04-06-1975', 1), -- aluno facom
  (10, 'Felipe', '01-05-1971', 3), -- aluno famat
  (11, 'Carlos', '06-01-1976', 3), -- aluno famat
  (12, 'Ana Luiza', '02-05-1972', 2), -- aluno fagen
  (13, 'Fernanda', '01-05-1988', 2), -- aluno fagen
  (14, 'Fagundes', '01-07-1978', 3), -- tec fagen
  (15, 'Cleber', '06-01-1976', 3); -- tec famat

/* PROFESSORES */
INSERT INTO professor VALUES
  (1, 5000.45),
  (2, 7500.65),
  (3, 6000.45),
  (4, 8000.45),
  (5, 8300.45);

/* TÉCNICOS ADMINISTRATIVOS */
INSERT INTO tecnico_adm VALUES
  (6),
  (14),
  (15);

/* ALUNOS */
INSERT INTO aluno VALUES
  (7, 70.45),
  (8, 65.35),
  (9, 73.75),
  (10, 55.45),
  (11, 85.15),
  (12, 93.35),
  (13, 64.36);

/* TELEFONES */
INSERT INTO telefone VALUES
  (7, '991009714'),
  (7, '32341904'),
  (7, '992549254'),
  (8, '983009746'),
  (9, '991003541'),
  (10, '986459152'),
  (11, '989751532'),
  (12, '991009714');

/* DISCIPLINAS */
INSERT INTO disciplina VALUES
  (1, 'AED1', 'Algoritmos e Estruturas de Dados 1', 50),
  (2, 'AED2', 'Algoritmos e Estruturas de Dados 2', 40),
  (3, 'ICC', 'Introdução à Ciência da Computação', 30),
  (4, 'C1', 'Cálculo Diferencial e Integral 1', 10),
  (5, 'C2', 'Cálculo Diferencial e Integral 2', 20),
  (6, 'C3', 'Cálculo Diferencial e Integral 3', 30),
  (7, 'C4', 'Cálculo Diferencial e Integral 4', 40),
  (8, 'GE', 'Gestão Empresarial', 70),
  (9, 'ADM', 'Administração', 30),
  (10, 'SO', 'Sociedade Organizacional', 50);

/* DISCIPLINAS DAS FACULDADES */
INSERT INTO facul_disciplina VALUES
  (1, 1), -- FACOM
  (1, 2), -- FACOM
  (1, 3), -- FACOM
  (2, 8), -- FAGEN
  (2, 9), -- FAGEN
  (2, 10), -- FAGEN
  (3, 4), -- FAMAT
  (3, 5), -- FAMAT
  (3, 6), -- FAMAT
  (3, 7); -- FAMAT

/* REQUISITOS DAS DISCIPLINAS */
INSERT INTO requisito_disciplina VALUES
  (2, 1), -- AED2 depende de AED1
  (5, 4), -- C2 depende de C1
  (6, 5), -- C3 depende de C2
  (7, 6), -- C4 depende de C3
  (8, 9); -- GE depende de ADM 

/* INICIAÇÕES CIENTÍFICAS */
INSERT INTO ic VALUES
  (10, 3, 'Formalização de Topologias'),
  (8, 1, 'Web Funcional'),
  (7, 2, 'Aplicações de Fractais');

/* TURMAS -> turma(idturma, identific, semestre, ano, iddisc, idsal) */
INSERT INTO turma VALUES
  (1, 'Turma A', 1, 2021, 1, 1), -- turma facom aed1
  (2, 'Turma B', 2, 2021, 2, 2), -- turma facom aed2
  (3, 'Turma C', 1, 2021, 3, 3), -- turma facom icc 
  (4, 'Turma D', 2, 2021, 4, 4), -- turma famat c1
  (5, 'Turma E', 2, 2021, 5, 5), -- turma famat c2
  (6, 'Turma F', 2, 2021, 6, 5), -- turma famat c3
  (7, 'Turma G', 1, 2021, 7, 4), -- turma famat c4
  (8, 'Turma H', 2, 2021, 8, 6), -- turma fagen c1
  (9, 'Turma I', 1, 2021, 9, 7), -- turma fagen c1
  (10, 'Turma J', 1, 2021, 10, 7); -- turma fagen c1

/* PROFESSORES DAS TURMAS */
INSERT INTO professor_turma VALUES
  (1, 1),
  (1, 2),
  (2, 2),
  (2, 3),
  (4, 4),
  (4, 5),
  (4, 6),
  (5, 8),
  (5, 9),
  (5, 10);

/* MATRICULA DOS ALUNOS NAS MATÉRIAS */
INSERT INTO matricula VALUES
  (7, 1, 0, 0),
  (8, 2, 0, 0),
  (11, 2, 0, 0);

END TRANSACTION;
