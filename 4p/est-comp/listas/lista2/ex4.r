xVec <- sample(0:999, 250, replace=T)
yVec <- sample(0:999, 250, replace=T)

#a
imparesxvec = xVec[xVec %% 2 != 0]
imparesxvec

#b
b = yVec[-1] - xVec[-length(xVec)]
b

#c
c = sin(yVec[-1])/cos(xVec[-length(xVec)])
c

#d
d = c()
for(i in 1:(length(xVec) - 2)) {
  d[i] = xVec[i] + 2*xVec[i + 1] - xVec[i + 2]
}
d

#e

num = exp(-(xVec[2:250]))
dem = xVec[1:249] + 10
e = num/dem
e
