# Arquitetura e Organização de Computadores 1

## Objetivo

- Estudo de um sistema de computação sob dois pontos de vista:
  - **Arquitetural** - se refere aos atributos do sistema visíveis a uma programador de linguagem de máquina e
  - **Organizacional** - as unidades operacionais e sua interconexão que realizam a arquitetura
- Vamos estudar a estrutura e a função de um computador
  - **estrutura** - a forma em que os componentes estão interconectados e
  - **função** - o comportamento de cada componente individualmente
  - Cada componente pode, por sua vez, de forma hierárquica, se decomposto em subcomponentes, descrevendo a sua estrutura e função

![intro](images/intro.png)

## Arquitetura & Organização

- Exemplo:
- É uma questão de projeto arquitetural se o computador deve ter uma instrução de multiplicação. Mas é uma questão organizacional se a instrução deve ser implementada com uma unidade de multiplicação ou através de repetidas somas
  - Muitas fabricantes oferecem uma família de modelos de computadores, todos com a mesma arquitetura, mas com diferenças na parte organizacional. Resultam assim em modelos com preços e desempenhos diferentes, mas podendo executar os mesmos programas escritos
  - Toda a família Intel x86 compartilha a mesma arquitetura básica
  - A família IBM System/370 compartilha a mesma arquitetura básica
    - Isto determina a compatibilidade de código - pelo menos para as versões anteriores
  - A organização difere entre diferentes versões

## Estrutura & Função

- Em cada nível o projetista se preocupa com a estrutura e a função
  - Estrutura: a maneira em que os componentes são interelacionados
  - Função: a operação de cada componente, individualmente

## Visão Funcional

![functionalView](images/functionalView.png)

### Operações (1)

- Data movement
  - ex., teclado para vídeo (keyboard to screen)

![readMovement](images/readMovement.png)

### Operações (2)

- Storage
  - internet download para unidade de disco

![downloadMovement](images/downloadMovement.png)

### Operações (3)

- Processamento de/para memória
  - ex., atualizando saldo bancário

![sumMovement](images/sumMovement.png)

### Operações (4)

- Processamento da memória para E/S
  - impressão do saldo bancário

![printMovement](images/printMovement.png)

## Estrutura de um Computador - Visão Top-Down

![topDownView](images/topDownView.png)

## Estrutura - A Unidade de Processamento

![cpuView](images/cpuView.png)

## Estrutura - A Unidade de Controle

![controlUnitView](images/controlUnitView.png)

## Evolução dos Computadores e Desempenho

### História dos Computadores

#### A Era Mecânica (1600s-1940s)

- Wilhelm Schickhard (1623)
  - Astrônomo e Matemático
  - Cálculos de adição, subtração, multiplicação e divisão
- Blaise Pascal (1642)
  - Matemático
  - Primeira máquina operacional de produção em série
    - 50 cópias
  - Somente somava e subtraia
  - Apresentou problemas operacionais e de manutenção
- Gottfried Liebniz (1673)
  - Filósofo, cientista, matemático e inventor
  - Melhorou a máquina de Pascal
  - somava, subtraia, multiplicava e dividia
- Charles Babbage (1822)
  - Matemático - "Pai do computador moderno"
  - Buscava mais precisão nos cálculos
  - Máquina de Diferenças (Difference engine)
    - Primeiro acordo científico governamental
    - Cálculo automático de tabelas matemáticas
    - *Primeira máquina utilizada para resolver um problema*
  - Máquina Analítica (Analytic engine)
    - Realizava qualquer operação matemática
    - Dados em cartões perfurados
    - Estrutura moderna: E/S, armazenadores, ALU
    - Adição em 1 segundo, multiplicação em 1 minuto
  - Estas máquinas sofriam de problemas mecânicos
- George Boole (1847)
  - Análise matemática da Lógica (Mathematical analysis of logic)
  - Investigou as Leis do Pensamento
- Herman Hollerith (1889)
  - Fundou *Tabulating Machine Company* (tornou-se a IBM)
  - Em 1880 o censo gastou 5 anos para tabular os dados (montar em forma de tabela)
  - Estimativas de tabulação
    - 1890: 7,5 anos
    - 1900: 10+ anos
  - A máquina de Tabulação de Hollerith reduziu as estimativas de 7,5 anos para 2 meses
