# inversa == x^2 + x -2*y = 0 // a = 1, b = 1, c = -2*y

gera_r = function(c) {
  #delta > 0 === 1-4c > 0 -> c < 1/4
  if(c < 1/4) {
    delta = 1-4*c
    x1 = (-1+sqrt(delta))/2
    x2 = (-1-sqrt(delta))/2
    return(c(x1,x2))
  }
}
ex9 = function(n) {
  vals = runif(n)
  xs = c()
  for(i in 1:n) {
    rs = gera_r(-2*vals[i])
    if(rs[1] >= 0 && rs[1] <= 1) {
      xs[i] = rs[1]
    } else if(rs[2] >= 0 && rs[2] <= 1) {
      xs[i] = rs[2]
    }
  }
  xs
}
estims = ex9(10000)
mean(estims < 0.7)
mean(estims)
