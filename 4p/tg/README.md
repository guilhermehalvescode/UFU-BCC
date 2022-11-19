# Teoria dos Grafos (Graph Theory, Diestel)

## Arvores

- Arvore e um grafo simples (não tem laços nem arestas multiplas), conexo e acíclico
  - Laço: aresta que liga um vertice a ele mesmo
  - Arestas multiplas: mais de uma aresta entre dois vertices
  - Conexo: existe um caminho entre qualquer par de vertices
  - Acíclico: não existe ciclo
- Cada elemento de uma arvore é chamado de no ou vertice
- Arestas de uma arvore são chamadas de ramos e ligam os vertices

---

- Elemento principal chamado raiz fica no topo da arvore
- A raiz não tem pai
- A raiz é ligada a outros vertices chamados filhos
- Os filhos que não possuem filhos são chamados de folhas ou no terminal

---

- O numero subarvores (filhos) de cada no e chamado de grau do no
- O comprimento do maior caminho entre um no e uma folha e chamada de altura do no
- A distancia da raiz ate um determinado no, e chamada de profundidade/nivel do no

---

- Dado um grafo com pelo menos três vertices (n = 3), se ele for conexo e não possuir ciclos, ele pode ser representado por uma arvore
  - G e conexo com n - 1 arestas
  - G e acíclico com n - 1 arestas
  - G e acíclico e a adição de uma nova aresta cria um ciclo
  - G e conexo e cada aresta G e uma ponte
    - Ponte: aresta que, se removida, desconecta o grafo (aumenta o numero de componentes conexos)
      - Componentes conexos: subgrafo conexo
        - Subgrafo: subconjunto de vertices e arestas de um grafo
  - Existe exatamente um caminho entre cada par de vertices

---

- O grau de um vertice e dado pelo numero de arestas que saem dele (ou entram nele)
  - melhor definido pelo numero de vertices adjacentes em um grafo simples
- Qualquer vertice de grau <= 1 e uma folha
- Qualquer vertice de grau > 1 e um no interno
- Toda arvore com n > 1 nos possui de 1 a n - 1 folhas

---

- Excentricidade de um vertice e a maior distancia entre ele e qualquer outro vertice
- Para calcular a excentricidade de um vertice, basta calcular a distancia entre ele e todos os outros vertices e pegar o maior valor
- Centro de uma arvore e o conjunto de vertices com menor excentricidade
- Para chegarmos o centro de uma arvore, basta ir removendo as folhas ate termos um grafo com 1 ou 2 vertices que são o centro dessa arvore inicial

---

- Tipos de grafo arvores:
  - Grafo estrela: um vertice central e todos os outros vertices sao adjacentes a ele
  - Floresta: conjunto de arvores (componentes conexos aciclicos e simples)
  - Arvore binaria: arvore de grau 2 (nenhum no tem mais que dois filhos)
    - possui um no raiz
    - filhos são duas subarvores disjuntas (esquerda e direita)
  - Arvore AVL: balanceada com rebalanceamento na inserção e remoção
    - subarvores esquerda e direita possuem diferença de altura de no maximo 1

- Representações:
  - Diagrama de inclusão (Diagrama de Venn), circulos representam nos e e dentro deles seus descendentes
  - Diagrama de barras
  - Aninhamento
  - Numeração por niveis

---

- Arvore enraizada e uma arvore com um vertice raiz
- Ancestral: vertice que esta acima de outro vertice
  - Ancestral proprio: vertice que esta acima de outro vertice e nao e o proprio vertice
- Descendente: vertice que esta abaixo de outro vertice
  - Descente proprio: vertice que esta abaixo de outro vertice e nao e o proprio vertice
- Irmãos: vertices que tem o mesmo pai

---

- Arvore enraizada ordenada: arvore enraizada com uma ordem de visita dos vertices
  - Pre-ordem: visita-se o vertice, depois os descendentes
  - Pos-ordem: visita-se os descendentes, depois o vertice
  - Em-ordem: visita-se os descendentes da esquerda, depois o vertice, depois os descendentes da direita

---

