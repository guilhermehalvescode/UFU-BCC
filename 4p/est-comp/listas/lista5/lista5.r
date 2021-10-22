#Lista 5
#Integrantes: Guilherme Alves Carvalho, Amauri Pietropaolo Tavares Junior, Heitor Freitas Ferreira, Luis Gustavo Seiji Tateishi, Gabriel Zeitoum

# Exercicio 1
penguins = read.csv("./penguins_size.csv", header = TRUE, sep = ',')
penguins$species = as.factor(penguins$species)
penguins$sex = as.factor(penguins$sex)
str(penguins)

## a
summary(penguins)
peso_medio = mean(penguins$body_mass_g, na.rm = TRUE)
comprimento_medio = mean(penguins$flipper_length_mm, na.rm = TRUE)

peso_sd = sd(penguins$body_mass_g, na.rm = TRUE)
comprimento_sd = sd(penguins$flipper_length_mm, na.rm = TRUE)


## b
adeliePenguins = penguins[penguins$species == 'Adelie', ]
print("Adelie")

print("peso_medio: ")
peso_medio_adelie = mean(adeliePenguins$body_mass_g, na.rm = TRUE)
peso_medio_adelie

print("peso_sd: ")
peso_sd_adelie = sd(adeliePenguins$body_mass_g, na.rm = TRUE)
peso_sd_adelie

print("comprimento_medio: ")
comprimento_medio_adelie = mean(adeliePenguins$flipper_length_mm, na.rm = TRUE)
comprimento_medio_adelie


print("comprimento_sd: ")
comprimento_sd_adelie = sd(adeliePenguins$flipper_length_mm, na.rm = TRUE)
comprimento_sd_adelie

chinsPenguins = penguins[penguins$species == 'Chinstrap', ]
print("Chinstrap")

print("peso_medio: ")
peso_medio_chins = mean(chinsPenguins$body_mass_g, na.rm = TRUE)
peso_medio_chins

print("peso_sd: ")
peso_sd_chins = sd(chinsPenguins$body_mass_g, na.rm = TRUE)
peso_sd_chins

print("comprimento_medio: ")
comprimento_medio_chins = mean(chinsPenguins$flipper_length_mm, na.rm = TRUE)
comprimento_medio_chins


print("comprimento_sd: ")
comprimento_sd_chins = sd(chinsPenguins$flipper_length_mm, na.rm = TRUE)
comprimento_sd_chins


gentooPenguins = penguins[penguins$species == 'Gentoo', ]
print("Gentoo")

print("peso_medio: ")
peso_medio_gentoo = mean(gentooPenguins$body_mass_g, na.rm = TRUE)
peso_medio_gentoo

print("peso_sd: ")
peso_sd_gentoo = sd(gentooPenguins$body_mass_g, na.rm = TRUE)
peso_sd_gentoo

print("comprimento_medio: ")
comprimento_medio_gentoo = mean(gentooPenguins$flipper_length_mm, na.rm = TRUE)
comprimento_medio_gentoo

print("comprimento_sd: ")
comprimento_sd_gentoo = sd(gentooPenguins$flipper_length_mm, na.rm = TRUE)
comprimento_sd_gentoo

### Analisando os dados, percebe-se uma diferença discrepante dos penguins da espécie Gentoo em relação aos outros (Chinstrap, Adelie). A média dos pesos e a média do tamanho da asa do mesmo é muito maior que a das outras espécies. Outra informação importante é o desvio padrão dos pesos das espécies, que está muito alto, demonstrando uma variação maior dos pesos dos penguins

## c

maleP = penguins[penguins$sex == 'MALE', ]
print("Male Penguins")

print("peso_medio: ")
peso_medio_male = mean(maleP$body_mass_g, na.rm = TRUE)
peso_medio_male

print("peso_sd: ")
peso_sd_male = sd(maleP$body_mass_g, na.rm = TRUE)
peso_sd_male

print("comprimento_medio: ")
comprimento_medio_male = mean(maleP$flipper_length_mm, na.rm = TRUE)
comprimento_medio_male

print("comprimento_sd: ")
comprimento_sd_male = sd(maleP$flipper_length_mm, na.rm = TRUE)
comprimento_sd_male

femaleP = penguins[penguins$sex == 'FEMALE', ]
print("Female Penguins")

print("peso_medio: ")
peso_medio_f = mean(femaleP$body_mass_g, na.rm = TRUE)
peso_medio_f

print("peso_sd: ")
peso_sd_f = sd(femaleP$body_mass_g, na.rm = TRUE)
peso_sd_f

print("comprimento_medio: ")
comprimento_medio_f = mean(femaleP$flipper_length_mm, na.rm = TRUE)
comprimento_medio_f


print("comprimento_sd: ")
comprimento_sd_f = sd(femaleP$flipper_length_mm, na.rm = TRUE)
comprimento_sd_f

### Analisando os dados, percebe-se que os penguins machos possuem, em média, o tamanho da asa e peso maior que dos penguins fêmeas.

## d
plot(penguins$flipper_length_mm, penguins$body_mass_g)

## e
cor(penguins$flipper_length_mm, penguins$body_mass_g, use="complete.obs")

## f
### Há uma correlação positiva forte entre o tamanho da asa do penguim e a massa do mesmo (r == 0.87,r > 0.7)

## g
wingWhLm = lm(body_mass_g ~ flipper_length_mm, data = penguins)
wingWhLm


## h
### O coeficiente angular encontrado 49.69 significa a variação no peso do penguin. Quando ocorre o aumento em 1mm na asa do penguin, a massa em gramas do penguin aumenta em 49.69 gramas

## i

weightPenguin = function (lengthWing) {
  return(49.69 * lengthWing - 5780.83)
}

weightPenguin(204)
### O peso médio de um penguim que tem o tamanho de asa de 204mm é 4355.93. Não poderiamos usar esse modelo de regressão linear para estimar o peso de um penguim com o tamanho de asa de 168mm, pois as amostras desse modelo não contém esse valor. O modelo só pode prever aqueles que estão dentro do intervalo da amostragem, aqueles que estão fora podem possuir um comportamento bem diferente do modelo linear.