- Konrad Zuse (1938)
  - Construiu o primeiro computador mecânico operacional, o Z1
    - Máquina binária (Binary machine)
  - O governo alemão não deu continuidade ao desenvolvimento
    - W.W.W.II já tinha começado
  - Howard Aiken (1943)
    - Projetou o Harvard Mark I
    - Implementação da máquina de Babbage

#### A Era Eletrônica

- Geração 1 (1945 - 1958)
  - ENIAC - Mauchly e Echert - University of Pennsylvania
  - Desenvolvido para calcular tabelas de disparos de artilharia
  - Considerado o primeiro computador eletrônico
    - O Colossus provavelmente é o primeiro, mas foi reconhecido recentemente
  - Processava 5000 adições por segundo
  - Detalhes:
    - 18000 válvulas
    - 70000 resistores
    - 10000 capacitores
    - 6000 chaves
    - 30 x 50 feets
    - 140 kW de potência
    - Sistema Númerico Decimal
    - Programado manualmente através de chaves e plugges
- IAS (Institute for Advanced Studies)
  - John von Neumann e Goldstine
  - A partir da ideia do ENIAC desenvolveram o conceito de programa armazenado em memória
  - Esta arquitetura é conhecida como "Von Neumann architecture" e tem sidoo a base para o projeto de computadores desde então
  - Aspectos
    - Processamento em representação binária
    - Dados e instruções (programas) são armazenados em uma única memória de leitura e escrita
    - Conteúdos de memória são endereçados por posição, sem considerar o conteúdo ele próprio
    - Execução sequencial
- Este período é o início das longas disputas por patentes, direitos autorais, créditos, etc. Disputa John Von Neumann vs. Alan Turing
- Geração 2 (1958 - 1964)
  - Mudança tecnológica
  - Transistores
  - Linguagens de Alto Nível
  - Aritmética de Ponto Flutuante
- Geração 3 (1964 - 1974)
  - Surgimento do Circuito Integrado
  - Memória de Semicondutor
  - Microprogramming
  - Multiprogramming
- Geração 4 (1974 - presente)
  - Large scale integration / VLSI
  - Single board computers
- Geração 5 (? - ?)
  - VLSI / ULSI
  - Computer communications networks
  - Inteligência Artificial
  - Máquina massivamente parelelas

#### Resumo: gerações de computadores

- Válvulas - 1946 - 1957
- Transistor - 1958 - 1964
- Small Scale Integration - 1965 on
  - Up to 100 devices on a chip
- Medium Scale Integration - to 1971
  - 100 - 3000 devices on a chip
- Large Scale Integration - 1971 - 1977
  - 3000 - 100000 device on a chip
- Very Large Scale Integration - 1978
  - 100000 = 1000000000 device on a chip
- Ultra Large Scale Integration
  - Over 1000000000 devices on a chip

### Estrutura da Máquina IAS - John von Neumann

  ![iasMachineStructure-VonNeumann](images/iasMachineStructure-VonNeumann.png)

#### IAS - detalhes

- 1000 x 40 bit words
  - Binary number
  - 2 x 20 bit instructions
- Set of Registers (storage in CPU)
  - Memory Buffer Register
  - Memory Address Register
  - Instruction Register
  - Instruction Buffer Register
  - Program Counter
  - Accumulator
  - Multiplier Quotient

#### Fetch Execution Cycle

  ![fetchExecCycle](images/fetchExecCycle.png)

#### IAS - Conjunto de Instruções

  ![IASInstructionSet](images/IASInstructionSet.png)

### Mudança Tecnológica: Transistores

- Substituiram as válvulas
- Menor
- Mais barato
- Menor dissipação de calor
- Dispositivos de estado sólido
- Fabricado com o material silício (Sand)
- Desenvolvido em 1947 no Bell Labs
- William Shockley et al.

### Mudança Tecnológica: Microelectrônica

- Literalmente - "small elctronics"
- Um computador é feito de portar lógicas (gates), células de memória (memory cells) e interconexões (interconnections)
- Isto pode ser feito em semicondutor
  - ex. silicon wafer

### Moore's Law

- Gordon Moore - cofundador da Intel
- A lei de Moore está relacionada com o aumento da densidade de componentes de um chip
- Previsões de Moore:
  - Número de transistores dobrará num período de 18 meses
  - O custo de um chip permanecerá o mesmo
- Densidades maiores de integração significa caminhos elétricos menores, resultando em maior desempenho
- Tamanho menores resulta em aumento da flexibilidade
- Redução das necessidades por potência elétrica e refrigeração
- Um número menor de interconexões aumenta a confiabilidade

