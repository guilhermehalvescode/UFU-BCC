x = c(55,22,56,79)

#funções de vetores
sum(x) #soma dos valores do vetor
sum(x)/length(x) # média
mean(x) # função de média
median(x) # mediana do vetor
min(x) #valor mínimo do vetor
max(x) #valor máximo do vetor
sd(x) #standard desviation(desvio padrão)
var(x) #variancia
sqrt(var(x)) # raiz da variancia é o desvio padrão

#ordenação 
sort(x, decreasing = TRUE) #decrescente

sort(x) #crescente

order(x) #ordem dos índices ordenados do sort

x[order(x)] == sort(x) # TRUE

a <- sample(1:10, size = 30, replace = TRUE) #sorteia do conjuntos [1,..,10] 30 números podendo repeti-los
a
unique(a) #mostra os valores do vetor sem repetição
duplicated(a) #averigua se os elementos se repetem no vetor
sum(duplicated(a)) # averigua quantos valores são repetidos(quantos TRUE's aparecem no vetor de duplicated)

#condicionais
if(sum(duplicated(a)) > 0) {
  print("há repetições")
} else {
  print("não há repetições")
}

if() {
  
}

sum(1:10)
sum(seq(from = 1, to = 10, by = 1)) # soma os valores da sequencia que começa de 1 até 10 de 1 em 1
sum(c(1,2,3,4,5,6,7,8,9,10))
sum(c(1,2,3,4,5), c(6,7,8,9,10))

soma = 0
for(i in c(1,2,5)) {
  soma = soma + i
}
soma
soma = function(x, y) {
  a = x + y
  return (a)
}
soma(2,4)

