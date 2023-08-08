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