# Arquitetura de Redes e Computadores

## Introdução

### 1. Primórdios da Redes e Computadores

- Falta de eficiência e ambiguidades nos protocolos de comunicação, causando erros de interpretação entre as mensagens trocadas.

- Primeiros protocolos, eram qualquer coisa a longa distância que geravam mensagens.

- Os cidadãos desafiam a comunicação, pois são estes que interpretam a mensagem, contrariando talvez, a originalidade da mensagem.

- _"Polybius"_ propôs um método que impedia o erro de interpretação de uma mensagem durante seu envio
  - Tochas eram utilizadas para passsar mensagens (similar a uma sequência de bits), e uma combinação dessas permite a composição de caracteres.
- _"Robert Hooke (1684)"_ desenvolveu um sistema óptico que sinalizava caracteres e eram observados a distância por um telescópio.

- É iniciado um sistema de controle de mensagens (sinalizar se está pronto ou não).
- O sentido óptico para de ser utilizado e é iniciado o envio de sinais elétricos.
  - _"Cooke e Wheatstone (1837)"_ desenvolveram um telégrafo de uma bússola que sinalizava códigos de controle (angulação da agulha apontava para símbolos e geravam mensagens.

> Os sistemas de redes abdicaram da interferência de pessoas para previnir os erros durante o transporte.

- **Estudo de Caso**: _Acidente de 1861_
  - Dois trens se colidem dentro de um túnel, pelo fato do erro de comunicação da situação de ocupação do túnel.
  - Os protocolos de troca de mensagens entre os operadores são o interesse deste exemplo. ("trem no tunel", "trem fora do tunel", "trem no tunel?").
  - Duplicação de mensagens trouxe um erro de interpretação que levou o acidente.

- _"Código Morse"_ que utilizava inicialmente três sinais, posteriormente foram utilizados pontos e traços espaçados entre eles, enviando mensagens.

- Ao decorrer do tempo, surgiram novas tecnologias que possibilitaram a troca mais facilitada de mensagens (tele-typer, telefone, ENIAC - primeiros computadores,  etc...).

### 2. As Primeiras Redes de Computadores

- 1º Protocolo: _"Mestre-Escravo"_
  - Uma parte envolvida está no controle, e outra responde as requisições.
  - Mestre: responsável pelas tarefas de transferência de dados.

- Surge mainframes (Sistema Computacional) conectados por redes (máquinas distintas conectadas em rede).
  - Problema de estabelecer um acordo sobre os recursos compartilhados na rede.
  - Projetistas aprenderam da forma mais difícil que as sequências de eventos ocorrem e podem arruinar o projeto de protocolo.

- "Peer Protocols" (Substitui o modelo mestre-escravo) - governa a troca de elementos pares entre os mainframes
  - Envolve o envio de um pedido (request) a todos os pares, onde o pedido é recebido e processado, possivelmente há uma resposta (response).
  - Computação de pares ou computação de rede, arquitetura de aplicação distribuída que distribui as tarefas entre pares.
  - Não há um elemento central, portanto se ocorrer uma falha, só uma parte da rede entra em parada.
  - Na rede de protocolo de pares, não há uma elemento central para desenvolver acordos entre recursos compartilhados nesta rede.
  - Colisão de 2 fluxos de dados pode causar tanto dano quado a de dois trens (Acidente do Túnel de Clayton).

### 3. Protocolos e Linguagens

- _"ideia"_ - espécie de acordo sobre a troca de informações entre elementos pares e que formam um sistema distribuído.

- _"protocolo"_ - define uma formato preciso para as mensagens (acordo sobre a troca de informações).
  - _"gramática"_ - regras para a troca de dados.
  - _"sintáxe"_ - formato preciso para mensagens válidas.
  - _"vocabulário"_ - conjunto de mensagens válidas.
  - _"semântica"_ - significado das mensagens
  - _"regras procedimentais"_ - remetente e destinatário devem conhecer o protocolo e implementá-lo corretamente.

- Portanto um protocolo se parece com a definição de uma linguagem.
- Interpretações diferentes de um conjunto de regras podem gerar implementações diferentes e cheias de inconsistências, por isso se vê a necessidade de padronizar os protocolos.

### 4. Padronização de Protocolos

- Instituição ISO que contempla o organismo de padronização ANSI propôs a padronização a tabela ASCII e inteface RS-232.
  - ASCII é formalmente conhecido como ISO 646.
- Organismos de padronização: CCITT, ITU, IFIP, NIST, FTSC, FCC, IEEE, etc...
- A padronização é importante, mas não garante a resolução de todos os problemas.
- ESTELLE, utilizado para testar os protocolos submetidos às entidades.

## Estruturas de Protocolos

### 1. Introdução - Estruturas de Protocolos

- "premissa" - sem conhecer o meio de transmissão, não há como especificar as regras e procedimentos que governam as trocas de informações entre elementos pares.
  - Isto é verdadeiro? "_conhecendo o meio ou não, é necessário definir as regras que governam as interações_"
- O protocolo independe do meio utilizado, utilizando um conjunto de regras para defini-lo:
  - como as mensagens são codificadas?
  - como é iniciada e finalizada a transmissão?
  - são várias as dúvidas quanto as ações!
- "erros difíceis de evitar" - são 2 erros comuns nos projetos de protocolos:
  - conjunto incompleto de regras e procedimentos
  - regras/procedimentos que são contraditórias
- "objetivo" - garantir que as regras que governam um protocolo sejam consistentes e completas
  - precisão na especificação
  - modularização das regras
  - estruturação do protocolo

#### **Exemplo - Servidor de arquivo e servidor de impressão**

- Problemas físicos
  - cabeamento
  - codificação
  - transmissão
  - velocidade de transmissão
  - etc...

- Problemas de controle
  - impressora está disponível?
  - taxa de trasmissão aceitável?
  - tem papel?
  - está suspensa?
  - comunicação no sentido A -> B é suficiente?
  - etc...
  
![exemploImpressora](images/exemploImpressora.png)

- O protocolo é definido pelo conjunto de formatos, regras e procedimentos acordados (combinado) entre os pares.
  - _Protocolo formaliza a trasmissão no canal de comunicação._
- Protocolo tem acordos e métodos para:
  - inicialização e finalização da troca de dados
  - sincronização do transmissor e receptor
  - detecção e correção de erros de transmissão
  - formatação e codificação dos dados

- Obs: todas essas fases podem ter mais níveis de abstração

- Níveis básicos de Abstração - Formatação
  
  ![niveisAbstracao](images/exemploAbstracao.png)

### 2. Elementos do Protocolo

- A especificação de um protocolo consiste em 5 elementos distintos:
  - serviço a ser oferecido pelo mesmo
  - definição do ambitente no qual o protocolo será executado
  - vocabulário das primitivas usadas para implementar o protocolo
  - codificação (formato) de cada primitiva no vocabulário
  - regras procedimentais -> consistência na troca de primitivas

- Obs: último elemento da especificação do protocolo é o mais difícil de projetar e verificar
  - as razões são problemas de temporização, condições de corrida, deadlocks, problema de concorrência entre pares

- "Uma síntese do protocolo" - geração da especificação a partir da especificação do serviço do protocolo
![sinteseProtocolo](images/exemploSintese.png)

### 3. Exemplo de um Protocolo

- W. C. Lynch (1968) - Especificação do **Serviço**
- O objetivo consiste transferir arquivos de texto como uma sequência de caracteres através de uma linha telefônica sem erros de transmissão (erros podem ser detectados)
- "Premissa"
  - canal de transferência de mensagens é "full-duplex" (ocorre em ambos sentidos)
  - Acks e Nacks são enviados pelo canal (B -> A), para reconhecer a mensagem enviada de A -> B, e vice-versa
  - possui 2 tipos de mensagens, a própria informação e a mensagem de controle no sentido inverso

- **Ambiente**
  - consisite minimamente de 2 usuários do serviço de transferência de um arquivo em um canal de transmissão
  - usuários submetem uma requisição para transferirem um arquivo e esperam até a conclusão
  - podem ocorrer distorções nas primitivas, mas não perde, duplica, insere e nem reorganiza estas primitivas (mensagens)
  - um nível inferior é responsável por corrigir distorções e gerar mensagens de erros

- **Vocabuário**
  - Ack - mensagem positivas
  - Nack - mensagem negativa
  - Err - mensagem com erro na primitiva
  - V = {Ack, Nack, Err}
  - cada tipo de primitiva pode ser refinada em várias mensagens de níveis inferiores

- **Sintáxe (formato) da Primitiva**
  - campo de controle - identifica o tipo da primitiva
  - campo de dados - conjunto de códigos de caracteres
  - Representação "C-like" para uma primitiva:

    ```c
    enum control { Ack, Nack, Err };
    struct primitiva {
      enum control tag;
      unsigned char data;
    }
    ```

- **Regras Procedimentais (escritas)**
  - Se a recepção anterior foi livre de erro, a próxima mensagem no sentido contrário levará um ACK; caso contrário a próxima mensagem contrária levará um NACK
  - Se a recepção anterior foi um NACK ou ERR, retransmite a primitiva antiga, qualquer outro caso, enviou uma nova primitiva para transmissão
- Para Formalizar estas regras, podemos usar diagramas de estado, expressões algébricas, etc...
  - "receive" - representa o estado de recepção de uma nova mensagem no canal está sendo aguardada
  - "dented box" - representa o reconhecimento de uma mensagem que está associada - "match" com o rótulo - "label" da caixa
  - "pointed box" - indica a transmissão de uma mensagem cujo tipo é indicado pelo rótulo - "label" da caixa
  - "square/retangle box" - indica uma ação interna para obter um próximo item de dado, por exemplo, caracter a ser transferido
  
  ![elementos](images/exemploEstados.png)

  ![lynchsProtocol](images/lynchsProtocol.png)

  ![timeDiagramLynchsProtocol](images/timeDiagramLynchsProtocol.png)

- Falhas do Projeto de Protocolo:
  - Transmissão só começa se ocorrer uma transmissão de dados em um sentido contrário
  - "dúvida" - qual ods pares decide como o canal vai ser iniciado ou encerrado?!
- Maior deficiência:
  - Dados duplicados são recebidos corretamente - ocorreu devido a sequência de eventos
  - Receptor, deve decidir se um dado foi recebido ou não corretamente

### 4. Serviço e Ambiente

- Um problema grande pode ser subdividido em problemas menores (Divide and Conquer)
- Funções abstratas são definidas sobre funções subjacentes, escondendo propriedades indesejáveis em um canal de comunicação
  - canal de comunicação se torma mais idealizado

#### Exemplo

- considere um protocolo para transmissão de dados que oferece codificação de caracteres e tuplas de 7 bits e um rudimentar detector de erro baseado em paridade
- são 2 os serviços: codificação e detecção de erros
- pode-se separar os serviços em dois módulos funcionais, chamados sequencialmente, construindo um canal virtual
- de fato, cada camada oferece um serviço diferente e implementa um protocolo em separado
  - 1º Camada implementa P1 => formato de 8 bits
  - 2º Camada implementa P2 => formato de 7 bits

![virtualChannel](images/virtualChannel.png)

- P2 (Processo P2) não sabe sobre o 8º bit adicionado e controlado por P1 (Processo P1)
  - P1 sabe que é o canal mais confiável sobre o meio de comunicação abaixo
- P1 oferece um canal virtual para P2, mas, mas ao mesmo tempo, P1 é transparente para P2

- 2 conceitos fundamentais em um protocolo
  - transparente - alguma coisa que existe, mas parece não existir
  - virtal - alguma coisa que parece existir, mas não existe de fato
- Para P1, o significado dos bits não importa, apenas o número de bits; de modo smilar nem P1, nem P2, conhece sobre protocolos de níveis superiores
- Cada nível encerra os dados transmitidos em uma "capsula", formado por um "header" e/ou "trailer", antes de passá-lo ao próximo nível
- formato de níveis superiores não precisam ser preservados

![dataEnvelope](images/dataEnvelope.png)

- o projeto tem um modelo hierárquico, conhecido em programação sequencial e modular, novo em sistemas distribuídos
- camadas ajudam a indicar a estrutura lógica do protocolo separando detalhes de alto-nível dos de baixo-nível
- quando o protocolo necessitar de correções e ajustes, será mais fácil reescrevê-lo pelo fato de estar modularizado
- ISO viu a necessidade no anos 70 de padronizar e criou o ***Modelo OSI*** baseado em camadas
- cada camada define um conjunto de serviços distintos e implementa protocolos específicos para aquela camada
- formato usado por uma camada é completamente independente dos formatos usados pelas demais camadas
- Exemplo: 
  - camada de rede envia pacotes
  - camada de enlace envia "frames", e assim por diante

  ![exemploCamadaRede](images/exRede.png)

### 5. Vocabulário e Formatos

- Cabeçalhos e "Trailers"
- servem para construir métodos de formatação de alto nível sistemáticos
- Exemplo: considere os caracteres ETX e DLE como delimitadores da mensagem bem como a ocorrência de erros de transmissão:
  - contador é perdido ou,
  - se o caracter ETX (End of Text) ou DLE (Data Link Escape) forem corrompidos, as técnicas de estruturação falham
- esquemas de detecção de erro requerem transmissão de informações redundantes na mensagem
  - se outros mecanismos forem contemplados, por exemplo, controle de fluxo, então outros campos faze-se necessários, por exemplo, número de sequência
- Cabeçalho e o Trailer podem ser refinados em subconjuntos ordenados chamados campos de controle
- Exemplo:
  - cabeçalho = {tipo, destino, janela, contador, prioridade}
  - trailer = {checksum, endereço de retorno}

### 6. Regras Procedimentais

- Até o momento, tarefas de projeto de protocolo e desenvolvimento de software se assemelham
- as regras procedimentais (procedure rules) são interpretadas paralelamente por dois ou mais pares (muito provavelmente em máquinas diferentes)
  - efeito de cada nova regra adicionada ao conjunto é frequentemente muito maior do que se possa imaginar
- Para se convencer da corretude do projeto é necessário algo melhor do que a reflexão informal
  - infelizmente a ferramenta mais popular para isto é Diagrama de Ordem Temporal
  
### 7. Projeto Estrutura de Protocolos

- toca em várias áreas conhecidas, mesmo que não seja um entendimento completo
- exemplo: nível físico do modelo OSI/ISO:
  - conhece-se precisamente qual o comportamento padrão dos diferentes que são "levados"
  - quão rápido pode-se transmitir dados neles
  - qual a taxa média de "bit error" resultante
- há várias técnicas para codificação binária em sinais analógicos
- conhece-se bem técnicas de sincronização sender/receiver
- acima da Camada Física depara-se com problemas, por exemplo, controle de acesso ao meio ou problemas de projeto de rede
  - roteamento através de redes
  - dimensionamento preciso da estrutura de redes
  - interconexão de várias redes via gateways
  - desenvolvimento em um nível superior de disciplinas para controle de fluxo e controle de congestionamento
- Obs: existem técnicas que podem resolver problemas na camada física, contudo os problemas estão apenas no início
  - propôr regras completas e não ambíguas para trocar informações em um sistema distribuído é difícil de muito complexo
- simplicidade - protocolos *Light-weight*
- um protocolo bem estruturado pode ser feito a partir de um pequeno número de "pedaços" bem projetados e bem conhecidos
- para entender o protocolo basta entender os pedaços
- protocolos feitos deste modo são mais fáceis de entender, de implementar e, mais apropriados para verificar e manter
- Protocolo "Light-Weight" - simples, robusto e eficiente 
- Modularidade - hierarquia de funções
- um protocolo que executa uma função complexa pode ser separado em pedaços que interagem de um modo simples e bem definido
- cada módulo é um protocolo "light weight"
- cada módulo não faz suposições sobre o trabalho de outros, nem mesmo a presença de outros
- funções ortogonais não podem ser misturadas, elas são projetas como entidades independentes
- controle de erro e controle de fluxo são funções ortogonais
- **Protocolo Bem-Formado** - um protocolo bem formado NÃO É:
  - "over-specified", ou seja, não há regras não alcançaveis ou não utilizáveis no conjunto de regras
  - "under-specified" ou incompleto, ou seja, durante sua execução, são requiridas regras que não estão definidas
  - "bounded" - não pode ultrapassar limites definidos do sistema (ambiente), como capacidade da fila de mensagens
  - "self-stabilizing" - quando erro arbitrário muda o estado do protocolo, este deve retornar a um estado conhecido
  - "self-adapting" - pode se adaptar em certas circunstâncias
  - _Polybus - "It is chiefly unexpected occurrences which require consideration and help."_
  - Rotustez - não é difícil projetar protoclos que trabalham em circunstâncias nomais
  - é o inesperado que torna o projeto um desafio (o protocolo deve ser preparado para tratar apropriadamente todas as ações que ocorram, em qualquer sequência, sob quaisquer condições)
  - protocolo deve fazer suposições mínimas sobre o ambiente para evitar dependêcnias de características que mudam
  - Consistência - existem alguma modos "padronizados" e temidos nos quais um protocolo pode falhar:
    - "deadlocks" - situação na qual não haverá um próximo estado
    - "livelocks"- sequências na execução, repetidas indefinidamente, sem fazer qualquer progresso
    - "no k-limited" - máquina de estado não finita
    - "não reiniciável" - não é possível a partir de um dado estado voltou ao estado inicial
    - "terminação imprópria" - finalização sem satisfazer as condições apropriadas de encerramento
  
### 8. Regras de Projeto de Protocolos

- Regras de Ouro para Projeto de Protocolos

1. Certificar-se que o Problema foi bem especificado
2. Definir os serviços em cada nível de abstração
3. Delinear as funcionalidades externas antes das internas
4. Manter o projeto simples
5. Não ligar o que é independente, qu tem ortogonalidade
6. Não introduzie o que "não é concreto"; não restringir oque é irrelevante; um bom projeto é "open-ended"; um projeto resolve uma classe de problemas
7. Antes de implementar, faça um protótipo de alto-nível, e verifique se os critérios de projeto foram alcançados
8. Implementar o projeto, medir seu desempenho, e se necessáriom otimizar o projeto do protocolo
9. Garantir que a implementação final, otimizada, é equivalente ao projeto de alto-nível que foi verificado
10. Não Pular as Regras de 1 a 7 (MAIS IMPORTANTE!!)

> Infelizmente, a regra 10 é mais violada

## Controle de Erro

### 1. Introdução - Controle de Erro

- "estatísticas" - número de erros ocorridos nas transmissões de dados são muito maiores comparados por erros de "hardware" nos sistemas computacionais
  - diferença de magnitude entre uma probabilidade de erro de 10^(-15) e outro de 10^-4 não pode ser subestimada
  - para transmitir 10¹⁵ bits a uma taxa de transferência de 100 Mbps(100000000 bps) são necessários 10¹⁵/10⁸ segundos.
  - 10⁷ segundos corresponde 10⁷/60 = 166666,6667 minutos, que por sua vez corresponde 166666,6667/60 = 2.777,7778 horas, que por sua vez 2777,7778 / 24 = 115,7407
  - Para um erro, ocorre de forma análoga, no caso do erro de hardware, este ocorre a cada 10¹⁵, portanto, ocorre em média a 115,7407 pelos cálculos acima
  - dependendo do meio, podem até ocorrer ruídos entre o envio dos dados
  - os dados podem ser reordenados, distorcidos ou removidos, devido ao meio
- "controle de erro" - objetivo de aumentar a confiabilidade da transmissão, preferivelmente para um nível de confiabilidade de operação "standalone" de um sistema computacional
  - não se deve esperar que o controle de erro capture todos os erros
  - uma controle de erro deve considerar os erros do canal a ser usado
  - Obs: se a taxa de ereo de um canal é menor que a de um equipamento periférico, incluie controle de erro trará solução?
    - não necessariamente, pois ao incluir o controle de erro, pode degradar o desempenho e até diminuir a confiabilidade dos dados

### 2. Modelo de Erro

- "Discrete Memoryless Channel" - modelo formal para este tipo de canal é o canal discreto sem memória
- "Canal discreto" - canal é dito discreto porque ele reconhece apenas um número finito de níveis de sinais distintos
- "Canal sem memória" - canal é dito sem memória porque a probabilidade de um erro é suposta ser independente dos erros anteriores
- "Canal Simétrico" - p (bit error 0) = p(bit error 1)

  ![dmc](images/dmc.png)

- Canal Simétrico Binário - estabelece a probabilidade "Pr" de ter ao menos "n" bits livres de erro EFI >= "n"
- Pr( EFI >= n ) = (1 - b)^n onde EFI "Erro Free Interval"
  - onde "n" >= 0 e "b" = taxa de média de erros de bits
  - essa fórmula é linear, probabilidade decresce linearmente a medida que o tamanho do intervalo livre de erros decresce (EFI)
  - de maneira similar, probabilidade que a duração de uma rajada exceda "n" bits decresce linearmente como "n"
- Para expressar "Pr" como função exponencial, substitui-se por:
  - Pr( EFI >= n ) = e^[-b*(n-1)]
  - estudos mostram que a equação acima (exponencial) prediz intervalos livres de erros melhor que a equação anterior (linear)
  - porém a equação pode ser melhorada com a adição de um fator que determina o fator de agrupamento >> Benoit Mandelbrost

### 3. Erros de Transmissão

- "principais erros de transmissão"
  - **inserção/remoção de dados** - causado por perda temporária de sincronização entre tranmissor e receptor
  - **remoção de dados** - pode ser causado artificialmente disciplinas inadequadas de controle de fluxo
  - **duplicação de dados** - podem ser gerados intencionalmente, p.ex., transmissor fazer retransmissão
  - **distorção de dados** - podem ser geradas variações nas condições do canal, gerando distorções nos dados
  - **reordenação de dados** - ocorre quando dados percorrem diferentes rotas
- "solução" - esquemas de controle de fluxo para resolver os problemas de **remoção**, **duplicação** e **reordenação de dados**
  - não obstante, erros de inserção e distorções podem ocorrer, assim, são necessários métodos para verificar a consistência dos dados
  - **inserção/remoção de dados** e **distorçã de dados**

### 4. Redundância de Dados

- "Detecção de Erro" - somente funciona se aumentarmos a redundância de dados na mensagem
  - além da detecção de erros de transmissão, o receptor pode também ser capaz de corrigir os erros seguindo 2 maneiras:
    - "Forward Error Control" - redundância se dá de tal modo que o receptor reconstroi a mensagem a partir da mensagem distorcida
    - "Feedback Error Control" - reundância de dados se dá de tal modo que o receptor apenas detecta que a mensagem contém distorções
- "Feedback Error Control" - reundância de dados se dá de tal modo que o receptor apenas detecta que a mensagem contém erros
  - códigos de transmissão são "Error Detecting Codes" ou Códigos de Detecção de Erros
  - aplicáveis em redes de computadores e no processamento paralelo onde custo do reenvio da informação é viável
- "Foward Error Control" - ECCs capazes de detectar e corrigir erros em primitivas apresentam complexidade/computabilidade bem maior que em ("Feedback Error Control")
- "Feedback Error Control" - há duas possibilidades:
  - transmissor com alta taxa de erro, levando com que a retransmissão pode ser requerida explicitamente, através de uma confirmação negativa
    - neste caso o receptor simplesmente descarta a primitiva corrompida e espera por uma retransmissão da mensagem
  - tranmissor com taxa de erro suficientemente baixa => ausência de confirmação indica sucesso
- "Controle de Erro" - tem o objetivo de diminuir a taxa de erro de um canal de comunicação
  - contudo, nem todos os erros podem ser detectados, sempre existe uma "Taxa de Erro Residual" (RER - "Residual Error Rate")
  - e.g., suponha-se que a probabilidade de erros de transmissão em mensagem. seja "p", e que o método de controle identifique uma fração "f" deste conjunto de dados, então:
    - RER = p * (1 - f)
  - esta equação implica que, por instância, a taxa residual é da ordem 10⁻⁹ ou menos

### 5. Tipos de Códigos de Erros

- São 2 os tipos básicos de codificação:
- "Block Codes"
  - todas as "code words" têm possivelmente o mesmo tamanho
  - codificação para cada mensagem de dado pode ser definida estaticamente
- "Convolution Codes" - há uma relação entre a codificação da primitiva corrente e a codificação das primitivas anteriores
  - "code word" produzida depende da mensagem de dados e de um número prévio de mensagens codificadas
  - codificador muda seu estado com cada mensagem que é processada, mas o comprimento da "code word" é usualmente estático
- Palavras Códigos ou "Code Words" podem ser classificadas:
  - "Linear Codes" - toda combinação linear de palavras de códigos válidas produz uma outra palavra código válida (mod-2 sum)
  - "Cyclic Codes" - cada deslocamento cíclico (cyclic shift) de uma palvra código produz uma palavra código válida (CRC)
  - "Systematic Codes" - toda palavra código inclui bits da primitiva original, seguida ou precedida por um grupo de bits de "checks"
- Em todos o casos, as palavras códigos são maiores que as palavras de dados sobre as quais se baseiam
  - se o número de bits originais é "d" e o número de bits adicionais é "e", a razão "d/(d+e)" é chamada "code rate"
  - melhorar a "code rate" frequentemente significa aumentar a redundância e por consequência diminuir a "code rate"
  - e.g., reduzir taxa de erro de um canal por um fator de 5 * 10² usando, p.ex., "Forward Error Control" pode exigir um código com um "code rate" <= 0.5
  - "code rate" <= 0.5 -> "redundância é maior que a própria mensagem" (e >= d, tem se que o número de bits adicionais maior ou igual ao número de bits do próprio dado a ser transmitido)

### 6. Verificação por Paridade

- Se a probabilidade de erros de múltiplos bits por mensagem é baixa, tudo que é necessário para o controle de erro um canal simétrico binário é o código de verificação por paridade
  - para toda mensagem que adicionarmos 1 bit, teremos a soma módulo 2 naquela mensagem igual a 1 (um)
  - se um único bit, incluindo o bit de verificação sofre mudança, o cálculo da paridade no receptor indica erro, mas não pode ser corrigido
  - se "q = 1 - p", então a probabilidade de transmissão livre de erro para mensagens de "n + 1" bits, sendo 1 bit de paridade
  - probabilidade de erros de 1 bit em "n + 1" bits transmitidos é a probabilidade binomial = "(n+1) \* p \* q^n"
  - sob tais circunstâncias, e.g., canal sem memória, a taxa de erro residual da verificação por paridade de 1 bit é: 1 - q^(n+1) * p * q^n

    ![dmc](images/dmc.png)
  - e.g., para n = 15 e p = 10⁻⁴ teremos a taxa de erro residual da ordem de 10⁻⁶ por mensagem ou 10⁻⁷ por bit
  - linha contínua mostra como a taxa de erro residual por "code word" aumenta como uma função da taxa "p" de erro de bits
  - Nem todos os erros podem ser detectados e, então, sempre exite uma "Taxa de Erro Residual" (RER) = p * (1 - f)
    - "f" - fração de erros identificada; "p" - probabilidade de erro

    ![residualErrorRate](images/residualErrorRate.png)

### 7. Correção de Erro

- "Forward Error Control" usa somente um conjunto pequeno de combinações disponíveis de bits para codificar as mensagens
  - códigos são escolhidos de modo que se tenha relativamente um número grande de erros de bits para converter uma mensagem válida em outra
- "code rate" - para um código de correção de erro é em geral menor que aquele para um código de detecção de erro
- lembre-se que "d" (nro de bits originais), "e" (nrm debits adicionais), e "d/(d + e)" - chama-se "code rate"
  - logo que aumentamos "e" -> "d / (d + e)" diminui, ou seja, maior é a redundância para códigos de correção do que somente detecção
- "Forward Error Correction" - por apresentar "code rate" menor que "Feedback Error Control", quando se deve utilizar?
- Deve ser considerado somente quando as mensagens de controle do RX para o TX for um problema por razões tais como:
  - valores altos para o atraso de transmissão
  - taxa de erros de bits alta
  - ausência de canal de retorno (receptor -> transmissor)
- e.g., problema de comunicação de uma comunicação de uma estação espacial (receptor) e o centro de controle (transmissor) na terra;
  - sinal de controle para liberar o obturador da câmera ou ajustar um curso, pode exigir vários minutos até alcançar a estação
  - neste cenário, pode não haver tempo suficiente para repetir o sinal no caso de erro de transmissão (sinal pode chegar como pode se perder)
- e.g., taxa alta de erros de bits -> neste caso, até mesmo a probabilidade de uma requisição para uma retransmissão ser recebida corretamente é inaceitavelmente baixa
  - coloca em dúvida a própria requisição para retransmissão
- Até mesmo a verificação de paridade simples por "code word" pode ser estendida de um código de detecção de um único erro para código de correção de um único erro
  - e.g., sequência de 7 bits é estendida de 1 bit, o que torna o nro. de bits na sequência um nro. par (Longitudinal Redundancy Check ou LRC)
  - 1000100 onde "0" é o bit de paridade
  - na sequência inclu-se redundância para a série de "n" códigos (Vertical Redundancy Check ou VRC)

    ![bitParityExtension](images/bitParityExtension.png)
- "Hamming Distance" - nro. de bits a serem alterados na msg. de modo a obter uma outra msg. válida - "mínima diferença entre code words"
  - diferença entre 2 "code words" é definida como o nro. de bits nos quais as "code words" se diferem, ou seja, em nro de bits
- Código com "Hamming Distance" de "n", implica que qualquer combinação de até "n - 1" erros de bit pode ser detectada
  - qualquer combinação até "(n - 1)/2" de erros de bits por código pode corrigida se o receptor interpretar toda palavra de código não válida como a palavra de código válida mais próxima
  - este método é formalmente chamado de "Maximum Likelihood Decoding" ou "Nearest Neighbor Decoding"
- Aumentando a Distância de Hamming, ou seja, escolhendo "code words" mais longas, aumenta-se a confiabilidade de um código tanto mais quanto maior a "code word"
  - Obs: Redundânica de um Código determina seu poder de detecção e correção de erros de transmissão
  - redundância pode ser redefinida como o nro de bits sobre o mínimo exigido para codificar inequivocamente uma mensagem

### 8. "Linear Block Code"

- pode-ser proteger os "m" bits adicionando "c" bits de verificação e escolhendo "n" códigos de um total de 2^(m + c)
- de tal forma que cada combinação de 2 códigos válidos contemple a maior diferença em bits quanto possível
  
  ![parityProtection](images/parityProtection.png)
- Como uma boa aproximação, o nro de bits de dados que podem ser protegidos cresce exponencialmente como o nro. de bits de verificação, ou seja, "c" bits de verificação

  ![parityProtection2](images/parityProtection2.png)
- Para corrigir erros de 1 bit, precisa-se de uma distância no Código de Hamming de ao menos 3 entre "code words"
  - neste contexto, quantos bits "c" de verificação precisamos
- para toda "code word" de "m + c" bits, tem-se precisamente "m + c" código resultantes com erros de 1 bit
- para cada palavra no espectro de "2^m" possíveis códigos de dados, precisamos de "m + c + 1" palavras para protegê-la contra erros de 1 bit -> total de palavras no código é (m + c + 1) * 2^m
- (m + c + 1) * 2^m = 2^(m + c) -> "m + c + 1 = 2^c"
  - permite calcular o nro mínimo debits de verificação dado o nro de bits de dados
  - também podemos calcular o nro máximo de bits de dados para um nro de bits de verificação "c"
  
    ![parityProtection](images/parityProtection.png)
- e.g. "hamming code" - em uma mensagem de "m" bits, inclui-se "c" bits de verificação -> "m + c" bits na mensagem
- "idéia" - sobrepor os bits de paridade, de forma que eles consigam verificar-se uns aos outros, bem como os bits de dados
  - código de Hamming é obtido a partir da palavra de dados, inserindo pontos de controle, denominados bits de paridade
  - bits de verificação são colocados na palavra de código de tal maneira que a soma da posição dos bits que eles ocupam aponte para o bit errado para qualquer erro de 1 único bit (mas não para 2 bits)
  - quando uma posição é escrita como a soma de potências de 2, p.ex (1 + 2 + 4), estas potências também apontam para os bits de verificação que cobre o bit em questão, neste caso bit de dados - 7

    ![hammingCode](images/hammingCode.png)

- "Representação Matricial" - método conveniente para "LBC"
  - e.g., considere um código com 3 bits de dados (D1, D2 e D3) e 3 bits de verificação (C4, C5 e C6)
  - seja C4 = D1 + D2; C5 = D1 + D3; e C6 = D2 + D3, então com algum rearranjo podemos represetnar as equações na forma de matricial
  
    ![matricialRep](images/matricialRep.png)
  - C^t é a matriz transposta de palavras de dados, escrita como um vetor de bits e de acordo com a equação anterior.
    - Matriz de Dados + Verificação * C^t produz o vetor "zero"
  - Podemos representar a matriz na forma: H * C^t = 0
    - onde H é a Matriz de Paridade (Dados + Verificação)

      ![matricialRepAlt](images/matricialRepAlt.png)
- erros de transmissão podem ser formalizados pela adição de um vetor E, ou seja, H * (C^t + E) = s
  - onde S é chamado de Síndrome
- Neste código, toda soma módulo 2 de palavras de código válidas produz uma outra palavra de código válida
  - assim, se o vetor de erros E coincide com alguma palavra de código válida, a síndrome é zero e o erro não é detectável

### 9. Cyclic Redundancy Checks

- "Cyclick Redundancy Check" - algoritmo de código cíclico mais utilizado em redes de computadores
  - ISO especifica uma algoritmo similar denominado FCS(Frame Check) utilizado em seus protocolos IEEE802
- CRC contempla o produto de bits de verificação de uma primitiva, cuja amostragem é definida segundo um critério
  - bits escolhidos fazer parte do fator (polinômio gerador) e, portanto, é transmitido o produto, ou seja, primitiva * fator;
  - no destino faz-se a divisão que é recebido pelo fator, se o resto é zero, significa ausência de erro ou erro não detectável
  - método de divisão é específico e o fator (polinômio gerador) usado determinam o leque de erros de transmissão que podem ser detectados
- Seja uma primitiva - sequência de "n" bits que podem ser representados por um polinômio de grau "n - 1"
  - Somatório b*i* * x com i = [0 .. (n - 1)]
  - b*i* é o coeficiente do bit na posição "i"
  - x^i indica o literal do bit na posição "i"
- e.g., considera a sequência "10011"
  - escrita em polinômio: "1\*x⁴ + 0\*x³ + 0\*x² + 1\*x + 1" ou "x⁴ + x + 1"
- Sejam as operações binárias (ou-exclusivo):
  - 0 + 0 = 0 - 0 = 0
  - 0 + 1 = 0 - 1 = 1
  - 1 + 0 = 1 - 0 = 0
  - 1 + 1 = 1 - 1 = 0
  - não há "carry bit" na adição e nem "borrow bit" na subtração, ou seja, todo "i" ... x^i + x^i = 0
  - para multiplicar 2 códigos de dados, basta multiplicar os polinômios correspondentes aos códigos de dados
- Dado codificado em 4 bits (p.ex., x² + 1) é multiplicado por "x + 1"
- Código gerado é o de paridade cuja "core rate" de 3/4
- É também um código cíclico, mas não é simétrico
  
  ![cyclicCode](images/cyclicCode.png)
- e.g., Calcule o polinômio cuja primitiva é "1 0 0 1 1" e o fator (polinômio gerador) é  "1 1 0 0"
  - "1 0 0 1 1" -> x⁴ + x + 1
  - "1 1 0 0" => x³ + x²
  - (x⁴ + x + 1) * (x³ + x²) = x⁷ + x⁶ + x⁴ + **x³ + x³** + x²
    - **x³ + x³** é zero, pela regra do ou exclusivo
  - (x⁴ + x + 1) * (x³ + x²) = x⁷ + x⁶ + x⁴ + x²
- Seja P - polinômio da primitiva e G - polinômio gerador de grau "r", então o resto da divisão é polinômio R com grau "r - 1", onde:
  - R = (P * x^r)/G
  - Plavra Código: "T = P * x^r - R"
    - T é trasmitido e o receptor divide o mesmo pelo polinômio gerador, se Resto for diferente de zero, um erro é detectado
- Um erro de transmissão adiciona um polinômio E ao código e o receptor descobre o erro por:
  - (T + E)/G = T/G(= 0) + E/G = E/G
- Um erro de comunicação é detectado se E/G != 0, caso contrário o erro não é detectável, pois o erro se tornou múltiplo do gerador

## Controle de Fluxo

### 1. Introdução - Controle de Fluxo

- "Controle de Fluxo" - relacionado com o controle de diálogo na troca de mensagens entre as entidades pares
- "esquemas simples de controle de fluxo" - consiste em ajustar a velocidade da origem das primitivas à velocidade com que o receptor pode receber e processar as primitivas
  - esquemas mais elaborados podem evitar erros tais como: remoção, inserção, duplicação e reordenação
  - Nota: isto é o que acontece nas camadas mais baixas da pilha de comunicação, p.ex., camada física
- Fundamentos Filosóficos do Controle de Fluxo, 4 pilares:
  - garantia que as primitvas são enviadas em uma frequência que a entidade receptora pode receber e processá-las
  - otimização na utilização do canal
  - diminuição ou eliminação da "perda de carga" do canal
  - distribuição criteriosa do uso dos recursos de comunicação
- O caminho entre a origem e o destino pode conter esquemas de interconexão com as seguintes características:
  - capacidade limitada para "storing" and "forwarding"
  - compartilhamento entre vários pares de entidades
- Obs: esquemas prudentes de controle de fluxo evitam que pares monopolizem todo o espaço de recursos disponíveis
- "Objetivo" - tendo por base um protocolo básico, propõe-se a concepção de um modelo de controle de fluxo
  - "receive" - representa o estado no qual a recepção de uma nova mensagem do canal está sendo aguardada
  - "dented box" - representa o reconhecimento de uma mensagem que está associada - "match" com o rótulo - "label" da caixa
  - "pointed box" - indica a transmissão de uma mensgam cujo tipo é indicado pelo rótulo - "label" da caixa
  - "square/ retangle box" - indica uma ação interna para obter o próximo item de dado, p.ex., caracter a ser transferido

    ![elementos](images/exemploEstados.png)
  - protocolo "simplex" - usado para transmitir dados em apenas um sentido (canal "half-duplex")
  
    ![noFlowControl](images/noFlow.png)
- "premissa" - protocolo apresentado funciona apenas se o receptor RX for mais rápido que transmissor TX
  - se esta suposição for falsa, a entidade que envia pode sobrecarregar o esquema de entrada da entidade receptora
- 1º Postulado: "Never make assumptions about the relative speeds of concurrent entities"
- Nota: gargalo do protocolo é provavelmente o receptor, logo não se deve assumir que o receptor suporte o transmissor
- como a recepção é geralmente mais dispendiosa(processamento) do que a transmissão, então receptor deve:
  - interpretar as primitivas; decidir o que fazer com elas
  - alocar memória; até encaminhá-las ao recurso final
- transmissão não precisa de um provedor para funcionar(ativa-se quando há algo para transmitir), mas quem transmitive deve:
  - liberar memória após a transmissão (liberação de recurso)
  - não assumir que o receptor irá se adaptar à entidade que transmite, ou seja, não assumir sincronismo entre transmissor e receptor
- "Técnica mais Antiga" de controle de fluxo para tratar a sincronização, sem que seja necessário negociação a priori entre receptor estabelece o compasso entre mensagens transmitidas
- método utiliza 2 mensagens de controle:
  - uma mensagem para suspender -> "x-off"
  - uma mensagem para retomar o tráfego -> "x-on"
- "premissa" - canal é livre de erros e o vocabulário do protocolo contempla 3 três mensagens:
  - V = { mesg, suspend, resume }
- Seja um protocolo "duplex", no qual o vocabulário contempla 3 tipos de mensagens, ou seja, V = { "mesg", "suspend", "resume" }

  ![xonoffProt](images/xonoffProt.png)
- Protocolo "x-on/x-off" ... no remetente (transmissor):
  - mensagem "mesg" apenas é enviada se "state" = "go"
  - estado é alterado pelo recebimento de msg. "suspend" ou "resume"
- Protocolo "X-on/X-off" - receptor também é divido em 2 partes:
- após a chegada de uma mensagem de dados o processo contador incrementa a variável "n":
  - "n" representa o nro. de msgs que foram recebidas do transmissor e que ainda estão esperando para serem aceitas pelo receptor
  - se o valor de "n" ultrapassa um limite, uma msg. "suspend" é enviada para o transmissor (controle de fluxo)
  - se o valor "n" decresce abaixo de um limite inferior, uma msg. "resume" é enviada para o transmissor (controle de fluxo)
  - quando o receptor aceita uma mensagem, o processo "acceptor" decrementa a variável "n"
- Obs: msg, de dados é passada do processo "contador" para o processo "acceptor" através de uma fila interna
- após a chegada de uma msg. de dados o processo contador incrementa a variável "n"

  ![receiverxonoff](images/receiverxonoff.png)
  - "n" representa o nro. de msgs. que foram recebidas do transmissor e que aguardam serem aceitas pelo receptor
  - se o valor de "n" decresce abaixo de um limite inferior, uma msg. "resume" é enviada para o transmissor (controle de fluxo)
  - quando o receptor aceita uma mensagem, o processo "acceptor" decrementa a variável "n"
  - Obs: msg. de dados é passada do processo "contador" para o "acceptor" através de uma fila interna
- Problemas do Protocolo X-on/X-off:
  - total confiança no meio de transmissão (não há erros ou perdas)
  - se mensagem "suspend" é perdida/atrasada, pode ocorrer "overflow"
  - se msg "resume" é perdida, tem-se um colapso total do sistema
  - funcionamento de um protocolo não deve depender do tempo que uma mensagem de controle leva para atingir o destino
- Logo, 2 principais problamas devem ser resolvidos:
  - erros de "overrun" (transbordo) de maneira mais confiável
  - proteção contra perda de mensagens (suspend/resume)
- "solução para erros de transbordo" - para resovler este problema basta deixar o transmissor esperar explicitamente o reconhecimento das mensagens já transmitidas
  - e.g. Protocolo "Ping-Pong" ou Protocolo "Stop and Wait"
- "Ping-Pong Protocol" - problema do transbordo é resolvido, mas o sistema ainda pode sofrer bloqueio se o controle ou alguma mensagem de dados se perder no canal
- "premissa" - total confiança no canal ou meio de transmissão, pois não há erros ou perdas no canal
- "Ping-Pong Protocol" - problema do transbordo é resolvido, mas o sistema ainda pode sofrer bloqueio se o controle ou alguma mensagem de dados se perder no canal
  - "t" - tempo de propagação em um canal
  - "a" - tempo que o receptor precisa para processar e aceitar a mensagem que acabou de ser entregue pelo canal
  - "p" - tempo que o transmissor precisa para prepara a mensagem a fim de a mesma possa ser transmitida pelo canal
- com estas considerações, transmissor terá atraso de "2t + a - p" unidades detempo para toda e qualquer primitiva transmitida
  - premissa - threads em paralelo para "p" e para "2*t + a"
- "Procolo Ping-Pong" - mesmo que protocolo "Stop and Wait"

  ![pingPong](images/pingPong.png)
  - "t" - tempo de propagação em um canal
  - "a" - tempo que o receptor precisa para processar e aceitar a mensagem que acabou de ser entregue pelo canal
  - "p" - tempo que o transmissor para prepara a msg. a fim de a mesma possa ser transmitida pelo canal
- "p < a" - obiviamente que "t" aumenta no mínimo linearmente com a distância entre o transmissor e receptor
  - observe-se que o reconhecimento não significa apenas a chegada da última primitiva, mas também significa um crédito que o receptor oferece ao transmissor para que envie a próxima primitiva
- "p < a" - obviamente que "t" aumenta no mínimo linearmente com a distância entre o transmissor e receptor
- observe-se que o reconhecimento não significa apenas a chegada da última primitiva
- reconhecimento também significa um crédito que o receptor oferece ao transmissor para que envie a próxima primitiva
- Obs: Sequência de passos contempla a idéia de janela!

### 2. Protocolo de Janelas

- Na fase de estabelecimento de conexão, as entidades definem quanto de buffer, banda, etc. haverá para a comunicação
  - entidades definem espaço para um número de requisições pendentes, espaço este comumente referenciado como crédito
  - créditos podem ser alterados dinamicamente quando os espaços para primitivas pendentes mudarem
  - "premissa" - assumir que por hoar não há perdas de primitivas
- Cada primitiva recebida é reconhecida com um único reconhecimento ou "acknowledgement" no sentido contrário
  - tudo o que se tem a fazer é manter a contabilidade das mensagens em trânsito (ao longo do canal)
  - crédito inicial pode ser negociado ou pode ser predefinido para um número de mensagems "W"

    ![windowProtocol](images/windowProtocol.png)
    - para cada primitiva enviada, TX decrementa seu crédito
    - para cada primitiva recebida por RX, devolve-se 1 novo crédito ao TX através do canal de retorno
    - "W - n" representa o número de créditos não utilizados
- Seja 
  - a(t) - número de créditos recebidos pelo transmissor no instante t
  - p(t) - número de primitivas enviadas ao receptor no instante t
  - n(t) - número de mensagens pendentes de reconhecimento no instante t
- O máximo número de primitivas que o transmissor pode ter pendentes, ou seja, esperando reconhecimento, é:
  - W - n(t) + p(t) - a(t)
  - W - n(t), número de créditos disponíveis
  - p(t) - a(t), número de crédito usados
- Como o número máximo de primitivas pendentes de reconhecimento - "acknowledgement" é W:
  - W - n(t) + p(t) - a(t) <= W
  - i.e, p(t) - a(t) <= n(t)
  - Lembrete: inicialmente todas as variáveis na inequação são 0 (zero)
- Obs: O máximo número de créditos (W), que é o máximo nro. de primitivas pendentes de reconhecimento é denominado o tamanho da janela ou "window size"
- Toda ação de envio no transmissor incrementa ambos os lados da inequação, lado direito primeiro e assim preserva sua validade
- similarmente, cada ação de recepção do processo receptor decrementa ambos os lados de 1, inicialmente o lado esquerdo, e novamente preserva a corretude
  - i.e. p(t) - a(t) <= n(t)
- Obs: Há de fato concordância com as definições apresentadas para a(t) e p(t)? elas se referem a visão do transmissor? n(t) não tem o mesmo significado de p(t)?
- Como visto, o valos máximo de "W" é o tamanho da janela - "window size" do protocolo
  - durante a transferência de dados, o número de créditos varia entre 0 e "W - 1", dependendo da velocidade entre TX e RX
  - canais com tepmo de trânsito alto podem ser otimizados se habilitarmos o transmissor a enviar uma ou mais primitivas enquanto espera por uma confirmação
  - os problemas citados em comunicações (inserções, duplicações, ...) ainda persistem, exigindo um melhor controle de fluxo
- Protocolo Ping-Pong com "timeouts"

  ![timeoutPingPong](images/timeoutPingPong.png)
- Com uso de múltiplas primitivas pendentes por reconhecimento, é necessário manter rastreado o controle do tempo decorrido entre as transmissões e as recepções
- para isto é necessário dismensionar o pior caso nos tempos de transmissão, isto para não considerar como perdida uma primitiva em pleno trânsito, que ainda não chegou no receptor
- A expressão a seguir é frequentemente utilizada:
  - T(worst) = T(médio) + N * sqrt(var(T))
  - T é o tempo de ida e volta da primitiva
  - N é tipicamente 1 e raramente 2
- Comportamento de entidades fins e o canal de comunicação podem ser modelados como um processo de Markov M/M/1
- Neste caso tem-se que: var(T) = T(médio) * T (médio)
- esta é uma consideração impoertante poist o cálculo de desvio padrão, ou seja, sqrt(var(T)) envolve as medidas anteriores e isto nem sempre está disponível
- Se considerarmos N = 1, temos: T(worst) = 2T(médio)
- Um erro comum, entretando, é quando ambas as entidades fins implemetaram mecanismos de "timeout"
- ambos transmissor e receptor decidem retransmitir a última mensagem enviada se o erro de remoção ocorre

  ![dfdTimeSequenceTimeoutWindowProt](images/dfdTimeSequenceTimeoutWindowProt.png)
- "conclusão" - ambos transmissor e receptor não devem estar habilitados para iniciar retransmissões
  - suficiente colocar esta habilidade em uma das duas entidades
  - tradicionalmente é o transmissor que tem esta prerrogativa uma vez que somente ele tem certeza de quando um novo dado deve ser enviado
- Deve haver um mecanismo que identifique exatamente a qual primitiva pertence um reconhecimento de erro que acaba de chegar
  - mesmo se houver uma primitiva pendente em qualquer instante
  - isto normalmente é feito por um número de sequência (seq. number)
  - como números são finitos (necessário mecanismo para verificar os números de sequência reutilizados ou reciclados)

### 3. Número de Sequência

- Número de sequência rotula cada primitiva enviada, que por sua vez terá msg. de reconhecimento - "acknoledgement"
  - i.e, número da primitiva reconhecdida está presente, de alguma forma, na mensagem de reconhecimento
- e.g., considere um número de sequência de um bit, isto permite o uso de "timeout" no Protocolo Bit Alternate
- e.g., como exemplo de um melhor uso do "timeout" e do nro. de sequência de 1 bit, vamos considerar uma "versão estendida" do Protocolo Bit Alternate
- Bartleet, Scantleury and Wilkinson [1969] - propuseram o "Protocolo Bit Alternate" - 02 FSM com 6 estados cada
  - propuseram procedimentos para alcançar transmissão "full-duplex" confiável em enlaces "half-duplex"
  - esquema proposto foi comparado com esquemas do mesmo tipo, descrito na mesma época (década de 1960)
  - W.C. Lynch - "Reliable Full-Duplex File Transmission over Half Duplex Telephone Lines"; Communications ACM; 1968
  - Método proposto utiliza 1 bit de controle que se mostrou infalível, desde que todos os erros possam ser detectados
    - semelhante ao esquema de transmissao proposto por W.C Lynch
- "Protocolo Bit Alternate" - 2 FSM com 6 estados cada
- "arestas" - especifica a troca de mensagens, sendo que cada aresta é identificada por 2 letras, p.ex., B0, B1, A0, A1K
- primeria letra especifica a origem da mensagem sendo recebida ou transmitida, enquanto a segunda letra especifica o número de sequência
- aresta com 2 setas indica entrada para ser aceita no receptor ou uma nova mensagem será transmitida no transmissor
- entradas errôneas, ou seja, mensagens que carregam um número de sequência incorreto, causam uma retransmissão da últmia mensagem já transmitida
- e.g., pesquisar o protocolo e entender os detalhes
- Bartlett, Scantlebury and Wilkinson [ACM - 1969] - propuseram o "Protocolo Bit Alternate" - 2 FSM com 6 estados cada

  ![bitAlternate](images/bitAlternate.png)
  ![bitAlternateDFD](images/bitAlternateDFD.png)
- 2 tipos de mensagens "mesg" e "ack" com os seguintes formatos:
  - {mesg, data, sequence number} - "mesg:o:s" indica mensagem de sequência; "r" mantém o último número de sequência recebido
  - "e" indica o último número de sequência esperado no receptor; "a" armazenad o último número de sequência atualmente recebido no receptor
  - {ack, sequence number}
- Considere o que acontece se a mensagem de "ack" está tão atrasada que o transmissor sofre "timeout" e retransmite a última mensagem

  ![timeDiagramBitAlternate](images/timeDiagramBitAlternate.png)
- "duplicaçao" e "reordenação" - presentes em redes de datagrama, isto é, em redes que não há circuito lógico ou circuito virtual
  - "redes de datagrama" - são aquelas nas quais primitivas podem usar diferentes rotas para alcançar as entidades parceiras
  - "circuito lógico" - são canais que de algum modo têm mapeamento no meio físico (por ex. circuitos de linhas para telefones)
  - "circuito virtual" - são canais que têm as características de comunicação de circuito lógicos mas não existem de facto (obtidas por configuração)
- "solução" - codificar a primitiva na ordem original com um número de sequência com espectro grande o suficiente para numerar qualquer quantidade de primitivas
- normalmente o número de sequência segue acoplado ao cabeçalho da primitiva (quanto maior, maior a quantidade de mensagens sem que o número de sequência seja reutilizado)
- se considerarmos primitivas de 15kb, com um número de sequência de 16 bits, e um canal de 100Mbps, este sistema vai conseguir funcionar por aproximadamente 9,5 segundos
  - 100 * 10⁶ / 15000 bits = 6666,67 primitivas por segundo, ou seja, cada primitiva irá utilizar um número de sequência
  - considerando que tem-se 16 bits para os números de sequência, então temos 65536 números de sequência possíveis
  - logo, basta dividir 655536 / 6666,67 = 9,83 segundos serão gastos para utilizarmos todos os números de sequência possíveis
- "problema" do limite do número de sequência desaparece se limitarmos o máximo número de primitivas que estejam em trânsito através do crédito concedito ao transmissor
  - gama de possíveis números de sequência tem de ser maior que os crécdito máximos negociados, permitindo assim ao receptor distinguir primitivas duplicadas de originais
- Suponha "M" números de sequência disponíveis e "W" números de créditos iniciais de primitivas, então:
  - "M > W" - evita número de sequência fora de ordem sem que o mesmo número de sequência se repita na janela
- Que estruturas/mecanismos utilizar para este controle??
  - transmissor deve contabilizar cada primitiva pendente - "outstanding primitives" dentro da janela corrente;
  - para "acks" individuais é necessário uma estrutura de dados que mantenha o estado, o número de sequência e a própria primitiva
  - uso de vetores para controle de quais mensagens já foram transmitidas, tendo ou não sido reconhecidas
  - se uma mensagem com número de sequência "s" foi transmitida mas ainda não foi reconhecida, então "busy[s] = true"
  -já "store[s] = primitiva" mensagem com número de sequência "s" já foi transmitida
  - inicialmente, todos os elementos do vetor "busy" = "true"
- Transmissor - modularizado com 3 procedimentos:
  - Transmissão de Primitivas
  - Processamento dos "ACKS"
  - Retransmissão de Primitivas
- além do parâmentros "W" e "M", são necessários mais 4 parâmetros (com valor inicial zero):
  - "s" - nro. se sequência da próxima primitiva a ser enviada
  - "window" - número de primitivas pendentes (não reconhecidas)
  - "n" - nro. de sequência da primitiva mais antiga sem reconhecimento
  - "m" - nro. de sequência da última primitiva reconhecida
"Transmissao de Primitivas" - transmissor rastreia toda mensagem pronta para ser enviada dentro da janela
  - para cada primitiva transmitida, incrementa-se o número de primitivas pendentes de "acks" - "window++"
  - primitiva transmitida(o) é armazenada na posição "s", onde "s" corresponde ao número de sequência - "store[s] = o"
  - busy[s] = true indica que msg. com nro. de sequência "s" foi enviada mas ainda não foi reconhecida
  - incremento de "s" em módulo "M", ou seja, "s" = "(s+1) % M", para obter o próximo nro. de seq. a ser utilizado
- "Processamento de Acks"
  - atualiza-se o número (m) do último reconhecimento
  - recebe-se um reconhecimento e libera-se o buffer atualmente utilizado pela primitiva reconhecida - busy[m] = false
- "Retransmissão de Primitivas" window > 0
  - percorre-se a estrutura de envio periodicamente - "timeout period", se "busy[n] == true", então reenvia primitiva "store[n]"
  - se "busy[n] == false", então "windo--" e "n = (n + 1) % M"

  ![senderSlidingWindow](images/senderSlidingWindow.png)
- Receptor - normalmente modularizado e com 2 procedimentos
  - "Recepçao de Primitivas"
  - "Aceitação de Primitivas"
- "Recepção de Primitivas" - além dos parâmetros W e M, são necessários mais 2 parâmetros 2 vetores
  - "m" - número de sequência da última primitiva recebida
  - "p" número de sequência da primitiva sendo esperada
  - "buffer[M]" - conteúdo das mensagems recebidas
  - "recvd[M]" - representa números de sequência recebidos, mas não processados como "true", ou "false" caso contrário
- "Aceitação da Primitiva" - para serem aceitas, as primitivas devem ser aceitas primeiro para então serem reconhecidas, pois se o forem correm o risco de usar "buffers" fora do espaço definido
  - recepção consome tempo e interpretação da primitiva, decisão do que fazer, alocação de memória, e até encaminhamento
  - processo de aceitação pode ser mais lento que o de recepção, o que sugere o reconhecimento somente depois da aceitação
  - utiliza-se o vetor "recvd[M]" para armazenar o nro, de sequência de msgs. que foram recebidas, mas ainda não aceitas
  - utiliza-se o vetor "buffer[M]" para armazenar o conteúdo destas msgs, ou seja, recebidas mas ainda não aceitas
  - adicionalmente, faz-se necessário uma variável extra "p" que é o nro. de sequência da próxima msg. que será aceita

  ![receiverSlidingWindow](images/receiverSlidingWindow.png)
- quando o receptor recebe uma primitiva, cabe ao mesmo verificar se a posição equivalente está livre "recvd[m] == false", e então:
  - "recvd[m] = true"
  - "recvd[ (m - W + M) % M ] = false" ou "recvd[ (m - W) % M ] = false"
- duplicação é percebida ao verificar o estado da posição sendo recebida - "recvd[m] == true" -> indicação de duplicação
- Há 2 motivos para primitivas duplicadas:
  - primitiva foi recebida mas ainda não foi reconhecida
  - primitiva foi recebida, reconhecida mas o reconhecimento ainda não chegou ao transmissor (somente neste deve ter re-reconhecimento)
- ao analisar o valor corrente do parâmetro "p", pode-se afirmar se o caso "ii" foi ou não devidamente tratado
- Uma primitiva recebida é considerada válida, dependendo de:
  - se o número de sequência não é do tipo módulo, ou seja, nao é janela deslizante, o teste é simplesmente "valid(m) = m < p"
  - se considerarmos o efeito do módulo "M", "p" será sempre menor do que "M", então: "valid(m) = (0 < p - m <= W) || (0 < p + M - m <= W)"
- Obs: se "s" é uma primitiva recebida que se encontra no buffer, então nenhuma açao é tomada pelo módulo de recepção
- Nota: protocolo de janela deslizante garante a retransmisão de msgs. não trata nro de sequência maior que "W" e nem menor que a última msg. que foi reconhecida
  - estrutura de dados é percorrida e o processo de aceitação (dependendo da aceitação) gera um Ack ou um NAck
  - processa e aceita (ou não aceita) "buffer[p]";
  - gera um Ack (ou NAck) para o número de sequência "p" para na sequência atualizar "p", ou seja, "p = (p+1) % M"

  ![receiverSlidingWindow](images/receiverSlidingWindow.png)
- Seja "M" nros de sequência disponíveis e "W" nros de créditos de primitivas, então, qual o "Tamanho Máximo da Janela"??
- "Tamanho Máximo da Janela" - dado "M" e sabendo-se que "M > W", então qual o máximo "W" para otimizar o canal?
  - se todas as mensagens que chegam fora de ordem sao simplesemente rejeitas, então a resposta é "M - 1"
  - se um nro. de sequência não for reutilizado até que a respectiva primitiva seja reconhecida, então, o cenário é outro
    - nestes casos, isto significa "W" não pode exceder "M/2"
- Se um nro. de sequência não for reutilizado até que a respectiva primitiva seja reconhecida, então, "W" não pode exceder "M/2"
- Considere "H" o maior número (%M) que o receptor reconheceu, então podemos ter 2 cenários
  - pior caso, transmissor recebeu apenas um "ack"
  - melhor caso, transmissor recebeu todos os "acks"
- Para o pior caso, o transmissor pode decidir retransmitir todas as "W - 1" primitivas e a própria "H" - ésima primitiva:
  - primitiva mais antiga que poderia ser retransmitida poderia ser [ H - (W - 1) % M ], ou (H - W + 1) % M
- Para o melhor caso, podem ser retransmitidas até "W" msgs. que sucederam a msg. com nro. de sequência "H"
  - primeira "W - 1" podem ter sido perdidas no canal, então a msg. com nro. de seq (H + W) % M é a primeira nova msg. a chegar
  - maior nro. e seq. que suceda H tem de ser distinguível do menor nro. de seq. com potencial de ser retransmitido(que preceda H)
  - isto significa que "M > 2W - 1" ou a janela de tamanho máximo será "W" igual a M/2 (W = M/2)

### 4. Reconhecimento Negativo

- "reconhecimento", até agora foi utilizado como método de controle de fluxo, mas não como controle de erro
  - se a msg. é perdida ou danificada e não é reconhecida, a ausência de reconhecimento positivo irá eventualmente causar o "timeout" no transmissor e, por conseguinte, a retransmissão da mensagem
- "reconhecimento negativo" - pode-se amenizar o problema, não obstante não se consegue eliminá-lo completamente
  - nack - usado pelo receptor qdo o mesmo recebe uma mensagem que foi danificada no canal durante a transmissão
  - qdo o transmissor recebe um "ack" negativo, ele sabe que deve retrasmitir a msg. correspondente, sem ter que esperar pelo "timeout"
- Ex: extensão do dfd de bit alternante para acomodar o reconhecimento negativo (antigo)

  ![dfdAlternatingBit](images/dfdAlternatingBit.png)
  ![dfdAlternatingBitRec](images/dfdAlternatingBitRec.png)

- Versão extendida

  ![extendedBitAlternateSender](images/extendedBitAlternateSender.png)
  ![extendedBitAlternateReceiver](images/extendedBitAlternateReceiver.png)

- "Automated Repeat reQuest" ARQ - método que utiliza reconhecimento para controlar a retransmissão de mensagens
  - Stop-and-Wait ARQ
  - Selective Repeat ARQ
  - Go-back-N Continuous ARQ
- e.g., Protocolo Ping-Pong estendido com reconhecimento negativo, pode ser classificado como "Stop-and-Wait ARQ"
- após cada mensagem enviada, o transmissor deve esperar por um NAck ou Ack, ou mesmo "timeout"
  
  ![pingPong](images/pingPong.png)
- Uso do reconhecimento no Protocolo de Janela Deslizante pode ser classificado como "Selective Repeat ARQ"
  - implementa método de repetição seletiva "one-at-a-time" onde somente a msg. não reconhecida mais velha é retransmitida
  - entretando, qualquer msg. quer gere um "ack" negativo ou "timeout" pode ser retransmitida, independente de outra mensagem
  - generalização do método é repetição seletiva contínua

  ![senderSlidingWindow](images/senderSlidingWindow.png)
  ![receiverSlidingWindow](images/receiverSlidingWindow.png)
- "Go-back-N Continuous ARQ" - pode ser implementado no Protocolo Bit Alternate estendido
  - basta que o transissor retransmita a msg. corrompida e todas mensagens subsequentes já enviadas
  - neste caso o projeto do receptor pode ser simplificado, p.ex., "acceptor" pode ser removido do receiver do protocolo de janela deslizante e o "buffer" torna-se desnecessário
- "Go-back-N", receptor recusa todas as msgs. que chegam fora de ordem espera por aquelas na sequência correta, ou seja, não se reconhece msgs. fora de ordem.
  - reconhecimento com nro. de sequência pode ser entendido como reconhecimento de todas as msgs. até àquela incluindo "s" - também chamado de "reconhecimento cumulativo"
- "Go-back-N" ou "Selective Repeat" com variaçoes podem reduzir o nro. de msgs. de reconhecimentos individuais que são enviadas do receptor para o transmissor - "reconhecimento em bloco"
  - neste caso, reconhecimento pode especificar a faixa de nros. de sequência que foram recebidas corretamente
  - "block acknowledgment" - pode enviar periodicamente pedido do transmissor e, assim, pode ser visto como uma forma estendida do "reconheciento cumulativo"

### 5. Evitando Congestionamento

- Há 2 razões principais para incluirmos controle de fluxo nos protocolos, ou seja, sincronização e controle de congestionamento
  - até este momento, praticamente ignoramos como evitar o congestionamento e nos concentramos na sincronização fim-a-fim
- "ponto não discutido", para um dado enlace, qual o tamanho da janela bem como a correspondente faixa de nrs. de sequência que se deve escolher?
  - é relativamente fácil estabelecer limites superiores no tamanho da janela, pois aumentar a partir de um ponto pode não mais melhorar a vazão caso o canal já esteja completamente saturado
- Considere t*prog* = 0.5 seg. do transmissor para o receptor t*prog* = 0.t seg. do receptor para o transmissor, ou seja, o canal será saturado pelo transmissor se a transmissão perdurar por 1 seg
  - é relativamente fácil estabelecer limites superiores no tamanho da janela, pois aumentar a partir de um ponto pode não mais melhorar a vazão caso o canal já esteja completamente saturado

  ![senderReceiver](images/senderReceiver.png)
- "tamanho da janela > S / M" -> perda de tempo?
  - é uma perda de tempo pois no momento que a última msg. da janela é transmitida, o "ACK" para a msg. válida mais velha deve ter chegado
  - ou caso o ACK não tenha chegado, é o momento de considerar a retransmissão da mensagem
  - necessário considerar o tipo de cálcuo proposto, pois o mesmo reduz o problema de controle de fluxo para uma questão do nível do enlace, enquanto ignora a ree que contém o enlace de dados
- Tendo por base com 2 enlaces, há 2 caminhos na definição de um protocolo de controle de fluxo
- "Hop-by-Hop" ou também chamado "Node-to-Node"
- "End-to-End" - não há participação dos nós intermdiários

  ![twoHopLink](images/twoHopLink.png)
- "Hop-to-Hop Protocol" - tamanho da janela é calculado separadamente para cada enlace de moco que possa ser saturado
  - primeiro enlace é 100 vezes mais rápio que o segundo, assim, se bem sucedidos na saturação dos 2 canais, ter-se-à um grande problema "versus" desempenho no uso de recursos
  - dados chegam 100 vezes mais rápido do que podem ser re-passados para o receptor e, independente do espaço em "buffer", pode ser sobrecarregado >> perda de mensagens
  - "alternativa" - "transfer point" passa a controlar o transmissor ao recusar as msgs. de "acks", não obstante o transmissor irá saturar o canal e ser bem sucedido (retransmissões ou dados novos)

  ![twoHopLink](images/twoHopLink.png)

- "solução" - contemplar um controle de fluxo que retire o máximo do uso dos recursos em separado, ou seja:
  - "buffer space" nos nós da rede
  - "bandwidth" do enlaces que conectam os nós da rede
  - esta abordagem falha nos 2 pontos, uma vez que gasta espaço de "buffer" no nó "transfer point", potencialmente bloqueando outros tráfegos que passam pelo nó

  ![twoHopLink](images/twoHopLink.png)
- "solução" - contemplar um controle de fluxo que retire o máximo do uso do recursos em separado, ou seja, a) "buffer space" nos nós da rede ou b) "bandwidth" do enlaces que conectam os nós da rede
  - também gasta "bandwidth" pois gatilha um dilúvio de retransmissões no enlace do transmissor para o "transfer point"
  - uso ótimo dos 2 enlaces pode ser atingido se o transmissor encaminha dados na velocidade do enlace de menor capacidade

  ![twoHopLink](images/twoHopLink.png)
