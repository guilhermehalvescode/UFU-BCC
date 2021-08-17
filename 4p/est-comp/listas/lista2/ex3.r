#a
fa = function(i) {
  i^3 + 4*(i^2)
}
a = sum(fa(c(10:100)))
a

#b
fb = function(i) {
  2^i/i + 3^i/i^2
}
b = sum(fb(10:25))
b
