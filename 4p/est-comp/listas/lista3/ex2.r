urna1 = c(rep("preta", 8), rep("branca", 3), rep("vermelha", 4))
urna2 = c(rep("preta", 3), rep("branca", 5), rep("vermelha", 7))
urna3 = c(rep("preta", 4), rep("branca", 3), rep("vermelha", 2))
urna4 = c(rep("preta", 2), rep("branca", 1), rep("vermelha", 8))

bolas = c()
for(i in 1:10000) {
  d1 = sample(1:6, size = 1)
  d2 = sample(1:6, size = 1)
  sum = d1 + d2
  if(sum < 4) {
    bolas[i] = sample(urna1, size = 1)
  } else if (sum >= 4 && sum < 7) {
    bolas[i] = sample(urna2, size = 1)
  } else if(sum == 7) {
    bolas[i] = sample(urna3, size = 1)
  } else {
    bolas[i] = sample(urna4, size = 1)
  }
}
mean(bolas == "vermelha")
