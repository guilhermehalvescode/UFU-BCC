# Linguagens Formais e Autômatos

## __*Teoria da Linguagens Formais*__

- Originada em 1950.

- Objetivo inicial
  - Desenvolver teorias relacionadas com as linguagens naturais (representar idiomas).

- Hoje
  - Importante para lingugagens artificiais.
  - Principalmente, linguagens da Ciência da Computação.

- Tipos de Formalismos usados
  - Operacional
  - Axiomático
  - Denotacional (Extra)

### **_Operacional_**

- Autômato ou máquina abstrata
  - estados
  - instruções primitivas
  - como cada intrução modifica cada estado

- Máquina abstrata
  - suficietemente simples
    - não deve permitir dúvidas sobre o seu funcionamento
  
  - também é dito um **Formalismo Reconhecedor**
    - análise de uma entrada para verificar

  - Exemplos
    - Autômato Finito
    - Autômato com Pilha
    - Máquina de Turing

### _**Axiomático**_

- Associam-se regras às componentes da linguagem

- Regras
  - permitem afirmar o que será verdadeiro
  - após a ocorrência de cada cláusula
  - considerando oq era verdadeiro antes da ocorrência

- Formalismos axiomáticos
  - Gramáticas Regulares
  - Gramáticas Livre do Contexto
  - Gramáticas Sensíveis ao Contexto
  - Gramáticas Irrestritas

- Gramática tabmém é dita um _Formalismo Gerador_
  - permite verificar se um determinado elemento da linguagem é _gerado_

### _**Denotacional**_ (ou _Formalismo Funcional_)

- Domínio (sintático)
  - que permite a caracterização do conjunto de palavras admissíveis na linguagem
  - tratam-se de funções, as quais são, em geral, composicionais (horizontalmente)
    - o valor denotado por uma construção é especificado em termos dos valores denotados por suas subcomponentes

- Formalismo Denotacional
  - Expressões Regulares
    - é simples inferir (gerar) aos elementos da linguagem.
    - asim, frequentemente também é denominado como um Formalismo Gerador.

### _**Hierarquia de Chomsky**_

- classifica as diversas classes de linguagens em uma ordem hierárquica.
- inclusão própria entre as classes.

## **_1. Revisão de Conceitos Básicos_**

- **Conjuntos**
- **Relações**
- **Funções**
- **Lógica**
- **Técnicas de Demonstração**
- **ASYNC**

## _**2. Linguagens, Gramáticas e Reconhecedores**_

- _Símbolo, Caractere_
  - entidades abstratas básicas
  - não definida formalmente
  - Exemplo: Símbolo
    - letras
    - dígitos

- *Alfabeto*
  - conjunto finito de símbolos
  - Exemplo: Alfabeto
    - $\Sigma_{1}$ = {a, b, c}
    - $\Sigma_{2}$ = {0, 1, ..., 9}
    - $\Sigma_{3}$ = { }

- *Palavra, Cadeia de Caracteres, Sentença*
  - sobre um alfabeto (pode ser binário)
  - sequência finita de símbolos justapostos (concatenados)
  - Exemplo: Palavra
    - **a, abcb** são palavras sobre {a, b, c}
    - $\varepsilon$
      - palavra vazia - sem símbolos
      - é palavra sobre qualquer alfabeto

- *Tamanho, Comprimento de uma palavra*
  - número de símbolos que compõem a palavra
  - representação
    - | w |
    - w denota uma palavra
  - Exemplo
    - | wafda | = 5
    - | $\varepsilon$ | = 0

- *Concatenação*
  - operação binária em uma linguagem
  - justaposição dos símbolos que representam as palavras componentes
  - propriedades:
    - associatividade: w(wt) = (vw)t
    - elemento neutro (palavra vazia): $\varepsilon$**w** = **w** = **w**$\varepsilon$
  - Exemplo: concatenação
    - para **v = ab** e **w = cd**
      - vw = abcd

