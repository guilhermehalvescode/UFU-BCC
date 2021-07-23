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
  - **Problemas**
    - Inconsistências ou redundâncias
      - Formatos distintos, linguagens, atributos, alto custo, alterações parciais (arquivos separados não são alterados igualmente).
    - Acesso aos dados
      - Fazer uma nova funcionalidade requer escrever um novo programa.
    - Isolamento de dados
      - Não há isolamento de dados e programas
      - O formato dos dados depende dos programas específicos.
    - Integridade
      - As restrições são implementadas por códigos prórios.
      - Dificil implementar restrições
    - Atomicidade (Impossibilidade de fazer tarefas imcompletas)
      - Atomicidade significa que um conjunto de operações devem ser executadas por completo, ou nenhuma deve ser executada, se ocorrer um erro.
      - Isso é difícil de se manter em programas próprios.
    - Acesso concorrente
      - Vários sistemas exigem acesso simultâneo (concorrente).
      - É difícil garantir a consistência dos dados nesse tipo de acesso.
    - Escalabilidade
      - Acesso a um volume grande de dados pode ser ineficiente
      - Crescimento de funcionalidades pode se difícil de implementar.
    - Segurança
      - Grandes sistemas têm vários usuários que possuem acessos restritos
      - É difícil controlar acesso em Arquivo Convencionais.

- Componentes de um SBD

  ![SBD](images/sbd.png "sbd")

- Capacidades de um SGBD
  - controlar transações, acessos, redundâncias
  - garantir restrições de integridade
  - backup e recuperação
  
- Características e Viabilidade
  - CARACTERÍSTICAS DA ABORDAGEM BASEADA EM BD
    - repositório para diversas aplicações
    - dados e metadados
  - VIABILIDADE
    - investimento em HW E SW
    - porte de aplicações
    - necessidade de concorrência (transações)

- Níveis de Abstração

  ![abstração](images/abstracoes.png)

- Independência de Dados
  - Independência Lógica: alterações no nível lógico não afetam os programas
    - Exemplo: inserção de uma nova tabela
  - Independência Física: alterações na estrutura de arquivos e índices não afetam o nível lógico
    - Exemplo: criação de um índice para melhoria de desempenho

- Profissionais envolvidos
  - Implementadores de DB
  - Projetistas de DB Lógico
  - Projetistas de DB Físico
  - Administradores de banco de dados (DBA)
  - Programadores de aplicativos
  - Usuários finais

- Histórico de SBD e Arquitetura de DB
  - Sistemas monolíticos centralizados
  - Arquitetura cliente/servidor em duas camadas
  - Arquitetura cliente/servidor em três camadas
    - Cliente => GUI/Apresentação
    - Servidor Web => Aplicação/Lógica
    - Servidor de DB => SGBD/Serviços DB
  - DB e mobilidade => devido à possibilidade de desconexão, o conceito de trabalho offline seguido de sincronização é importante
  
- Linguagens de Definição e Manipulação
  - DDL define:
    - esquema conceitual
    - esquema interno
    - esquema externo
  - DML manipula:
    - busca
    - inserção
    - modificação
    - remoção

- Outras Linguagens
  - API
    - ODBC
    - JDBC
    - Outros Drivers
  - INTERFACE:
    - menus
    - formulários
    - gráficas
    - administração
  - UTILITÁRIOS:
    - carga
    - backup
    - recuperação
    - monitoração

- Arquitetura de um SGBD Relacional

  ![arqSGBD](images/arqSGBD.png)

- Modelo de Dados
  - É um conjunto de ferramentas para descrever dados, incluindo relacionamentos e restrições de integridade
  - Exemplos
    - Modelo de Entidade-Relacionamento - ER/MER
    - Modelo Orientado a objetos
    - Modelo Semântico de Dados
    - Modelo Hierárquico
    - Modelo de Redes
    - Modelo Relacional
    - Modelo Relacional - Orientado a objeto

## _**Modelo de Entidade-Relacionamento (ER / MER / DER)**_

- Também chamado de Modelo de Entidade-Relacionamento ou Diagrama de Entidade-Relacionamento
- Uma visão panorâmica

  ![visaoPanoramica](images/visaoParoramica.png)

- É uma modelagem de dados em alto nível com foco do domínio do problema e não na solução
- Elemetos básicos
  - Modelar conceitos do mundo real
  - Modelar as características dos conceitos
  - Modelar os relacionamentos entre conceitos
- O MER, ou ER, tem como objetivo facilitar o projeto de BD por meio de um modelo indendente da implementação de fácil compreensão por parte do usuário
- A partir dos requisitos, consegue-se modelar um DER
- Conceitos básicos
  - Entidade, Tipo Entidade e Conjunto de Entidades
  - Relacionamento e Conjunto de Relacionamentos
  - Atributos
- Def: O Diagrama ER-DER é uma representação gráfica de Entidades, Atributos, e Relacionamentos que modelam o Esquema de um Banco de Dados
- **DER Exemplo - Company Database**

  ![Company Database DER](images/DER.png)

***

