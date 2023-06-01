# Inteligência Computacional

1. Redes Neurais Artificiais
2. Computação Evolutiva
3. Sistemas Nebulosos

> Anotações no caderno, professor não permite usar notebook na aula (??????)

## Revisão prova

### Explicar algoritmo genético e como é seu funcionamento

- O algoritmo genético funciona da seguinte forma: há uma estrutura de dados que representa um indivíduo, podendo essa ser no formato de um vetor binário, inteiro ou real e uma função de avaliação que da uma nota para esse indivíduo. O algoritmo inicia com uma população de indivíduos e avalia a nota desses, e enquanto um critério de parada não for atendido (número de gerações, etc...), realiza uma seleção nesses indivíduos, e logo após realiza o cruzamento e mutações (ambos possuem uma probabilidade definida para acontecer) para gerar novos indivíduos e substituir esses novos na antiga população

### Como funciona o crossover de N partes e o Crossover médio

- O crossover de N partes particiona os pais escolhidos para cruzamento em N partes, e gera os dois filhos trocando as partes de índice par do cromossomo, sendo um exemplo
  - Pai1: 10|111|00|1 -> Filho1: 10|101|00|0
  - Pai2: 01|101|11|0 -> Filho2: 01|111|11|1
- Já o crossover médio ou intermediário ocorre realizando uma proporção entre os genes dos pais envolvidos no cruzamento, seguindo a fórmula:
  - filho1 = alfa x gene pai1 + (1 - alfa) gene pai2
  - filho2 = alfa x gene pai2 + (1 - alfa) gene pai1
- Podendo realizar apenas em um gene, a partir de uma sequência de genes ou em todos os genes, sendo um exemplo, com alfa = 0,5 (realiza a média)
  - Pai1: 2.45, 2.33, 2.40 (crossover a partir do segundo gene) -> Filho1: 2.45, 1.83, 1.9
  - Pai2: 2.50, 1.33, 1.40 (crossover a partir do segundo gene) -> Filho2: 2.45, 1.83, 1.9

### Tipos de crossover/roleta/torneio

- (muito difícil eu lembrar todos) Os tipos de crossover são: de N pontos (entra os de 1 ponto e de 2 pontos), ordem 1 (que copia uma subsequência do pai1 para o filho1 e copia o restante do pai2 para o filho 1, sem repetição), o Uniforme (que utiliza uma máscara aleatória), o PMX, o Cíclico, o ERX e os para valores reais (discreto ou arimético)
- A seleção por roleta é uma forma de selecionar de forma probalística os indivíduos de uma população baseado em seu valor de aptidão, sendo que cada indivíduo tem sua probabilidade de ser escolhido baseado em seu valor de aptidão. Após essas probabilidades serem calculadas, é sorteado aleatoriamente um desses indivíduos, simulando uma roleta.
- A seleção por torneio é uma forma de seleção em que N indivíduos são selecionados, e o que tiver melhor aptidão entre esses N é escolhido, simulando um torneio entre os N participantes.

### Explicar o algoritmo MLP (com foward propagation e backpropagation no ajuste de pesos)

- MLP é uma arquitetura de uma rede neural artificial onde existem camadas de entrada, ocultas e de saída, com n neurônios em cada camada e entre cada camada existem pesos que são atualizados/corrigidos durante o treinamento de uma rede neural. O forward propagation diz respeito ao processo de fornecer dados de entrada para essa rede, de modo que cada camada com seus respectivos neurônios calculem sua ativação (soma ponderada dos pesos da camada atual com a entrada, e após a aplicação de uma função de ativação) e propagam para a próxima camamda, até que chegue na camada de saída da rede. Já o backpropagation, diz respeito ao processo de atualizar os pesos da rede, através do erro obtido na camada de saída (diferença do que era esperado e o que a rede gerou), de forma que a partir da camada de saída chegue até a camada de entrada atualizando os pesos através dos valores das derivadas parciais dos erros.

### Explicação sobre tipos de aprendizado de máquina

- Os tipos de aprendizado de máquina são:
  - aprendizado supervisionado: no qual se tem as classes dos dados utilizados no algoritmo, dessa forma consegue-se saber se o algoritmo esta errando ou não no processo de treinamento
  - aprendizado não supervisionado: no qual não se tem as classes dos dados utilizados no algoritmo, dessa forma o mesmo tenta achar características comuns entre os dados, formando grupos similares entre si (não há uma classificação definida para a informação passada)
  - aprendizado por reforço: no qual o aprendizado ocorre por recompensas negativas ou positivas diante dos resultados mostrados pelo algoritmo, um exemplo seria (se pousou tranquilamente o avião, recompensar positivamente, porém se pousou e explodiu o avião, recompensar negativamente).