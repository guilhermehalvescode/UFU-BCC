# Inteligência Artificial

## Introdução

### Definindo uma IA

- Não existe ua definição unica para IA
- Podem ser essas:
  - Sistemas que pensam como humanos
  - Sistemas que pensam racionalmente
  - Sistemas que agem como humanos
  - Sistemas que agem racionalmente

- Obs:
  - definições na parte de cima (ênfase em processos mentais) e na parte de baixo (ênfase no comportamento)
  - definições na parte da esquerda (ênfase no desempenho humano) e na parte da direita (ênfase na racionalidade)

### Pensando como um humano

- A psicologia cognitiva tenta entender como a mente funciona, criando desta forma modelos
- IA consiste em criar algoritmos que desempenhasm bem uma tarefa e são portanto bons modelos de desempenho humano. Tais algoritmos podem tambem se beneficiar de resultados da psicologia cognitiva (especialmente visão e processamento e linguagem natural)
- Ciência cognitiva: integra IA e tecnicas da psicologia para construir teorias precisas do funcionamento da mente humano

### Agindo como um humano

- Tipificada pelo teste de Turing: um teste que decide se uma maquina e inteligente ou não.

### O Teste de Turing

- Alguns temas abordados:
  - Processamento em Linguagem Natural
  - Sistemas Especialistas
  - Representação do Conhecimento
  - Aprendizagem
- Turing escapa da definição de inteligência

### Pensando Racionalmente

- Usa a logica matematica para capturar o raciocinio
- E atrativa do ponto de vista formal
- Apresenta algumas dificuldades:
  - Tradução: como mapear o ambiente para simbolos
  - Representação: Como representar fenômenos do mundo real (tempo, espaço, etc)?
  - Raciocinio: E possivel fazer manipulação simbolica de forma tratavel?

### Agindo racionalmente

- Nesta abordagem IA e vista como um processo de construir agentes racionais
- O agente racional percebe e age sobre o ambiente para satisfazer seus objetivos
- O agente racional
  - Faz a coisa certa
  - Procurar maximizar a tarefa de atingir seus objetivos
- Nem sempre e possivel executar a melhor ação a existência de determinadas limitações
  - Tempo
  - Processamento computacional
  - Memoria
  - Presença de incertezas

### Abordagem Racional

- Mais generica que a bordagem da leis do pensamento

### Sub-areas de IA

- Raciocinio logico
- Aquisição e Representação de Conhecimento
- Planejamento
- Visão
- Aprendizagem
- Algoritmos geneticos
- Redes neuronais

### Aplicações de IA

- Matematica
  - Prova de teoremas, resolução simbolica de equações, etc;
- Pesquisa Operacional
  - Otimização de busca heuristica
- Jogos
  - Xadrez, dama, etc
- Processamento de Linguagem Natural
  - Tradução automatica, verificadores ortograficos
- Robotica
  - Navegação, manipulação, monitoramento

## Agentes Inteligentes

- Um agente e algo que percebe seu ambiente atraves de sensores e age atraves de atuadores
- Agente humano:
  - Sensores: olhos, ouvido, nariz, ...
  - Atuadores: mãos, pes, boca, ...
- Agente robotico:
  - Sensores: visão, proximidade, contato, ...
  - Atuadores: garra, motores, ...

- Exemplo - Descrever a medida de desempenho, ambiente, sensores e atuadores de um agente que realiza o diagnostico medico de um paciente em um hospital  ch
  - ambiente: consultorio, clinica, hospital
  - medida de desempenho: quantidade de diagnosticos corretos do exame
  - sensores: imagem, 
  - atuadores: gerar documentos (atestado, prescrições), caixas de som

### Agente Baseado em Tabela

- Para construir um agente racional devemos construir uma
tabela que contém a ação apropriada para toda seqüência
possível de percepções

