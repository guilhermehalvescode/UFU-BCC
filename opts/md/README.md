# Mineração de Dados

## Introdução

### Motivação

> O que é mineração de dados?

- é o processo de preparação de dados para uso eficiente em modelos/processos de inteligência artificial
- um dos assuntos mais exitantes da atualidade
- estão presentes nos mais diversos momentos da nossa vida

> Onde é utilizado?

- Pesquisas na internet
- Reconhecimento facial de pessoas em redes sociais...
- Filtrando spans da sua caixa de emails...

> Por que é tão predominante hoje?

- Grandes avanços na coleta de dados e tecnologia de armazenamento permitem que organizações acumulem um vasto conjunto de dados
- Mineração de dados, diferente das técnicas tradicionais de análises de dados, permitem extrair informação úteis desses grandes conjuntos

### Sitemas de Informação e Mineração de Dados

- SI
  - coleta, processa, armazena, analisa e dissemina informações para um objetivo específico
- MD
  - processo de descobrir informações úteis em grandes repositórios de dados de maneira automática

### Visão Geral MD

- Técnicas são desenvolvidas para limpar grandes bases de dados de modo a encontrar padrões novos e úteis que podem, caso contrário, permanecer desconhecidos

- Esquema geral: dados => informação
  - Input Data => Pre-processamento de dados => Mineração de dados => Pos-processamento de dados => Informação

### Surgimento da área

Desafios colocados pelas novas bases de dados que motivaram o surgimento da mineração de dados:

- Escalabilidade
  - bases de dados com gigabytes ou terabytes de dados
- Alta dimensionalidade de dados
  - bases de dados com centenas ou milhares de atributos
- Dados complexos e heterogêneos
  - bases podem conter atributos contínuos, categórigos, textos semi-estruturados, etc;
- Propriedades dos dados e distribuição
- Análises não tradicionais

### Áreas Relacionadas à MD

- Amostragem, estimação e testes de hipótese a partir da Estatística
- Busca, técnicas de modelagem e teorias de aprendizado a partir da Inteligẽncia Artificial

### Etapas do Processo de Descoberta do Conhecimento

#### Dados de entrada

- podem ser armazenados em uma variedade de formatos (tabelas relacionais, planilhas, etc)

#### Pré-processamento dos dados

- etapa que visa colocar os dados de entrada em um formato apropriado para análise subsequente
- tarefas relacionadas à esta etapa incluem união de dados de várias fontes, limpeza dos dados a fima de remover ruídos e observações duplicadas e seleção manual de registros e características que são relevantes para a tarefa de mineração de dados
- devido às muitas formas que dados podem ser coletados e armazenados, **esta etapa é talvez a mais trabalhosa** e a que consome mais tempo dentro do processo de descoberta de conhecimento

#### Pós-processamento de dados

- integração dos resultados de mineração de dados aos sistemas de apoio à decisão
- essa etapa assegura que somente resultados válidos e úteis são incorporados ao sistema de apoio à decisão
- medidas estatísticas ou métodos de teste de hipótese podem ser aplicados durantes a fase para eliminar reultados de MD falsos

#### Tarefas de Mineração de Dados

Normalmente, são divididas em duas categorias

- Tarefas preditivas
  - almejam prever os valores de um atributo particular tendo baseado ns valores de outros atributos
  - o atributo a ser predito é denominad alvo (target) ou variável depedente, enquanto os atributo usados para fazer a predição são chamados de explicativos ou variáveis independentes.

- Tarefas descritivas
  - almejam derivar padrões (correlação, agrupamentos, anomalilas, etc) que resumam as relações subjacentes nos dados
  - tarefas descritivas e francamente requerem téncicas de pós-processamento para validar e explicar os resultados

Exemplos de tarefas de mineração de dados bastante comuns e que serão estudadas na disciplina:

- modelagem preditiva
  - modelo para predição da variável alvo em função as variáveis independentes: regressão e classificação
