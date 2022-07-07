import math
import random

def dist(p1,p2):
    return math.sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)

def parProximoDireto(V,i,f):
    d=dist(V[i],V[i+1])
    par=(V[i],V[i+1])
    for j in range(i,f-1):
        for k in range(j+1,f):
            if dist(V[j],V[k])<d:
                d= dist(V[j],V[k])
                par=(V[j],V[k])

    arrayAux = []
    for k in range(i,f):
        arrayAux.append(V[k])
    ordenadoEmY = sorted(arrayAux, key = lambda x:x[1])
    return (d, par, ordenadoEmY)

def parProximoDC(V,i,f):
    if f-i<100:
        return parProximoDireto(V,i,f)
    m = int((f+i)/2)
    r1 = parProximoDC(V,i,m)
    r2 = parProximoDC(V,m+1,f)
    delta = r1[0]
    par = r1[1]
    if r2[0]<r1[0]:
        delta = r2[0]
        par = r2[1]

    ordenadoEmYEsquerda = r1[2]
    ordenadoEmYDireita = r2[2]
    ordenadoEmY = merge(ordenadoEmYEsquerda, ordenadoEmYDireita)

    faixa = []
    for k in range(len(ordenadoEmY)):
        if abs(ordenadoEmY[k][0] - V[m][0]) < delta:
            faixa.append(ordenadoEmY[k])


    for k in range(len(faixa)-1):
        for l in range(1,8):
            if k+l < len(faixa):
                if dist(faixa[k],faixa[k+l])<delta:
                    delta = dist(faixa[k],faixa[k+l])
                    par = (faixa[k],faixa[k+l])
    return (delta, par, ordenadoEmY)

prob = []
x=-1
for i in range(20000):
   x += random.randint(1,3)
   y = random.randint(0,100000)
   prob.append([x,y])

print parProximoDireto(prob,0,len(prob))
print parProximoDC(prob,0,len(prob))