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