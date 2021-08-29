reprodCoelhos = function(n, k) {
  fib = c(1,1)
  to = n
  while(to > 2) {
    end = length(fib)
    fib = c(fib, fib[end] + fib[end - 1]*k)
    to = to - 1
  }
  fib[n]
}
reprodCoelhos(4, 70)