### Crescimento na quantidade de transistores na CPU

  ![transistorGrowthCPU](images/transistorGrowthCPU.png)

### Gargalo da Arquitetura de Von Neumann

- Aumento da velocidade do processador
- Aumento da capacidade de memória
- Velocidade da memória é inferior a velocidade do precessador

  ![vonNeumannBottleNeck](images/vonNeumannBottleNeck.png)

### Trends in DRAM use

  ![trendsInDramUser](images/trendsInDramUser.png)

### Soluções para a perda de desempenho

- Aumentar o número de bits recuperados a cada acesso
  - Make DRAM "wider" rather than "deeper"
- Mudar a interface DRAM
  - Cache
- Reduzir frequência de acesso à memória
  - Cache mais complexa e cache no chip
- Aumentar largura debanda de interconexão
  - Barramentos de alta velocidade
  - Caching
  - Buffering
  - Hierarquia de barramentos - Estruturas de barramentos mais elaborados
  - Configurações com múltiplos de processadores

### Melhorias na organização e na arquitetura do chip

- Aumentar velocidade de hardware do processador
  - Deve-se fundamentalmente a redução do tamanho das portas lógicas no chip
    - Mais portas, empacotamento mais próximo, aumento na taxa de clock
    - Redução no tempo de propagação dos sinais
- Aumentar tamanho e velocidade das caches
  - Dedicando parte do chip do processador para cache
  - Tempos de acesso à cache caem significamente
- Mudar organização e arquitetura do processador
  - Aumenta velocidade de execução efetiva
  - Paralelismo

### Problemas associados com a velocidade do relógio e a densidade lógica

- Potência
  - A densidade de potência (Watts/cm²) aumenta com a densidade da lógica e da velocidade do relógio
  - Dissipação do calor
- Atraso do circuito RC
  - Velocidade em que os elétrons fuem são limitados pela resistência e capacitância dos fios metálicos que os conectam
  - O atraso aumenta à medida que o produto RC aumenta
  - Fiação de interligação mais fina, aumenta a resistência
  - Fiação mais próxima, aumenta a capacitância
- Latência da memória
  - Velocidade da memória impacta a velocidade do processador
- Solução:
  - Dar mais ênfase nas abordagens de organização e arquiteturas para melhorar o desempenho

### Ténicas Avançadas para Ganhos de Desempenho

- Pipelining
- On board cache
- On board l1 & l2 cache
- Branch prediction
- Data flow analysis
- Speculative execution
- Superscalar architectures
- Multi-Threading

### Aumento da capacidade de cache

- Normalmente, dois ou três níveis de cache entre processador e memória principal
- Densidade de chip aumentada
  - Mais memória cache no chip
  - Acesso mais rápico à cache
- Chip Pentium dedicou cerca de 10% da área do chip à cache
- Pentium 4 dedica cerca de 50%

### Lógica de execução mais complexa

- Explorar o Paralelismo em Nível de Instruções
- Pipeline funciona como linha de montagem
  - Diferentes estágios de execução de diferentes instruções ao mesmo tempo ao longo do pipeline
- Superscalar permite múltiplos pipelines dentro de um único processador
  - Instruções que não dependem uma da outra podem ser executadas em paralelo

  ![superScalarXpipelining](images/superScalarXpipelining.png)

### Intel: melhorias na performance

  ![intelPerformanceGrowth](images/intelPerformanceGrowth.png)

### Tendência

- Múltiplos cores
  - Múltiplos processadores em único chip
    - Grande cache compartilhada
  - Se o software puder usar múltiplos processadores, dobrar o número de processadores quase dobra o desempenho
  - Assim, use dois processadores mais simples no chip ao invés de um processador mais complexo
  - Com dois processadores, caches maiores são justificados
    - Consumo de potência da lógica de memória menor que lógica do processamento

### Lei de Amdahl

- Gene Amdahl (AMDA 67)
  - A lei de Amdahl é usada para encontrar a máxima melhora esperada para um sistema em geral quando apenas uma única parte do mesmo é melhorada
- *Speedup* em potencial do programa usando múltiplos processadores
- Concluiu que
  - Código precisa ser paralelizável
  - *Speedup* é limitado, gerando retornos decrescentes para uso de mais processadores
- Dependente da tarefa:
  - Servidores ganham mantendo múltiplas conexões em múltiplos processadores
  - Bancos de dados podem ser divididos em tarefas paralelas

### Dicas importantes para um bom projeto

