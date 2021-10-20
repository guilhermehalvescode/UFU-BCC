library(tree)
library(rpart)
library(rpart.plot)
set.seed(29)
data(iris)
iris <- iris[sample(150),]
n <- round(length(iris$Species)*0.8)
treino <- iris[1:n,]
teste <- iris[(n+1):150,]

setosa <- treino[treino$Species == "setosa", ]
virginica <- treino[treino$Species == "virginica", ]
versicolor <- treino[treino$Species == "versicolor", ]
plot(treino$Petal.Length, treino$Petal.Width, type = "n", xlab = "Tamanho da pétala", ylab = "Largura da pétala", main = "Petála da iris")
points(setosa$Petal.Length, setosa$Petal.Width, pch = 16, col = "orange", cex = 0.5)
points(virginica$Petal.Length, virginica$Petal.Width, pch = 16, col = "red", cex = 0.5)
points(versicolor$Petal.Length, versicolor$Petal.Width, pch = 16, col = "blue", cex = 0.5)