- "End-to-End Protocol", neste caso, a capacidade fim-a-fim da rede é igual a capacidade do menor enlace, assim, o tamanho da janela pode ser escolhido apropriadamente
- Obs: Em Redes mais complexa, não há esperança que o transmissor possa facilmente predizer onde se encontra o enlace de menor capacidade até o receptor
  - em rede maiores, a capacidade do enlace de dados não depende apenas do "hardware", mas **também do nro. de usuários**
- e.g., Se 10 usuários inicam a transf. de arquivos no mesmo enlace da rede, este enlace subtamente se transforma no enlace de menor capacidade de todos eles
- "mais seguro a fazer" - derivar o tamanho máximo da janela para toda a rede considerando o enlace de menor capacidade
- "dynamic window", controle de fluxo com janela dinâmica permite que o protocolo seja auto-adaptável
  - método simples e comum de se usar é forçar o transmissor a diminuir o tamanho da janela toda vez que ocorrer "timeout" (e.g. caso de retransmissão automática)
  - considerando que o "timeout" não mais ocorre, o transmissor pode aumentar gradualmente o tramanho da janela até o seu valor máximo (busca-se o máximo de transferência a todo instante)
- "alguma análises", há diferentes filosofias quanto a precição dos parâmetros de modo que esta técnica seja utilizada, dentre elas:
  - diminuir a janela de 1 toda vez que "timeout" ocorre e, aumentar de 1 toda vez que se recebe um "ack" positivo
  - diminuir a janela pela 1/2 do tamanho corrente a cada "timeout" e aumentar de 1 msg. quando a ocorrência de "N" "acks" positivos recebidos
  - diminuir a janela para o seu valor mínimo de 1 n ocorrência do "timeout" e, aumentar a janela de 1 quando a ocorrência de "N" "acks" positivos recebidos