```portugol
Função AGENTE-DIRIGIDO-POR-TABELA(percepção) retorna uma ação
  Variáveis estáticas:
    • percepções, uma seqüência, inicialmente
    vazia
    • tabela, uma tabela de ações, indexada
    por seqüências de percepções, de início
    completamente especificada
  Início
    anexar percepção ao fim de
    percepções
    ação ← ACESSAR(percepções, tabela)
    retornar ação
  fim
```

### Dificuldade com Agente baseado em Tabela

- Seja P o conjunto de percepções possiveis e T o tempo de vida do agente (o numero de percepções que recebera). Assim sendo, a tabela contera $\sum|p|^t$

### Agente baseado em Tabela: Vantagens e Desvantagens

- Vantagens
  - Facil de implementar
  - Arquitetura para problemas simples
  - Podemos adicionar par de entrada-saida sempre que quisermos
- Desvantagens
  - A entrada e pesquisada na tabela, cujo tempo de execução esta diretamente associado ao tamanho da tabela
  - Tudo (entrada-saida) precisa ser escrito na tabela
  - Sem capacidade de aprendizagem

### Outros Tipos de Agentes Programas

- Agentes Reativos Simples
- Agentes Reativos com Estado Interno
- Agentes Baseados em Metas
- Agentes Baseados em Utilidade
- Agentes com Aprendizagem

### Agentes Reativos Simples

- Usam uma regra "Condição/Ação" (tambem denominadas "regras de produção" ou regra "situação/ação" ou regra "se/então")
- Exemplo: Se existe um obstaculo a frente então desvie

### Agente Reativo Baseado em Regras

```portugol
função Agente-Reativo-Simples(percepção) retorna ação
  estatico: regras, um conjunto de regras condição-ação

  estado = INTERPRETA-ENTRADA(percepção)
  regra = CASA-REGRA(estado, regras)
  ação = AÇÃO-DA-REGRA(regra)
  retorna ação
```

### O "Mundo" do Aspirador de Po

- Percepções: localização e presença de po
- Ações: aspirar, ir para a esquerda, ir para a direita, nenhuma (não executa nenhuma ação)

### O Agente Aspirador de Po Reativo

```portugol
Função:
asp-reativo([local,status]) retorna Ação
  Se status = sujo então returnaspirar
  Se local = A então return movimente-para-direita
  Se local = B então return movimente-para-esquerda
```

### Limitação de Agentes Reativos

- A melhor ação e escolhida somente se o ambiente e totalmente conhecido (ou completamente observavel)

### Agente Reativos: Vantagens e Desvantagens

- Vantagens
  - Facil de implementar (apenas a estrutura IF-ELSE e necessaria)
  - Muito rapido em comparação com outros
  - Eficiente por causa das regras de condição/ação
  - Os agentes reativos são agentes de memoria fixa
- Desvantagens
  - Esses tipos e agentes têm escalabilidade quase zero
  - Aplicavel apenas para sistemas simples e pequenos (entradas e saida limitadas)
  - Sem capacidade de aprendizagem ou inteligência muito limitada
  - Mudança no ambiente exige mudança nas regas de condição/ação

### Limitação de agentes reativos (cont.)

- Suponha que o sensor de localização seja retirado do robô. Qual seria o seu comportamento para as regras especificadas?
- A melhor forma de se tratar com um estado parcialmente conhecido (parcialmente observavel) e manter um historico de informações (um estado interno ou memoria interna)

### Agente Reativo com Estado Interno (agente baseado em modelo)

```portugol
função agente_reativo_com_memória(percepção) retorna uma ação
  persistente:
    estado (atual)
    regras (do tipo se-então)
    ação (mais recentemente executada)
  estado = atualiza_estado(estado, ação, percepção)
  regra = casamento (estado,regras)
  ação = obtem_ação(regra)
```

### Agente Aspirador com Estado Interno

```portugol
asp-reativo-estado([status]) retorna Ação persistente local
  Se status = sujo então return aspirar
  Se local = A então
    local = B
    return movimente-para-direita
  Se local = B então
    local = A
    return movimente-para-esquerda
```

