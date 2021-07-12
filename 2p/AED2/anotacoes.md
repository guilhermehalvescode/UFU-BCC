# AED2

## Análise de algoritmos

### Complexidade computacional

> Custo = memória + tempo

- Memória é mais barato que tempo
- Memória pode ser elástica (malloc)
- Outros custos
  - tráfego de rede
- Sempre o tempo de execução e memória é relacionado ao tamanho da entrada

### Tipos de Analises

- Análise empírica
  - Comparação entre programas
  - Avalia o custo de um algoritmo avaliando a execução
  - Cronometrar o tempo de execução e monitorar quanto de memória é utilizado
  - Vantagens
    - Permite avaliar o programa no computador/linguagem especifico
    - Considera custos que a análise matemática não considera, exemplo custo de alocação
    - Permite comparar linguagens
    - Permite comparar computadores
  - Desvantagens
    - Necessita implementar o código
      - Depende da habilidade do programador
    - Resultado pode variar muito
      - Computador utilizado
      - Processos em paralelo no momento da avaliação
    - Depende da natureza dos dados
      - Dados reais,
      - Dados aleatórios
        - Desempenho médio
      - Dados perversos
        - Sempre força o pior caso do algoritmo
- Análise matemática
  - Estudo das propriedades do algoritmo
  - Estudar como o algoritmo se comporta a medida que a entrada cresce em volume
  - Independente de variáveis de máquina
  - Estudo em um computador idealizado (simplificado)
    - Ex.: soma tem um custo maior que a multiplicação, porém para simplificar ignoramos
  - Só considera custos dominates do algoritmo
  - Para *n* entradas, o custo aumenta em *n*, *n²*, *n!*, etc...
  - Vejamos o seguinte algoritmo
  
      ```c
      int M = A[0];
      for(i = 0; i<n; i++){
        if(A[i] >=M){
          M = A[i];
        }
      }
      ```

  - Ignorando dentro do for, o algoritmo executara 3 + 2n instruções
    - *n* = tamanho array
  - Logo, considerando um laço vazio, podemos criar uma função matemática
  - f(n) = 3+2n
  - Considerando agora dentro do if e os seguintes arrays
  
      ```c
      int A1[4] = {1,2,3,4}
      int A2[4] = {4,3,2,1}
      ```

  - A1: comando if sempre testa **positivo**
  - A2: comando if sempre testa **negativo**
  - **Sempre devemos considerar o *MAIOR* número de instruções**
  - No pior caso o algoritmo será
    - f(n) = 3+2n+2n

### Comportamento assintótico

- Se um algoritmo é mais rápido para um grande conjunto, ele vai ser mais rápido que o outro pra um pequeno conjunto
- A função f(n) = 4n+3
  - 3 é uma *constante de inicialização*, logo desconsideramos

### Notação Grande-O

- O pior que o algoritmo pode ser é o Big-O
- Não ultrapassa esse limite
- Normalmente pode ser visto pela quantidade de laços aninhados
- Exemplo com selection sort:
  
  ```c
  int i,j,me,troca;
    for (i = 0; i < (n - 1); i++)
  {
    me = i;

    for (j = i+1; j < n; j++)
    {
      if (array[j] < array[me])
        me = j;
    }
    if (i != me)
    {
      troca = array[i];
      array[i] = array[me];
      array[me] = troca;
    }
  }
  ```

- Primeiro deve se calcular a soma ``` nEx = 1+2+3+...+(n-1)+n ```
- nEx é o numero de execuções do laço interno (não é simples de calcular)
- Nesse caso é nEx equivalente a uma *prograssão aritmética* de razão 1
- [n(1+1)]/2
- Alternativa é estimar o *limite superior*
  - Supomos o pior caso para o algoritmo
  - Logo o algoritmo original é tão ruim ou melhor do que esse que calcularemos
  - Como calcular isso?
    - Trocar o laço interno (que varia de tamanho dependendo do laço externo) por um laço constante (n)
    - Simplifica a análise
    - Piora o desempenho
      - Algumas execuções do laço são inúteis
    - Sobramos com 2 laços aninhados cada um executando *n* vezes
    - Logo sobramos com uma função de custo ```f(n) = n²```
    - Utilizando a notação big-O o custo no pior caso é ``` O(n²) ```
  - Com isso chegamos a função que delimita o limite superior de custo  de tempo
  - O custo na prática pode ser melhor que n², mas nunca melhor

