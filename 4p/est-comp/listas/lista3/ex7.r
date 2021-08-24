f1 = function(x) {
  exp(-x^2/2)
}
(3/sqrt(2*pi))*mean(f1(runif(10000)))


f2 = function(x) {
  cos(x)^2
}

pi/2*mean(f2(runif(10000)))