### Agente Reativos com Estado Interno: Aspectos Positivos

- Mais eficiente do que agentes reativos e agentes baseados em tabela
- Podem trabalhar em um ambiente de tarefa parcialmente observavel

### Agente Reativo com Estado Interno

- Saber o estado atual do mundo não e sempre suficiente para decidir o que fazer
  - Exemplo: Num cruzamento um agente motorista pode ir para diferentes direções. Qual e a melhor escolha? A melhor escolha depende de onde o motorista quer ir. Para isto ele necessita de algum objetivo a ser alcançado

### Agente Baseado em Objetivos

- Raciocina com ações cujos efeitos podem satisfazer objetivos
- E simples quando uma unica ação satisfaz o objetivo. Entretanto, pode ser necessario busca e planejamento. Pode haver projeção de ações para ver se o objetivo pode ser alcançado
- Dificuldade: o ambiente pode mudar enquanto o agente raciocina

### Agente Baseado em Utilidade

- Objetivos não são suficientes para gerar comportamento de alta qualidade: diferentes sequências de ações podem alcançar um dado objetivo
- Função utilidade: mapeia um estado (ou uma sequência de estados) em um numero que descreve o grau de satisfação do agente com a ação tomada
- Informa o quanto um determinado estado do mundo e preferido com relação a outros

### Agente Baseado em Aprendizado

- Codificar comportamento racional para todas as situações do mundo e muito "trabalhoso"
- Agentes inteligentes devem ser capazes de aprender. O comportamento do agente deve ser modificado em função de um feedback recebido pelo ambiente
- Aprendizado permite que agentes operando em ambientes desconhecidos possam se tornar mais competentes que seu conhecimento inical permitia

## Resolvendo Problemas por meio de Tecnicas de Busca

### Revisitando o Agente Reativo

- O agente reativo:
  - E tambem chamado de agente situado ou agente de estimulo-resposta
  - Reage a estimulo do ambiente
  - Não e capaz de planejar com antecedencia
  - Não possui capacidade para tomada de decisões
  - Desconhece as consequências de suas ações

### Resolvendo Problemas

- Um agente que resolve problemas:
  - Decide o que fazer(formula o seu objetivo)
  - Conhece o efeito de suas ações
  - Encontra uma sequência de ações que se executdas satisfaz os seus objetivos

### Resolvendo Problemas: o agente deliberativo

- O agente "deliberativo":
  - Formulação do objetivo e do problema: processo de determinação do objetivo e da escolha relevante de um conjunto de ações e estados
  - Busca: obtem a(s) sequência(s) de ações que satisfaz(em) o objetivo
  - Solução: uma sequência de ações que satisfaz o objetivo
  - Execução: realização das ações da solução

### Descrição do Problema

- Formulação do problema:
  - Envolve o conheciento que o agente deve usar para resolver o problema:
    - Estado inicial (o que o proprio agente sabe)
    - Conjunto de operadores (ações genericas). A execução de uma ação muda o estado do mundo
    - Teste de objetivo: verifica se um certo estado satisfaz um objetivo formulado (um estado ou uma propriedade de um estado)
    - Função custo do caminho(g): soma dos custos das ações em um caminho

### Definindo o Problema atraves de um tipo de dado

- Tipo de dado: Problema
  - Componentes:
    - Estado inicial
    - Operadores
    - Teste de objetivo
    - Função custo

### Busca

- Proposito de uma busca: encontrar uma sequência de ações que transformem o estado inicial do mundo em um estado final (que satisfaça um objetivo)
- Possibilidades:
  - Encontrar uma solução
  - Encontrar a solução otima
- Custo do Caminho X Custo da busca
  - Compromisso entre encontrar a melhor solução e o tempo gasto para obtê-la

### Formulação do Problema: Exemplo

