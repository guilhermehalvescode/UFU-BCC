# Atividade Prática 3 - Guilherme Alves Carvalho

## Compilação (gcc)

> `gcc app.c ./libs/sharedmems.c ./libs/procs.c -pthread -o exe.out`

## Estrutura

- `./app.c` - arquivo esqueleto disponibilizado pelo professor.
- `./libs` - pasta com modulos utilizados em `./app.c`.
  - `./libs/proc.c` - rotinas com os códigos de todos os processos, assim como funções auxiliares.
  - `./libs/sharedmems.c` - rotinas com criação das memórias compartilhadas f1 e f2, com suas respectivas estruturas e com a utilização de rotinas de manipulação da fila estática com contador.
  
> `./libs/proc.c` e `./libs/sharedmems.c` possuem seus respectivos headers na `./libs`

> Um arquivo `exe.out` também foi enviado, compilado usando gcc em Linux Ubuntu 20.04
