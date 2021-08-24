lukeNpassos = function(n) {
  positions = c()
  for(cases in 1:100000) {
    pos = 0;
    for(i in 1:n) {
      pos = pos + sample(c(-1, 1), size = 1)
    }
    positions[cases] = pos
  }
  return(mean(positions == 0))
}
# i
lukeNpassos(4)
# ii
lukeNpassos(6)
# iii
lukeNpassos(10)
# iv
lukeNpassos(20)