1. Projetar dando atenção a Lei de Moore
2. Usar abstração para simplificar o projeto
3. Tornar o caso comum mais rápico
4. Melhorar o desempenho explorando o paralelismo
5. Melhorar o desempenho explorando o pipelining
6. Melhorar o desempenho aplicando a predição
7. Empregar sistema hierárquico de memórias
8. Obter estabilidade pelo emprego de redundância

## IAS MACHINE (Programming) - Von Neumann Architecture

### IAS HARDWARE

- Principais conceitos
  1. Conceito de programa armazenado
  2. Os dados e instruções são armazenados em uma única memória de leitura e gravação
  3. A Unidade Lógica e Aritmética (ALU) é capaz de operar com dados binários
  4. O conteúdo desta memória é endereçavel por local, sem se referira ao tipo de dados contido nela
  5. Unidade de controle, que interpreta e executa as instruções na memória
  6. A execução ocorre de maneira sequencial de uam instrução para a próxima, a menos que seja explicitamente modificada
  7. Os equipamentos de entrada/saída são operados pela unidade de controle
- Dispões de 4 regristadores
  - PC = Program Counter
  - IR = Instruction Register
  - AC = Accumulator Register
  - MQ = Multiplier Quotient Register
    - Used in Multiplication and division
  
### ORGANIZAÇÃO DA MEMÓRIA E FORMATO DA INSTRUÇÃO

  ![iasMemOrganizationFormat](images/iasMemOrganizationFormat.png)

### FETCH-DECODE-EXECUTE CYCLE

- Existem seis fases fundamentais do ciclo de execução de instruções:
  1. Buscar instrução (também conhecida como pré-busca)
  2. decodificação de instrução
  3. avaliar endereço (geração de endereço)
  4. buscar operandos (ler dados da memória)
  5. executar (acesso ALU)
  6. armazenar resultado (dados da memória de write-back)

### IAS CODE CHEAT SHEET

- O IAS tem [códigos](IAS/IAS-refcard.pdf) de [comandos](IAS/ISA_IASmach.pdf) que são codificados em binário, mas para melhor interpretação, são escritos em símbolos, convertidos para hexadecimal

#### EXEMPLO 1

  ![iasCodeEx1](images/iasCodeEx1.png)

### Desvio De Fluxo

- Como expressar comandos de seleção condicional como if-then-else ou comandos de repetição for e while
- A implementação destes comando é feita através de saltos no código da aplicação. No caso do computador do IAS, a instrução JUMP+ M(X) pode ser utilizada para desvia o fluxo de execução, ou saltar, para instrução no endereço X da memória

## Como o Processador Funciona

### Arquitetura von Neumann

- Como discutido anteriormente, os projetos dos computadores modernos são baseados na Arquitetura de John von Neumaan
- A Arquitetura von Neumaan se fundamenta em três conceitos chaves:
  - Dados e Instruções são armazenados em uma única memória de leitura-escrita
  - Os conteúdos da memória são endereçados por posição, sem considerar o tipo de dados armazenado
  - A execução ocorre em modo sequencial

### Aboordagens de Hardware e Software

  ![sfHwApproaches](images/sfHwApproaches.png)

### O que é um programa?

- Uma sequência de passoa
- Em cada passo, uma operação lógica ou aritmética é realizada
- Em cada operação, um conjunto diferente de sinais de controle são necessários

### Função da Unidade de Controle

- Para cada operação é provido um código único
  - ex. ADD, MOV
- Um módulo de hardware interpreta o código e fornece os sinais de controle
- Assim, temos um computador

### Componentes Básicos de um Computador

- A Unidade de Controle e a Unidade Lógica e Aritmética constituem a Unidade Central de Processamento (CPU)
- Dados e instruções precisam entrar no sistema e os resultados, sairem
  - Via mecanismos de Entrada/Saída
- Armazenagem temporária do código e resultados se faz necessária
  - Memória principal

### Componentes do Computador (Top Level View)

  ![topLevelViewComputerComponents](images/topLevelViewComputerComponents.png)

### Ciclo de Execução de Instruções

- Ciclo de dois estágios
  - Busca (fetch)
  - Executa

    ![fetchExecCycleS](images/fetchExecCycleS.png)

### Ciclo de Busca (Fetch Cycle)

- O Contador de Programa (PC) mantém o endereço da próxima instrução na memória
- O processador busca (fetch) a instrução armazenada na posição de memória referênciada por PC
- Realiza o incremento do PC
  - Se não houver comando indicando o contrário