- Suponha que uma primitiva leva 0,5 segundos para ir do transmissor ao receptor e o mesmo tempo de 0,5 segundos para voltar o Ack
  - transmissor satura o anal se transmitir por mais que 1s
- "factível", se a taxa do canal e S bpc, o transmissor pode transmitir S bits, para então se preocupar com o reconhecimento
  - se cada primitiva tem "N" bits, a melhor janela e "S/N", mas ressalvando a importância de garantir que "N < S".
  - janela maiores do que "S/N" representam desperdício!

## Redes de Computadores (Introdução)

### 1. Conceitos Básicos e Aplicações Típicas

- Definição: conjunto de computadores autônomos e interconectados
  - ao exigir que os computadores sejam autônamos, excluímos da nossa definiçã mestre/escravo
- classificação quanto a extensão geográfica
  - LAN - Local Area Network - (10m a 1 km)
  - CAN - Campus Area Network - (1km a 10km)
  - MAN - Metropolitan Area Network - (5km a 100km)
  - WAN - Wide Area Network - (100 a 5000km)
- classificação quanto às máquinas:
  - Homogêneas - computadores idênticos
  - Heterogêneas - computadores não idênticos
- Não se deve confundir redes de computadores com sistemas distribuídos, dado que tais sistemas constituem um caso especial das redes de computadores
- sistema distribuído: a distinção chave é a de que a existência de múltiplos computadores é transparente, ou seja, não visível para o usuário
  - em um sistema distribuído, o *software* apresenta alto grau de coesão e transparência, especialmente no nível do sistema operacional