### Outros tipos de análise

>Apesar da Big-O ser útil e recorrente, existem outras análises

- Grande-Omega
  - Limite assintótico inferior
  - *Melhor caso*
  - Ω(n²) diz que na melhor das hióteses, o custo é n²
  - Não fica melhor que isso em questão de custo, no máximo igual
  - Como definir:
    - Função *```f(n)```* é *```Ω(g(n))```*
      - Se existem 2 constantes >0 chamamos de *c* e *m*
      - *n>=m*
      - Temos _```f(n) >= c* g(n)```_
  - Para todos os valores de *n* a direita de *m* o resultado de *```f(n)```* é sempre >= que o valor da notação Grande-Omega x *c*
  - Exemplo:
    - Função com custo *```f(n) = 3n³ + 2n²```* é ***```Ω(n³)```***
    - Consideramos *c = 1* e *n >= 0*
    - Logo *```3n³ + 2n² >= 1n³```*
    - ![Gráfico da função f(n) = Ω(g(n))](images/notacao_big_omega.jpg)
    - Após o ponto *m* o custo de *```f(n)```* é sempre ***maior*** que o custo de _```c*g(n)```_
- Grande-O
  - Pior caso
  - Função *```f(n)```* é *```O(g(n))```*
  - Se existem 2 constantes >0 chamamos de *c* e *m*
    - *n>=m*
    - Temos _```f(n) <= c* g(n)```_
      - Para todos os valores de *n* a direita de *m* o resultado de *```f(n)```* é sempre <= que o valor da notação Grande-O x *c*
    - Exemplo:
      - Função com custo *```f(n) = 3n³ + 2n²```* é ***```O(n³)```***
      - Consideramos *c = 6* e *n >= 0*
      - Logo *```3n³ + 2n² <= 6n³```*
      - ![Gráfico da função f(n) = Ω(g(n))](images/notacao_big_o.jpg)
      - Após o ponto *m* o custo de *```f(n)```* é sempre ***menor*** que o custo de _```c*g(n)```_
  - Regra da Soma
    - Importante quando temos algoritmos em *sequência*
    - Nesse caso a complexidade de execussão é dada pela complexidade do **maior** deles
    - *```O(f(n)) + O(g(n)) = O(max(f(n),g(n)))```*
    - Exemplo:
      - Primeiro será executado o algoritmo O(n) e depois o algoritmo O(n²)
      - Logo a complexidade de tudo é O(n²)
- Grande-Theta
  - Limite assintótico **firme** ou **estreito**
  - Analisa o limite inferior e superior *ao mesmo tempo*
  - θ(n²) diz assintóticamente que o custo do algoritmo original é n²
  - É como se tivessem 2 constantes, uma restringindo abaixo, e outra restringindo acima
  - Função *```f(n)```* é *```θ(g(n))```*
  - Se existem 3 constantes >0 chamamos de *c1*, *c2* e *m*
    - Para *n>=m*
    - Temos _```c1 * g(n) <= f(n) <= c2* g(n)```_
      - Para todos os valores de *n* a direita de *m* o resultado de *```f(n)```* é sempre = ao valor da notação Grande-θ x *c1* e x *c2*
    - Exemplo:
      - Função com custo *```f(n) = 1/2n² - 3n```* é ***```θ(n²)```***
      - Consideramos *c1 = 1/14*, *c2 = 1/2* e *n >= 7*
      - Logo *```1/14n² <= 1/2n² - 3n <= 1/2n²```*
      - ![Gráfico da função f(n) = Ω(g(n))](images/notacao_big_theta.jpg)
      - Após o ponto *m* o custo de *```f(n)```* é sempre ***menor*** que o custo de _```c2 * g(n)```_ e ***maior*** que o custo de _```c1 * g(n)```_