- Arvore geradora: subgrafo conexo de um grafo que contem todos os vertices e uma quantidade minima de arestas (forma uma arvore)

- Arvore geradora minima: arvore geradora de menor peso
  - Peso: soma dos pesos das arestas

- Algoritmo de Kruskal: algoritmo que encontra uma arvore geradora minima
  - Ordena as arestas por peso
  - Adiciona as arestas na arvore geradora minima, desde que nao crie ciclos (se criar descarta a aresta)
  - Para saber se uma aresta cria um ciclo, basta verificar se os vertices dela ja estao na arvore geradora minima
  - Ir repetindo ate que a arvore geradora minima tenha todos os vertices
  - O algoritmo de Kruskal funciona para grafos conexos e desconexos

---

1. Qual e o centro da arvore mostrada na figura

    ![ex1Arvores](images/ex1Arvores.png)

2. Encontre a arvore geradora minima usando o Algoritmo de Kruskal

    ![ex2Arvores](images/ex2Arvores.png)

3. Quais as principais caracteristicas que definem um grafo como uma arvore
   - Conexo, Aciclido e Simples com n - 1 arestas, onde n e o numero de vertices

4. Quais os gargalos que tornam a arvore AVL mais lenta que a arvore rubro-negra quando tem muitos itens inseridos?
   - O processo de balanceamento por rotação da AVL se torna muito custoso quando temos muitos itens inseridos, pois a cada inserção ou remoção, a arvore precisa ser balanceada

## Conectividade

- Grafo orientado e um grafo em que as arestas possuem direção (digrafo)
- Grafo não orientado e um grafo em que as arestas nao possuem direção (grafo)

### Conexo para digrafo

- Digrafo pode ser fortemente conexo ou fracamente conexo
  - fortemente: existe um caminho entre cada par de vertices
  - fracamente: se transformar em um grafo (não direcionado) e esse for conexo

### Componentes conexos

- subgrafo conexo máximo: subgrafo conexo que nao pode ser aumentado adicionando mais vertices ou arestas
- tanto para digrafo quanto para grafo, o numero de componentes conexos e dado pelo numero de subgrafos conexos maximas

### Ponte

- Aresta que, se for removida, o grafo vira desconexo

### Conjunto de separação u-v ou Conjunto de corte

- conjunto de vertices que, se removidos, desconectam o grafo
  - ao remover os vértices desse conjunto, o grafo se torna desconexo
- conjunto de corte contendo apenas um vértice são chamados de "pontos de articulação"

#### Conjunto separação de tamanho mínimo (k(G))

- Menor conjunto que desconecta o grafo, denotado por k(G)
- Para um grafo completo (todos os vértices estão conectados), k(Kn) = n - 1
  - como todos os vértices estão conectados entre si, só podemos reduzir ao grafo trivial para tornar o grafo desconexo

#### P-Conectividade

- Grafo é p-conexo se p <= k(G) e p >= 1
  - ou seja, p-conexo é um grafo que tem um conjunto de corte de tamanho no máximo p, não existe um conjunto de corte de tamanho menor que p

#### Conjuntos de caminhos internamente disjuntos

- Conjunto de caminhos que nao se cruzam (no exemplo abaixo, entre A e F)
  - Caminho 1: A -> C -> E -> G -> F
  - Caminho 2: A -> B -> H -> F
  - Caminho 3: A -> J -> I -> F

### Teorema de Menger

- Dado vértices não adjacentes u e v, existe um conjunto de caminhos internamente disjuntos que conecta u e v, e o tamanho desse conjunto é de mesmo tamanho do conjunto de separação de tamanho mínimo.
  - ou seja, para calcular o tamanho mínimo de um conjunto de separação, basta calcular o tamanho do conjunto de caminhos internamente disjuntos que conecta dois vértices não adjacentes

### Teoremas

- Se um grafo não orientado conexo tem n vértices e m arestas, então ele tem no mínimo n - 1 arestas (m >= n - 1)
- Se a quantidade de arestas m de um grafo não direcionado é maior n-1 tomado 2 a 2 (m > $\binom{n-1}{2}$), então o grafo é conexo
- Todo grafo completo tem $\binom{n}{2}$ arestas, sendo $K_{x}$ denominado como grafo completo com x vértices

