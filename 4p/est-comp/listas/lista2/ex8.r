tamanho.seq = function(p) {
  # 0 = cara, 1 = coroa
  caras = 0;
  repeat {
    jogada = sample(c(0, 1), size = 1, replace=TRUE, prob = c(1 - p, p))
    if(jogada) break
    caras = caras + 1
  }
  caras
}

maior = 0
for(i in 1:100) {
  jogadas = tamanho.seq(1/2)
  if(jogadas > maior)
    maior = jogadas
}
maior