- Pequeno-o
  - Parecida com a Grande-O
  - Enquanto no Grande-O a relação é *<=*
  - Já na pequeno-o a relação é *<*
  - O custo real sempre será MENOR que o pequeno-o e *nunca igual*
- Pequeno-omega
  - Parecida com a Grande-Omega
  - Enquanto no Grande-Omega a relação é *>=*
  - Já na pequeno-omega a relação é *>*
  - O custo real sempre será MAIOR que o pequeno-o e *nunca igual*

### Classes de problemas

- *```O(1)```*
  - Ordem constante
  - Não depende do tamanho da entrada de dados
- *```0(log(n))```*
  - Ordem logarítmica
  - Resolve um problema transformando ele em problemas menores
  - Exemplo:
    - Realizar uma busca binária em um vetor de tamanho *n*
- *```O(n)```*
  - Ordem linear
  - Uma operação é realizada para cada um dos elementos da entrada
  - Exemplo:
    - Printar um vetor de tamanho *n*
- *```0(nlog(n))```*
  - Ordem log linear
  - Trabalha com particionamento de dados
  - Transforma o problema em partes menores dele mesmo e resolve de forma idependende, depois une tudo
  - Exemplo:
    - QuickSort
- *```O(n²)```*
  - Ordem quadratica
  - Dados são processados em pares
  - Normalmente tem presença de aninhamento de laços
  - Exemplo:
    - Printar uma matriz de tamanho _n_ por _n_
- *```O(n³)```*
  - Ordem cúbica
  - Normalmente tem presença de aninhamento de 3 laços
  - Exemplo:
    - Printar uma matriz de tamanho _n_ por _n_ por _n_
- *```O(2^n)```*
  - Ordem exponencial
  - Solução de força bruta
  - Não é útil do ponto de vista prático
  - Muito lento
  - Exemplo:
    - Quebrar senha de sistema, é necessário testar todas as combinações
- *```O(n!)```*
  - Ordem fatorial
  - Solução de força bruta
  - Não é útil do ponto de vista prático
  - Muito lento
  - Comportamento **muito** pior que a exponencial

> Consideremos um computador que executa 1000000 operações por segundo vamos criar uma tabela que mostra o tempo de execução do algoritmo com base no tamanho de entrada

*```f(n)```* | n = 10 | n = 20 | n = 30 | n = 50 | n = 100
-------------|--------|--------|--------|--------|--------
*```n```* | 1x10^-5 segundos | 2x10^-5 segundos | 4x10^-5 segundos | 5x10^-5 segundos | 6x10^-5 segundos
*```nlog(n)```* | 3.3x10^-5 segundos | 8.6x10^-5 segundos | 2.1x10^-4 segundos | 2.8x10^-4 segundos | 2.5x10^-4 segundos
*```n²```* | 1x10^-4 segundos | 4x10^-4 segundos | 1.6x10^-3 segundos | 2.5x10^-3 segundos | 3.6x10^-3 segundos
*```n³```* | 1x10^-3 segundos | 8x10^-3 segundos | 6.4x10^-2 segundos | 0.13 segundos | 0.22 segundos
*```2^n```* | 0.001 segundos | 1 segundos | 2.8 dias | 35.7 anos | 365.6 séculos
*```3^n```* | 0.059 segundos | 58 minutos | 3855.2 séculos | 2.3x10^8 séculos | 1.3x10^13 séculos

>O problema da análise assintótica é que em entradas pequenas as simplificações são problemáticas