- Não obstante, há muitas intersecções entre os dois temas, p.ex., em ambos há a necessidade de manipulação de arquivos
  - a diferença está em como isto se dá!
- Benefícios decorrentes das Redes de Computadores
  - compartilhamento de informações e recursos
  - crescimento da capacidade de processamento
  - diversidade de equipamentos e liberdade de escoha
  - aumento de confiabilidade
  - processamento de informação *in loco*
  - um meio alternativo de comunicação
- Impacto produzido pela Tecnologia de Rede:
  - Ensino/Pesquisa
  - Produção e Serviços
  - Administração
- Empresas de Telecomunicações - serviços de comunicação de dados:
  - RENPAC - Rede Nacional de Comutação de Pacotes
  - Serviços Multimídia - Áudio e Vídeo
  - CAD cooperativo, Teleconferência, Telemedicina

### 2. Estruturas de Redes de Computadores

- utilizaremos a terminologia utilizada na Rede ARPANET (Advanced Research Project Agency Network)

  ![ARPANETterms](images/ARPANETterms.png)
- separando-se os aspectos da comunicação na rede (subrede) dos aspectos da aplicação (hosts), o projeto da rede pode ser simplificado

![topologiasEx](images/topologiasEx.png)

### 3. Arquiteturas de Redes de Computadores

