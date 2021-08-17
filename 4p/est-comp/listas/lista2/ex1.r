#a
a = c(1:20) 

#b
b = c(20:1)

#c
exc = c(1:20, 19:1) 
exc

#d
d = c()
j = 1
for (i in seq(from = 1, to = 34, by = 3)) {
  d[j] = (0.1^(i + 2))*(0.2^i)
  j = j + 1
}
d

#e
e = rep(c(4,6,3), 10)
e

#f
f = rep(c(4,6,3), 11, length.out = (3 * 11) - 2)
f
f == c(e, 4)
