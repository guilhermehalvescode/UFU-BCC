nVal = function(n) {
  valores = c()
  for(i in 1:n) {
    val = runif(1)
    if(val < 1/7) {
      valores[i] = 1
    } else if(val < 3/7) {
      valores[i] = 5
    } else {
      valores[i] = 10
    }
    
  }
  return(valores)
}
mean(nVal(100) == 5)
mean(nVal(1000) == 5)
mean(nVal(10000) == 5)