- A instrução é carregada no Registrador de Instrução (IR)
- O processador interpreta a instrução e realiza as ações requeridas

### Ciclo de Execução (Execute Cycle)

- Movimentação Processador - Memória
  - transferência de dados entre CPU e memória principal
- Movimentação Processador - E/S
  - transferência de dados entre CPU e módulo de E/S
- Processamento de Dados
  - Realiza alguma operação lógica ou aritmética nos dados
- Operações de Controle
  - Alteração da sequência da execução de instruções
  - ex.: desvios condicionais e não-condicionais (jump)
- Combinação das operações listadas anteriormente

### Execução de um Programa (Máquina Hipotética)

  ![hypotheticalMachine](images/hypotheticalMachine.png)

### Exemplo de Execução de um Programa (Processando a expressão: B = B + A)

  ![execExample](images/execExample.png)

### Ciclo de Instrução - Diagrama de Estados

  ![instructionCycleStateDiagram](images/instructionCycleStateDiagram.png)

### Interrupções

- Mecanismos pelos quais outros módulos (ex. E/S) podem interromper a sequência normal de processamento
- Fontes de interrupções:
  - Programa
    - ex. overflow, division by zero
  - Timer
    - Gerado pelo processamento interno do relógio (timer)
    - Usado em sistema multi-tarefa preemptivos
  - E/S
    - a partir do controlador de E/S
  - Falha de Hardware
    - ex. memory parity error

### Fluxo de Controle do Programa

  ![interruptionFlow](images/interruptionFlow.png)

### Interrupt Cycle (ciclo de interrupção)

- Acrescentado ao ciclo de instrução
- Processador verifica se há interrupção
  - Indicado por um sinal de interrupção
- Se não há interrupção, busca a próxima instrução na memória
- Se houver interrupções pendente:
  - Suspende a execução do programa corrente
  - Salva o contexto
  - Configura PC com o endereço de início da rotina de tratamento da interrupção (interrupt handler routine)
  - Processamento da interrupção
  - Restaura o contexto e contiuna com o programa interrompido

### Ciclo de Instruções (com interrupções) - Diagrama de Estado

  ![interruptionInstructionCycle](images/interruptionInstructionCycle.png)

### Cenário com Múltiplas Interrupções

- Desabilitar Interrupções
  - O processador ignorará futuras interrupções enquanto processa uma interrupção
  - Interrupções permanecem pendentes e serão conferidas a primeira interrupção ter sido processada
  - Interrupção são manipuladas na sequência que elas acontecem
- Definir Prioridades
  - Interrupções de baixa prioridade são interrompidas por interrupções de alta prioridade
  - Quando a interrupção de mais alta prioridade foi processada, o processador retorna a interrupção anterior

### Múltiplas Interrupções - Sequencial

  ![sequentialInterruption](images/sequentialInterruption.png)

### Múltiplas Interrupções - Aninhadas (nested)

  ![nestedInterruption](images/nestedInterruption.png)

## Aritmética Computacional

### Unidade Lógica e Aritmética

- Faz os cálculos lógicos e aritméticos
- Tudo, num sistema computador, está lá para servir esta unidade
- Manipula valores inteiros (ponto fixo)
- Manipula valores reais (ponto flutuante)
- A FPU pode ser uma unidade separada
  - Co-processador matemático (maths co-processor)
  - A FPU pode ser um chip separado (486DX +)

### Interface da ULA: entradas e saídas

  ![aluInterface](images/aluInterface.png)

### Representação Inteira

- Utiliza os símbolos 0 e 1 para representar todas as coisas
- Números positivos são armazenados no formato binário
  - Exemplo: 41 = 00101001
  - Sem sinal de negativo
  - Sem vírgula
