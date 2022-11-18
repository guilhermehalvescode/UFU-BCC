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