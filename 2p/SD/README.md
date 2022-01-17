# Sistemas Digitais

## Representação de Quantidades Binárias

- Nos sistemas digitais eletrônicos, a informação binária é representada por tensões que estão presentes no circuito eletrônico

## Portas Lógicas e Álgebra Booleana

- Uma relação funcional acaba tornando-se uma tabela verdade

| A | Z = f(A) |
| - | -------- |
| F |     F    |
| V |     V    |

| A | Z = f(A) |
| - | -------- |
| F |     V    |
| V |     F    |

- Existem relações do tipo Z = f(A, B) dependente de duas variáveis lógicas A e B. Sendo os exemplos:

  ![andXor](images/andXor.png)
  ![andXorCircuit](images/andXorCircuit.png)

- Estas relações podem ser estendidas da forma Z = f(A, B, ..., Y). Ex:
  
  ![andXorExtension](images/andXorExtension.png)

- Além do AND e OR, há a existência do inversor no qual terá como saída o complemento lógico da entrada. F -> V e V -> F

  ![notNandNor](images/notNandNor.png)

## Teoremas da Álgebra de Boole

- O fato de uma variável só poder assumir um de dois valores nos conduz ao complemento do complemento de uma variável A ser a própria variável A, isto é: A = ~~A

  ![teoremas](images/teoremas.png)

### Provas (Tarefa)

- Obs: X' = complemento de X

1. A + AB = A
   - A + AB = A(1 + B)
   - = A.1 [teo - A + 1 = 1]
   - = A [teo - A.1 = A]

2. A(A + B) = A
   - A(A + B) = AA + AB
   - = A + AB [teo - A.A = A]
   - = A [teo ex.1 - A + AB = A]

3. AB + A(B') = A
   - AB + A(B') = A(B + B')
   - = A.1 [teo - A + A' = 1]
   - = A [teo - ]

4. (A + B)(A + B') = A
   - (A + B)(A + B') = AA + AB' + AB + BB'
   - = A + AB' + AB + 0 [teo - A.A' = 0 e A.A = A]
   - = A + A + 0 [teo ex.3 - AB + AB' = A]
   - = A + 0 [teo - A + A = A]
   - = A [teo - A + 0 = A]

5. A + A'B = A + B
   - Caso 1: A = 0, B = 0
     - 0 + 0'0 = 0 + 0
     - 0 + 1.0 = 0
     - 0 + 0 = 0
     - 0 = 0
   - Caso 2: A = 0, B = 1
     - 0 + 0'1 = 0 + 1
     - 0 + 1.1 = 1
     - 0 + 1 = 1
     - 1 = 1
   - Caso 3: A = 1, B = 0
     - 1 + 1'0 = 1 + 0
     - 1 + 0.0 = 1
     - 1 + 0 = 1
     - 1 = 1
   - Caso 4: A = 1, B = 1
     - 1 + 1'1 = 1 + 1
     - 1 + 0.1 = 1
     - 1 + 0 = 1
     - 1 = 1

6. A(A' + B) = AB
   - A(A' + B) = AA' + AB
   - = 0 + AB [teo - A.A' = 0]
   - = AB [teo - A + 0 = A]

7. A + BC = (A + B)(A + C)
   - Provando (A + B)(A + C) = A + BC
   - (A + B)(A + C) = AA + AC + AB + BC
   - = A + AC + AB + BC [teo - A.A = A]
   - = A + AC + BC [teo ex.1 - A + AB = A]
   - = A + BC [teo ex.1 - A + AC = A]

8. A(B + C) = AB + AC

9. AB + A'C = (A + C)(A' + B)
   - Provando (A + C)(A' + B) = AB + A'C
   - (A + C)(A' + B) = AA' + AB + A'C + BC
   - = 0 + AB + A'C + BC [teo - A.A' = 0]
   - = AB + A'C + BC [teo - A + 0 = A]

10. (A + B)(A' + C) = AC + A'B
    - (A + B)(A' + C) = AA' + AC + A'B + BC

## O Teorema de Morgan

  ![morgansTeorem](images/morgansTeorem.png)

- O complemento de vários ANDs é igual a vários ORs do complemento das variáveis
- O complemento de vários ORs é igual a vários ANDs do complemento das variáveis

## Funções Lógicas

- Para o desenvolvimento de um processo de simplificação das funções lógicas, há duas formas padrão nas quais as funções lógicas podem ser expressas:
  1. Forma padrão de soma de produtos
  2. Forma de produto padrão de somas

- Exemplo: Dada a funções lógica de quatro variáveis
  - F(,B,C,D) = (A' + BC)(B + C'D)
  - expressar como uma soma de produtos
    - A'B + A'C'D + BBC + BCC'D
    - A'B + A'C'D + BC
- Exemplo: Dada a função lógica de cinco variáveis
  - F(A,B,C,D,E) = (A + (BC)')(D + BE)'
  - expressar a função como uma soma de produtos
    - (A + B' + C')(D'(B' + E'))
    - (A + B' + C')(D'(B' + E'))
    - (A + B' + C')((BD)' + (DE)')
    - A(BD)' + A(DE)' + (BD)' + (BDE)' + (BCD)' + (CDE)'
