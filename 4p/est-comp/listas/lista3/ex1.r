l1 = sample(1:6, size = 100000, replace = TRUE)
l2 = sample(1:6, size = 100000, replace = TRUE)
somas = l1 + l2
mean(somas == 7 | somas == 11)