---

1. Qual a diferença entre um grafo direcional fracamente conexo para um fortemente conexo
   - Um grafo direcional fracamente conexo é um digrafo que se transformado em um grafo nao direcional, é conexo, já o fortemente conexo é um digrafo que já é conexo (sem necessidade de transformar em um grafo nao direcional)

2. Dado um grafo com 'm' arestas e 'n' vertices, como saber se esse grafo é completo? Ou seja, quantas arestas ele deve possuir?
    - Para saber se um grafo é completo, basta verificar se ele possui $\binom{n}{2}$ arestas, ou seja, se 'm' é igual a $\binom{n}{2}$

3. O Tour do Cavalo Aberto (Open Knight’s Tour) de um tabuleiro n x n descreve um caminho tal que, dado um espaço inicial no tabuleiro, um cavalo do xadrez poderia navegar por todas os espaços, sem passar duas vezes pelo mesmo espaço. Pode-se montar um grafo G que represente o tour do cavalo, onde cada vértice é um espaço do tabuleiro, e cada aresta representa uma movimentação do cavalo de entre dois vértices
   1. Pode-se afirmar que G é conexo. Por quê?
     - O problema do cavalo aberto é um problema de caminho hamiltoniano, ou seja, um caminho que passa por todos os vertices do grafo apenas uma vez. Como na definição do problema, o tabuleiro tem caminhos hamiltonianos para qualquer posição inicial, o grafo G também tem caminhos hamiltonianos, logo, é conexo
   2. Qual a conectividade de G(k(G))?
      - (vou responder oq julgo ser) k(G) é o conjunto de separação de tamanho mínimo, ou seja, o conjunto de vertices que, se removidos, desconectam o grafo. Como o G é conexo, |k(G)| >= n - 1 (peidei aqui, mas acho que é isso)

## Passeios Eulerianos

> Uma definição importante (não escrita antes)

- Multigrafo: grafo que pode ter mais de uma aresta entre dois vértices

---

### Definições

- Grafo euleriano: grafo que possui um circuito euleriano fechado
  - circuito euleriano: passeio que passa por todas as arestas do grafo apenas uma vez, começando e terminando no mesmo vértice
- Grafo não-euleriano semi-euleriano: grafo que possui um circuito euleriano aberto
  - circuito euleriano aberto ou caminho euleriano: passeio que passa por todas as arestas do grafo apenas uma vez, começando e terminando em vértices diferentes
- Não euleriano: grafo que não possui um circuito euleriano aberto nem fechado

### Teorema de Euler

- Um grafo G é dito euleriano se há um ciclo que passa por todas as arestas do grafo sem repeti-las
  - esse ciclo é denominado de ciclo euleriano

- Se tivermos um grafo não-euleriano, podemos transformá-lo em um grafo euleriano, adicionando arestas
  - para isso, basta adicionar arestas entre vértices de grau ímpar, até que todos os vértices tenham grau par

#### Teorema multigrafo

- M multigrafo vai ser euleriano se:
  - for conexo
  - e cada vértice de M tem grau par

#### Grafo Atravessável

- Um grafo G é atravessável que tem:
  - um caminho contendo todas as arestas de M (multigrafo anterior)
    - esse caminho é euleriano

#### Teorema (Hierholzer)

- Um grafo conectado (conexo) tem um caminho euleriano se e somente se exatamente zero ou dois de seus vértices tem um grau ímpar

#### Teorema de Euler-Hierholzer

- Um multigrafo é euleriano se e somente se é conexo e todos os vértices tem grau par

1. É possível arranjar as peças de dominó em um percurso fechado?
2. Na Modelagem, o que significam os vértices, as arestas e qual problema esta associado?
3. Considere um grafo G com um trajeto euleriano. Se o grafo possui um vértice v com grau ímpar, então o trajeto euleriano começa e termina no mesmo vértice?
4. Dado o grafo G abaixo, ele possui um passeio euleriano?

    ![grafoG](images/grafoG.png)