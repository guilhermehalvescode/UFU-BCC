# Análise de Algoritmos

- Analisar eficiência computacional de algoritmos utilizando formalismo apropriado
- Aplicar técnicas de projeto de algoritmos
- Projetar algoritmos eficientes de acordo com a técnica mais adequada ao problema

> "Quanto tempo gasta??"

- memória, comunicação

> "Estou fazendo direito??"

- Depois:
  - "É possível resolver isso na prática??"
  - "É possível resolver isso??"

## Leibniz e os dados (Aula 1)

- Aquecimento e off topic
- Dado um lance de um par de dados, qual é soma mais provável 11 ou 12??
- (Se vc errou, esta em boa compania: Leibniz)

### Indução Matemática

- Se, ser verdade para n implica em ser verdade para n + 1
- Verdade para um n0
- É verdade (para n grande)
- Efeito Dominó
- Provas e Projeto de algoritmo

![induction](images/induction.png)

### Exercícios

1. Prove por indução
  ![inductionEx](images/inductionEx.jpg)
2. Hanói
  ![hanoiEx](images/hanoiEx.jpg)
3. Pseudo-Algoritmo

- avaliaP(V, x):
  - R = 0
  - Q = 1
  - P / é de 1 a |V|:
    - R = R + Q * Vi
    - Q = Q * x
  - Retorna R

## Eficiência do algoritmo (Aula 2)

![maioriaXvet](images/maioriaXvet.png)

- Compilo e testo ... OK?
- Não!
- Linguagem?? Compilador?? Arquitetura??
- for x while
- c = c + 1 x c++
- Ir até a metade do vetor
- Operador ternário ou mesmo de uma multiplicação
- Evitar recomputação da metade (|V|/2) de acesso ao V[i]
- "Escovação de Bits!!"

---

- Vou abandonar a idéia do tempo em "segundos"
- Vou criar um modelo...uma fórmula matemática
- Representar o tempo de execução do algoritmo
- Complexidade do Algoritmo
- (=/= dificuldade em desenvolver, aprender, ...)

---

- Vou contar quantas vezes eu executo cada linha
- Em função do tamanho da entrada:n
  - No nosso caso, o tamanho do vetor
- **No pior caso**
- somar tudo
- isso vai "caminhar" para um modelo do tempo gasto

![maioriaXvet](images/maioriaXvet.png)
![execPerLineMaioriaXvet](images/execPerLineMaioriaXvet.png)

---

- Vou considerar o crescimetno da função
- "a cara do gráfico"
- Quanto n é grande!

---

- Para n grande
- n e n + 1 são "iguais"
- n/2, n e 2n são "iguais"
- ...
- Ok??

---

### Definição (O)

- Para uma dada função g(n) definimos O(g(n)) da sequinte form:
- O(g(n)) = {f(n): existem constantes positivas c e n0 tal que 0 <= f(n) <= cg(n) para todo n >= n0}

---

- f(n) = O(g(n))
- "f de n é ózão de g de n
- é -> pertence
- g limita o crescimento de f

![gLimitF](images/gLimitF.png)

---

#### Exemplo

![exfn](images/exfn.png)

---

- 100n + 5 = O(n) ?
- 400n = O(n^2) ?
- n^2 = O(5000000n)

---

- Jogue fora as constantes aditivas
- Se livre das constantes multiplicativas
- n linear
- n^2 quadrática
- n^3 cúbico

---

- O(1): constantes
  - Qual?? Qual não estupido??
- O(ln n): logarítmico ou "log"
- O(2^n)
- Existem outros...

---

- Achar o maior(menor) elemento de um vetor
- Procurar alguma coisa em um vetor
- Remover um item de uma lista ligada, Cuidado com a pergunta!!
- Remover um item de um vetor
- Saber se existe um par de elementos em V tal que Vi + Vj = K

---

![defOmega7](images/defOmega7.png)

---

![defTheta](images/defTheta.png)

### Exercícios (Eficiência)

- Exercício 1
  - 1 /// 1^n
  - log10 n
  - lg lg n
  - lg n
  - n /// lg (2^n) /// n + 5
  - n lg n
  - n^2
  - 2^n
  - n!
- Resolução prof
  - Os constantes: 1, 1^n
  - Os sublineares: lg lg n, (log10 n, lg n)
  - Os lineares: lg(2^n), n, n + 5
  - n lg n
  - Quadrático: n^2
  - Exponencial: 2^n
  - n!

- Exercício 2

![prova%23](images/prova%23.png)

---

### O(n)

``` c++
for(int i = 0; i < n; i++) {
  // ...
}
```

- Cuidado com os "..."
- Sem laço, sem repetição, sem chamada de função

### O(n^2)

``` c99
for(int i = 0; i < n - 1; i++) {
  for(int j = 0; i < n; j++) {
    // ...
  }
} 
```

- Somatório de 1 até n - n(n + 1)/2

### Exemplo indução

![inductionEx1](images/inductionEx1.png)


## Algoritmos de Ordenação

### BubbleSort

- Método intuitivo
- (não sei se o nome é intuitívo)
- Muito ruim!
- Assintoticamente
- (Constantes!)
- "Improved"

![bubbleSort](images/bubbleSort.png)

---

- O laço interno "empurra" o maior elemento do subproblema para a posição final: na iteração n o elemento n é colocado no seu lugar
- O laço externo - decrescente - controla o tamanho do subproblema que será alterado, desta forma o elemento que foi colocado na última posição do subproblema não será mais alterado

---

- Complexidade: O(n^2)

![bubbleSortPy](images/bubbleSortPy.png)

- 4
- [2, 3, 5, 4, 1]
- [2, 3, 5, 4, 1]
- [2, 3, 4, 5, 1]
- [2, 3, 4, 1, 5]
- 3
- [2, 3, 4, 1, 5]
- [2, 3, 4, 1, 5]
- [2, 3, 1, 4, 5]
- 2
- [2, 3, 1, 4, 5]
- [2, 1, 3, 4, 5]
- 1
- [1, 2, 3, 4, 5]

### Insertion

- Analogia com ordenação de cartas de um baralho
- Inicia com um conjunto de cartas na mesa
- Pegue um carta qualquer na mão, a mão está ordenada
- Pegue a próxima carta e insira-a na posição correta, a mão está ordenada
- ...

![insertionSort](images/insertionSort.png)

---

- No início de cada iteração: V[1..j-1] esta ordenado
  - Correto no início: vetor unitário
- (V[(j+1)..n] aguardando a ordenação)
- k = V[j] será colocado no lugar "correto" do vetor ordenado (linhas 4/7)
- O tamanho do vetor ordenado cresce em uma unidade (laço for)
- "Loop invariante" : propriedade de estar ordenado se mantem, mesmo o tamanho do vetor aumentando
- O laço for j é executado n vezes
- O laço while até j vezes
- Complexidade: O(n^2)

![insertionSortPy](images/insertionSortPy.png)

### MergeSort

- V1 e V2
- Vf que é ordenado contem os elementos de V1 e V2
- De novo, cartas de baralho

---

- Tava pensando...
- Assintoticamente não vejo como melhorar...
- Mas da pra fazer inplace??
- (O google falou que sim!)


