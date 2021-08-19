library(dslabs)
data("murders")
str(murders)
#a
media = mean(murders$population)
estadoMaisPopuloso = murders[murders$population == max(murders$population), ]$state
estadoMenosPopuloso = murders[murders$population == min(murders$population), ]$state