- Exemplo: Ferias na Romênia. No momento em Arad. Desejo estar em Bucharest amanhã.
  - Formulação do objetivo: estar em Bucharest
  - Formulação do problema:
    - Estados: as varias cidades
    - Operadores(Ações): dirigir entre as cidades
    - Função custo: Quilometragem total ou tempo de viagem
    - Teste de objetivo: estou em Bucharest?
  - Encontrar solução: sequência de cidades atingidas saindo de Arad e chegando em Bucharest

> Mapa de estradas

- Quebra-cabeça de 8 ou 15

- Problema das 8 rainhas
  - Teste de objetivo: As oito rainhas estão posicionadas no tabuleiro, De tal forma que nenhuma ataque outra?

### Problemas do Mundo Real

- Navegação de robôs
- Sequenciamento de montagens
- etc

### Busca (continuação)

- O que um algoritmo de busca faz?
  - Gera sequência de ações
  - Multiplas escolhas de caminho
  - Essencialmente faz-se uma escolha e deixa as outras para serem analisadas posteriormente
  - A decisão de quem escolher primeiro define uma estrategia de busca
  - O processo de busca pode ser comparado ao processo de construir uma arvore
  - A raiz da arvore de busca corresponde ao estado inicial
  - Os nos folhas correspondem a estados que não possuem sucessores devido ao fato de não terem sido expandidos ainda ou porque foram expandidos e geraram o conjunto vazio
  - Em cada passo, o algoritmo busca um no folha para expandir

### O Algoritmo de Busca

```portugol
Algoritmo geral de busca:
  Função buscaGeral(problema,estratégia) devolve fracasso ou solução
  Inicio_de buscaGeral
    inicializa a árvore de busca com o estado inicial do problema
    repete
    inicio
      se não existem mais candidatos a serem
      expandidos devolva fracasso
      escolha um nó folha para expandir de acordo
      com a estratégia
      Se o nó contém o estado que satisfaz o objetivo
      então **devolva** a solução
      senão expanda o nó e adicione na árvore de busca
    fim
  Fim-de buscaGeral
```

- Estruturas de Dados para Arvores de Busca:
  - Tipo de dado: no
    - componentes:
      - estado
      - no_pai
      - operador (que foi aplicado para gerar o no)
      - profundidade
      - custo_do_caminho

- E preciso representar a coleção dos nos que necessitam ser expandidos (chamada fronteira)
- A representação mais simples poderia ser um conjunto de nos. A estrategia de busca seria então uma função que seleciona o proximo no a ser expandido do conjunto
- Vamos assumir que esta coleção e representada como uma fila

- Operações associadas a fila:
  - criaFila(elementos): cria uma fila com os elementos dados
  - estaVazia(fila): retorna verdade se não existem mais elementos na fila
  - removeDaFrente(fila): remove o elemento da frente da fila e o devolve
  - enfileira(elementos, fila): insere um conjunto de elementos na fila

- Busca

  ```portugol
  Função buscaGeral(problema, enfileiraF) devolve uma solução ou fracasso
  inicio
    nós <- criaFila(criaNó(estadoInicial(problema)));
    repita
    inicio
      se a fila nós é vazia retorne fracasso
      nó <- removedaFrente(nós);
      se testeDeMeta(problema) aplicada a estado(nó)
        obtém sucesso retorne nó;
        nós <- enfileiraF(nós,expande(nó, operadores(problema))
  fim
  ```

  - Critérios para avaliação de uma estratégia de busca:
    - Completude: se existe uma solução a estratégia será capaz de encontrá-la?
    - Complexidade no tempo: quanto tempo ela demora para obter uma solução?
    - Complexidade de espaço: de quanto memória ela necessita para realizar a busca?
    - Qualidade da solução: a solução encontrada é a solução ótima?
  - Estratégias de Busca não Informadas (Busca Cega) - estas não possuem informação sobre o número de passos ou o custo do caminho entre um nó e nó meta
    - Busca em largura
    - Busca em profundidade
    - Busca de custo uniforme
    - Busca em profundidade limitada
    - Busca em profundidade iterativa
    - Busca bidirecional