- Considerando as funções _```f(n) = (10^100)n```_ e _```g(n) = 10n*logn```_
  - Big-O da primeira é _```O(n)```_ e da segunda é _```O(nlogn)```_
  - A primeira seria considerada mais performática de forma assintótica
- Ao analisár a constante multiplicativa de n em f(n) descobrimos o número 10^100
  - Logo _```10n*logn```_ > _```f(10^100)n```_ apenas para ***n>2^(10^99)***
  - para qualquer valor abaixo desse *n*  _```10n*logn```_ < _```f(10^100)n```_
    - Ou seja, na prática  _```10n*logn```_ é mais performático

### Relações de recorrência

>Relembrando conceito de função recursiva

- Função que chama a sí mesmo durante a execução
- Exemplo: fatorial(n)
  - Matemáticamente é definido por _```0! = 1; N! = N(N-1)```_
  - Implementação em C:

    ```c
      int fat(int n){
        if(n==0)
          return 1;
        else
          return n*fat(n-1);
      }
    ```

>*Recorrência* ou *Relação de recorrência*

- Expressão que descreve a função em termos de entradas menores da função
- Muitos algoritmos são baseados em recorrência
- Importante para solução de problemas combinatórios
- É uma função recursiva

>Relação de recorrência do fatorial

_```T(n) = T(n-1) + n```_

>Complexidade da recorrência

- Não utiliza laços de repetição
- Erroneamente imaginamos que a função possuíria complexidade ___O(1)___
- Para saber a complexidade tem que resolver a relação de recorrência
- Encontrar a *fórmula fechada* que da o valor da função em termos de *n*
- Considere o relação _```T(n) = T(n-1) + 2n + 3```_
  - Para *n* em _{2,3,4,...}_
  - Existem inumeras funções *T* que satisfazem a recorrência
  - Depende do caso base: T(1)
  - Considerando T(1) = 1
    n|1|2|3|4|5
    -|-|-|-|-|-
    T(n)|1|8|17|28|41
  - Considerando T(1) = 1
     n|1|2|3|4|5
      -|-|-|-|-|-
      T(n)|5|12|21|32|45
  - **Problema**: *muitas soluções possíveis*
    - Para cada valor *i* e *n* em _{2,3,4,...}_ existe ***uma*** função *T* que tem caso base _```T(1) = i```_ e satisfaz a recorrência
  - **Solução**: expandir a relação até encontrar o comportamento no caso geral e assim encontrar a __fórmula fechada__

>Expandindo a relação de recorrência

- Considerando a seguinte relação _```T(n) = T(n-1) + 3```_
  - Representa um algoritmo que possui *3 operações* e *1 chamada recursiva*
- Resolução
  - Substituir o termo _```T(n-1)```_ sobre _```T(n)```_, teremos:
    - _```T(n-1) = T(n-2) + 3```_
  - Substituir o termo _```T(n-2)```_ sobre _```T(n-1)```_, teremos:
    - _```T(n-2) = T(n-3) + 3```_
  - Juntar as 3 expressões
    - _```T(n) = T(n-1) + 3```_
    - _```T(n) = (T(n-2) + 3) + 3```_
    - _```T(n) = ((T(n-3) + 3) + 3) + 3```_
      - Simplificando tudo (somente para claridade)
        - _```T(n) = T(n-1) + 3```_
        - _```T(n) = T(n-2) + 3*2```_
        - _```T(n) = T(n-3) + 3*3```_
  - A cada passo se soma 3 e o valor de n é diminuído em 1
  - Podemos resumir a expansão com a equação
  - _```T(n) = T(n-k) + 3*k```_
  - O processo de expansão acaba no caso base T(1), logo quando: _```n-k = 1```_, ou seja quando _```k = n-1```_
  - Substituindo *k* na equação  _```T(n) = T(n-k) + 3*k```_ por *n-1*
    - _```T(n) = T(1) + 3*(n-1)```_
    - _```T(n) = T(1) + 3n-3```_

