# ex1
size = 10000000
dado1 = sample(1:6, size = size, replace = TRUE)
dado2 = sample(1:6, size = size, replace = TRUE)
soma = dado1 + dado2
#p(a)
abs(mean(soma >= 9) - 10/36)

#p(b|c)
pc = dado1 == 5 | dado2 == 5
somaImpar = (dado1[pc] + dado2[pc]) %% 2 != 0
abs(mean(somaImpar) - 6/11)

#p(A interseção D)
abs(mean(soma >= 9 & pmin(dado1, dado2) == 4) - 1/9)

#p(C U D)
abs(mean(pc | pmin(dado1, dado2) == 4) - 14/36)
