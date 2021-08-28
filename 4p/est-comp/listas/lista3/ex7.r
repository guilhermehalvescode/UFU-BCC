f1 = function(x) {
  (1/sqrt(2*pi))*exp(-x^2/2)
}
3*mean(f1(runif(1000000, min = -1, max = 2)))


f2 = function(x) {
  cos(x)^2
}

pi*mean(f2(runif(1000000, min = 0, max = pi)))