- análises de associação
  - descoberta de padrões que descrevem atributos fortemente associados na base dados
- agrupamento
  - busca por grupos de observações com alguma similaridade
- detecção de anomalia
  - identificação de observações com caraterísticas que distoam do padrão

## Dados

> Objetivos?

- Compreender conceitos relacionados aos tipos de dados e entender bases de dados podem ser formadas por diferentes tipos de dados
- Analisar a importância da qualidade dos dados no processo de mineração e aprender técnicas que podem ajudar a melhorar a qualidade dos dados
- Estudar as principais etapas de pré-processamento dos dados

### Bases de dados

- uma base de dados pode ser vista como uma coleção de objetos de dados
- objetos de dados são descritos por um número de atributos que capturam as caraterísticas básicas de um objeto

> Frequentemente, uma base de dados é um arquivo, no qual os objetos são linhas no arquivo e cada coluna corresponde a um atributo

### Tipos de dados

#### Atributos e medidas

- Atributos é uma propriedade ou caracterísitca de um objeto que pode variar, ou de um objeto para outro ou de um tempo para outro

- Medida de escala é uma função que assoca um valor numérico ou simbólico ao atributo de um objeto
  - Fazemos o processo de atribuir medidas em vários momentos
    - pesando
    - classificando as pessoas em homens e mulher
    - contando
  - Em todos esses casos, o valor físico de um atributo de um objeto é mapeado para um valor simbolico ou numérico

#### Tipo de um atributo

- Aponta quais propriedades dos atributos são refletidas nos valores para medí-lo

- Pode-se definir quatro tipos de atributos:
  - nominal, ordinal, intervalo, frequência
- Obs: Atributos nominais e ordinais são denominados atributos categóricos, enquanto atributos de intervalos e frequência são denominados atributos numéricos

#### Descrição de atributos pelo número de valores

- Atributos podem ser divididos pelo número de valores que podem ter:
  - Discreto: atributos que possuem um conjunto de valores finitos ou "contavelmente" infinito
    - Binário: um caso especial do atributo discreto, onde apenas 2 valores são assumidos, p. ex: verd/false
  - Contínuo: valores reais

#### Tipos de bases de dados

- Características gerais:
  - Dimensionalidade
  - Esparsidade
  - Resolução
- Três grupos* de bases de dados:
  - Dados de registros
  - Dados baseados em grafo
  - Dados ordenados

> Esses grupos não cobrem todas as possibilidades de bases de dados

### Qualidade dos dados

#### Medidas e erros na coleta de dados

- Erros de medida referem-se a qualquer problema resultante do processo de medida dos dados
- Erro de coleta dos dados referem-se a erros tais como, omissão de objetos de dados ou valores de atributos, ou inapropriadamente incluir um objeto de dado

#### Ruídos

- É o componente aleatório de um erro de medida. Ele pode envolver distorção de um valor ou a adição de um objeto sujo
  - Eliminação de ruído costuma ser difícil
  - Muitas pesquisas focam no desenvolvimento de algoritmos robutos
    - produzem resultados aceitáveis mesmo quando há presença de ruídos

#### Outlier

- São objetos de dado que, de alguma forma, tem características diferentes da maioria dos outros objetos de dados na base de dados ou ainda valores de um atributo que não são comuns em relação aos valores típicos para aquele atributo

#### Ausência de valores

- Ausência de um ou mais valores de atributos em um objeto
  - Há várias estratégias para lidar com esse problema, sendo cada uma delas adequada para uma situação distinta
    - Eliminar objetos de dados ou atributos
    - Estimar os valores ausente
    - Ignorar os valores ausentes durante a análise

---

Outros problemas que podem comprometer a qualidade dos dados são:

- Dados inconsistentes
  - Dados que estão errados, P.ex: Valor do atributo peso negativo, ou valor do campo CEP com 2 dígitos
  - Dados duplicados, P.ex: email duplicado