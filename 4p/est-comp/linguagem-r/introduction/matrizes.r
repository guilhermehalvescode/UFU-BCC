#matrizes
a = matrix(data = c(7,12,12,32,43,60), ncol = 3, byrow = TRUE)
a[2,2] #acessando o elemento da segunda linha e segunda coluna 
a[2,] #acessa segunda linha
a[, 3] #acessa terceira coluna
a[, c(1,3)] #acessa primeira e terceira coluna

# muda o nome das colunas para "A", "B", "C"
colnames(a) = c("A", "B", "C") 
# muda o nome das linhas para "A", "B", "C"
rownames(a) = c("Q", "W") 
a["Q", "B"]
# altera o valor da posicao
a[1,3] = 13 
g = a[,3][c(2,1)]
g
a
# acopla na coluna os vetores
cbind(a, c(34, 78), c(54, 43))
# acopla na linha os vetores
rbind(a, c(34, 78, 45), c(54, 43, 90))
#data frames
library(dslabs) # puxa a lib
data(murders) # puxa os dados
murders # variável dos dados puxados
head(murders) # imprime os 6 primeiros do inicio dos conjuntos de dados
tail(murders) # imprime os 6 primeiros do inicio dos conjuntos de dados
str(murders) # mostra a estrutura dos dados
estados = murders$state # acessando a coluna por nome da variável
sum(murders$total)
order(murders$total)
murders[5, ]
rate = 100000 * murders$total/murders$population
indices = order(rate)
murders[indices[length(indices)],]
murders[indices[1], 1]
murders$rate = rate
murders
str(murders)
plot(x = murders$population, y = murders$rate)
murders[murders$rate == max(rate), ]
mean(murders$rate)
mean(murders$population)
boxplot(murders$rate)
hist(murders$rate)
summary(murders$rate)
levels(murders$region)
nordeste = murders[murders$region == "Northeast", ]
nordeste = nordeste[, -3]
sul = murders[murders$region == "South", ]
sul = sul[, -3]
centro_norte = murders[murders$region == "North Central", ]
centro_norte = centro_norte[, -3]
oeste = murders[murders$region == "West", ]
oeste = oeste[, -3]
boxplot(leste$rate, main = "Leste", ylim = c(min(rate), max(rate)))
boxplot(nordeste$rate, main = "Nordeste", ylim = c(min(rate), max(rate)))
boxplot(centro_norte$rate, main = "Centro Norte", ylim = c(min(rate), max(rate)))
boxplot(sul$rate, main = "Sul", ylim = c(min(rate), max(rate)))
par(mfrow = c(1, 4))
