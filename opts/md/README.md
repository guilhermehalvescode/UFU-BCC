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

### Pré-processamento dos dados (Métodos)

#### Agregação

> consiste na combinação de dois ou mais objetos em um único objeto

- Segue o princípio de "menos é mais"
- Atributos quantitativos podem ser agregados através de uma soma ou média
- Atributos qualitativos, como um produto p. ex, podem ser omitidos ou sumarizados como o conjunto de todos os produtos vendidos
- Ex: ao invés de usar registros de 365 dias, agrega-se esses registros para 12 meses
- Motivações para agregação
  - menores bases de dados
  - mudança de escala
  - comportamento mais estável dos objetos dos dados e atributos
- Desvantagem: potencial perda de detalhes interessantes

#### Amostragem

> Seleção de um subconjunto dos objetos de dados para ser analisada

- Na estatística, amostragem é utilizada porque trabalhar para obter todo o conjunto de dados inteiro é muito caro ou consome muito tempo
- Na mineração de dados, amostragem é utilizada porque é muito caro ou consome muito tempo para processar todos os dados
- Princípio da amostragem: usar uma amostra funcionará quase tão bem quanto usando um conjunto de dados inteiro se a amostra é representativa

- amostragem aleatória simples?
  - selecionar uma amostra de forma aleatória com probabilidade uniforme
- com recolocação?
- estratificada?

#### Redução de dimensionalidade

> Técnicas que reduzem a dimensionalidade de uma base de dados por criar novos atributos que são uma combinação dos velhos atributos

#### Seleção de subconjunto de features

> Seleção de novos atributos que são um subconjunto dos velhos atributos

- Exemplos: Filtros, wrapper, entre outros

#### Criação de características

- Extração de características
  - Criação de um novo conjunto a partir dos dados originais crús
- Mapeamento dos dados para um novo espaço
  - aplicação de transformada de Fourier em séries temporais com ruídos
- Construção de características
  - base de dados massa e volume

#### Discretização de Binarização

- Discretização
  - processo de transformar atributos contínuos em categóricos
- Binarização
  - processo de transformar atributos contínuos e discretos em atributos binários

#### Transformação de variáveis

> Refere-se a transformação que é aplicada a todos os valores de um atributo

- Transformações funcionais simples
  - uma função matemática simples é aplicada para cada valor individualmente
  - devem ser aplicadas com cautela, pois mudam a natureza dos dados
- Normalização
  - o objetivo dessa transformação é fazer um conjunto inteiro de valores ter uma propriedade particular

## Similaridade

### Para atributos simples

- proximidade entre objetos com apenas um atributo
- atributo nominal
- atributo ordinal
  - ruim, regular, OK, bom, maravilhoso
- atributo intervalar ou de razão

### Dissimilaridade entre objetos de dados

- Normalmente, medidas que calcular a distância entre objetos costumam ser denominadas medidas de dissimilaridade
- Exemplos:
  - Distância Euclidiana
  - Distância de Manhatan
  - Distância de Minkowski

#### Euclideana

- positividade
- simetria
- desigualdade triangular

#### Minkowski

- positividade
- generalização da euclidiana e de manhatan

### Similaridade entre objetos de dados

- Similaridade é o oposto de dissimilaridade

#### Coeficiente de igualdade simples

- Denominado também de SMC
- Similaridade para Dados binários
- SMC = $\frac{f_{11}+f_{00}}{f_{01}+f_{10}f_{11}+f_{00}}$

#### Coeficiente de Jaccard

- Similaridade para Dados binários*
- J = $\frac{f_{11}}{f_{01}+f_{10} + f_{11}}$

#### Similaridade do Cosseno

- Muito usado para calcular similaridade entre documentos
- $\cos(x,y) = \frac{x . y}{||x|| ||y||}$
- ||x|| = $\sqrt{x_1^2 + x_2^2 + ... + x_n^2}$

## Exploração dos Dados

