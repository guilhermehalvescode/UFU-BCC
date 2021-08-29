library(dslabs)
data("murders")
str(murders)
#a
media = mean(murders$population)
estadoMaisPopuloso = murders[murders$population == max(murders$population), ]$state
estadoMenosPopuloso = murders[murders$population == min(murders$population), ]$state
summary(murders)

#b
rate = (murders$total/murders$population)*10000
murders$rate = rate

#c
murders[order(murders$rate), ]$state

#d
inferior5 = murders[murders$rate < 0.05, ]$state
superior5 = murders[murders$rate > 0.05, ]$state

#e
maiorTaxa = murders[order(murders$rate)[length(murders$rate)], ]$state
menorTaxa = murders[order(murders$rate)[1], ]$state

#f
south = murders[murders$region == "South", ]
meanSouth = mean(south$rate)
sdSouth = sd(south$rate)

northCentral = murders[murders$region == "North Central", ]
meanNorthCentral = mean(northCentral$rate)
sdNorthCentral = sd(northCentral$rate)

west = murders[murders$region == "West", ]
meanWest = mean(west$rate)
sdWest = sd(west$rate)

northEast = murders[murders$region == "Northeast", ]
meanNortheast = mean(northEast$rate)
sdNortheast = sd(northEast$rate)

nomeReg = c("South", "North Central", "West", "Northeast")
taxasMax = c(max(south$rate), max(northCentral$rate), max(west$rate), max(northEast$rate))
taxasMin = c(min(south$rate), min(northCentral$rate), min(west$rate), min(northEast$rate))
regMaiorTax = nomeReg[taxasMax == max(taxasMax)]
regMenorTax = nomeReg[taxasMin == min(taxasMin)]

#g
boxplot(south$rate, main = "South", ylim = c(min(rate), max(rate)))
boxplot(northCentral$rate, main = "North Central", ylim = c(min(rate), max(rate)))
boxplot(west$rate, main = "West", ylim = c(min(rate), max(rate)))
boxplot(northEast$rate, main = "Northeast", ylim = c(min(rate), max(rate)))
par(mfrow = c(1,4))
# South region is the most violent place, considering It's boxplot offset above from other regions