- Definições
  - **Entidade:** é um conceito do mundo real com existência independente
    - Ex: empregado (conceito físico), projeto, curso (conceito abstrato)
  
    ![entidadeRepresentação](images/entidade.png)
    - o retângulo representa uma **Entidade**
    - o tipo _Empregado_ representa um Conjunto de Entidades, ou seja, todas as instâncias do BD
  - **Atributo:** é uma propriedade da entidade (campo de um objeto)
    - Ex: código, nome, créditos

      ![atributosRepresentação](images/atributos.png)
    - Um atributo no DER é representado por uma elipse ligada à entidade
    - **Existem vários tipos de atributos:**
    - Simples: atributo que não possui divisão (sexo, cpf - não podem ser subdivididos)
    - Composto: atributo que pode ser dividido em partes com significados diferentes
    ![atributosVariações](images/atribuitosVar.png)
      - Uma atributo composto pode formar uma hierarquia
      ![hierarquiaAtributos](images/hierarquiaAtributos.png)
    - Monovalorado: atributo possui um único valor (nome - uma pessoa só pode ter um nome)
    - Multivalorado: atributo que possui um conjunto de valores para uma mesma entidade (telefone - uma pessoa pode ter mais de um telefone)
      - No DER, um atributo multivalorado é representado por uma elipse com contorno em linha dupla
      ![atributosMultivalorados](images/atributosMultivalorados.png)
    - Chave (Primary Key): é um atributo cujos valores são distintos para instâncias distintas de um Conjunto de Entidades (código de uma disciplina/sigla ou código de uma turma - são valores únicos para instâncias diferentes)
    ![atributosChave](images/atributosChave.png)
      - Obs: uma entidade pode ter mais de um atributo chave
    - Derivado: é um atributo que não está definido, mas pode ser obtido a partir de outros atributos através de algum procedimento (não precisa ser armazenado)
      - idade (se houver a data de nascimento, podemos calcular a idade) 
      - numero de empregados de um departamento (se houver uma tabela de empregados relacionados a uma tabela de departamentos, podemos contar quantos empregados estão relacionados à aquele departamento específico)
      ![atributosDerivados](images/atributosDerivados.png)
        - Obs: No DER uma atributo derivado é representado por uma elipse com contorno em linha tracejada (este atributo não será armazenado fisicamente no BD)
  - **Relacionamento:** é uma associação entre entidades que é definido quando uma entidade se refere a outra. Ex: lotação de um empregado em um departamento

    ![relacionamento](images/relacionamento.png)
    - Um relacionamento no DER é representado por um losango às entidades (existem vários tipos de relacionamentos)
    - Papeis em relacionamentos:  papel em um relacionamento define como a entidade participa do mesmo
      - Ex: empregado está lotado em departamento e departamento tem lotação de empregados
      - Muitas vezes o papel está implícito e não é representado no ER
    - Auto-relacionamento: associam instâncias de uma mesma entidade
      - Ex: supervisão de empregados (um empregado pode ser supervisor de outros empregados), papéis: empregado é supervisor de empregado, e empregado é supervisionado por empregado
      - É necessário indicar os papéis que são denotados por rótulos nas linhas que modelam o relacionamento
      ![autoRelacionamento](images/autoRelacionamento.png)
    - Cardinalidade em Relacionamentos: é uma restrição na quantidade máxima de instâncias de uma entidade que podem estar associadas a uma instância de outra entidade
      ![cardinalidadeRelacionamentos](images/cardinalidadeRelacionamentos.png)
      - No DER definimos a cardinalidade de N ou 1, neste caso, indicando que uma instância de funcionário pode estar associadas a, no máximo, uma instância de departamento (um funcionário só trabalha para um departamento, mas um departamento tem vários funcionários)
    - Participação em Relacionamentos:
      - Participação Total: é uma restrição que indica a necessidade de que qualquer instância da entidade, estar associada a, no mínimo, uma instância no relacionamento
        - Ex: toda instância de PROJECT necessariamente está associada a um departamento no relacionamento CONTROLS (_Não pode existir um projeto no Conjunto de Entidades que não esteja relacionado a um departamento_)
        ![relacionamentoTotal](images/relacionamentoTotal.png)
        - No DER um relacionamento com participação total é indicado por meio de uma linha dupla . Quando não é total, chamamos de ***Participação Parcial***
        - Participação Parcial: no caso do exemplo acima, um departamento pode não ter um projeto relacionado a ele
    - Entidade Fraca: é aquela que não possui um atributo chave e é identificada por meio de um relaciomento total com pelo menos um tipo Entidade Forte
      - Ex: Dependente/Entidade Fraca, Funcionário/Entidade Forte
  
      ![entidadeFraca](images/entidadeFraca.png)
      - No DER, um Tipo Entidade Fraca é representado por meio de retângulo com contorno em linha dupla. O relacionamento total com pelo menos uma entidade forte é denotado por um losângulo com contorno em linha dupla. A "chave local" é denotada por sublinhado pontilhado. A Chave de uma instância de uma entidade fraca é um atributo composto pela chave da entidade forta mais a sua "chave local"
    - Grau de Tipo-Relacionamento: é o número de entidades que participam
      - Ex: relacionamentos de grau 3 (ternário) ligam 3 entidades, por exemplo: relacionamento entre agencia, cliente e conta
      ![relacionamentoGrau](images/relacionamentoGrau.png)
      - Um tipo-relacionamento de grau n tem n arocs no diagrama
    - Relacionamentos binário/ternário: diferença entre um relacionamento ternário e três relacionamentos binários 
  
      ![relacionamentoTernario](images/relacionamentoTernario.png)
      ![relacionamentoBinario](images/relacionamentoBinario.png)

