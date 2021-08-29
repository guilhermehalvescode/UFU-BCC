#Lista 2
#Integrantes: Guilherme Alves Carvalho, Amauri Pietropaolo Tavares Junior, Heitor Freitas Ferreira, Luis Gustavo Seiji Tateishi, Gabriel Zeitoum dos Santos
#1
#a
a = c(1:20) 

#b
b = c(20:1)

#c
exc = c(1:20, 19:1) 
exc

#d
d = c()
j = 1
for (i in seq(from = 1, to = 34, by = 3)) {
  d[j] = (0.1^(i + 2))*(0.2^i)
  j = j + 1
}
d

#e
e = rep(c(4,6,3), 10)
e

#f
f = rep(c(4,6,3), 11, length.out = (3 * 11) - 2)
f
f == c(e, 4)

#2
excosx = function(x) {
  exp(x)*cos(x)
}
res = excosx(seq(3, 6, 0.1))
res

#3
#a
fa = function(i) {
  i^3 + 4*(i^2)
}
a = sum(fa(c(10:100)))
a

#b
fb = function(i) {
  2^i/i + 3^i/i^2
}
b = sum(fb(10:25))
b

#4
xVec <- sample(0:999, 250, replace=T)
yVec <- sample(0:999, 250, replace=T)

#a
imparesxvec = xVec[xVec %% 2 != 0]
imparesxvec

#b
b = yVec[-1] - xVec[-length(xVec)]
b

#c
c = sin(yVec[-1])/cos(xVec[-length(xVec)])
c

#d
d = c()
for(i in 1:(length(xVec) - 2)) {
  d[i] = xVec[i] + 2*xVec[i + 1] - xVec[i + 2]
}
d

#e

num = exp(-(xVec[2:250]))
dem = xVec[1:249] + 10
e = num/dem
e

#5
xVec <- sample(0:999, 250, replace=T)
yVec <- sample(0:999, 250, replace=T)

#a
a = which(yVec > 600)


#b
b = yVec[a]

#c
exc = xVec[which(xVec %in% b)]
exc

#d
d = sqrt(abs(xVec - mean(xVec)))
d

#e
e = sum(abs(yVec - max(yVec)) <= 200)
e

#f
f = sum(xVec %% 2 == 0)
f

#g
g = xVec[order(yVec)]
g

#h
h = yVec[seq(from = 1, to = length(yVec), by = 3)]
h

#6
num.impar = function(v) {
  imp = 0
  for(i in v) 
    imp = imp + (i %% 2)
  imp
}

res = num.impar(seq(1, 11, 2))
res

num.impar2 = function(v) {
  sum(v %% 2)
}

res2 = num.impar(seq(1, 11, 2))
res2

#7
fibonacci = function(n) {
  fib = c(1,1)
  to = n
  while(to > 2) {
    end = length(fib)
    fib = c(fib, fib[end] + fib[end - 1])
    to = to - 1
  }
  return(fib[1:n])
}
fibonacci(6)

#8
tamanho.seq = function(p) {
  # 0 = cara, 1 = coroa
  caras = 0;
  repeat {
    jogada = sample(c(0, 1), size = 1, replace=TRUE, prob = c(1 - p, p))
    if(jogada) break
    caras = caras + 1
  }
  caras
}

maior = 0
for(i in 1:100) {
  jogadas = tamanho.seq(1/2)
  if(jogadas > maior)
    maior = jogadas
}
maior

#9
reprodCoelhos = function(n, k) {
  fib = c(1,1)
  to = n
  while(to > 2) {
    end = length(fib)
    fib = c(fib, fib[end] + fib[end - 1]*k)
    to = to - 1
  }
  fib[n]
}
reprodCoelhos(4, 70)

#10
library(dslabs)
data("murders")
str(murders)
#a
media = mean(murders$population)
estadoMaisPopuloso = murders[murders$population == max(murders$population), ]$state
estadoMenosPopuloso = murders[murders$population == min(murders$population), ]$state
summary(murders)

#b
rate = (murders$total/murders$population)*10000
murders$rate = rate

#c
murders[order(murders$rate), ]$state

#d
inferior5 = murders[murders$rate < 0.05, ]$state
superior5 = murders[murders$rate > 0.05, ]$state

#e
maiorTaxa = murders[order(murders$rate)[length(murders$rate)], ]$state
menorTaxa = murders[order(murders$rate)[1], ]$state

#f
south = murders[murders$region == "South", ]
meanSouth = mean(south$rate)
sdSouth = sd(south$rate)

northCentral = murders[murders$region == "North Central", ]
meanNorthCentral = mean(northCentral$rate)
sdNorthCentral = sd(northCentral$rate)

west = murders[murders$region == "West", ]
meanWest = mean(west$rate)
sdWest = sd(west$rate)

northEast = murders[murders$region == "Northeast", ]
meanNortheast = mean(northEast$rate)
sdNortheast = sd(northEast$rate)

nomeReg = c("South", "North Central", "West", "Northeast")
taxasMax = c(max(south$rate), max(northCentral$rate), max(west$rate), max(northEast$rate))
taxasMin = c(min(south$rate), min(northCentral$rate), min(west$rate), min(northEast$rate))
regMaiorTax = nomeReg[taxasMax == max(taxasMax)]
regMenorTax = nomeReg[taxasMin == min(taxasMin)]

#g
boxplot(south$rate, main = "South", ylim = c(min(rate), max(rate)))
boxplot(northCentral$rate, main = "North Central", ylim = c(min(rate), max(rate)))
boxplot(west$rate, main = "West", ylim = c(min(rate), max(rate)))
boxplot(northEast$rate, main = "Northeast", ylim = c(min(rate), max(rate)))
par(mfrow = c(1,4))
# South region is the most violent place, considering It's boxplot offset above from other regions