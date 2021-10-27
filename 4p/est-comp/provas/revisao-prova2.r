dados <- USArrests
str(USArrests)
dados <- scale(dados)
matriz_dist <- dist(dados)
dendograma <- hclust(matriz_dist, method = "ward.D2")
plot(dendograma)
abline(h = 4)
aglomerados <- cutree(dendograma, k = 4)
rect.hclust(dendograma, k = 4)
which(aglomerados == 1)
proteina <- read.table("protein.txt", header = TRUE, sep = "\t")
str(proteina)
scale(proteina[,-c("Country")])
proteina[,c("Eggs", "RedMeat")]

iris
iris <- iris[sample(nrow(iris)),]
n <- round(nrow(iris)*0.8)
n
treino <- iris[1:n,]
teste <- iris[-(1:n),]

modelo.iris <- rpart(formula = Species~., data = treino, parms = list(split = "information"))
rpart.plot(modelo.iris, extra = 101)

previsao.iris <- predict(modelo.iris, newdata = teste[,-5], type = "class")
previsao.iris
mean(previsao.iris == treino$Species)
table(previsao.iris, teste$Species)

floresta.iris <- randomForest(formula = Species~., data = treino, ntree = 700)
floresta.iris
names(floresta.iris)
floresta.iris$err.rate
previsao.floresta <- predict(floresta.iris, newdata = teste[,-5], type = "class")
mean(previsao.floresta == teste$Species)
sum(treino$Species == "versicolor")

cogumelos
n <- round(nrow(cogumelos)*0.8)
treino <- cogumelos[1:n, ]
teste <- cogumelos[-(1:n), ]
summary(cogumelos)
floresta.cogumelos <- randomForest(formula = class~., data = treino)
previsao.cogumelos <- predict(floresta.cogumelos, newdata = teste[,-1], type = "class")
mean(previsao == teste$class)

data("heartrate")
coracao <- heartrate
cor(coracao$age, coracao$maxrate)
cor(iris[,-5])
modelo.coracao <- lm(formula = maxrate~., data = coracao)
plot(coracao$age, coracao$maxrate, pch = 16)
abline(modelo.coracao)