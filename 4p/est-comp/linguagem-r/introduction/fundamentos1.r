#### matemática básica

2+2
2-2
2/2
2*2
2**3 || 2^3
13%%2 # Resto

exp(1)
log(2, base = 10)
log(x = 10, base = exp(1))
log(base = 10, x = 2)
log(2) #base = exp(1) = e (euler)

#criando variáveis
soma1 <- 2 + 3
soma2 = 2 + 3
2 + 3 -> soma3

##### você pode rodar cada linha da seguinte maneira: (1) coloque o cursor ao final da linha e aperte control+enter no Windows ou cmd+enter no Mac ou aperte o botão Run que está localizado no menu; (2) selecione a linha ou o pedaço de código que deseja rodar e utilize algum procedimento citado em (1).


##### como visto acima, a hashtag é utilizada para fazer comentários; uma linha precedida por hashtag não será executada.

#2+2
2+2

###### os comandos abaixo não serão executados; o R apontará um erro.
#2234r*S&F(SD&F234)
#c(c))

#### R pode executar operações lógicas

#### é igual?
2==2
2==3

##### é diferente?
2!=2
2!=3

#### é "maior que" ou "menor que"?
2>1
2<1

#### é "maior ou igual que" ou "menor ou igual que"?
3>=1
3<=1


#### R pode trabalhar com strings
a = "apple"
b = "apple"
"pedro" == "pedro"
"pedro" != "Pedro"

a < b # compara tamanho das strings

#### é permitido utilizar espaços em strings 
"an apple"

###você pode utilizar operadores lógicos para comparar strings

"apple"=="Apple"
"apple"!="orange"

#### se você comparar strings a partir de uma desigualdade, então o R comparará o tamanho das strings

"apple" < "apple"

"apple">"apples"

#### atribuindo valores a um objeto

a <- 2+2
valor_a <- 2+2
valor.a <- 2+2

######## não é permitido iniciar o nome de uma variável por um número, por exemplo; também não é permitido ter espaços no nome de uma variável

#9a <- 2+2
#variavel a <- 2+2

#### você agora pode imprimir a variável a e fazer operações com ela.
a
a^2
a*4
class(a)

####você pode criar um vetor númerico ou com strings, por exemplo, utilizando a função "combine" ou também conhecida por "concatenate", c().

numeros <- c(1,2,3)
numeros
texto <- c("a","b")
texto
numeros2 <- 10:34
numeros2

sim_nao <- c(TRUE,FALSE,TRUE)
sim_nao

vetor6 = 32:99 # lista por enumeração
vetor6

vetor7 = seq(from = 1, to = 76, length.out = 100)
vetor7
#### vocé pode combinar vetores

numeros3 <- c(numeros, numeros2)


#####vocé pode selecionar certos elementos de um vetor:

x <- c(-1,10,11,12,13,14,15,16,17,18,19)

### escolhendo elementos de acordo com a posição

x[4] #quarto elemento
x[-4] #todos os elementos, exceto o quarto
x[2:4] #os elementos da segunda posição até a quarta
x[-(2:4)] #todos os elementos, execeto aqueles que da segunda posição até a quarta
x[c(1, 5)] #elementos da primeira e quinta posição

### escolhendo elementos pelo valor

x[x == 10] # elementos que são iguais a 10.
x[x < 0] #elementos que são menores do que zero


#### quando você salva diferentes tipos de dados, esses dados recebem uma "classe" que descreve quais tipos de dados estão no vetor

class(numeros)
class(texto)
class(sim_nao)


#### o que acontece se combinarmos numeros e strings?

vetor_combinado <- c(numeros, texto)
vetor_combinado

# dado virtual
dado1 = sample(1:6, size = 70000, replace = TRUE)
dado2 = sample(1:6, size = 70000, replace = TRUE)
soma = dado1 + dado2
deu12 = soma == 12
sum(soma <= 7)/70000