- Representações de valores sinalizados:
  - Sinal-magnitude (Sign-Magnitude)
  - Complemento-a-dois (Two's compliment)
- De modo geral, se a sequência de n dígitos binários a_(n-1)a_(n-2)...a1a0 for interpretada como um número inteiro sem sinal A, seu valor será dado por:

  ![intRep](images/intRep.png)

### Representação Sinal-Magnitude (Sign-Magnitude)

  ![signMagnitude](images/signMagnitude.png)

- O bit mais a esquerda é o bit de sinal
  - 0 significa que o valor é positivo
  - 1 significa que o valor é negativo
  - +18 = 00010010
  - -18 = 10010010
- Problemas:
  - É necessário considerar o sinal e a magnitude nas operações aritméticas
  - Duas representações para o zero (+0 and -0)
- Expressão geral:

  ![signMagnitudeExpression](images/signMagnitudeExpression.png)

### Representação em Complemento-de-Dois

- Benefícios:
  - Uma única representação para o zero
  - As operações aritméticas são simples
    - (mais tarde, veremos mais detalhes)
  - A negação é aparentemente simples
    - 3 = 00000011
    - Fazendo a complementação booleana, temos:
      - 11111100
      - Adicionando 1 ao LSB, temos:
        - 11111101 = -3

| Características importantes: | |
|------------|-----------|
| Faixa de Valores representáveis | -2^(n-1) a 2^(n-1)-1 |
| Representações para o zero | 1 |
| Negação | Pegue o complemento booleando de cada bit do número positivo correspondente e então some 1 ao padrão de bits resultante, tratado como um número inteiro sem sinal |
| Expansão do número de bits | Acrescente posições de bit à esquerda  e preencha esses bits com o valor do bit de sinal original |
| Regra de overflow | Se dois número com o mesmo sinal forem somados, ocorrerá overflow apenas se o resultado tiver sinal oposto |
| Regra de subtração | Para subtrair B de A, pegue o complemento de dois de B e some-o com A |

- Expressão Analítica

  ![twoComplementExpression](images/twoComplementExpression.png)
- Caso especial 1 - Negar o zero
  - Ignorando o overflow, temos:
    - -0 = 0

    ![zeroNegation](images/zeroNegation.png)
- Caso especial 2 - Negar o -128
  - -(-128) = -128 ... Monitorar o MSB(Sign bit)
  - O valor deveria mudar durante a negação

    ![signBitNegation](images/signBitNegation.png)
- Representação geométrica de inteiros

  ![geoRepTwoComplement](images/geoRepTwoComplement.png)

### Aritmética de Inteiros

- Adição de Inteiros

  ![binaryAdd](images/binaryAdd.png)
- Subtração de Inteiros

  ![binarySubtraction](images/binarySubtraction.png)
- Aritmética de Números Inteiros (Adição e Subtração)
  - Adição:
    - Operação aritmética binária normal
    - Monitora o bite de sinal para overflow
  - Subtração:
    - Realiza o complemento-dois do subtraendo e adiciona ao minuendo
    - Isto é, a - b = a + (-b)
  - Precisamos, somente, dos circuitos de complemento e de adição

- Hardware para Adição e Subtração
  
  ![addSubHw](images/addSubHw.png)
- Aritmética de Números Inteiros:
  - Multiplicação
    - Comparada as operações de adição e subtração, a operação de multiplicação é de maior complexidade
    - Realizar produtos parciais para cada dígito
    - Tomar cuidado com a posição do valor (coluna)
    - Adicionar os produtos parciais
    - O resultado terá o dobro do tamanho (em bits) dos operandos

      ![unsignedMulBinary](images/unsignedMulBinary.png)

- Unsigned Binary:

  ![unsignedMulBinaryDiagram](images/unsignedMulBinaryDiagram.png)
- Diagrama para multiplicação não sinalizada

  ![unsignedMulDiagram](images/unsignedMulDiagram.png)
- Execução de multiplicação não sinalizada

  ![unsignedMulExecution](images/unsignedMulExecution.png)
- Multiplicação de Números sinalizados
  - O método anterior não funciona para valores sinalizados (representados em complemento-dois)
  - Solução #1
    - Converter para positivo
    - Multiplicar, como feito anteriormente
    - Se os sinais forem diferentes, negar o resultado
  - Solução #2
    - Booth's algorithm
- Booth's Algorithm
  - Multiplicador e multiplicando armazenados nos registradores Q e M respectivamente.
  - O resultado da multiplicação é guardado nos registradores A e Q
  - Existe um registrador de um bit adicional, colocado a direda do LSB de Q, denominado Q(-1)
  - A e Q(-1) serão inicializados com o valor 0 (zero)
  - Como antes, a lógica de controle examina os bits do multiplicando, um de cada vez
  - Quando cada bit for examinado, também será examinado o bit a sua direita
    - Se esses dois bits forem iguais (1-1 ou 0-0), então todos os bits dos regs. A, Q, Q(-1) serão deslocados 1 bit a direita
    - Se eles forem diferentes, o multiplicando será somado ou subtraído do registrador A, dependendo se os dois bits forem (0-1 ou 1-0), respectivamente. Após a adição ou subtração, ocorre o deslocamento aritmético de um bit a direita

    ![boothAlgorithm](images/boothAlgorithm.png)
- Exemplo do Booth's Algorithm

  ![boothAlgorithmEx](images/boothAlgorithmEx.png)

### Aritmética de Ponto Flutuante

#### Como representar números reais?

- Notação de Ponto Fixo
  - Utiliza um ponto que funciona da mesma forma que o ponto da notação decimal. Dígitos à esquerda do ponto representam a parte inteira do valor, e os dígitos à direita do ponto representam a parte fracionária.
  - 010.101 = 0 x 2² + 1 x 2¹ + 0 x 2⁰ + 1 x 2⁻¹ + 0 x 2⁻² + 1 x 2⁻³
- Notação de Ponto Flutuante
  - O problema do Ponto Fixo, é que o tamanho da parte inteira e da fracionária fica fixo com relação a seu armazenamento em memória
  - Para números com a parte apenas inteira, a região alocada para tratar a parte fracionária será inutilizada e vice-versa
- Notação Ciêntífica:
  - 976,000,000,00,000
    - 9.76 * 10¹⁴
  - 0.0000000000000976
    - 9.76 * 10⁻¹⁴
  - Mover dinamicamente o ponto decimal para uma posição conveniente e usar o exponente para assegurar o valor original
  - Um número pode ser representado na forma:
    - +- M . B^(+-E)
- Representação em Ponto-flutuante

  ![floatingPoint](images/floatingPoint.png)
  - +/- 1.mantissa x 2^(exponente)
  - O nome (PF) não expressa a representação
  - O ponto é fixo entre o bit de sinal e o corpo da mantissa
  - O valor do exponente (polarizado) indica a posição do ponto
- Ponto Flutuante: exemplos

  ![floatingPointEx](images/floatingPointEx.png)
- Sinais para o Ponto Flutuante
  - A mantissa é armazenada em complemento-dois
  - O expoente é representado na notação excess ou biased (polarizado)
    - Exemplo:
      - Excess (bias) 127 significa
      - Campo exponente de 8 bit
      - Faixa de valores puros 0-255
      - Subtraia 127 para obter o valor correto
      - Nova faixa -127 to +128
- Normalização
  - Números em FP são frequentemente normalizados 
  - i.e., o expoente é ajustado para que o bit mais significativo (leading bit) da mantissa seja 1
  - Sendo ele (leading bit) sempre 1, não há necessidade de armazená-lo
  - Considerando a notação científica, os números são normalizados para terem somente um dígito antes do ponto decimal
    - Exemplo: 3.123 x 10³
- Valores representáveis:

  ![representableValues](images/representableValues.png)
- Density of Floating-Point Numbers

  ![densityFpNumbers](images/densityFpNumbers.png)

- IEEE754 Formats

  ![ieee754](images/ieee754.png)

- Floating-Point Numbers and Arithmetic Operations

  ![fpArithmetic](images/fpArithmetic.png)
- Floating-Point Addition and Subtraction

  ![fpAddSub](images/fpAddSub.png)
- Floating-Point Multiplication

  ![fpMul](images/fpMul.png)
- Floating-Point Division

  ![fpDiv](images/fpDiv.png)
- Considerações sobre Precisão - Guard Bits
  - Considere dois números nos formato normalizado IEEE, com valores muito próximos
  - x = 1,00 ... 00 * 2¹ e y = 1,11 ... 11 * 2⁰
  - Se o número menor foir subtraído do maior, ele deve ser deslocado 1 bit para a direita para alinhar os expoentes

    ![guardBitsEx](images/guardBitsEx.png)
- Considerações sobre Precisão - Arredondamentos
  - IEEE standard approaches:
    - Round to nearest:
      - The result is rounded up to the nearest representable number
    - Round toward +infinity:
      - The result is rounded up toward plus infinity
    - Round toward -infinity:
      - The result is rounded down toward negativa infinity
    - Round toward 0:
      - The result is rounded toward zero
- Intervalo Aritmético
  - Fornece um método eficiente para monitorar e controlar erros em cálculos de ponto flutuante, produzindo dois valores para cada resultado
  - Os dois valores correspondem aos pontos limite inferior e superior de um intervalo que contém o resultado verdadeiro
  - A largura do intervalo indica a precisão do resultado
    - Se os pontos de extremidade não puderem ser representados, os pontos de extremidade do intervalo serão arredondados para baixo e para cima, respectivamente
    - Se o intervalo entre os limites superior e inferior for suficentemente estreito, obtém-se um resultado suficientemente preciso
  - Arredondamento para Menos infinito e arredondamento para o Maior são úteis na implementação do intervalo aritmético
  - Truncamento:
    - Round em direção a zero
    - Bits extras são ignorados
    - Técnica mais simples
    - Um bias consistente em direção a zero na operação
      - Bias grave porque afeta todas as operações para as quais existem bits extras diferentes de zero

## Sistema de Memória

![memoryHierarchy](images/memoryHierarchy.png)
![memorySecondaryHierarchy](images/memorySecondaryHierarchy.png)
![memoryPyramid](images/memoryPyramid.png)

### Características do Sistema de Memória

- Localização (CPU, Interna, externa)
- Capacidade (Tamanho da palavra, número de palavras)
- Unidade de Transferência (palavra, bloco)
- Método de Acesso (sequencial, direto, aleatório, associativo)
- Desempenho (tempo de acesso, tempo de ciclo, taxa de transferência)
- Tipo Físico (semicondutor, superfície magnética)
- Características Físicas (volátil, não volátil, apagável ou não)
- Organização

### Localização

- Do ponto de vista do processador a memória pode ser vista como interna ou externa
  - A memória interna é frequentemente denominada como memória principal ou primária
    - O processador requer a sua própria memória local, na forma de registradores
    - Caches é outra forma de memória interna
  - A memória externa consiste em dispositivos de armazenamneto periféricos acessíveis ao processador por meio de controladores de E/S
    - Solid State Disks, Hard Disks, e Optical Disks

### Capacidade

- Tamanho da palavra
  - A unidade natural da organização
- Quantidade de palavras
  - ou Bytes

### Unidade de Transferência

- Interna
  - Usualmente governada pela largura do barramento de dados
- Externa
  - Usualmente um bloco que é muito maior que uma palavra
- Unidade Endereçável
  - Menor localização que pode ser unicamente endereçada
  - Internamente o endereçamento é feito por palavras
  - Em unidades de discos - blocos denominados clusters

### Métodos de Acesso (1)

- Sequencial
  - O acesso deve ser feito em uma sequencia linear específica
  - O tempo de acesso depende da localização dos dados e da localização anterior
  - ex. unidade de fita (tape)
- Direto
  - Blocos individuais tem endereços únicos
  - O acesso é feito por um salto de aproximação seguido por acesso sequencial
  - O tempo de acesso depende da localização de da localização anterior
  - ex. discos

### Métodos de Acesso (2)

- Aleatório (Random)
  - Endereços individuais identificam localizações de maneira exata
  - O tempo de acesso é independente da localização ou do acesso anterior
  - ex. RAM
- Associativa
  - Dados são localizados atráves de uma comparação com o conteúdo de uma porção do armazenador
  - O tempo de acesso é independente da localização ou do acesso anterior
  - ex. cache

### Hierarquia de Memória

- Registradores
  - na CPU
- Interna ou Memória principal
  - Pode incluir um ou mais níveis de cache
  - "RAM"
- Memória Externa
  - Armazenador secundário (backing store)

### Parâmetros de Desempenho

- Tempo de Acesso (latência)
  - Tempo decorrido entre a apresentação do endereço e a obtenção do dado válido
    - Para memória de acesso aleatório (RAM), é o tempo necessário para executar uma operação de leitura ou gravação
    - Para memória de acesso não aleatório, é o tempo que leva para posicionar o mecanismo de leitura-gravação no local desejado
- Tempo do Ciclo de Memória
  - Tempo de acesso mais qualquer tempo adicional necessário antes que o segundo acesso possa ser iniciado
    - Tempo adicional pode ser necessário para que os transientes desapareçam nas linhas de sinal ou para regenerar os dados se eles forem lidos destrutivamente
    - Tempo de ciclo é:
      - Tempo de acesso + recuperação
- Taxa de Transferência
  - A taxa na qual os dados podem ser transferidos para dentro ou para fora de uma unidade de memória
    - Para memória de acesso aleatório é igual a 1/(tempo de ciclo)

### Tipos Físicos

- Semicondutor
  - RAM
- Magnético
  - Disk & Tape, flash memory
- Ótico
  - CD & DVD
- Outros
  - Magneto-optical
  - Bubble
  - Hologram

### Características Físicas

- Declínio (Decay)
- Volatilidade (Volatility)
- Apagável (Erasable)
- Consumo de Energia

### Processor x Memory - Performance Gap

![processorXmemoryGap](images/processorXmemoryGap.png)