## _**Modelo de Entidade-Relacionamento-Estendido (EER / MEER / DEER)**_

- Intriduz semântica adicional ao ER  
- Entidades do ER podem representar
  - CLASSE
  - SUBCLASSE
  - SUPERCLASSE
- HERANÇA
  - subclasses herdam atributos da superclasse

- ERR - Especilização/ Generalização
  - ESPECIALIZAÇÃO: definir sub-classes à partir da super-classe
  - GERERALIZAÇÃO: definir super-classe à partir de sub-classes

    ![especializacaoGeneralizacao](images/especializacaoGeneralizacao.png)
  
  - Exemplo
    
    ![especializacaoGeneralizacaoExemplo](images/especializacaoGeneralizacaoExemplo.png)
    - Cada entidade do Conjunto de Entidades das subclasses também é um empregado
  
- EER - Herança de Relacionamentos
  - Além dos atributos, as subclasses herdam os relacionamentos das superclasses
  - Uma instância da superclasse pode ser instânciada de zero, ou mais suclasses, dependendo do ***critério de especialização/generalização***

- EER - Especialização/Generalização (Notação)

  ![especializacaoGeneralizacaoNotacao](images/especializacaoGeneralizacaoNotacao.png)

- EER - Subclasses mutuamente esclusivas
  - Critério de Especialização/Generalização
    - Disjunto: este critério modela uma restrição tal que as subclasses são mutuamente exclusivas, ou seja, uma instância da superclasse pode ser, no máximo, a instância de uma das subclasses

      ![disjointNot](images/disjointNot.png)

      - No DER, o critério disjunto é indicado pela letra "d" no relacionamento de superclasse/subclasse 
      - Uma instância de disciplina não pode ser de graduação e pós-graduação

        ![exemploGraduacao](images/exemploGraduacao.png)
    - Sobreposto: subclasses se sobrepõem, ou seja, uma instância de superclasse pode ser instância de mais de uma subclasse

      ![overlapNot](images/overlapNot.png)
      - No DER, o critério sobreposto é o *default* ou pode ser explicitado pela letra "o"
      - Uma instância de pessoa pode praticar mais de um tipo de esporte

        ![exemploEsporte](images/exemploEsporte.png)

- EER - Exemplo de Especialização

  ![exemploEmpresa](images/exemploEmpresa.png)
  - Notação de união, significa que herda (extends)

- EER - Exemplo de Generalização

  ![exemploVeiculos](images/exemploVeiculos.png)
  - As entidades "car" e "truck" foram generalizadas na "vehicle"

- EER - Exemplo definida como atributo

  ![exemploEmpresaAtributo](images/exemploEmpresaAtributo.png)
  - Especialização é vista como um "job type"

- EER - Herança múltipla em subclasses

  ![herancaMultipla](images/herancaMultipla.png)

- EER - Categoria (_UNION TYPE_ ou _CATEGORIA_)
  - União de entidades(superclasses) formando categorias (ou clusters), onde a instância de uma subclasse da categoria tem que ser instância d epelo menos uma das superclasses
  - A categoria é modelada por meio de um relacionamento (União) da subclasse com mais de uma superclasse, e a subclasse representa um subconjunto da união de todas as superclasses

    ![exemploCategoria](images/exemploCategoria.png)

- EER - Agregação
  - É um conceito de abstração para a criação de objetos compostos com base em componentes (três casos)
    1. Entidade agrega atributos de objetos para representar um objeto mais complexo (ex: COMPA agrega CNa e Caddr)
    2. Relacionamento que agrega atributos (ex: INTERVIE agrega ContactNa e ContactPho)
    3. Entidade que representa objeto agregado a partir do relacionamento de outros objetos (não é natural no ER. Como resolver isso?)

        ![exemploEntrevista](images/exemploEntrevista.png)

  - O problema: como relacionar Entrevista a outra entidade chamada Oferta de emprego?
    - Resolução: Abordagem com Entidade_Fraca
  
      ![resolucaoEntidadeFraca](images/resolucaoEntidadeFraca.png)

  - Exemplo de EER

    ![exemploAeroporto](images/exemploAeroporto.png)

- Projeto Conceitual - UML
  - Diagramas de classes da UML como alternativa de modelagem conceitual

    ![umlEmpresa](images/umlEmpresa.png)

  - UML - Especialização/Generalização

    ![umlEspecializacaoGeneralizacao](images/umlEspecializacaoGeneralizacao.png)