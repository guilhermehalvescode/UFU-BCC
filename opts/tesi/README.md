# Tópicos Especiais em Segurança da Informação (Smart Contracts)

> O que são Smart Contracts

- Ethereum é uma plataforma para contratos inteligentes, usa uma blockchain, define um token e uma EVM (Ethereum Virtual Machine)
- Principal linguagem: Solidity

```solidity
contract Leilao {
enum EstadosLeilao { LancesEstado, FinalizadoEstado}
EstadosLeilao meuEstado;

mapping (address => uint) lances;
uint blocklimit;
address vencedor;
address payable dono;
uint vencedorval;
bool pagou;

constructor(address payable d,uint tempo) public {
  blocklimit= block.number + tempo;
  meuEstado = EstadosLeilao.LancesEstado;
  vencedorval = 0;
  dono =d;
  pagou = false;
}
```

## Criptografia

### Exponencial e Polinomial

- Polinomial: factível, tratável
- Exponencial: intratável
- 2^160 esta além do poder computacional mundial
- NP é fácil verificar
- certificado/informação/solução
- máquina não determinística
- quase todos os problemas estudados são NP
- verificar se um numero é par, verficiar se um grafo é um ciclo

---

- Grande parte da criptografia só funciona com número grandes, só é segura dessa forma
- Fatoração x Multiplicação
- trapdoor
- CPU: 64 bits

---

- Biblioteca de Números Grandes
- Limite: memória e CPU
- Os numeros são armazenados como vetores
- As bibliotecas implementam as operações usuais: +, -, *, /, ehPrimo, etc

### Exponenciação

```portugol
int potencia(b,e):

  Se o expoente é par
    temp = potencia(b,e/2)
    retorna temp*temp

  temp = potencia(b,e/2)
  retorna temp*temp*b
```

### O problema do Logaritmo

- Dado um número x, b com x = b^e, determinar e
- Busca exaustiva: O(n), Busca exponencial: O(log n)

### O problema do Logaritmo Discreto

- Dados x, b e n com x = b^e mod n, determinar e
- mod n faz x ser circular, sendo n escolhido adequadamente

### Estabelecimento de Chaves

- Alice e Bob querem conversar de forma privada
- Eva (eavesdropper) fica escutando tudo
- Alice e Bob conhecem um bom cifrador
- mas não compartilham nenhum segredo
- Todos envolvidos conhecem o básico de matemática: multiplicação, (exponenciação)
- Este é um cenário razoável na Internet

---

- Alice, Bob e Eva conhecem uma base g
- (Alice pode escolher um número aleatório e colocar no blog dela...)
- Alise escolhe uma chave a e calcula g^a
- Bob escolher uma chave b e calcula g^b
- Alice faz um broadcast de g^a, Bob faz de g^b
- Alice conhece: g, a, g^a, g^b
- Bob conhece: g, b, g^a, g^b
- Eva conhece: g, g^a, g^b

---

- Alice conhece: g, a, g^a, g^b
- Alice faz (g^b)^a, obtendo g^(ab)
- Bob conhece: g, b, g^b, g^a
- Bob faz (g^a)^b, obtendo g^(ba) = g^(ab)
- Eva conhece: g, g^a, g^b
- Eva faz o que??
- Eva não consegue calcular g^(ab)
- Alice e Bob podem usar g^(ab) como chave secreta
- Eva não consegue calcular g^(ab) mesmo que saiba g, g^a e g^b (g^(a+b) somente)

## Hash

- Espalhamento ou dispersão
- Estrutura de Dados (Banco de Dados)
- Transforma uma lista grande em muitas listas pequenas/unitárias
- O(1)
  - o mundo real não funciona assim
- São uma informação pequena que representa uma informação grande

### Hashing Criptográfico - Propriedades

- h = H(x)
  - Compressão: |h| é muito menor que |x| (h possui tamanho fixo)
  - Eficiência
  - (Algoritmo Público)
  - Difícil de inverter = computacionalmente inviável, com probabilidade desprezível
  - Unidirecionais
    - Dado x, calcular h é fácil
    - dado h deve ser difícil determinar x' tal que H(x') = h
  - x' pode ser diferente de x
  - Difícil de colidir
    - Dado x, é difícil encontrar x' tal que H(x) = H(x')
    - Colisão: x != x' e H(x) = H(x')

---

- Há um algoritmo para inverter o hash

- Resistência a segunda pré-imagem
  - Dado x1
  - É difícil encontrar x2, (x1 != x2) tal que H(x1) = H(x2)
