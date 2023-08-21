# Teoria da Computação

## Introdução

### Motivação

Qualquer que seja a área científica de estudo, existem limites que não podem ser superados, qualquer que seja a tecnologia utilizada

Existem problemas da matemática que não podem ser resolvidos por um programa de computador

Tais problemas devem ser identificados

Para isso, precisamos formalizar as noções de:

- Problema (Como dar uma representação genérica de qualquer problema? Numa forma que o computador vai entender?)
- Programa (O que é exatamente um algoritmo em computação?)

### Noção de Problema

Ex: Determinar se um número natrual é par é um problema

Características de um problema:

- um problema é uma questão genérica que se aplica a um conjunto de elementos (ex: os naturais)
- cada instância de um problema (uma questão que corresponde a um elemento particular do conjunto estudado) tem uma resposta: 35 é par? Resposta: Não
- a noção de problema é independente da noção de programa: não é o programa que define o problema (existem vários programas para resolver um mesmo problema)
- para resolver um problema utilizando um programa é necessário fixar uma representação das instancias do problema (é sobre tal representação que o programa atuará)

### Exemplos de problemas

- ordenar um vetor de números é um tipo de problema que um programa pode resolver
- determinar se um programa escrito em C para qualquer que sejam os dados de entrada (problema da parada): detectar a existência de loop $\infty$
- Quando a resposta de um problema é sempre SIM ou NÃO o problema é chamado de binário (o problema da parada é um problema binário)
- Pode-se verificar que os resultados obtidos para classe dos problemas binários podem ser entendidos aos problema não binários (problema de otimização num grafo por exemplo)

### Noção de Programa

Uma programa (escrito em C por exemplo) que sempre fornece uma resposta para um problema dado é chamado de Procedimento Efetivo

Uma linguagem de programação ficará associada à noção de procedimento efetivo somente se existe um procedimento de interpretação ou compilação que transformará o programa num código diretamente executado pelo processador

Para formalizar a noção de procedimento efetivo, serão utilizados formas de linguagens de programação tão simples que o procedimento de intrepretação será imediato: tais programas serão chamados de Autômatos

> E a noção de Algoritmo?

Até hoje não existe uma definição única e aceita por todos

Para Minsky (1967) por exemplo, um algoritmo (um conjunto de regras que especificam a cada instante o próximo comportamento) é sinônimo de procedimento efetivo

Um dos objetivos da disciplina é de formalizar a noção de procedimento efetivo e de analisar os procedimentos efetivos utilizados como solução de problemas

### Formalização da noção de Problema

Para poder estudar a noção de procedimento efetivo, independentemente do programa e da máquina que o executa, a representação dos dados de entrada do problema deve fazer a abstração dos tipos de dados utilizados pela linguagem de programação

Cada instância do problema será então representada por uma sequência finita de símbolos que pertencem a um conjunto de símbolos que dependem do problema

Exemplos:

- {0, ..., 9} para um problema sobre inteiros
- {a, ..., z} para um problema sobre as instruções de uma linguagem de programação

#### Noção de Alfabeto e Palavras

Def: um alfabeto $\Sigma$ é um conjunto finito de símbolos

Def: uma palavra w (cadeia, string, sequência) definida sobre um alfabeto é uma sequência finita de elementos do alfabeto

O comprimento de uma palavra w será anotado |w|

|w| pode ser igual a 0: trata-se então da palavra vazia anotada geralmente e, $\epsilon$ $\lambda$

#### Representação dos Problemas

Todos os dados manipulados em computação podem ser representados por cadeias de caracteres

Ex: uma imagem será representada por uma sequência das intensidade dos seus pontos

Seja uma problema binário cujas instancias foram condificadas por palavras definidas num alfabeto $\Sigma$

O conjunto de toas as palavras definidas em $\Sigma$ pode ser particionado em 3 subconjuntos:

- as palavras que representam instâncias do problema tais que a resposta do problema é SIM (instâncias positivas do problema)
- as palavras que representam as instâncias do problema tais que a resposta do problema é NÃO (instâncias negativas do problema)
- as palavras que não representam instâncias do problema

Ex: alfabeto $\Sigma = \{0, ..., 9, a, ..., z\}$

- Problema dos números pares

19 resposta NÃO

26 resposta SIM

2a9 resposta: não é uma instância do problema (é um tipo de NÃO)

As duas últimas classes podem ser agrupadas numa única classe

Conclusão: Um problema pode ser caracterizado pelo conjunto das palavras que representam as instâncias positivas do problema

#### Noção de Linguagem

Def: Uma linguagem é uma conjunto de palavras definidas a partir de um mesmo alfabeto

Um problema é caracterizado pela linguagem que codifica as instâncias positivas do problema

A resolução de um problema consiste então em reconhecer as palavras de uma linguagem que caracteriza as instâncias positivas de um problema

Exemplos:

- {ε,aaaaa,a,bbbbbb} e {aab,aaaa,ε,a,b,abb} são linguagens (finitas) no alfabeto {a,b}
- {ε,0,1,00,01,10,11,000,001,...} é a linguagem de todas as palavras que podem ser formadas no alfabeto {0,1}
- A linguagem Ø representa a linguagem vazia que não contém nenhuma palavra. É uma linguagem diferente da linguagem {ε} (linguagem que contém a palavra vazia)
- O conjunto as palavras para escrever programa em C é uma linguagem

### Representação das linguagens

Não existe uma representação (notação) que descreve qualquer linguagem!

Se a linguagem é finita, a enumeração explícita das palavras que pertencem à linguagem é suficiente para definir a linguagem

Se a linguagem é infinita a enumeração explícita não corresponde a uma possibilidade de descrição da linguagem