#Lista 4
#Integrantes: Guilherme Alves Carvalho, Amauri Pietropaolo Tavares Junior, Heitor Freitas Ferreira, Luis Gustavo Seiji Tateishi, Gabriel Zeitoum

# Exercício 2

##b
hasHeartAttack = function (chest_pain, sex, smokes, exercises) {
  if(chest_pain == "yes") {
    return ("yes")
  }
  # chest_pain == "no"
  
  if(exercises == "yes" && smokes == "yes") {
    return ("no")
  } else {
    if(smokes == "yes") {
      return ("yes")
    } else {
      return ("no")
    }
  }
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
