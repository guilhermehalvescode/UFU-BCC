
wins = c()

for(i in 1:1000000) {
  d1 = sample(1:6, size = 1)
  d2 = sample(1:6, size = 1)
  soma = d1 + d2
  if(soma == 7 || soma == 11) {
    wins[i] = TRUE
  } else if(soma == 2 || soma == 3 || soma == 12) {
    wins[i] = FALSE
  } else {
    somaInicial = soma
    repeat {
      d1 = sample(1:6, size = 1)
      d2 = sample(1:6, size = 1)
      soma = d1 + d2
      if(soma == 7) {
        wins[i] = FALSE
        break
      } else if(soma == somaInicial) {
        wins[i] = TRUE
        break
      }
    }
  } 
}
mean(wins)
