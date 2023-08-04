# Tópicos Especiais em Segurança da Informação (Smart Contracts)

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

### Estabelecimento de Chaves

- Alice e Bob querem conversar de forma privada
- Eva (eavesdropper) fica escutando tudo
- Alice e Bob conhecem um bom cifrador
- mas não compartilham nenhum segredo
- Todos envolvidos conhecem o básido de matemática: multiplicação, (exponenciação)
- Este é um cenário razoável na Internet

## Hash

- Espalhamento ou dispersão