- para reduzir a complexidade no projeto, as redes são organizadas como uma série de camadas ou níveis, cada qual construída a sua predecessora

![arcLayers](images/arcLayers.png)

- exemplo: como prover comunicação para a última camada de uma rede estratificada em 7 camadas

![7layerArc](images/7layerArc.png)

- um aspecto importante que precisa ser ben entendido é a relação entre comunicação virtual e real bem como a diferença entre protocolos e interfaces
- sem a abstração de processos pares, é muito difícil senão impossível o particionamento do projeto integral da rede em problemas menores e gerenciáveis
- Alguns aspectos essenciais do projeto de redes de computadores estão presentes em várias das camadas, dentre eles destacamos
  - toda camada deve prover um mecanismo para estabelecer conexão
  - outro aspecto, diz respeito às regras que governam a transferência de dados, ou seja, simplex-communication, half-duples ou full-duplex
  - tratamento de erros é igualmente importante, dado que circuitos que possibilitam a comunicação física não são perfeitos
  - nem todos os canais de comunicação preservam a ordem de envio das mensagens
  - inabilidade de tratar mensagens longas, exigindo mecanismos de desmontagem, transmisão e remontagem da mensagem

### 4. Modelo OSI (Open System Interconnection)

![OSImodel](images/OSImodel.png)