- *Prefixo, Sufixo, Subpalavra*
  - prefixo (sufixo)
    - qualquer sequência de símbolos inicial (final) de uma palavra

  - subpalavra
    - qualquer sequência de símbolos contígua de uma palavra
  
  - Exemplo: para a palavra abcb
    - prefixos: $\varepsilon$, a, ab, abc, abcb
    - sufixos: $\varepsilon$, b, cb, bcb, abcb
    - prefixos e sufixos são subpalavras

- *Concatenação Sucessiva*
  - concatenação sucessiva de uma palavra com ela mesma
  - indefinida para $\varepsilon$⁰
  - $w^n$: concatenação sucessiva de w, por ela mesma, onde n indica o número de concatenações.
  - Exemplo:
    - w³ = www
    - w¹ = w
    - a⁵ = aaaaa
    - $a^n$ = aaa...aa (a repetido n vezes)
    - w⁰ = $\varepsilon$, para w != $\varepsilon$

- *Produto de Conjunto de Palavras*
  - Sejam V e W conjuntos de palavras de $\Sigma$.
    - VW = { vw / v $\in$ V e w $\in$ W }
  - Exemplo:
    - $\Sigma$ = {0, 1, 2, 3}, V = {00, 11}, W = {222, 333}
    - VW = {00222, 00333, 11222, 11333}
    - VV = V² = {0000, 0011, 1100, 1111}
    - V⁰ = { $\varepsilon$ }, por definição (não é um conjunto vazio)
    - V³ = { 000000, ..., 111111 }
    - V⁴ = { 00000000, ..., 1⁸ }

- *Fechamento de Kleene*
  - Seja W um conjunto de palavras sobre $\Sigma$
  - W* = $\cup_{i \geq 0 }$($W^i$)
  - W* = W⁰ $\cup$ W¹ $\cup$ W² $\cup$ W³ ...
  - Conjunto de todas as concateanções possíveis de W, incluindo $\varepsilon$
  - Exemplos:
    - V = {00, 11}, V* = { $\varepsilon$, 00, 11, 0000, 0011, 1100, 1111, 000000, ... }
    - $\Sigma$ = {0, 1}, $\Sigma$* = { $\varepsilon$, 0, 1, 00, 01, 10, 11, ... }

- *Fechamento Positivo*
  - Seja W um conjunto de palavras sobre $\Sigma$,
  - $W^+$ = $\cup_{i \geq 1} W^i \rArr$ igual a $W^*$, exceto $\varepsilon$.
  - $W^+$ = W¹ $\cup$ W² $\cup$ W³ ...
  - Conjunto de todas as concatenações possíveis de W, excluindo $\varepsilon$
    - _Note que W⁰ = {$\varepsilon$} não está incluso, mas se, $\varepsilon \in W \rArr \varepsilon \in W^+$_
  - Exemplos: 
  - V = {00, 11}, $V^+$ = {00, 11, 0000, 0011, 1100, 1111, ...}
  - $\Sigma$ = {0, 1}, $\Sigma^+$ = {0, 1,00, 11, 01, 10, 0000, ...}
  
- *Linguagem Formal*
  - Uma linguagem L é um conjunto de palavras sbore um alfabeto $\Sigma$, ou seja, L $\subset \Sigma^*$
  - Exemplo: Ling. Formal sobre $\Sigma$ = {a, b}
    - conjunto vazio
    - conjunto formado pela palavra vazia
      - note-se que {} $\neq$ {$\varepsilon$}
    - conjunto das palíndromos
      - palavras que têm a mesma leitura da esquerda para a direita e vice-versa
      - linguagem infinita
      - $\varepsilon$, a, b, aa, bb, aaa, aba, bab, bbb, aaaa, ... são palíndromos

- **Como representar uma linguagem formal L?**
  - Se L é finito, basta listar todas as palavras.
  - se L é infinito, existem 2 formalismos principais:
    - _Formalismo Gerador: Gramática_
    - _Formalismo Reconhecedor: Autômato_
  
