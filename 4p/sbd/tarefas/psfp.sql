SET search_path TO sfp;
--ROLLBACK;BEGIN TRANSACTION;SET CONSTRAINTS ALL DEFERRED;
INSERT INTO
    agencia
VALUES
(default,'CAPES','F', 1000000000.00),
(default,'CNPQ','F', 1000000000.00),
(default,'FAPEMIG','E', 500000000.00),
(default,'FAUDI','M', 50000000.00);

INSERT INTO
    pessoa
VALUES
(default,'11111111111','Karel abraham','D'),
(default,'22222222222','Tito Rabat','M'),
(default,'33333333333','Maverick Viales','G'),
(default,'44444444444','Valentino Rossi','N');

INSERT INTO
    funcionario
VALUES
(1, 10000.00),
(2, 5000.00);

INSERT INTO
    bolsista
VALUES
(1, 1000.00),
(2, 500.00),
(3, 11000.00),
(4, 5500.00);

INSERT INTO
    projeto
VALUES
(
        default,
       'Interlagos',
        DATE'01 / 01 / 2020',
        10,
        1,
        1
    ),
(
        default,
       'Jacarepagua',
        DATE'01 / 01 / 2021',
        20,
        2,
        2
    );

INSERT INTO
    atividade
VALUES
(default,'Primeira atividade', 1, NULL),
(default,'Segunda atividade', 1, 1),
(default,'Terceira atividade', 1, 1),
    (default,'Quarta atividade', 1, 2),
    (default,'Quinta atividade', 1, 3),
    (default,'Sexta atividade', 1, 2),
    (default,'Atividade 7 nivel 0', 2, NULL),
    (default,'Atividade 8 nivel 1', 2, 7),
    (default,'Atividade 9 nivel 1', 2, 7),
    (default,'Atividade 10 nivel 2', 2, 8),
    (default,'Atividade 11 nivel 2', 2, 9),
    (default,'Atividade 12 nivel 2', 2, 9);

INSERT INTO
    pesati
VALUES
    (1, 1),
    (1, 5),
    (2, 1),
    (3, 1);

END TRANSACTION