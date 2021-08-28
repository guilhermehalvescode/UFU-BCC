# a
N = 20
lukePosLprec = function(l) {
  caiu = c()
  # takes too long
  for(cases in 1:10000) {
    pos = l;
    repeat {
      pos = pos + sample(c(-1, 1), size = 1)
      if(pos == 0 || pos == N) break; 
    }
    caiu[cases] = (pos == 0)
  }
  return(mean(caiu))
}

#b
estims = unlist(Map(lukePosLprec, 1:19))
plot(1:19, estims, main = 'Resultado', type = 'l')
