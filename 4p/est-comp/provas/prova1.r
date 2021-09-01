#nome = Guilherme Alves Carvalho
# Questão 1
library(dslabs)
data(heights)
#a
heights$alt.cm = heights$height * 2.54
heights

#b
proporHomens = sum(heights$sex == "Male")/length(heights$sex)
proporHomens

#c
maiorAlt = max(heights$alt.cm)
maiorAlt
homemOuMulherMax = heights[heights$alt.cm == maiorAlt, ]$sex
homemOuMulherMax[1]

#d
menorAlt = min(heights$alt.cm)
menorAlt
homemOuMulherMin = heights[heights$alt.cm == menorAlt, ]$sex
homemOuMulherMin[1]

#e
mediaE = mean(heights$alt.cm)
mediaE
sdE = sd(heights$alt.cm)
sdE

#f
#homens
altsHomens = heights[heights$sex == "Male",]
mediaAltsHomens = mean(altsHomens$alt.cm)
sdAltsHomens = sd(altsHomens$alt.cm)

#mulheres
altsMulheres = heights[heights$sex == "Female",]
mediaAltsMulheres = mean(altsMulheres$alt.cm)
sdAltsMulheres = sd(altsMulheres$alt.cm)
# A média dos homens foi mais próxima da média do conjunto total, pois a proporção destes é aproximadamente 77%, diferentemente das mulheres que acabaram se distanciando mais da média total
# Como apresenta uma maior quantidade maior de homens, ocorreu com que o desvio padrão dos homens foi mais distante do desvio padrão do conjunto total (alturas acabam se diferenciando mais conforme a quantidade de homens aumenta), diferentemente das mulheres que possuem seu desvio padrão próximo do conjunto total

#g
boxplot(altsHomens$alt.cm, main = "Homens", ylim = c(menorAlt, maiorAlt))
boxplot(altsMulheres$alt.cm, main = "Mulheres", ylim = c(menorAlt, maiorAlt))
par(mfrow = 1:2)
# Os homens em média são maiores que as mulheres e 75% dos homens são maiores que 75% de todas as mulheres, demonstrando que um homem geralmente é maior que uma mulher

#Questão 2
#coroa == 0 e cara == 1
monteCarlo = c()
#aumentar para 100000 ok?
for(i in 1:10000) {
  dimJuju = 18
  dimJorel = 7
  repeat {
    moeda = sample(0:1, size = 1)
    if(moeda) {
      # juju vence
      dimJorel = dimJorel - 1
      dimJuju = dimJuju + 1
    } else {
      # jorel vence
      dimJorel = dimJorel + 1
      dimJuju = dimJuju - 1
    }
    if(dimJuju == 0 || dimJorel == 0){
      break
    }
  }
  monteCarlo[i] = dimJuju == 0
}
mean(monteCarlo)

#Questão 3
#a
gerador = function(n) {
  vals = runif(n);
  for(i in 1:n) {
    val = vals[i]
    if(val < 1/6) {
      vals[i] = 1
    } else if(val < 2/6) {
      vals[i] = 2
    } else if(val < 3/6) {
      vals[i] = 3
    } else if(val < 4/6) {
      vals[i] = 4
    } else if(val < 5/6) {
      vals[i] = 5
    } else {
      vals[i] = 6
    }
  }
  vals
}

#b
monteCarlo = c()
for(i in 1:100000) {
  resultados = c()
  repeat {
    lanc = gerador(1)
    resultados = c(resultados, lanc)
    if(sum(resultados == 6) == 2) break
  }
  monteCarlo[i] = sum(resultados != 6)
  #monteCarlo[i] = length(resultados) - 2
}
mean(monteCarlo)

# GO LISTEN DONDA FROM KANYE WEST :))))