#### Camada Física

- Intimamente relacionada com o meio físico empregado: fibra óptico, cabo coxial, par trançado
- Gera sinais elétricos, óticos ou eletromagnéticos para serem propagados
- Função do protocolo da Camada Física:
  - especificar qual a duração e intensidade do sinal
  - técnica de multiplexação
  - pinagem

![hwLayer](images/hwLayer.png)

#### Camada de Enlace

- Utiliza a Camada Física para transmissão dos *data frames*
- *Data Frames* são delimitados por sequências pré-estabelecidas
- Transmite (Recebe) *data frames* aguardando (enviando) o respectivo quadro de reconhecimento
- Algumas características do protocolo:
  - transmissão não confiável (mesmo com reconhecimento de recepção)
  - *data frames* podem ser duplicados ao chegar fora de ordem
  - duplicações geralmente ocorrem quando o *data frame* de reconhecimento é deformado na transmissão
  - controla o fluxo de *data frames*, evitando que um *host* envie quadros em uma taxa superior a que o receptor é capaz de processar

#### Camada de Rede

- Controla a operação da subrede
- Algumas de suas Funções:
  - roteamento de pacotes de *host* origem ao *host* destino
  - o roteamento pode apresentar características dinâmicas ou estáticas
  - fragmentação e remontagem de pacotes para atender limites impostos
