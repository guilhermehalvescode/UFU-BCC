xVec <- sample(0:999, 250, replace=T)
yVec <- sample(0:999, 250, replace=T)

#a
a = which(yVec > 600)


#b
b = yVec[a]

#c
exc = xVec[which(xVec %in% b)]
exc

#d
d = sqrt(abs(xVec - mean(xVec)))
d

#e
e = sum(abs(yVec - max(yVec)) <= 200)
e

#f
f = sum(xVec %% 2 == 0)
f

#g
g = xVec[order(yVec)]
g

#h
h = yVec[seq(from = 1, to = length(yVec), by = 3)]
h