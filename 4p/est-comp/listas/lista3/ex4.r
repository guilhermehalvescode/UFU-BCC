dwith = c(0, 1, 0)
jim = c(0, 0, 1)

wins = c()
for(i in 1:100000) {
  sequencia = sample(0:1, size = 3, replace=TRUE)
  repeat {
    if(all(sequencia == dwith)) {
      wins[i] = FALSE
      break
    } else if(all(sequencia == jim)) {
      wins[i] = TRUE
      break
    }
    sequencia = c(sequencia[2:3], sample(0:1, size = 1)) 
  }
}
mean(wins)
