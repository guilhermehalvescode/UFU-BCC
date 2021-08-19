fibonacci = function(n) {
  fib = c(1,1)
  to = n
  while(to > 2) {
    end = length(fib)
    fib = c(fib, fib[end] + fib[end - 1])
    to = to - 1
  }
  return(fib[1:n])
}
fibonacci(6)