- Aprender a importancia de uma investigação preliminar dos dados a fima de melhor entender algumas características específicas
- Entender que tal investigação pode auxiliar na seleção do pré-processamento e de algorimos de análise mais apropriados

### Estatísticas resumidas

- números que resumem propriedados dos dados
- capturam várias características de um grande conjunto de valores através de um único número ou um pequeno conjunto deles
  
#### Frequência e Moda

- A frequência de um valor de atributo é o percentual de vezes que o valor ocorre na base de dados
- A moda é o valor mais frequente de um atributo

#### Porcentagem

- Para dados contínuos, a noção de porcentagem é mais útil
- Dado um atributo x ordinal ou contínuo e um número p entre 0 e 100, a porcentagem p de x é o valor de x que divide a base de dados em duas partes, uma contendo p% dos objetos de dados e a outra contendo 100-p% dos objetos de dados

#### Medidas de localização: média a mediana

- A média é a medida mais comum de localização de um conjunto de pontos
- Contudo, ela é muito sensível a outliers
- Logo, a mediana é uma medida de localização mais robusta

#### Medidas de localização: variação e variância

- Variação
  - é a diferença entre o maior e o menor valor de um conjunto de pontos
- Variância
  - é uma medida de dispersão que indica o quão distantes os pontos estão da média
  - $\sigma^2 = \frac{\sum_{i=1}^n (x_i - \mu)^2}{n}$
  - $\sigma = \sqrt{\sigma^2}$
  - é a medida mais comum

### Visualização

- Conversão dos dados em um formato visual ou tabular que caracterize os dados
- É uma das técnicas mais salientes e eficazes para a exploração de dados
  - habilidade natural dos seres humanos para entender grandes volumes de dados apresentados visualmente
  - pode detectar tendências
  - pode detectar outliers e padrões incomuns

#### Representação

- Geralmente objetos são representados como pontos
  - os atributos podem ser representados como coordenadas, cores, tamanhos, etc

#### Arranjo

- Arranjo dos pontos em um espaço bidimensional ou tridimensional
- Auxilia no entendimento dos dados

#### Seleção

- Seleção de um subconjunto de atributos de dados para serem visualizados
  - redução de dimensionalidade é comumente utilizado para selecionar os atributos a serem visualizados
- Da enfase a objetos de dados que são mais interessantes
- Seleção de um subconjunto de objetos de dados para serem visualizados
  - pode ser feito de forma aleatória ou de forma estratificada

#### Técnicas

- Histogramas
  - mostra a distribuição de valores de uma única variável
  - mostra a frequência dos objetos em uma faixa de valores
  - pode ser usado para dados contínuos ou discretos
  - ajuda a identificar outliers, valores atípicos, valores faltantes e identificar agrupamentos

- Histogramas bidimensionais
  - mostra a distribuição de valores de duas variáveis
  - mostra a frequência dos objetos em uma faixa de valores
  - pode ser usado para dados contínuos ou discretos
  - ajuda a identificar outliers, valores atípicos, valores faltantes e identificar agrupamentos

- Box Plots
  - mostra distribuição de dados de uma variável
  - ajuda identificar outliers e comparar atributos

- Scatter plots
  - determina a posição através dos valores dos atributos
  - podem ser tridimensionais
  - podem ser usados para dados contínuos ou discretos
  - útil para conjuntos de gráficos que mostram a relação entre pares de atributos

- Countour Plots
  - particiona em regiões o espaço de atributos, utilizando linhas

- Matrix Plots
  - útil quando objetos estão ordenados de acordo com a classe
  - agrupa de forma ordenada os objetos de dados de acordo com a classe
  - pode ser feito no formato de matriz de correlação, mostrando similaridade entre as amostras

### Processamento analítico online - OLAP

- OLAP é um conjunto de técnicas que permitem a análise de dados multidimensionais
- Muitas operações de exploração dos dados são mais fáceis a partir de tal representação
- Há dois passos chaves para converter dados tabulares (relacionais) em multidimensionais
  - Definição de dimensões
  - Definição de medidas