g = function(x) {
  return (exp(-(1-x)/x)/x^2)
} 

u = runif(1000000, min = 0, max = 1)
func_g = g(u)
mean(func_g)

#mega sena
jogadas = c()

for(j in 1:10000) {
  bilhete = sample(1:60, size = 6, replace = FALSE)
  jogadas[j] = 0
  repeat {
    jogadas[j] = jogadas[j] + 1
    sorteio = sample(1:60, size = 6, replace = FALSE)
    if(sum(sorteio %in% bilhete) >= 4){
      break
    }
  }
}

runif(1)
runif(5)
set.seed(123)
runif(8)
runif(10)
