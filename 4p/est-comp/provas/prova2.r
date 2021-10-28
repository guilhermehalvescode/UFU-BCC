#prova 2
#nome = Guilherme Alves Carvalho

# Questão 1
## a
papagaios = read.csv("papagaio.txt", header = TRUE, sep = ",")
papagaios
head(papagaios)
tail(papagaios)
str(papagaios)
summary(papagaios)

## b
papagaios = papagaios[sample(nrow(papagaios)), ]
papagaios

## c
### Artica
pArtica = papagaios[papagaios$especie == "arctica", ]

pArticaTamanhoMedia = mean(pArtica$tamanho)
pArticaTamanhoSd = sd(pArtica$tamanho)

pArticaPesoMedia = mean(pArtica$peso)
pArticaPesoSd = sd(pArtica$peso)

pArticaEnvMedia = mean(pArtica$envergadura)
pArticaEnvSd = sd(pArtica$envergadura)

### Corniculata
pCorni = papagaios[papagaios$especie == "corniculata", ]

pCorniTamanhoMedia = mean(pCorni$tamanho)
pCorniTamanhoSd = sd(pCorni$tamanho)

pCorniPesoMedia = mean(pCorni$peso)
pCorniPesoSd = sd(pCorni$peso)

pCorniEnvMedia = mean(pCorni$envergadura)
pCorniEnvSd = sd(pCorni$envergadura)

### Cirrhata
pCirr = papagaios[papagaios$especie == "cirrhata", ]
pCirrTamanhoMedia = mean(pCirr$tamanho)
pCirrTamanhoSd = sd(pCirr$tamanho)

pCirrPesoMedia = mean(pCirr$peso)
pCirrPesoSd = sd(pCirr$peso)

pCirrEnvMedia = mean(pCirr$envergadura)
pCirrEnvSd = sd(pCirr$envergadura)

par(mfrow = c(1, 3))
boxplot(pArtica$peso, main = "Artica", ylim = c(min(papagaios$peso), max(papagaios$peso)))
boxplot(pCorni$peso, main = "Corniculata", ylim = c(min(papagaios$peso), max(papagaios$peso)))
boxplot(pCirr$peso, main = "Cirrhata", ylim = c(min(papagaios$peso), max(papagaios$peso)))

### O peso dos papagaios da espécie Artica é bem menor em relação as outras duas espécies, sendo que mais de 75% de suas observações de peso se encontraram inferiores as 25% observações com pesos menores das duas outras espécies
## d
papagaios$especie = as.factor(papagaios$especie)

## e
n = round(nrow(papagaios)*0.8)

treino = papagaios[1:n,]
teste = papagaios[(n+1):nrow(papagaios), ]

## f
library(rpart)
library(rpart.plot)
par(mfrow = c(1, 1))
modelo.papagaio = rpart(especie~., data = treino, parms = list(split = "gini"))
rpart.plot(modelo.papagaio, extra = 101)

## g
previsao = predict(modelo.papagaio, newdata = teste, type = "class")
taxa = mean(previsao == teste$especie)
taxa
table(previsao, teste$especie)

### A taxa de acerto deu um valor considerável acima de aproximadamente 0.69, porém quando reembaralhada a amostra, a árvore de decisão varia bem suas taxas de acerto sobre o conjunto teste, demonstrando uma variabilidade alta da amostra.

# Questão 2
## a
pArtica = papagaios[papagaios$especie == "arctica", ]
pCorni = papagaios[papagaios$especie == "corniculata", ]
pCirr = papagaios[papagaios$especie == "cirrhata", ]

## b
coef = function(x, y) {
  xBar = mean(x)
  yBar = mean(y)
  n = length(x)
  num = sum(x * y) - n * xBar * yBar
  
  den = sqrt(sum(x*x) - (n * xBar * xBar)) * sqrt(sum(y*y) - (n * yBar * yBar))
  
  return (num/den)
}

coefArtica = coef(pArtica$tamanho, pArtica$peso)
coefCorni = coef(pCorni$tamanho, pCorni$peso)
coefCirr = coef(pCirr$tamanho, pCirr$peso)

### Para espécie Corniculata as variáveis tamanho e peso estão mais correlacionadas linearmente, r = 0.9025978

## c
pCorni
modelCorni = lm(peso ~ tamanho, pCorni)
modelCorni

## d
### Uma variação de aumento(diminuição) em 0.5 cm no tamanho da ave provocaria um aumento(diminuição) de 24.25 * 0.5 = 12.125 gramas no peso da ave. Isso ocorre porque, o coefieciente angular do modelo linear vale 24.25, representado pela função peso = 24.25 * tamanho - 300.59, se aumentasse(diminuisse) 1 cm o tamanho, o peso aumentaria(diminuiria) em 24.25 gramas

## e
retaModelCorni = function (x) {
  if(x < min(pCorni$tamanho) || x > max(pCorni$tamanho)) {
    return("erro")
  }
  return (24.25 * x - 300.59) 
}

retaModelCorni(18) 
#erro
retaModelCorni(41.01)
# 693.9025