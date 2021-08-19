num.impar = function(v) {
  imp = 0
  for(i in v) 
    imp = imp + (i %% 2)
  imp
}

res = num.impar(seq(1, 11, 2))
res

num.impar2 = function(v) {
  sum(v %% 2)
}

res2 = num.impar(seq(1, 11, 2))
res2
