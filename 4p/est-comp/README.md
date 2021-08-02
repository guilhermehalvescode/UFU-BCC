# Estatística Computacional

## Introdução ao R

- Operações básicas normais, e segue a mesma ideias das funções matemáticas
- Código de explicação se encontra na pasta [fundamentos1.r](linguagem-r/introduction/)

## Probabilidade

### Definição frequentista

- Probabilidade é a medida que define a aleatoriedade
- P(A) = lim (n -> + inf) n(A)/n
- Esta definição não define se este limite converge, sem resposta

### Definição axiomática de probabilidade

- Ω: espaço amostral, A **c** Ω
- Uma função P será dita uma medida de probabilidade se:
  - P(A) >= 0, para qualquer A **c** Ω
  - P(Ω) = 1,
  - P(A U B) = P(A) + P(B), se A ∩ B = vazio
  - P(A U B U C) = P(A) + P(B) + P(C), se A ∩ B = vazio, A ∩ C = vazio, B ∩ C = vazio

### Lei dos Grandes Números

- X*1*, X*2*, X*3*, ..., X*n*. (independentes e igualmente distribuídas)
- E[X*i*] finita
- Então o limite (n -> inf) (X*1* + X*2* + X*3* + ... + X*n*)/n = E[X]
- Assim, para um n grande,
  - (X*1* + X*2* + X*3* + ... + X*n*)/n ~~ E[X]
