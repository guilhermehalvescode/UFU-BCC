#Lista 3
#Integrantes: Guilherme Alves Carvalho, Amauri Pietropaolo Tavares Junior, Heitor Freitas Ferreira, Luis Gustavo Seiji Tateishi, Gabriel Zeitoum

#Exercício 1
l1 = sample(1:6, size = 100000, replace = TRUE)
l2 = sample(1:6, size = 100000, replace = TRUE)
somas = l1 + l2
mean(somas == 7 | somas == 11)

urna1 = c(rep("preta", 8), rep("branca", 3), rep("vermelha", 4))
urna2 = c(rep("preta", 3), rep("branca", 5), rep("vermelha", 7))
urna3 = c(rep("preta", 4), rep("branca", 3), rep("vermelha", 2))
urna4 = c(rep("preta", 2), rep("branca", 1), rep("vermelha", 8))

#Exercício 2
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

#Exercício 3
wins = c()

for(i in 1:1000000) {
  d1 = sample(1:6, size = 1)
  d2 = sample(1:6, size = 1)
  soma = d1 + d2
  if(soma == 7 || soma == 11) {
    wins[i] = TRUE
  } else if(soma == 2 || soma == 3 || soma == 12) {
    wins[i] = FALSE
  } else {
    somaInicial = soma
    repeat {
      d1 = sample(1:6, size = 1)
      d2 = sample(1:6, size = 1)
      soma = d1 + d2
      if(soma == 7) {
        wins[i] = FALSE
        break
      } else if(soma == somaInicial) {
        wins[i] = TRUE
        break
      }
    }
  } 
}
mean(wins)

#Exercício 4
dwith = c(0, 1, 0)
jim = c(0, 0, 1)

wins = c()
for(i in 1:100000) {
  sequencia = sample(0:1, size = 3, replace=TRUE)
  repeat {
    if(all(sequencia == dwith)) {
      wins[i] = FALSE
      break
    } else if(all(sequencia == jim)) {
      wins[i] = TRUE
      break
    }
    sequencia = c(sequencia[2:3], sample(0:1, size = 1)) 
  }
}
mean(wins)

#Exercício 5
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

#Exercício 6
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

#Exercício 7
f1 = function(x) {
  (1/sqrt(2*pi))*exp(-x^2/2)
}
3*mean(f1(runif(1000000, min = -1, max = 2)))


f2 = function(x) {
  cos(x)^2
}

pi*mean(f2(runif(1000000, min = 0, max = pi)))

#Exercício 8
nVal = function(n) {
  valores = c()
  for(i in 1:n) {
    val = runif(1)
    if(val < 1/7) {
      valores[i] = 1
    } else if(val < 3/7) {
      valores[i] = 5
    } else {
      valores[i] = 10
    }
    
  }
  return(valores)
}
mean(nVal(100) == 5)
mean(nVal(1000) == 5)
mean(nVal(10000) == 5)

#Exercício 9
# inversa == x^2 + x -2*y = 0 // a = 1, b = 1, c = -2*y

gera_r = function(c) {
  #delta > 0 === 1-4c > 0 -> c < 1/4
  if(c < 1/4) {
    delta = 1-4*c
    x1 = (-1+sqrt(delta))/2
    x2 = (-1-sqrt(delta))/2
    return(c(x1,x2))
  }
}
ex9 = function(n) {
  vals = runif(n)
  xs = c()
  for(i in 1:n) {
    rs = gera_r(-2*vals[i])
    if(rs[1] >= 0 && rs[1] <= 1) {
      xs[i] = rs[1]
    } else if(rs[2] >= 0 && rs[2] <= 1) {
      xs[i] = rs[2]
    }
  }
  xs
}
estims = ex9(10000)
mean(estims < 0.7)
mean(estims)