- Alguma informação de x1 pode ser usada...
- No exemplo de hash $\sum mod 10$, basta trocar 2 dígitos de x1 para obter H(x1) = H(x2)

### Algumas funções de hash

- MD5 (message digest)
  - Ron Rivest
  - MD2, MD4, ...
  - hash de 128 bits
  - Atualmente não é considerado seguro (colisões)

- Família SHA
  - Secure Hash Algorithm
  - SHA-0, SHA-1, SHA-2, SHA-3
  - até 512 bits
  - SHA-0 é insegura (criptoanálise)
- RIPEMD
  - 160 bits
- SHA3 e RIPEMD são as mais usadas no mundo das criptomoedas

### Aplicações

#### Compromissos - Commitments

- Eu preciso me comprometer com uma informação: M
- Eu não posso/quero revelar a informação M agora
- Eu publico um hash H(M)

---

- Alice conhece M (e h = H(M))
- Alice envia h para Bob
- Bob consegue determinar M?
- Em algum momento do futuro Alice envia M' para Bob
- Bob tem condições de saber se M == M'?
  - Bob calcula h' = H(M') e compara com h enviado por Alice

---

- Bom consegue determinar M?
  - Não, propriedade de unidirecionalidade de H
- Alice tem condições de gerar M' != M com H(M') == H(M)?
  - Não, propriedade de resistência a colisão de H
- Alguém tem condições de gerar M' != M com H(M') == H(M)?
  - Não, propriedade de resistência a segunda pré-imagem de H
- Bob tem condições de saber se M == M'?
  - Sim, basta comparar h com h'

---

##### Aplicações dos compromissos

- Leilão de Envelope fechado
- Os candidatos enviam envelopes fechados e lacrados até uma data limite
- No dia do leilão, o leiloeiro abre os envelopes e anuncia o vencedor (maior lance)
- (comum em licitações/privatizações)

---

- Leilão de Envelope fechado
  - O candidato i envia hi = H(Mi)
  - Cada hi é publicado
  - Após a fase de compromisso, os candidatos revelam Mi
  - O leiloeiro e os demais candidatos podem verificar se a legitimidade de cada Mi
  - (Diferente do sistema de envelope o candidato pode desistir de revelar Mi)

---

- O uso de commits é muito frequente em Smart Contracts
- O algoritmo é executado por todos os mineradores
- Execução confiável, porém sem confidencialidade
- Solução: compromissos e Zero Knowledge Proofs

#### Filtros de Bloom

- Estrutura de dados probabilística
- Dado uma função de hashing H podemos criar um número arbitrariamente grande de funções de hashing
  - H1, H2, H3, ...

---

- Definimos:
  - Hi(x) := H(i || x)
  - Concatenamos o identificador de função na mensagem (salting)
  - (Pode ser antes, depois, envelopando, ...)
  - Hi(x) != Hj(x) para i != j
  - (É o que esperamos ...)
  
---

- Um filtro de Bloom é uma ED com a seguinte interface:

```portugol
void insert(k)
contains(k) -> boolean
```

- contains(k) é probabilístico e retorna:
  - true: k **talvez** está no filtro
  - false: k não está no filtro
  - (não melhora se perguntar de novo!)

---

- O construtor de um Filtro de Bloom recebe dois parâmetros:
  - n que determina o tamanho de um vetor V de booleanos (inicializado em false)
  - h que determina o número de funções de hashing a serem utilizadas: h1, h2, ..., hh

---

- Ideia das funções

```python

def insert(k):
  for i in range(1, h+1):
    t = hi(k) 
    V[t % n] = True

def contains(k):
  for i in range(1, h+1):
    t = hi(k)
    if V[t % n] == False:
      return False
  return True
```

---

- O que acontece se k não foi inserido?
  - Todas as posições de V serão false
  - contains(k) sempre retorna false
  - (não há falsos negativos)
- O que acontece se k foi inserido?
  - Todas as posições de V serão true
  - porém outro k' pode ter colidido com k
  - por isso quando contains(k) retorna true, **talvez** ele esteja no filtro 

---

- É possível calcular a probabilidade de falsos positivos
- É possível estimar o tamanho do conjunto
- União e intersecção (probabilística) de conjuntos
- Consulta confidencial a uma base de dados grande!! (bitcoin)
- (O cliente pede o filtro e faz a consulta localmente...)

#### Árvore de Merkle