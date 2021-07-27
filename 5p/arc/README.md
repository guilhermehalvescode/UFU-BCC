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