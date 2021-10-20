#Lista 4
#Integrantes: Guilherme Alves Carvalho, Amauri Pietropaolo Tavares Junior, Heitor Freitas Ferreira, Luis Gustavo Seiji Tateishi, Gabriel Zeitoum

# Exercicio 1
##a
# mat_dist = matrix(c(0, 9, 3, 6, 11, 9, 0, 7, 5, 10, 3, 7, 0, 9, 2, 6, 5, 9, 0, 8, 11, 10, 2, 8, 0), nrow = 5)
mat_dist = rbind(c(0, 9, 3, 6, 11), c(9, 0, 7, 5, 10), c(3, 7, 0, 9, 2), c(6, 5, 9, 0, 8), c(11, 10, 2, 8, 0))

mat_dist = as.dist(mat_dist)

cluster = hclust(mat_dist, method = "complete")
plot(cluster)

##b
mat_dist = rbind(c(0, 9, 3, 6, 11), c(9, 0, 7, 5, 10), c(3, 7, 0, 9, 2), c(6, 5, 9, 0, 8), c(11, 10, 2, 8, 0))

mat_dist = as.dist(mat_dist)

cluster = hclust(mat_dist, method = "single")
plot(cluster)

##c
mat_dist = rbind(c(0, 9, 3, 6, 11), c(9, 0, 7, 5, 10), c(3, 7, 0, 9, 2), c(6, 5, 9, 0, 8), c(11, 10, 2, 8, 0))

mat_dist = as.dist(mat_dist)

cluster = hclust(mat_dist, method = "complete")
plot(cluster)
rect.hclust(cluster, k = 2)
### No primeiro aglomerado temos a observação 3 e 5
### No segundo aglomerado temos a observação 1, 2 e 4

##d
mat_dist = rbind(c(0, 9, 3, 6, 11), c(9, 0, 7, 5, 10), c(3, 7, 0, 9, 2), c(6, 5, 9, 0, 8), c(11, 10, 2, 8, 0))

mat_dist = as.dist(mat_dist)

cluster = hclust(mat_dist, method = "single")
plot(cluster)
rect.hclust(cluster, k = 2)
### No primeiro aglomerado temos a observação 1, 3 e 5
### No segundo aglomerado temos a observação 2 e 4


# Exercício 2
library(tree)
library(rpart)
library(rpart.plot)
##a

### Leitura do conjunto de dados
patients = read.csv("heart.txt", header = TRUE, sep = ",");

### Remoção de variáveis inúteis
patients = patients[, -1]

patients$heart_attack = as.factor(patients$heart_attack)
patients$exercises = as.factor(patients$exercises)
patients$sex = as.factor(patients$sex)
patients$smokes = as.factor(patients$smokes)
patients$chest_pain = as.factor(patients$chest_pain)

### Visualização da estrutura
str(patients)

### Embaralhando
patients = patients[sample(nrow(patients)), ]
train = patients[1:4, ]
test = patients[5:6, ] 
### Separação das variáveis
sick = patients[patients$heart_attack == "yes", ]
nonSick = patients[patients$heart_attack == "no", ]
summary(sick)
summary(nonSick)

modelHeart <- rpart(heart_attack ~., data = train, parms = list(split = "gini"))

rpart.plot(modelHeart, extra = 101)

##b
hasHeartAttack = function (chest_pain, sex, smokes, exercises) {
  return("yes");
}


# Exercício 3
kids = read.csv("SBI.csv", header = TRUE, sep = ",")
kids
str(kids)

##a
kidsValues = kids$sbi == "NotApplicable"
for(i in 1:length(kidsValues)) {
  if(kidsValues[i]) {
    kidsValues[i] = "no" 
  } else {
    kidsValues[i] = "yes"
  }
}
kids$infection = as.factor(kidsValues)

##b
kids = kids[, c(-1, -2, -8)]

##c
reordered = kids[sample(nrow(kids)), ]
nrow(kids)*0.8
train = reordered[1:1878, ]
test = reordered[1879:nrow(kids), ]
train

##d
library(tree)
library(rpart)
library(rpart.plot)

modelHeart = rpart(infection ~., data = train, parms = list(split = "gini"))
rpart.plot(modelHeart, extra = 101)

predictHeart = predict(modelHeart, newdata = test, type = "class")
mean(predictHeart == test$infection)
table(test$infection, predictHeart)

##e
library(randomForest)
rf.modelHeart = randomForest(infection~., data = train)
rf.modelHeart
rf.predictHeart = predict(rf.modelHeart, newdata = test)

mean(test$infection == rf.predictHeart)
table(test$infection, rf.predictHeart)
