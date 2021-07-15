# Sistemas de Bancos de Dados

## **_Motivação_**

- SBD é essencial para qualquer organização

- O conteúdo da disciplina é fundamental. para a Formação Tecnológica na área de Computação e Informática.

- As técnicas e fomalismos apresentados são importantes no desenvolvimento profissional e na atuação do egresso.

## _**Serve para?**_

- Capacitar o aluno a utilizar princípios e ferramentas teóricas para modelar a semântica de uma aplicação com abordagem de banco de dados.

- Capacitar o aluno a implementar sistemas de informação utilizando uma **Sistema Gerenciador de Banco de Dados - SGBD**.

## _**Objetivos**_

1. Interagir com um SGBD instalado em um servidor, aplicando os conceitos de arquitetura de SGBD.

2. Projetar um esquema de banco de dados e implantar um banco de dados em um servidor.

3. Usar uma linguagem de manipulação de dados para inserção, consultas e atualizaçã ode banco de dados.

4. Implementar visões lógicas do banco de dados.

5. Usar uma linguagem de dados embutida em uma linguagens de desenvolvimento de aplicações.

6. Usar uma linguagem procedural que executa no servidor por meio de funções.

7. Usar uma linguagem procedural no servidor para implementar regras ativas (gatilhos).

8. Implementar controles de segurança e acesso aos dados do banco de dados.

9. Implementar objetos complexos armazenados em um SGBD e a definir estratégias e recursos necessários para implementação de banco de dados distribuídos.

## _**Introdução**_

- **Banco de Dados** é uma coleção de itens de dados relacionandos.

- Propriedades implícitas:
  - Representam uma realidade, significado e são projetados com objetivos definidos.

- > O conceito é aplicado quando há necessidade de armazenar grande volumes de dados.

- **Esquema**, **Instância** e **Estado** de um BD
  - O esquema de um bd é uma descrição dele.
  - Instância é uma ocorrência de um dado, ex: registro de um empregado.
  - Estado é o conjunto de instâncias em um determinado momento de um BD.
  - > Empregado (nome, endereço, ...) <- Esquema
  - > ('Guilherme Alves C', 'Av. Aspirante Mega') <- Instância
  - > Conjunto de instâncias diferentes do banco de dados ao longo do tempo <- Estado

- _Exemplos de BD_
  - Banco de dados de uma empresa, contendo dados de clientes, funcionários, e produtos.
  - Bancos de dados de uma universidade, contando dados de cursos, alunos, professores e técnicos-administrativos. 

- Definição SGBD (Sistema Gerenciador de Banco de Dados)
  - Software que gerencia um ou mais bancos de dados.
  - Oracle, PostgreeSql, MySql, Sybase, MS Sql Server, MS Access, Firebird.

- Definição SBD (Sistema de Banco de Dados)
  - SBD = BD + SGBD + Aplicação.

- Alternativa à abordagem de BD
  - Uso de arquivos com gerenciamento por programas própios.
  - Problemas
    - Inconsistências ou redundâncias.
      - Formatos distintos, linguagens, atributos, alto custo, alterações parciais (arquivos separados não são alterados igualmente).
    - Acesso aos dados.
      - TO-DO
    - Isolamento de dados.
    - Integridade.
    - Atomicidade (Impossibilidade de fazer tarefas imcompletas).
    - Acesso concorrente.
    - Escalabilidade.
    - Segurança. 