> Analisando a complexidade Big-O dessa recursão

- Complexidade da recorrência _```T(n) = T(n-1) + 3```_  

- _```T(n) = T(n-k) + 3k```_
- _```T(n) = T(1) + 3(n-1)```_
- _```T(n) = T(1) + 3n-3```_
  - _```T(1)```_ é o caso base, que é o retorno e o custo é constante: ___O(1)___
  - Substituindo _```T(1)```_ por _```O(1)```_
- _```T(n) = 3n-3 + O(1)```_
- Ou seja, a complexidade é linear _```O(n)```_

## Tabela Hash

- Estrutura chave valor
- É feita por uma tabela de espalhamento com uma função de hash
  - dado um parâmetro (chave) de uma função
- No final a chave sempre será um número inteiro
  - Caso originalmente seja texto ou um real é possível converter para int

### Aplicações

- Busca em base de dados
- Verificação de integridade de dados e autenticação de mensagens
- Armazenamento de senha e criptografia
  - Necessita de uma função mais elegante
  - Armazena-se o resultado da função de hash e não a senha
  - Evitar ao máximo colisão
    - Teriam 2 senhas que geram o mesmo hash
- Implementação da tabela de símbolos dos compiladores
  - Verificação de palavras chave (criação de variável)

### TAD Tabela Hash

- Trabalhamos com array de ponteiros
  - Útil para guardar a informação NULL
  - Maior desempenho
  - Evita gasto excessivo de memória
    - Guarda um array de ponteiro pra uma struct, e não um array de struct
  - Fácil saber qual dado no array static está sendo usado e qual ainda ta vago (NULL)

### Tamanho da tabela

- Ideal é o tamanho seja um numero primo
- Evitar potencia de 2, mesmo que seja mais fácil de buscar haverá mais colisões

### Função Hash

- Inserção: precisa calcular a posição dos dados dentro da tabela
- Pra isso usa a função hash
  - Dado um dado de parâmetro retorna uma posição de memória que tem o dado
- Distribui as informações equilibrada
- Não pode ser
- Todas as posições devem ser acessiveis pela tabela hash
- Função hash espalha os elementos, nunca haverá ordenação
- Sempre haverá posições sobrando
  - Não estamos preocupados com eficiencia da memória
  - Otimizado para busca
- Condições de um bom hash
  - Simples e barato
  - Garantir q valores diferentes não geram a mesma saída
  - Diminuir colisões
- Tipos de hash
  - Método da divisão
    - Método da congruência linear
    - **resto da divisão**
    - dada uma chave *positiva* se calcula o resto da divisão pelo tamanho da tabela
    - Valores diferentes podem dar o mesmo resto dependendo do tamanho da tabela
      - Para evitar isso tamanho que seja número primo
  - Método da multiplicação
    - Método da congruência linear multiplicativo
    - Dada uma constante fracionária entre 0 e 1 para multiplicar pela chave
    - Com esse resultado pega a parte fracionária do número
    - Multiplica pelo tamanho da tabela e pega a parte inteira e tem-se a posição final do item
  - Método da dobra
    - Soma as metades da chave (como se fosse array)
    - Pega só os dois primeiros itens (unidade e dezena)
    - até que se tenha um valor na chave que seja menor ou igual o tamanho do array

### Inserção

>Sem colisão

- Calcular a posição dada a chave
- Alocar o dado
- Guardar a posição da alocação no vetor

>Com colisão

- Calcular a posição dada a chave
- Verificar se ouve colisão
  - Enquanto houver, recalcular posição
- Alocar o dado
- Guardar a posição da alocação no vetor

### Busca

>Sem colisão

- Calcular a posição da chave
- Verificar se ouve colisão
- Verificar se há algo naquela posição
- Se sim, retornar uma cópia do dado

>Com colisão

- Calcular a posição da chave
- Verificar se ouve colisão
  - Enquanto houver, e a chave for diferente da armazenada no local, recalcular posição