- Nota: em subredes de difusão esta camada é extremamente simples, uma vez que a principal função (roteamento) é inexistente

![roteamentoEx](images/roteamentoEx.png)

#### Camada de Transporte

- Algumas de suas Funções:
  - receber dados da camada de sessão
  - particionar estes dados em unidades menores
  - garantir envio de dados sem duplicação e na ordem correta
- Possui 2 tipos de serviços:
  - serviço rápico com mensagens de tamanho limitado e sem garantia de entrega, ordem ou ausência de duplicação
  - serviço mais lento, porém altamente confiável e sem limites de tamanho de mensagens
- É a primeira camada a promover comunicação *host-host*, assim controla o fluxo de dados entre 2 processos comunicantes

#### Camada de Sessão

- Permite que 2 *Application Process - APs* estabeleçam sessões entre si a fim de organizar e sincronizar a troca de informação
- Conexão de Sessão => definição das regras de diálogo entre 2 APs
  - Two Way Simultaneous (TWS)
  - Two Way Alternate (TWA)
  - One Way (OW)

#### Camada de Apresentação

- Serviços oferecidos:
  - representação canônica de dados
  - compressão de dados
  - criptografia
- Necessidade da Representação Canônica de Dados:
  - quando arquiteturas diferentes devem se comunicar
- Compressão é útil para o envio de grandes massas de dados
- Criptografia é utilizada quando os dados são confidenciais

#### Camada de Aplicação

- Dispõe de serviços comumente utilizados por usuários de redes
  - correio eletrônico
  - *login* remoto
  - serviços de diretório
  - submissão de *jobs* remotos
- Também se constitui em postos de acesso à rede por APs
- *Application Program Interface - APIs* (em vias de padronização)
  - são bibliotecas de funções para envio/recepção de mensagens

### 4. Serviços e Protocolos do Modelo OSI

- Modelo de Referência permite a especificação de várias Classes de Serviço