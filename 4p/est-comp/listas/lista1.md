# Primeira Lista de Exercícios: Revisao de Probabilidade

## Exercícios

1. Um dado equilibrado é lançado 2 vezes e os números obtidos nos dois lançamentos são registrados. Considere os seguintes eventos aleatórios:
   - A = soma maior ou igual a 9.
   - B = soma ı́mpar.
   - C = um dos lançamentos foi 5.
   - D = o mı́nimo entre as duas faces é 4.

   - Calcule as seguinte probabilidades: P(A), P(B|C), $P(A \cap B ) P(C \cup D)$
     - P(A) - Para calcular P(A) devemos calcular a probabilidade da soma do lançamento de dois dados ser maior ou igual que 9.
       - A probabilidade de ser igual a 9 é $4 \over 36$ (6, 3) (5, 4), (4, 5), (3,6)
       - A probabilidade de ser maior que 9 é a probabilidade de no primeiro e no segundo lançamento sair um número maior igual 5, ou seja, (6, 4), (6, 5), (6, 6), (4, 6), (5,6), (6, 6) que gera a probabilidade $6 \over 36$
       - Dessa forma o resultado é $4 \over 36$ + $6 \over 36$ = $10 \over 36$
     - P(B|C) - Para calcular P(B|C), devemos calcular a probabilide da soma ser impar, dado que um dos lançamentos foi 5
       - Devemos calcular $P(B \cap C) \over P(C)$, pois sabemos que, condicionalmente, o espaço amostral é B, e que um evento deste espaço é P(B $\cap$ C)
       - P(B $\cap$ C): $6 \over 36$ (5, 2), (2, 5), (5, 4), (4, 5), (6, 5), (5, 6)
       - P(C): $9 \over 36$ (5, 1), (1, 5), (5, 2), (2, 5), (5, 3), (3, 5), (5, 4), (4, 5), (5, 5)
       - Então P(A|B) = $6 \over 36$/$9 \over 36$ = $6 \over 9$
     - P(A $\cap$ D) - Devemos calcular a probabilidade de, entre a soma das faces ser 9, o mínimo entre as faces dos dados seja 4, ou seja, probabilidade dos eventos dentro de A onde 4 seja o menor resultado dentre as faces dos lançamentos
       - Sabendo que os eventos de P(A) são: (6, 3), (3, 6), (5, 4), (4, 5), (6, 4), (6, 5), (6, 6), (4, 6), (5, 6), (6, 6)
       - Os eventos válidos são: (5, 4), (4, 5), (4, 6), (6, 4)
       - Logo P(A $\cap$ D) = $4 \over 36$ = $1 \over 9$ 
     - P(C $\cup$ D) - Devemos calcular a probabilidade de um dos lançamentos ser 5 ou o mínimo entre duas faces ser 4
       - Sabemos que P(C) + P(D) - P(C $\cap$ D)
       - P(D) = $5 \over 36$ (4, 4), (5, 4), (4, 5), (6, 4), (4, 6)
       - P(C) + P(D) = $10 \over 36$ + $5 \over 36$
       - P(C $\cap$ D) = $2 \over 36$ (5, 4), (4, 5)
       - Portanto, P(C $\cup$ D) = $10 \over 36$ + $5 \over 36$ - $2 \over 36$ = $13 \over 36$

2. Um exame de sangue feito por um laboratório tem eficiência de 94% para detectar uma certa doença quando ela de fato existe. Entretanto, o teste aponta um resultado falso-positivo para 1% das pessoas sadias testadas (isto é, se uma pessoa testada for saudável, então, com probabilidade 0,01, o teste indicará que a pessoa sadia tem a doença). Se 0,4% da população tem a doença, qual é a probabilidade de uma pessoa ter a doença dado que o resultado de seu exame foi positivo?
   - P = positivo, D = doente, ND = não doente
   - P(P|D) = 0.94
   - P(P|ND) = 0.01
   - P(D) = 0.004
   - P(ND) = 0.96
   - P(P) = P(P $\cap$ D) + P(P $\cap$ ND) = P(D)P(P|D) + P(ND)P(P|ND)
   - P(D|P) = $P(D \cap P)\over P(P)$ = $P(D)P(P|D)\over P(P)$ = $P(D)P(P|D)\over P(D)P(P|D) + P(ND)P(P|ND)$ = $0,004.0,94\over 0,004.0,94 + 0,96.0,01$ = $376 \over 7276$

3. Considere três urnas com as seguintes configurações: a urna I contém 6 bolas pretas, 3 brancas e 5 vermelhas; a urna II contém 4 bolas pretas, 4 brancas e 2 vermelhas; a urna III contém 4 bolas pretas, 2 brancas e 7 vermelhas.  Lança-se um dado equilibrado.  Se sair 5, uma bola da urna I é retirada; se sair 1, 4, então uma bola da urna II é retirada; se sair 2, 3 ou 6, então uma bola da urna III é retirada
   - (a) Calcule a probabilidade da bola retirada ser vermelha.
     - Devemos calcular a P(V)
     - Sabemos pelo teorema da probabilidade total que: P(V) = P(V$\cap U_{1}$) + P(V$\cap U_{2}$) + P(V$\cap U_{3}$) = P($U_{1}$)P(V|$U_{1}$) + P($U_{2}$)P(V|$U_{2}$) + P($U_{3}$)P(V|$U_{3}$)
     - Subsituindo temos: $1 \over 6$$5 \over 14$ + $1 \over 3$$1 \over 5$ + $1 \over 2$$7 \over 13$
     - Portanto, P(V) = 0.395424245 ~= 39,5% 
   - (b) Calcule a probabilidade de ter sido sorteada a urna III, sabendo-se que a bola retirada foi vermelha.
     - Queremos calcular P($U_{3}|V$)
     - Sabemos que P($U_{3}|V$) = $P(U_{3} \cap V) \over P(V)$
     - Sabemos da alternativa A que P(V) = 0.395424245, então temos: $P(U_{3} \cap V) \over 0.395424245$
     - Também $P(U_{3} \cap V)$ pode ser escrito como, $P(U_{3})P(V|U_{3})$
     - Concluimos com, $P(U_{3})P(V|U_{3}) \over 0.395424245$, e substituindo temos: ${0.269230769}\over{0.395424245}$ = 0.680865608 $\approx 68,1\%$

4. Os amigos David Gilmour, Robert Plant, Nick Manson e Jimmy Page desejam fazer um *amigo oculto* entre eles. Calcule a probabilidade de que este amigo oculto não dê errado. Obs: um amigo oculto dá errado quando uma pessoa sorteia ela mesma
   - P(C) = 1 - P(NC), Probabilidade de um amigo oculto não dar errado é 1 menos a probabilidade de dar errado
   - P(NC) é a soma das probabilidades de cada um escolher ele mesmo