- Verificar se há algo naquela posição
- Se sim, retornar uma cópia do dado

### Hash perfeito e imperfeito

- Normalmente usamos o imperfeito
  - Mais de uma chave resultar no mesmo valor
  - Há colisão
- Usamos o perfeito para problemas com escopo pequeno e limitado
  - Exemplo: tabela das 32 palavras reservadas em C

### Tratamento de colisões

> Uma tabela hash é composta por duas partes: função de hash e tratamento de colisão

- Escolha da função de hash
  - Garantir bom potêncial de espalhamento
  - Garantir distribuição de dados uniforme
  - sempre será imperfeito
- Técnicas 
  - Endereçamento aberto
    - Open addressing ou rehashing
    - Os elementos sempre são inseridos na própria tabela, não necessita uma estrutura auxiliar
    - Em caso de colisão, coloca na próxima posição (ou dado um critério de escolha) vaga
    - Vantagens
      - Maior número de posições
      - Melhor uso de memória
      - Busca é realizada na própria tabela
        - Recupera mais rápido os elementos
    - Mais adequada para aplicações com limitação de memória
    - Desvantagem
      - Maior tempo de processamento nos cálculos das posições, com base no número de colisões
      - Agrupamento primário
        - Longos trechos da tabela já ocupados
    - Como cálcular a próx posição?
      - Sondagem linear
        - Tenta sempre jogar pra próxima posição
    - Estratégia simples
  - Espalhamento quadrático
    - Ao invés de somente somar i, usamos uma equação do segundo grau que dependa da variável i
      - Lembrando que i é equivalente ao número de tentativas de cálcular a posição (quantidade de colisões)
    - ![Imagem comparando as técnicas](images/sondagem_quadratica.png)
    - Problemas
      - Agrupamento secundário
        - Gera menos agrupamentos que a sondagem linear
  - Duplo hash
    - Primeira função de hash calcula o endereço
    - A segunda é utilizada se houver colisão
    - Para calcular a posição após a colisão basta fazer ```hash1 + i*hash2```
      - hash2 não pode ter imagem que contenha o 0
  - Encadeamento separado
    - Cada posição do array é um ponteiro pra uma Lista Encadeada, em que a cabeça é a primeira posição inserida e a calda são as posições que deram colisão

## Grafos

### Busca em largura

> Faz uso do conceito de fila, 

- Percorre o grafo de forma sistemática
- Colocam todos os vértices ligado ao que você está e coloca em uma fila
- Quando olhar o vertice de fato, retira-o da fila e insere na fila os vertices dele

### Busca em profundidade

> Backtracking

- Resolve o problema de achar a solução de um labirinto
- Vai sempre por um caminho até não conseguir avançar mais, ai retorna
- Usa um conceito de pilha, porém para não precisar usar um tad pilha usa a **recursão** que já usa esse conceito
- Tem se uma função mascara que percorre até ```i<grau->[ini]``` , se a posição i não foi visitada eu chamo a função que faz a recursão
  - A chamada recursiva parte da proxima aresta

### Busca pelo menor caminho

> Lembra um pouco a busca em largura

- Menor número de arastas percorridas
- Caso seja um grafo ponderado é a menor soma dos pesos das arestas
- Mais comum: Dijkstra
  - Partindo de um vertice inicial, calcula a menor distância dele para todos os outros

### Árvore geradora mínima

> Spanning tree

- É o grafo mínimo que mantém o grafo conectado
- Sempre tem um caminho entre qualquer 2 vértices
  - Grafo conexo
- Não pode ser digraph
- Tem que ser ponderado
  - Ter pesos associados as arestas
- É utilizado para gerar labirintos

> Algoritmos clássicos

- Prim
  - a cada iteração procura a *aresta de menor peso*
  - Começa de um vertice e constrói uma árvore a partir dele
- Kruskal
  - Constrói várias árvores e tenta unir em uma árvore só