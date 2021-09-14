#### matem?tica b?sica

2+2
2-2
2/2
2*2
13%%2

exp(1)
log(x = 10, base = exp(1))

##### voc? pode rodar cada linha da seguinte maneira: (1) coloque o cursor ao final da linha e aperte control+enter no Windows ou cmd+enter no Mac ou aperte o bot?o Run que est? localizado no menu; (2) selecione a linha ou o peda?o de c?digo que deseja rodar e utilize algum procedimento citado em (1).


##### como visto acima, a hashtag ? utilizada para fazer coment?rios; uma linha precedida por hashtag n?o ser? executada.

#2+2
2+2

###### os comandos abaixo n?o ser?o executados; o R apontar? um erro.
2234r*S&F(SD&F234)
c(c))

#### R pode executar opera??es l?gicas

#### ? igual?
2==2
2==3

##### ? diferente?
2!=2
2!=3

#### ? "maior que" ou "menor que"?
2>1
2<1

#### ? "maior ou igual que" ou "menor ou igual que"?
3>=1
3<=1


#### R pode trabalhar com strings
"apple"


#### ? permitido utilizar espa?os em strings 
"an apple"

###voc? pode utilizar operadores l?gicos para comparar strings

"apple"=="Apple"
"apple"!="orange"

#### se voc? comparar strings a partir de uma desigualdade, ent?o o R comparar? o tamanho das strings

"apple" < "apple"

"apple">"apples"

#### atribuindo valores a um objeto

a <- 2+2
valor_a <- 2+2
valor.a <- 2+2

######## n?o ? permitido iniciar o nome de uma vari?vel por um n?mero, por exemplo; tamb?m n?o ? permitido ter espa?os no nome de uma vari?vel

9a <- 2+2
variavel a <- 2+2

#### voc? agora pode imprimir a vari?vel a e fazer opera??es com ela.
a
a^2
a*4
class(a)

####voc? pode criar um vetor n?merico ou com strings, por exemplo, utilizando a fun??o "combine" ou tamb?m conhecida por "concatenate", c().

numeros <- c(1,2,3)
numeros
texto <- c("a","b")
texto
numeros2 <- 10:34
numeros2

sim_nao <- c(TRUE,FALSE,TRUE)
sim_nao

#### voc? pode combinar vetores

numeros3 <- c(numeros, numeros2)


#####voc? pode selecionar certos elementos de um vetor:

x <- c(-1,10,11,12,13,14,15,16,17,18,19)

### escolhendo elementos de acordo com a posi??o

x[4] #quarto elemento
x[-4] #todos os elementos, exceto o quarto
x[2:4] #os elementos da segunda posi??o at? a quarta
x[-(2:4)] #todos os elementos, execeto aqueles que da segunda posi??o at? a quarta
x[c(1, 5)] #elementos da primeira e quinta posi??o

### escolhendo elementos pelo valor

x[x == 10] # elementos que s?o iguais a 10.
x[x < 0] #elementos que s?o menores do que zero


#### quando voc? salva diferentes tipos de dados, esses dados recebem uma "classe" que descreve quais tipos de dados est?o no vetor

class(numeros)
class(texto)
class(sim_nao)


#### o que acontece se combinarmos numeros e strings?

vetor_combinado <- c(numeros, texto)
vetor_combinado

