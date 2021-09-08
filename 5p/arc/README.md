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

- "topologia típica" - de difusão da subrede de comunicação e na qual a informação transmitida é recebida por todos os dispositivos na rede
- "domínio de colisão" - segmento lógico onde os pacotes transmitidos por elementos pertencentes a ele podem colidir uns com os outros
- "colisão" - duas ou mais estações pertencentes ao mesmo segmento compartilhados de rede transmitem simultaneamente
- "domínio broadcast" - conjunto de dispositivos que recebem qualquer pacote (unidade de informação da camada de rede) broadcast originário de qualquer dispositivo dentro do segmento de rede
  - domínio broadcast pode ser segmentado através de VLANs, como será comentado mais a frente
  - domínio broadcast pode ser segmentado por um roteador, no qual cada porta do roteador representa um domínio broadcast distinto. como será comentado mais a frente

### 3. Arquiteturas de Redes de Computadores

- para reduzir a complexidade no projeto, as redes são organizadas como uma série de camadas ou níveis, cada qual construída a sua predecessora

![arcLayers](images/arcLayers.png)

- exemplo: como prover comunicação para a última camada de uma rede estratificada em 7 camadas

![7layerArc](images/7layerArc.png)

- um aspecto importante que precisa ser bem entendido é a relação entre comunicação virtual e real bem como a diferença entre protocolos e interfaces
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

### 5. Serviços e Protocolos do Modelo OSI

- "Modelo de Referência" permite a especificação de várias "Classes de Serviço", enquanto que uma Classe de Serviço permite a especificação de várias "Classes de Protocolos".
  - no nível mais baixo de abstração, tem-se a implementação do protocolo, mais especificamente, tantas implementações quanto possíveis face as tecnologias utilizadas

  ![protClasses](images/protClasses.png)
- RM-OSI - propõe a estratificação da pilha de comunicação em camadas horizontais cuja finalidade consiste
  - permite uma discussão da interação entre elementos pares
  - desenvolvimento incremental dos serviços de cada camada
  - sistema aberto pode ser visto como sucessão de sub-sistemas
- "entidades" - são elementos ativos em cada camada
  - entidades na Ln (Camada N) implementam serviços usados na L(n+1) (Camada N + 1), ou seja, Ln provê serviços para a L(n + 1)
  - entidades na Camada N + 1 (L(n + 1)) usam/invocam serviços da Camada N (Ln), ou seja, L(n+1) usa/invoca serviços de Ln (Camada N)
- "entidade" - elemento ativo uma cada camada, p.ex, processo
- SAP - Service Access Point; CEP - Connection End Point

  ![SAPex](images/SAPex.png)
- "serviço orientado a conexão" - pressupõe o estabelecimento de um canal lógico entre as entidades pares, ou seja, canal lógico pelo fato de não dispor de uma conexão física exclusiva entre os elementos pares
  - canais lógicos podem compartilhar uma mesma conexão física, bem com contemplar ou não os dispositivos ao longo do caminho entre o remetente e destinatário
- "tipos de serviços orientados a conexão"
  - mensagens - têm fronteira limitadas
  - cadeias de bytes - não têm fronteiras limitadas
  - serviços típicos - transferência de arquivos, login remoto, etc.
- "serviço não orientado a conexão" - também denominados de serviços de datagrama, constituem-se em serviços análogos aos "serviços postais" dos correrios
  - dentre os serviços típicos, destacam-se o acesso a banco de dados, sincronização de relógios, etc.
- Com o objetivo de permitir que objetos como Entidades, SAPs e CEPs sejam referenciados, faz-se necessário um esquema de identificação
  - identificadores de Entidades (entidades) = Titles
  - identificadores de SAPs (Service Access Points) = Endereços
  - identificadores de Conexões (Connection End Points) = CEP-identifier
- "algumas associações possíveis"
  - 1 Entidade N possui 1 Título N
  - 1 SAP N possui 1 Endereço N
  - 1 CEP N possui 1 identificador CEP n
- "troca de dados" entre entidades ocorre de duas formas:
  - "entidades pares" - p.ex., entre Entidades N+1 remotas, a troca de informações é governada pelo Protocolo N+1
  - "entidades adjacentes" - p.ex., entre a Entidade N+1 e Entidade N no mesmo "host", a troca de informações se dá pelo SAP n
  - "observação" - entidades trocam não somente informações de dados, mas também informações de controle
- Neste contexto, são 4 os tipos de unidades de dados:
  - "informação de controle de protocolo" - trocada entre entidades pares com a finalidade de coordenar as suas operações conjuntas
  - "dado do usuário" - dado transferido entre uma E(n+1) e uma En, ou seja, dados transferidos entre entidades adjacentes
  - "informação de controle de interface" - informação trocada entre E(n+1) e En para coordenar as suas interações através do SAPn
  - "dado de interface" - dado transferido da Entidade N + 1 (E(n+1)) á Entidade N (En) afim de que seja enviado à Entidade N+1 par
- 2 tipos de Unidade contendo informações de Dado e Controle:
  - "unidade de dado do Protocolo N" (PDUn) - informação trocada entre entidades e constituída de controle e dado do usuário
  - "unidade de dado de interface N+1" - informação trocada entre uma entidade N+1(E(n+1)) e uma entidade N (En) através de um SAPn, sendo constituída de controle e dado do usuário

  ![uniDadoeControle1](images/uniDadoeControle1.png)
- RM-OSI - não restringe o tamanho da Unidade de Dado
- Formas de mapeamento possíveis:
  - "segmentação" - função realizada pela entidade N (En) através da qual uma SDUn é mapeada em várias PDUs N
  - "remontagem" - função realizada pela entidade N (En) par através da qual múltiplas PDUs N são mapeadas em uma SDUn

  ![uniDadoeControle2](images/uniDadoeControle2.png)
- Formas de mapeamento possíveis:
  - "bloqueio" - função realizada por uma entidade N (En) que mapeia múltiplas SDUs N (SDUn) em uma PDUn
  - "desbloqueio" - função realizada por uma entidade N par que mapeia uma PDU N (PDUn) em múltiplas SDUs N (SDUn) correspondentes

  ![uniDadoeControle3](images/uniDadoeControle3.png)
- Formas de mapeamento possíveis:
  - "concatenação" - permite uma entidade N mapear múltiplas PDUs N (PDUn) em uma SDU n-1 (SDU(n-1))
  - "separação" - permite uma entidade N par mapear uma SDU n-1 (SDU n-1) em múltiplas PDUs N (PDUn) correspondentes

  ![uniDadoeControle4](images/uniDadoeControle4.png)
- Modelo OSI estabelece 4 tipos de primitivas:
  - "requisição" - uma entidade requer a execução de um serviço
  - "indicação" - uma entidade é informada da ocorrência de um evento
  - "resposta" - uma entidade deseja responder a um evento
  - "confirmação" - uma entidade recebe o resultado de sua requisição

  ![OSIchecks](images/OSIchecks.png)
- "conceito clássico" - define a forma como entidades equivalentes interagem entre si para a realização de um objetivo comum para a prestação de serviços a entidades na camada superior
- "protocolo da camada N" - conjunto de regras e formatos, representados por aspectos semânticos, sintáticos e temporais, que regem a comunicação entre entidades pares
- "especificação de protocolo" - compreende a descrição
  - dos serviços evocados para transferência de cada tipo de PDU
  - formal da estrutura da cada PDU bem como os tipos de PDUs
  - formal da operação da entidade de protocolo
  - dos procedimentos do protocolo de cada tipo de PDU
- "primitivas" - são formados por 2 pares:
  - uma parte correspondente aos dados do usuário
  - outra parte contendo informações de controle relativa ao protocolo
- "estrutura das PDUs" - especificação do protocolo
  - Cadeias de Bits - protocolos de camdas inferiores
  - ASN.1 (Abstract Syntax Notation Number One) + Regras de Codificação - baseada na tipificação dos dados (sintaxe abstrata), normalmente presente em níveis mais alto - protocolos orientados a aplicação
- "modelagem de um protocolo" - entidade de protocolo é modelada como uma máquina de estados finitos (autômato)
  - transição de um estado para outro ocorre quando um evento válido ocorre na interface do autômato, gerando com resultado alguma ação
- "exemplos de transições de estado"
  1. recepção de uma primitiva de seriço na interface com a camada superior, p.ex., dados para serem transmitidos
  2. recepção de uma primitiva na interface com a camada inferior, p.ex., retorno de chamadas de procedimento anteriormente realizadas
  3. ocorrência de eventos locais da própria camada, também disparam ações e mudanças de estado na máquina de estado

  ![OSIautomato](images/OSIautomato.png)
  - associado à ocorrência de um evento válido, o autômato muda de estado e gera alguma ação interna específica
  - método de especificação utiliza uma tabela evento-estado onde cada entrada na tablea especifica o evento saída e o novo estado
  - novo estado para o qual o autômato deverá transitar devido a uma combinação de entrada e estado atual

### 6. Padronização em Redes de Computadores

- "padrões" - (standards) conjunto de normas e procedimentos, cujo cumprimento pode ser de obrigatório ou recomendável
- "objetivo dos padrões"
  - homogeneizar produtos e serviços
  - minimizar investimentos em estoques
  - compatibilizar equipamentos de diferentes procedências
- Padrão de Facto - adotado sem nenhuma ação de entidade reguladora p.ex, IBM, Padrão de Facto da Internet
- Padrões de Jure - produzidos por entidades reguladoras, nacionais ou internacionais, p.ex., ISO 9000
- Entidades de Padronização - Eng. Elétrica
- Brasil - Associação Brasileira de Normas Técnicas (ABNT)
- EUA - America National Standard Institute (ANSI)
- EUA - Institute of Electrical and Eletronic Engineers (IEEE)
- Alemanha - Deutsch Industrie-Norm(DIN)
- Inglaterra - British Standard Institution (BSI)
- "entidades de padronização" - redes de computadores
- ITU-TS "International Telecommunication Union - Telecommunication Standadization" antiga CCITT "Comité Consultatif International de Télégraphique et Téléphonique"
- ISO "International Standard Organization"
- Padrões ITU-TS:
  - normalmente se referem a transmissão de dados a longas distâncias
  - situam-se mais próximo do hardware
- Padrões ISO:
  - são mais voltados aos serviços que uma rede provê
  - protocolos de conversação inter-hosts
  - cobrem praticamente todo o espectro de tecnologias de rede
- Modelo ISO/OSI ou OSI (Open Systems Interconnection):
  - estipula que uma rede de computadores dever ser estipulada em 7 camadas, propondo um ou mais padrões para controlar cada camada
  - estes padrões estão ainda em vias de se tornarem padrões de facto
- Padrões de Facto são também chamados Padrões Internet:
  - enfatizam o transporte confiável de um host para outro
  - apenas três serviços são padronizados no nível de usuário: transferência de arquivo, correio eletrônico e login remoto
- Serviço introduzidos (Comunidade ou Fabricante):
  - Yellow Pages - diretório
  - RPC "Remote Procedure Call"
  - NFS "Network File System"
- "tendência" - novos serviços como aqueles oferecidos por redes ISDN "Integrated System Digital Network" serão aderentes ao Modelo OSI

### 7. Redes Públicas, ARPANET e BITNET

- "rede pública" - denominação dada os sistemas das operadoras de redes utilizados no oferecimento de serviços de comunicação de dados para os hosts e terminais de seus clientes
  - embora sejam diferentes em diferentes países, todas utilizam-se do Modelo OSI (ISO 7498) ou de Protocolos OSI ou ITU (antiga CCITT)
  - as 3 camadas inferiores são conhecidas coletivamente como X.25 (CCITT Recommendation Number), entretando a ISO o adotou como um padrão
  - para as demais camadas, padrões separados para a especificação do serviço e do protocolo são adotados pela ISO
- ISO 8802 são derivados dos Padrões IEEE 802

  ![ISOlayers](images/ISOlayers.png)
- ARPANET - resultado do Projeto DARPA (Defense Advanced Research Projects Agency) do Departamento de Defesa do USA
  - iniciado na década de 60 com o propóstio de pesquisar redes de computadores através de investimentos concedidos aos departamentos de ciência da computação e até mesmo coorporações privadas
  - após a consolidação da tecnologia ARPANET no oferecimento de serviços por vários anos, uma rede militar - MILNET (Military Network) foi contruída com a mesma tecnologia
  - a ARPANET tinha suas próprias LANs, eventualmente conectadas a IMPs conectando-a a ARPA Internet com milhares de hosts e centenas de milhares de usários durante a década de 1970
  - os IMPs originais da ARPANET eram minicomputadores Honeywell DDP-516 com memória de 12 K palavras de 16-bits
  - atualmente, são conhecidos por PSN Packet Switch Nodes ou simplesmente SN (Switch Nodes) mas com a mesma funcionalidade
- ARPANET não segue o Modelo OSI, na verdade, pois antecedeu a proposta em mais de uma década sendo as vezes difícil compará-los
  - p.ex., Protocolo IMP-IMP é uma mistura de Camada 2 e 3 do OSI
- Protocolo de rede é o IP (Internet Protocol): projetado para permitir a interconexão de uma grande variedade de redes, porr isso é um protocolo não orientado a conexão
- Protocolo de Transporte da ARPANET pode ser:
  - TCP (Transmission Control Protocol): orientado a conexão
  - UDP (User Datragram Protocol): não orientado a conexão
- Não encontramos nem camada de sessão, nem de apresentação e até a década de 1980 pouco os nenhum uso tiveram
- Quanto aos Serviços da Camada de Aplicação, destacam-se
  - FTP(File Transfer Protocol)
  - SMTP(Simple Mail Transfer Protocol)
  - TELNET e outros

  ![ARPANET](images/ARPANET.png)

### 8. Aspectos Conceituais do RM-OSI

- um pouco de história (RM-OSI da ISO)
- "gatilho" - necessidade de "networking"

  ![nwUSA](images/nwUSA.png)
- "característica marcante" - heterogeneidade
- Rede DARPA (Defense Advanced Reasearch Projects Agency) - 1976
- Projeto DIX da Digital, Intel e Xerox - 1974/1976
- "análise" - em ambos houve o aparecimento de Padrões Proprietários
  - surgem os primeiros problemas de interoperabilidade, face a grande quantidade de redes com padrões proprietários
  - surge a necessidade da padronização para que a interoperabilidade deixe de ser um problema, face a necessidade maior de comunicação entre as diferentes plataformas (pilhas de comunicação)
- "Systemas Abertos" - "Open Systems"
  - Iniciativa da ISO (International Standardization Organization)
  - Criação do Comitê OSI (Open Systems Interconnection)
- OSI - escopo de atuação único e exclusivamente sobre os aspectos de comhincação de dados

  ![openSys](images/openSys.png)
- Modelo de Referência OSI
  - padrão concernente apenas aos aspectos da arquitetura de redes
  - separa as funcionalidades e capacidades de rede em camadas
  - define termos e objetos que são palavras reservadas no mundo das redes de computadores
- "denominação" - apenas Modelo Referência OSI (7 camadas)
  - camadas definem desde aspectos físicos, enlace, rede, transporte, sessão, apresentação e aspectos abstratos da aplicação
  - camadas próximas ao meio físico referenciadas como de baixo nível e, camadas próxima do usuário são referenciadas com de alto nível
- Modelo de Referência OSI - CAMADAS SUPERIORES

  ![OSIupperLayers](images/OSIupperLayers.png)
- Modelo de Referência OSI - CAMADAS INFERIORES

  ![OSIbottomLayers](images/OSIbottomLayers.png)
- "aspectos conceituais" - Modelo de Referência OSI
  - comunicação entre camadas é feita através da requisição de serviço ou da resposta a serviços
  - serviços são requisitados (respondidos) através de pontos específicos localizados nas interfaces entre as camadas
  - estes pontos onde serviços são requisitados (respondidos) são chamados SAPs(Service Access Points)

  ![SAP](images/SAP.png)
  - e.g., SAPs são identificados pela interface da camada, ou seja, p.ex., SAP da Camada de Rede é o N-SAP

  ![OSIlayersTransport](images/OSIlayersTransport.png)
  - interações entre entidades de camadas "pares" e presentes em nós distintos se dá através de primitivas
  - para que duas camadas "pares" se comuniquem eles devem especificar o mesmo conj. de primitivas (protocolo)
  - serviços são requisitados (respondidos) na "vertical", enquanto que as primitivas são trocadas entre elementos pares, ou seja, entre elementos da mesma camada - "horizontal"

  ![peerHorizontal](images/peerHorizontal.png)
- "protocolos" - abstraem a comunicação da camada logo abaixo da camada que requisita os serviços
  - quando uma entidade em uma camada solicita serviços à camada abaixo, supõe-se que o "provider" enviará os dados disponibilizados
  - dados enviados são denominados genericamente de primitivas
  - este processo se repete até a camada de mais baixo nível
  - serviços de uma camada "K" implementam o respectivo protocolo e repassam através do "K-1"-SAP à camada inferior

  ![7layer](images/7layer.png)
- "primitiva" - unidade de informação encaminhada entre uma camada e outra pode ser do tipo: "request", "confirm" em TX
- "request" - primitiva enviada pela camada "N+1" para a camada "N" ao requisitar um serviço - invocação de serviço
- "indication" - primitiva entregue a camada "N+1" RX pela camada "N" RX para sinalizar a ativação de ums serviço requisitado ou de alguma ação iniciada pelo serviço da camada "N" TX
- "response" - primitiva da camada "N+1" RX em resposta a uma primitiva "indication" RX para completar ou reconhecer uma ação previamente invocada pela primitiva "indication" RX
- "confirm" - primitiva retornada para a camada "N+1" em TX da camada "N" em TX para reconhecer ou completar uma ação previamente invocada pela primitiva "request" em TX

  ![layersResReq](images/layersResReq.png)
- Quanto aos serviço, 2 grupos se destacam:
  - "serviços confirmados" - serviço com as quatro fases, ou seja, prmitivas "request", "indication", "response" e "confirm"
  - "serviços não confirmados" - serviços que especificam 2 fases, ou seja, primitivas "request" e "indication"
- No OSI as camadas "pares" se comunicam através de um objeto denominado entidade da camada
  - neste contexto, entidade é uma palavra reservada - termo que sempre vai significar uma capacidade de comunicação
  - no modelo de protocolos em camada, a entidade de protocolo é definida como a entidade que processa um protocolo específico
  - em cada camada, uma ou mais entidades implementam suas funcionalidades/serviços que a camada oferece
  - cada entidade interage diretamente e somente com a camada logo abaixo e provê facilidades para serem usadas pela camada logo acima da camada em que se situa a entidade
- Quando uma camada "N+1" requisita um serviço à camada "N", o conjunto de bytes enviados pode ser dividio em 2 partes:
  - cabeçalho - parte de protocolo da camada(n+1)
  - conteúdo - parte de dados da camada(n+1)
- PDU - "Protocol Data Unit" = "cabeçalho" + "conteúdo"
- PDU da camada "N + 1" se encaixa na perte de dados da PDU da camada "N" e, assim, recebe um novo nome na camamda "N", comumente denominado de SDU - "Service Data Unit"
  - portanto, na fronteira superior, a camda recebe uma SDU, adiciona o protocolo da camada na qual se situa e se transiforam em PDU
- "transormação da primitiva" - na fronteira superior, a camada recebe uma SDU, adiciona o protocolo da camada na qual se situa e a transforma em PDU da camada "N"

  ![primitiveTransformation](images/primitiveTransformation.png)
- N-PDU = N-SDU + N-Protocol
- 1 SDU pode gerar várias PDUs
  - camadas inferiores, devido às limitações dos meios de transmissão, são ricas em protocolo, mas pobres em serviço
  - maior o número de serviços em uma mesma camada permite que poucos protocolos ofereçam toda a gama de serviços

  ![PCI](images/PCI.png)
- Relação entre Serviço e Complexidade de Protocolos ao longo do Modelo de Referência OSI
- Quando uma camada requisita serviços da camada inferior, ela é dita usuário (user) dessa camada
  - camada inferior abstrai a existência das outrsa camadas mais abaixo, oferencendo a somatória das funcionalidades de todas as camadas abaixo na forma de serviços
  - "service provider" - abstração é chamada de provedor de serviços
- O provimento de serviço abstrai inclusive o aspecto da comunicação com a camada parceira
  - logo, o provedor de serviços oferece os serviços e a conexão da Camada "N + 1" a um usuário da Camada "N"

  ![OSIcomplexity](images/OSIcomplexity.png)
  - provedor ser serviços oferece os serviços e a conexão da Camada "N-1" a um usuário da Camada "N"

  ![servicesN-1ToN](images/servicesN-1ToN.png)

## Physical Layer

- "função principal da camada física" -
  - geração de sináis elétricos, ópticos ou eletromagnéticos
  - propagação destes sinais no meio físico
- Cabe à Camada Física especificar:
  - natureza do meio físico
  - forma como os hosts e IMPs são conectados ao meio físico
  - forma como 0s e 1s são codificados em sinais do meios físico
  - parâmetros e respectivas tolerância de sinais
  - procedimento de multiplexação de sinais no meio, se houver
- Alguns Padrões: IEEE 802, CCITT X.21, etc.
- Transmissão de Bits (... dos quadros da camada de enlace):
  - full-fuplex - os dois hosts comunicantes transmitem simultaneamente
  - half-duplex - apenas um host por vez transmite
- Transmissão de bits pelo meio físico pode ser:
  - serial- um bit é transmitido a cada intervalo de tempo
  - paralela - bits (em conjunto) são transmitidos serialmente por N dutos independentes -> N bits por unidade de tempo
- Transmissão Síncrona e Assíncrona:
  - síncrona - bit é transmitido a cada intervalo de tempo bem definido
  - assíncron - bit é transmitido num intervalo de tempo arbitrário
- Na prática que tipo de transmissão é utilizada?
  - transmissão assíncrona com bloco de bits "Start/ Stop"

  ![blockTransmission](images/blockTransmission.png)

### 1. Aspectos Teóricos de Comunicação de Dados

- Análise por Série de Fourier - informações podem ser transmitidas através de meios físicos variando-se alguma propriedade física, como voltage (tensão elétrica) ou corrente elétrica
  - reprentando o valor deste sinal como uma função do tempo, g(t), pode-se modelar o comportamento do sinal e analisá-lo matematicamente
- "Jean Fourier" - provou que uma função periódica "g(t)", com período T pode ser contruída somando-se funções "seno" e "cosseno" com diferentes amplitudes...

  ![gtFourier](images/gtFourier.png)
  - onde f = 1/T é a frequência fundamental e an e bn são as amplitudes dos termos (harmônicas) das funções seno e cosseno
- Através da Série de Fourier, uma função pode ser reconstruída
  - ou seja, se o "T" é conhecido e as amplitudes são dadas, a função original pode ser achada realizando-se as somas da equação anterior
- "an" pode ser obitido para uma função "g(t)" multiplicando-se ambos os lados da eq. por "sin(2pinft)" e integrando de 0 a T

  ![intFourier](images/intFourier.png)
  - para o cálculo dos coeficientes, vale as relações:

    ![relacoesIntFourier](images/relacoesIntFourier.png)
- e.g. ... dado uma taxa de "b" bits/s, o tempo requerido para enviar 8 bits é: b bits - 1 s, então 8 bits - t??
  - t \* b = 8\*1 -> t = (8 \* 1)/b -> t = 8/b segundos e como se trata de um sinal periódico, a idéia é a de que o mesmo se repita após "t" seg.
  - período da 1ª Harmônica é exatamente este tempo, ou seja, 8/b seg., então a frequência da 1ª Hármonica é o inverso - 1 / (8/b) = b/8 Hz
- seja a tranmissão do caracter "01100010", então pela Análise da Série de Fourier os coeficientes "an", "bn" e "c" são:

  ![exCalCoefSerieFourier](images/exCalCoefSerieFourier.png)

- Fig 2.1 mostra a saída de voltagem do TX (Transmissor)

  ![voltSaidaTX](images/voltSaidaTX.png)
  ![voltSaidaTX2](images/voltSaidaTX2.png)

- nenhum recurso de transmissão é capaz de transmitir sinais sem perder parte da energia no processo -> "**atenuações**"
- no entanto, tais atenuações se dão de forma diferente para cada uma das componentes -> "**distorções**"
- "**largura de banda**" - faixa de frequências transmitidas sem que as componentes sejam fortemente atenuadas
  - trata-se de uma propriedade física do meio de transmissão que, geralmente depende da construção, expessura e comprimento do meio
- e.g. ... dado uma taxa de "b" bits/s, o tempo requerido para enviar 8 bits é "8/b" s, ou seja, a frequência da primeira harmônica é o inverso do período da 1ª Harmônica... "b/8" Hz
  - considere a transmissão deste byte por uma linha telefônica comum cuja frequência de corte está em cerca de 3000 Hz
- O que significa esta restrição na Linha Telefônica ?? !!
  - siginifica que o nro do harmônica mais alto transmitido é aproximadamente "3000/(b/8)" ou "24000/b"
  - por outro lado, o sinal no receptor pode chegar alterado, considerando que algumas componentes serão atenuadas gerando um sinal resultante com distorções em relação ao sinal original
- Fig. 2.2 mostra taxas comumente usadas e o efeito da largura de banda de uma linha telefônica comum com fcorte = 3000 Hz
  - para 9600 bps em uma linha telefônica de qualidade de voz, o modelo sugerido da Fig 2.1 (a) assume a forma da Fig 2.1 (c) ... todas as demais harmônicas serão atenuadas e o resultado final contempla 2 comp.

  ![tabTransTel](images/tabTransTel.png)
- "Teorema de Nyquist" - um canal livre de ruído com largura de banda "H" transmitindo um sinal com "V" bauds possui uma taxa de tranmissão "T" <= "2 \* log2 v bps"
- e.g., ... seja um canal de 3 kHz sem ruído, então podemos transmitir sinais binários (ou seja, 2 níveis = 2 bauds) a uma taxa de até ... 2 \* 3000 \* log2 2 = 2 \*3000 \* 1 = 6000 bps
- Alguns valores para Taxas de Transmissão:
  - Elétricos (par trançado - cobre) - 10 Mbps; 100 Mbps; 1000 Mbps
  - Fibras Óticas - 100 Mbps; 1000 Mbps; 10s de 1000s
  - ATM - faixa de Gbps
- Nyquist provou que, se um sinal arbitrário atravessar um filtro com frequência de corte H, o sinal filtrado pode ser completamente reconstruído a partir de apenas 2*H amostras por segundo
  - coletar amostras acima deste limite é inútil, pois este componentes serão filtrados/eliminados e/ou atenuados pelo canal
- Entretando, se ruído está presente no canal, "Shannon" mostrou que a máxima taxa de transmissão T para um canal com largura de banda B é no máximo ... T <= B * Log2 (1 + S/N)  bps
  - S/N - comumente denominada de relação "sinal/ruído" reflete a relação entre a potência do sinal propriamente dito e a potência do sinal de ruído
- normalmente a relação sinal/ruído não é fornecida, ao invés disso, a quantidade 10*log10 s/n é fornecida (decibels - dB)
  - p.ex: uma relação S/N de 10 e -> 10 dB, uma relação de 100 -> 20dB, uma relação de 1000 -> 30 dB e assim por diante
- e.g., seja uma canal de 3000Hz de largura de banda e relação sinal/ruído de 30dB (parâmetro típico para linha de telefone)
  - então B * log2 (1 + s/n) = 3000 * log 2 (1 + 1000) ... aprox. 30000 bps, ou seja, canal não poderá transmitir a mais que 30000 bps
  - taxa máxima de transmissão independe do nro. de níveis ou "baus" do sinal (Teorema de Nyquist = T <= 2 * H * log2 v  bps)
- "baud" - frequência dom que o sinal podde ser propagar no meio de transmissão, ou seja, um canal de 10 M bauds permite 10⁶ variações do sinal por segundo
  - p.ex.: um canal de N bauds poderá transportar N bps com codificação On/Off ou N/2 com codificação Manchester
- Como transportar em um canal de N "bauds" um número maior que N bps?
  - e.g., ... usando sinal digital com codificação On/Off e 4 níveis de tensão representando as ocorrências dos bits 00, 01, 10 e 11 => 2 N bps
  - no entanto, acarreta alta taxa de falhar na decodificação do sinal

### 2. Meios de Tansmissão Guiados

- "meio físico" - diferentes meios físicos podem ser usados para realizar a tranmissão, cada qual com características próprias de largura de banda, retardo, custo de instalação e manutenção
- "meior magnéticos" - gravação de dados em fita magnética
- e.g., ... considere unidades de fitas com capacidade de 200 GB (Giga Bytes), então 1000 unid. de fita perfazerm uma capacidade de 300 terabytes ou 1600 terabits (1 TB - 2¹² bytes)
  - se considerarmos o trasporte deste volume de dados em 24 horas (86400 seg), então a largura de banda efetiva será:
    - 1600 terabits/ 86400 seg = 19 Gbps ... nenhuma rede de computador sequer contempla desemplenho próximo deste valor
- "par trançado" - dois fios enrolados de forma helicoidal para evitar que os fios assumam característica de antena, além disso minimiza a componente indutiva da impedância
  - componente resistiva da impedância sofre o efeito pelicular

  ![caboTrancado](images/caboTrancado.png)
- Utilizados para transmissão de Sinais Analógicos e Digitais, em razão do baixo custo e facilidade de instalação
- frequência máxima de tranmissão - depende do comprimento e espessura do par de fios, o que em última instância caracteriza a impedância elétrica do par
  - 1000s de metros => transmissão não ultrapassa 2 Kbps
  - 10s de metros => tranmissão pode atingir 100 Mbps
- Obs: comum redes na faixa de 10 Mbps terem como meio de transmissão pares trançados para distâncias inferiores a 1Km
- "largura de banda" - depende da espessura do fio e da distância percorrida, mas em muitos casos é possível alcançar 10s de 10⁶ ou Mbps por alguns quilômetros.
- Há diversos tipos de cabeamento de pares trançados e dentre eles destacam-se Cabos UTP e STP de várias categorias:
  - Cat. 3 - 16 MHz / Cat. 5 - 100 MHz
  - Cat. 6 - 250 MHz / Cat. 7 - 600 MHz
- Obs: Cabos Cat. 6 ocupam em média 30% mais de espaço que Cabos Cat.5/5e ... exigindo mais espaço na tubulação
- "cabo coxial" - composto por um condutor cilíndrico isolado envolto por uma malha de cobre e uma capa plástica de proteção
  - blindagem forma uma capa de proteção eletrostática ao condutor
  - forma de contrução minimiza as perda em altas frequências
  - estrutura assimétrica contribui para a atenuação da amplitude de sinal

  ![coxialCable](images/coxialCable.png)
- cabos de 50 ohms - comumente usados em transmissões digitais, são adequados ao suporte de uma frequência de transmissão ou duas no caso de FSK (Frequency Shift Keying)
- cabos de 75 ohms - comumente usado em transmissões analógicas e de TV a Cabo, possuem largura de faixa estendida permitindo a multiplexação pela divisão da frequência (FDM)
  - distância máxima de uma cabo depende da atenuação imposta ao sinal, mas o limite máximo de 30 dB é comumente estabelecido
  - atenuação depende do comprimento do cabo, de suas características elétricas, da frequência do sinal e do número de conectores existentes
- "fibra ótica" - composta de um núcleo de sílica envolto por uma casca também de sílica, tudo protegido por uma camada plástica
  - luz é mantida no núcleo por reflexão na casca (Fibra Multimodo)
  - possuem diâmtros entre 50 e 200 picometros
  - atenuação de 1 a 4 dB / Km na potência do sinal ótico

  ![fibraOtica](images/fibraOtica.png)
- Características de um Sinal Ótico:
  - luz policromáticas de onda centrado em 0.8 picometro
  - sinal é produzido por diodos LED e captado por fotodetectores
  - totalmente imune a interferências eletromagnéticas

  ![Otica](images/Otica.png)
- diferentes raios de luz incidindo na fronteira acima do ângulo crítico são refletidos internamente em diferentes ângulos e, por isso, os raios de luz tem modos específicos
- "fibra multimodo" - fibra na qual diferentes raios de luz são refletidos em diferentes ângulos
- "fibra monomodo" - fibra cujo diâmetro é tão reduzido que atua como um guia de onda, onde a luz dse propaga em linha reta
  - fibra "monomodo" ou fibra de "modo único" são geralmente mais caras, mas são amplamente utilizadas em distâncias mais longas
  - fibras disponíveis "monomodo" podem transmitir 50 Gbps por 100 Km sem necessidade de amplificação do sinal
- Utilização de Fibras Óticas:
  - são de difícil instalação e por isso utilizadas em redes com topologia em anel, onde o tráfego de informação se dá num único sentido
  - conexão de um host numa fibra ótica é um processo complicado
- Características de Redes baseadas em Fibra Ótica:
  - operam a taxas de 100 Mbits/s
  - taxas de Gbits/s com percursos de longas distâncias necessitam fibras monomodo (diâmtros de 5 a 10 picometros e luz produzida por diodos laser)
- Sistema Óptico - consiste de três elemento básicos: da fonte de luz, meio de tranmissão e detector de luz
- atenuação da luz no vidro depende do comprimento de onda da luz e, normalmente, é medida em decibéis
  - 10 * log10 Potência Transmitida/ Potência Recebida   decibéis
- e.g., ... considere um fator de perda = 2, ou seja, potência recebida é a 1/2 da potência transmitida, então a atenuação da luz é:
  - 10 \* log10 2 = 10 \* 0,301030 aprox 3 dB (decibéis)
- Fig. 2.7 - Atenuação do tipo de vidro usado nas Fibras em dB/Km para três bandas de comprimento de onda - 0,85; 1,30 e 1,55 pico

  ![attenFibraOtica](images/attenFibraOtica.png)
- "comunicação ótica" - utiliza três bandas de comprimento onda centralizadas em 0,85; 1,30 e 1,55 mícron, respectivamente
  - as duas últimas, 1,30 e 1,55 mícron, apresentam boas propriedades de atenuação, inferior 5% por quilômetro
  - outro ponto a ser considerado é a dispersão cromática, ou seja, expansão dos pulso de luz à medida que se propagam
  - quando se produz os pulsos de uma forma especial, os mesmo viajam por 1000s de quilômetros sem que haja distorção significativa - também denominados "solitons"
- "cabos de fibra" - são semelhantes aos cabos coaxiais, exceto por não terem a metálica, mas somente a capa plática ao redor
  - normalmente as fibras são agrupadas em feixes, protegidas por um revestimento exterior - "sheath"

  ![caboFibra](images/caboFibra.png)
- Fibras podem ser conectadas de três maneiras:
- "conectores" - conectores de extremidade permitem que as fibras sejam conectadas em soquetes de fibra
  - tem a vantagem de permitirem a reconfiguração do sistema, mas geram perdas de 10% a 20% da luz
- "união mecânica" - uma luva especial fixa as fibras uma vez que tenham sido cuidadosamente alinhadas
  - normalmente exige tempo de alguns minutos de equipe treinada e resultam em perdas de 10% da luz
- "fusão" - fusão da fibras para formar uma conexão sólida após serem cuidadosamente alinhadas
  - desempenho tão bom quanto de uma fibra sem emendas
- Para produzir os sinais, utilizam-se dois tipos de fontes de luz - "Light Emitting Diodes - LEDs" e "Semiconductor Lasers"
  - extremidade de recepção consiste de um fotodiódo, que emite um pulso elétrico ao ser atingido pela luz e tem tempo de resposta em torno de 1 nanosegundo -> taxa de dados de 1 Gbps

  ![ledXsemiCond](images/ledXsemiCond.png)
- "fibras óticas" vs "fios de cobre"
  - fibra óticas contemplam largura de banda muito alto do que fios de cobre, o que justifica seu uso nas redes de última geração
  - nro de repetidores a cada 50 km em linha de fibra ótica, enquanto são necessárias a cada 5km em linha de cobre
  - fibras óticas não são afetadas por picos de tensão, interferência eletromagnética ou quedas no fornecimento de energia
  - fibras óticas são imunes a ação corrosiva de alguns elementos químicos no ar, adaptando-se muito bem a ambientes industriais
  - fibras são mais leves que fios de cobre, e.g., 1000 pares trançados com 1km pesam oito toneladas, enquanto 2 fibras com igual capacidade pesam apenas 100 kg
  - fibras não desperdiçam luz e dificilmente são interceptadas, assim, oferecem um excelente nível de segurança
  - por outro lado, fibras são tecnologias menos familiares, exigindo conhecimento de profissionais especializados
  - por outro lado, fibras são basicamente unidirecionais, então a comunicação bidirecional exige duas fibras ou duas bandas de frequência em um única fibra ótica

### 3. Transmissão sem Fio

- "ondas eletromagnéticas" - resultado do movimento dos elétrons que poe se propagar pelo espaço livre ou mesmo no vácuo
  - nro de oscilações por segundo de uma onda eletromagnética é chamado de frequência - "f" e é medida em Hz (Hertz)
  - já a distância entre dois máximos ou mínimos consecutivos é chamada de comprimento de onda - "lambda"
  - ondas eletromagnéticas viajam a mesma velocidade, independente da frequência - 3 * 10⁸ m/s = c (velocidade da luz)
  - em meios físicos como cobre e fibra, esta velocidade cai par a 2/3 deste valor e se torna ligeiramente dependente da frequência
    - lambda = c \* T = c \* 1/f ou lamda \* f = c

  ![ondaEle](images/ondaEle.png)
- e.g., na prática "lambda" é medido em metros e "f" em MHz, então: lamda \* f = c (velocidade da luz) ou 3 \* 10⁸ m/s
  - lambda (m) \* f (MHz) = 300 \* 10⁶ m/s = aprox. 300
  - ondas de 100 MHz tem cerca de 3 m (comprimento)
  - ondas de 1000 MHz tem 0,3 m (comprimento)
  - ondas de 3000 MHz tem 0,1 m (comprimento)
- "espectro eletromagnético" - contempla porções de rádio, micro-ondas, infravermelho e luz visível do espectro
  - podem ser usadas na transmissão de dados, desde que seja modulada a amplitude, frequência ou fase de ondas
  - volume de informações que uma onda é capaz de transportar é diretamente proporcional à sua largura de banda

  ![espectroOndaEle](images/espectroOndaEle.png)
- Se diferenciarmos a equação "lambda * f = c" em relação a "lamda", obtem-se df/dlambda = c lambda² e, se na sequência considerarmos as diferenças finitas em vez de diferenciais, obtem-se:
  - deltaF = c * deltaLambda/lambda²
- e.g., considere a banda de 1,3 mícron, assim, temos lambda = 1,3 \* 10⁻⁶ e deltaLambda = 0,17 \* 10⁻⁶ enquanto deltaF = aprox. 30 THz
  - 8 bits/ Hz -> 240 Tbps (não é a esmo que pessoas ligadas têm um carinho todo especial pelas fibra óticas)
- "**transmissão de rádio**" - fáceis de gerar, percorrem longas distâncias e penetram facilmente em prédios, daí serem amplamente utilizadas em redes de comunicação
  - são omnidirecionais, ou seja, viajam em todas as direções a partir da fornte, assim, TX e RX não precisam estar fisicamente alinhados
- ondas de rádio dependem da frequência, p.ex., em baixas frequências elas atravessam obstáculos, mas a potência cai abruptamente à medida que a distância aumenta
  - este decréscimo aumenta cerca de "1 / r²" no ar
  - em altas frequências, as ondas tendem a viajar em linha reta e a ricochetear nos obstáculas -> necessidade alinhamento TX e RX
- ondas que alcançam a ionosfera - camada de partículas carregadas situada em torno da terra a cerca de 100 a 500 km - são refratadas por elas e retornam à Terra

  ![ionosfera](images/ionosfera.png)
  ![waveTypes](images/waveTypes.png)
- "transmissão de microondas" - ondas acima de 100 MHz trafegam em linha reta e, portanto, podem ser concentradas em uma faixa estreita do espectro de potência

  ![espectroOndaEle](images/espectroOndaEle.png)
  - demanda por mais espectro serve para manter o processo de aperfeiçoamento tecnológico, permitindo que as transmissões utilizem frequências cada vez mais altas
  - bandas de 10 GHz já são rotineiras, mas a partir de 4 GHz surge um novo problema - absorção pela água
  - e.g., considere ondas de 10 GHz, então o comprimento de onda "lambda" = 3 \* 10⁸ m/s / 10 \* 10⁹ Hz = 0,03 m = 3 cm
    - estas ondas possuem alguns centímetros e são absorvidas pela chuva, exigindo o estabelecimento de novos enlaces para contornar o problema
  - "vantagem" - microondas não exigem direitos sobre um caminho, o que constitui em vantagem significativa sobre fibra ótica
  - possibilidade de concentrar um pequeno feixe de energia em uma antena parabólica oferece relação S/N muito alta, mas antenas de TX e RX devem estar alinhadas com o máximo de precisão
  - microondas não atravessam muito bem as paredes de edifício diretamente das ondas de rádios
- História - durante décadas as microondas formaram o núcleo do sistema de telefônica de longa distância (antes da fibra ótica)
- "microondas" vs "fibra ótica"
- microondas dispensam a necessidade de se ter direitos sobre um caminho, o que constitui em vantagem significativa sobre fibra:
  - basta adquirir um pequeno lote de terra a cada estação repetidora, ou seja, a cada torre de retransmissão
  - MCI - Microwave Communications Inc. tornou-se uma companhia telefônica de longa distância - com 100s de repetidores
  - SPRINT investiu em cabos de fibra ótica, uam vez se formou a partir da Southern Pacific Railroad, que por deter um grande nro de concessões de direitos de percurso, investiu em linhas óticas
- microondas são relativamente mais econômicas, pois a instalação de torres e antenas pode ser mais econômica que enterrar 1000s km de fibras em uma área urbana
- "alocação de espectro" - governos nacionais alocam bandas de espectro para rádio, televisão, celulares, como também para empresas de telefonia, polícia, usuários marítimos ... etc
  - ITU-R (contexto mundial) coordena a alocação de modo que possam ser fabricados dispositivos que funcionem em vários países
- dentre as abordagens de concessão, destaca-se o leilão de frequências para telefonia móvel que por um lado enriquece governos e por outro dexa as concessionárias endividadas
- outra abordagem é a de simplesmente não alocá-las, permitindo que quem queira fazer uso o faça
  - ISM (Industrial, Scientific, Medical) - bandas para uso sem licença
- ISM - Industrial, Scientific, Medical - uso sem licença
  - banda 2,4 GHz está disponível na maioria dos países, mas é sujeita a inteferências de fornos de micro-ondas e instalações de radar
  - Bluetooth e algumas LANs sem Fio seguem o Padrão 802.11, utilizam banda 2,4 GHz e mais recentemente 5,7 GHz, não obstante equipamentos que operam nesta faixa ainda são dispendiosos
- U-NII Unlicensed National Information Infrastructure
  - U-NII Low (U-NII-1) 5,15 a 5,25 GHz
  - U-NII Mid (U-NII-2) 5,25 a 5,35 GHz
  - U-NII Worldwide (U-NII-2e) 5,47 a 5,725 GHz
  - U-NII Upper (U-NII-3) 5,725 a 5,850 GHz
- "ondas de infravermelho" - ondas relativamente direcionais

  ![espectroOndaEle](images/espectroOndaEle.png)
- "ondas de infravermelho" - ondas usadas na comunicação de curto alcance como aparelhos de TV equip, estereofônicos

  ![bandPatterns](images/bandPatterns.png)
- "ondas de infravermelho" - são direcionais, econômicas e fáceis de montar, mas não atravessam paredes sólidas
  - por isso, não é possível controlar o aparelho de televisão do vizinho com o seu controle remoto há alguns metros e separados por paredes
- e.g., considere ondas de 1 GHz, então o comprimento de onda "lambda" = 3 \* 10⁸ m/s / 1 \* 10⁹ Hz = 0,3 m = 30 cm
- e.g., considere ondas de 100 GHz, então o comprimento de onda "lambda" = 3 \* 10⁸ m/s / 100 \* 10⁹ Hz = 0,003 m = 3 mm
- "segurança do sistema infravermelho" - ... mais seguro contra espionagem quando comparada aos sistemas de rádio
- "transmissão de ondas de luz" - apontar um feixe laser com 1mm da largura para um alvo do tamanho da cabeça de um alfinete e a 500 m exige uma pontaria quase impossível

  ![lightTransEx](images/lightTransEx.png)

### 4. Satélites de Comunicação

- "satélite de comunicação" - repetidor com diversos "transponders" - cada um ouve uma parte do espectro, amplifica os sinais de entrada e os transmite em outra frequência
- Lei de Kepler - período orbital de um satélite varia de acoro com o raio da órbita elevado à poteência de 3/2
  - ou seja, quanto mais alto o satélite, mais longo o período
- e.g., satélites de baixa órbita saem da visão com bastante rapidez e tem período de 90 minutos, por isso faz-se necessário muitos deles para proporcionar cobertura contínua
- satélite de comunicação e algumas propriedades como: altitude da terra, tempo RTT, e nro. de satélites para cobertura global

  ![satAlt](images/satAlt.png)
- "satélites geoestacionários" - satélites de alta órbita e também chamados satélites geossíncronos (tripulados)
  - normalmente estão espaçados de 2 graus e se situam no plano equatorial de 360 graus a fim de evitar interferências
  - isto significa 360/2 = 180 satélites no céu ao mesmo tempo, mas por outro lado cada "transponder" pode usar várias frequências e polarizações, com a finalidde de aumentar a largura de banda disponível

  ![bandSat](images/bandSat.png)
- "satélites de órbita média" - se deslocam lentamente em longitude, levando cerca de seis horas para cirular a Terra
  - MEOs (Medium Earth Orbit) situam-se em órbitas mais baixas
  - tem área de corbetura menor no solo o que por outro lado exige transmissores menos potentes para alcança-los
- "satélites de órbita baixa" - estão muito próximos da Terra e se deslocam rapidamente, mas não necessários grandes quantidades desses satélites para formar um sistema completo
  - satélites "iridium" estão possicionados em altitude de 750 km em órbitas polares circulares e organizados em eixos polares norte-sul, com um satélite a cada 32 graus de latitude
  - organizados em eixos norte-sul com um satélite a cada 32 graus de latitude permite que toda a Terra seja coberta

  ![satOrg](images/satOrg.png)
  - propriedade interessante do Iridium é que a comunicação entre clientes distantes ocorre no espaço, com um satélite retransmitindo dados para o satélite seguinte

  ![satCom](images/satCom.png)
- "satélites" vs "fibra ótica"
- Há 20 anos, pensava-se que o futuro da comuniação residia nos satélites de comunicações, uma vez que por 100 anos não houve sinais de mudança no sistema telefônico
  - em meados da década de 80, companhias telefônicas começaram a substituir suas redes de longa distância por fibra ótica e introduziram serviços de alta largura de banda, com ADSL
  - conexões de fibra ótica pareciam ser a melhor opção a longo prazo, no entando, satélites de comunicações contemplam alguns segmentos de mercado que a fibra ótica não é capaz de alcançar

1. segmento - fibras óticas do sistema telefônico tratam diversar chamadas interurbanas ao mesmo tempo, mas não oferecem alta largura de banda aos usuários individualmente
2. segmento - comunicação móvel demanda serviço onipresente e, neste sentido, é possível que uma combinação de rádio e fibra funcionem para a maioria dos usuários
3. segmento - em momentos em que a difusão é essencial, satélites permitem que 1000s de estações terrestres recebem mensagens ao mesmo tempo
4. segmento - em locais onde o terreno é inadquado ou a infraestrutura é pouco desenvolvida, lançar um satélite é mais econômico que estender 100s de cabos submarinos
5. segmento - mercado de satélites cobre áreas em que a obtenção do direito de estender cabos de fibra é difícil ou excessivamente dispendiosa
6. segmento - quando a exploração rápida tem importância crítica, como em sistemas de comunicação militares em guerra, satélites possibilitam uma montagem rápida do sistema

- resumo - parece que a comunicação do futuro será por fibras óticas terrestres combinadas com rádio celular, mas, para algumas aplicações específicas, os satélites são melhores

### 5. Rede Pública de Telefonia

- "problema" - como conectar sistemas computacionais de uma mesma empresa ou organização, mas em locais deferentes??
  - quando as distâncias ficam grandes e é imprescindível atravessar uma estrada ou passagem pública, os custos de instalação de cabos privatos são proibitivos
- "solução" - utilizar recursos de relecomunicações existentes, p.ex., PSTN - "Public Switched Telephone Network" ... projetada (1950) para tráfego de voz humana de forma audível
- Alexandre Graham Bell (1876) - invenção do telefone e, na sequência, uma grande demanda pela nova invenção. Fig. (a)
  - modelo de conexão de telefones exigia que cada apareglho fosse conectado com "n" outros aparelhos de usuários
  - logo, ficou claro que este modelo de conexão de um telefone a outro, não seria escalável além de ser altamente dispendioso

  ![topologiasABC](images/topologiasABC.png)
- Bell Telephone Company - 1ª estação de comutação de telefonia (New Haven - Connecticut - 1878) .. Fig (b)
  - necessidade de centralizar as conexões individuais dos assinantes através das estações de comutação -> aumenta escala

  ![topologiasABC](images/topologiasABC.png)
- Com a disseminação de Estações de Comutação da Bell System por todos os lugares (USA), tornou-se necessário a reorganização das estações em níveis ... Fig. (c)
  - sistema telefônico (1890) passou a contemplar 3 elementos principais: estações de comutação/ rede inteligando usuários às estações de comutação e conexões de loga distância interligando estações

  ![topologiasABC](images/topologiasABC.png)
- Estações interurbanas, regionais e locais se comunicam através de "troncos" de alta largura de banda - "troncos entre estações".
  - nro. de diferentes tipos de centros de comutação e sua topologia varia de país para país, dependendo da densidade telefônica do território.

  ![telephoneLogic](images/telephoneLogic.png)
- "loops locais" - normalmente formados por cabos Cat. 3, mas no início utilizou-se cabos sem isolamento separados por 25cm de distância um do outro fixados em postes telefônicos.
  - constitui-se no último fragmento de tecnologia análogica
- "estações de comutação" - interligadas por cabos coaxiais, antenas de microondas e principalmente fibra ótica
  - com o advento da fibra ótica, eletrônica digital e computadores "desktop", os troncos e "switches" passam a ser totalmente digitais
  - destaca-se os "loops" locais, os troncos e as estações finais interurbanas responsáveis pela comutação das chamadas

  ![telInternetNetwork](images/telInternetNetwork.png)
- "local loop" - utiliza sinalização analógica há 100 anos e é provável que continue a utilizá-la por mais algumas décadas
  - quando se transmite dados digitais por uma linha de discagem analógica, primeiro os dados são convertidos para a forma analógica
  - conversão é feita por dispositivos responsáveis pela "modulação" e "demodulação" dos sinais - (MODEMs 56 kbps)
  - estação de comutação converte os dados para a forma digital, para serem transmitidos pelos troncos de longa distância
- "sinalização analógica" - consiste na variação da tensão elétrica no tempo, de modo a representar um fluxo de informação
  - como os meios de transmissão se comportam como filtros, então o sinal recebido não é igual ao sinal transmitido (atenuação, dispersão e retardo)
- "ondas quadradas" - são representadas para os sinais digitais, no entanto, por contemplam um amplo espectro de frequências, estão sujeitas a forte atenuação bem como distorção
  - diante de tais efeitos, utiliza-se sinalização AC(Alternate Current) ao invés de DC (Direct Current) na linha telefônica
  - introduz-se um sinal contínuo na faixa de 1000 Hz a 2000 Hz, denominado portadora de onda senoidal na qual parâmetros como amplitude, fase ou frequência podem ser alterados

  ![digitalSignal](images/digitalSignal.png)
- "modulação" - constitui o chaveamento por deslocamento - "shift keying" - da amplitude, frequência ou fase da onda

  ![digitalAnalogicSignal](images/digitalAnalogicSignal.png)
- "modulador-demodulador" ou "modem" - dispositivo que aceita um fluxo serial de bits como entrada e produz um portadora modulada por um (ou mais) desses métodos (ou vice-versa)
- Teorema de Nyquist - considerando um linha telefônica perfeita de 3000 Hz, não há razão para amostragem maior que 6000 Hz
  - um canal livre de ruído com largura de banda "B" transmitindo um sinal com "V" bauds possui uma taxa de transmissão "T" <= "2 \* H \* log2 v  bps"
  - modems realizam amostragem na faixa de 2400 vezes/seg e consentram-se em oubter mais bits por amostra
- "baus" - nro de amostras ou símbolos por segundo, ou seja, durante cada "baud" envia-se um "símbolo" o que permite que uma linha de "n" bauds envia "n" símbolos / seg
- e.g., considere uma linha de 2400 bauds e a modulação de uma símbolo "0" volts indica "0" lógico e o símbolo "1" volt indica "1" lógico, então qual será a taxa de transmissão ??
  - se os símbolos 0, 1, 2 e 3 são usadas, ou seja, voltagens 0, 1, 2 e 3, então cada símbolo carrega 2 bits de informação e, assim qual será a taxa de transmisão ??
- "modems avançados" - combinam técnicas de modulação como ASK, PSK e FSK para transmistir vários bits por baud
  - observe os pontos a 45, 135, 225 e 315 graus com amplitude constante, uma vez que a distância a partir da origem é constante
  - fase é indicada pelo ângulo formado entre a linha da origem até o ponto em questão e o eixo da abscissa - eixo "x"

  ![modulacoes](images/modulacoes.png)
- QPSK - contempla 4 combinações válidas e pode ser usada para transmitir 2 bits/símbolo
- QAM-16 ou 16 "Quadratur Amplitude Modulation" com 4 amplitudes e 4 fases, permite 16 combinações diferentes
  - pode transmitir 4 bits por símbolo, ou seja, em uma linha de 2400 bauds podemos transmitir até 9600 bits por segundo
- QAM-64 ou 64 "Quadratur Amplitude Modulation" permite até 64 combinações diferentes, ou seja, 6 bits por símbolo
  - pode transmitir 6 bits por símbolo, ou seja, em uma linha de 2400 bauds podemos transmitir até 14400 bits por segundo
- QAM-16 ou 16 "Quadratur Amplitude Modulation" com 4 amplitudes e 4 fases, permite 16 combinações diferentes
  - pode transmitir 4 bits por símbolo, ou seja, em uma linha de 2400 bauds podemos transmistir até 9600 bits por segundo

  ![modulationTwistedPair](images/modulationTwistedPair.png)
- V.32 bits ou QAM-128 - contém 6 bits de dados e 1 bit de paridade por amostra de 2400 bauds
  - e.g., fax modems utilizam essa velocidade para transmitir páginas digitalizadas como mapas de bits

  ![modulationHigher](images/modulationHigher.png)
- Modems série padrão V.34 - funcionam em 28800 bps a 2400 bauds com 12 bits de dados/ símbolo
  - Modems séris V.34 - utilizam 14 bits de dados/símbolo a 2400 bauds para atingir 33600 bits por segundo
- Modems - permitem o tráfego em ambos os sentidos ao mesmo tempo, para tanto, utilizam frequências diferentes
  - canal de transmissão pode ser "simplex", "half-duplex" ou "full-duplex"
- Modems modernos param a 33600 bps, pois o limite de Shanon para o Sistema Telefônico é próximo de 35 kbps
- Modems modernos param a 33600 bps, pois o limite de Shanon para o Sistema Telefônico é próximo de 35 kbps
  - tal restrição está relacionada com o comprimento médio dos "loops" locais ou com a qualidade das linhas desses "loops" locais ??
- Entretando, se ruído está presente no canal, "Shannon" mostrou que a máxima taxa de transmissão T para um canal com largura de banda B é no máximo ... T <= B * Log2 (1+ S/N) bps
  - S/N - comumente denominada de relação "sinal/ruído" reflete a relação entre a potência do sinal propriamente dito e a potência do sinal de ruído
  - tem-se 2 "loops" locais entre uma chamada de origem (Computador) e receptor (ISP #1)
  - adicionalmente "loops" locais acrescentam ruído de sinal e, caso possamos eliminar um deles, a taxa pode ser duplicada

  ![telInternetNetwork](images/telInternetNetwork.png)
- Nyquist provou que, se um sinal arbitrário atravessar um filgro com frequência de corte H, o sinal filtrado pode ser completamente reconstruído a partir de apenas 2\*H amostras por segundo
  - coletar amostras acima deste limite é inútil, pois os componentes serão filtrados/eliminados e/ou atenuados pelo canal
- e.g., ... Modems 56 kpbs -a para um canal telefônico de 4000 Hz, o nro. máximo de amostras por segundo é 8000
- Modems 56 kbps - para um canal telefônico de 4000 Hz, o nro. máximo de amostras independentes por segundo é 8000
  - USA - um dos bits da amostra é usado para fins de controle, então podemos transmitir até 56000 bits/seg de dados do usuário
  - Europa - 8 bits estão disponíveis para os usuários, então modems podem oferecer até 64000 bits/segundo de dados
  - Modems V.90 - denominação para modems neste padrão
- Modems V.92 - modems capazes de transmitir 48 kbps no canal "upstream" caso a linha possa lidar com esta funcionalidade
- Serviço de Banda - Larga - serviço com maior largura de banda que o serviço da telefonia padrão e que utiliza a tecnologia xDSL (Digital Subscriber Line - linha digital do assinante)
  - justificatvia para os modems serem lentos é que o sistema telefônico foi concebido e otimizado para transportar voz humana
  - como não foram concebidos dados, a faixa de frequência de corte 300 Hz a 3400 Hz restringe fortemente a taxa de transmissão de dados
- xDSL conecta-se um a tipo diferente de "switch", sem esse filtro, disponibilizado toda a capacidade de "loop" local
  - limitador passa a ser a constituição física do "loop" local, não a largura de banda artifical de 3100 Hz criada pelo filtro
  - esboço de largura de banda potencial como um função da distância em Cabo UTP de categoria 3 para xDSL

  ![trPdis](images/trPdis.png)
  - quando se escolhe uma velocidade para oferecer, está ao mesmo tempo escolhendo um raio a partir de suas estações finais, além da qual o serviço não pode ser oferecido
    - quanto mais baixo a velocidade escolhida, maior o raio e maior o nro. de cliente cobertos, mas menos atraente é o serviço
- Serviço xDSL foram criados visando certos objetivos
  - devem funcionar nos "loops" locais de par trançado existente
  - não deve afetar os telefones e aparelhos atuais de fax dos clientes
  - devem ser muitoi mais rápido que 56 kbps
  - devem estar sempre ativos e serem tarifados mensalmente
- Proposta inicial do ADSL (AT&T) - divisão do espectro de frequência do "loop" local - divisão (1,1 MHz) em 3 bandas:
  - POTS (Plain Old Telephone Service) - sinal de voz
  - "upstream" - do usuário para a estação final
  - "downstream" - da estação final para o usuário
- AT&T empregou a técnica de Multiplexação por Divisão de Frequência (FDM - Frequência Division Multiplexing)
- "abordatem alternativa" - DMT (Discrete MultiTone) que divide o espectro de 1,1 MHz do loop local em 256 canais de 4312,5 Hz
- DMT (Discrete MultiTone) que divide o espectro do 1,1 MHz do loop local em 256 canais independentes de 4323,5 Hz cada
  - canal "0" é usado para o POTS e canais "1" a "5" não são usados para impedir que o sinal de foz e os sinais de dados se interfiram
  - 2 canais para controle "upstream" e "downstream" e 248 canais disponíveis para dados do usuário
  
  ![channels](images/channels.png)
  - embora os canais possam ser usados por fluxos "full-duplex", harmônicos, linhas cruzdas e outros efeitos impedem o seu uso
  - cabe ao prevedor definir quantos canais serão usados para "upstream" (10%) e para "downstream" (80% a 90%)
- ADSL - "Assynchronous" DSL surgiu justamente da assimetria na divisão dos canais para "upstream" e para "downstream"
  - divisão comum reserva 32 canais para "upstream" e 216 canais para "downstream", totalizando 248 canais + 2 para controle "up" e "down"
- ADSL (ANSI T1.413 e ITU G.992.1) - permite velocidades de até 8 Mbps "downstream" e 1 Mbps "upstream"
  - em cada canal, utiliza-se modulação semelhante ao v.34, com taxa de amostragem de 4000 bauds, em vez de 2400 bauds
    - linha é monitorada constantemente de modo que a taxa de dados seja ajustada de forma contínua quando necessário
    - dados são enviados com QAM-16, com até 15 bits por baud, usando um diagrama de constelação análogo ao da Figura 2.25(b)

  ![modulacoes](images/modulacoes.png)
- e.g., com 224 canais "downstream" e 15 bits/baud a 4000 bauds, a largura de banda downstream é 13,44 Mbps
  - 224 canais \* 4000 bauds/canal \* 15 bits / baud = 13,44 Mbps
  - mas na prática, a relação sinal/ruído nunca é boa o bastante par ase alcançar essa taxa, mas é possível utilziar 8 Mbps por curtos períodos
- Instalação típica ADSL  contempla uma dispositivo (Network Interface Device - NID) instalado pela companhia nas dependências do cliente ADSL
  - normalmente o NID + Filtro Analógico separa a banda 0 a 4000 Hz utilizada pelo POTS, asism o sinal é roteado até o telefone
- Instalação típica ADSL - Sinal POTS é roteado até o telefone, e o sinal de dados é roteado até um modem ADSL
  - ADSL é um processor de sinais digitais configurado para atuar como 250 modems QAM operando em paralelo em frequências diferentes

  ![adsl](images/adsl.png)
  - considerando que a maioria dos modems atuais é externo, o computador está conectado ao modem em alta velocidae
    - isto pode ser feito inserindo-se uma placa Ethernet no computador e operando-se uma rede local de apenas 2 nós
  - no lado da estação final, está instalado um divisor correspondente, assim, a voz é filtrada enviada ao switch de voz
    - sinal acima de 26 kHz é roteado para o dispositivo DSLAM (Digital Subscriber Line Access Multiplexer)
  - DSLAM (DSL Access Multiplexer) realiza o trabalho semelhante ao do Modem ADSL, o que permite a recuperação do sinal digital (fluxo de bits) que são enviados ao ISP
  - desvantabem deste projeto é a presença do NID e do divisor no local do cliente, pois a instalação desses itens só pode ser feita por um técnico da companhia telefônica (dispendioso)

    ![NIDdiv](images/NIDdiv.png)
- "projeto alternativo" - G.lite ou ITU é G.992.2 é o ADSL sem o divisor, assim a linha telefônica é usada como está
  - com uma pequena diferença que é a inserção de um microfiltro em cada tomada de telefone, entre o telefone ou o model ADSL e o fio
  - microfiltro para o telefone é um filtro de banda baixa que elimina frequências acima de 3400 Hz
  - microfiltro para o modem ADSL é um filtro de banda alta, que elimina frequências abaixo de 26 kHz
- G.lite não é tão confiável quanto um divisor, e assim só pode ser usado até 1,5 Mbps (contra 8 Mbps para o ADSL com um dividor)

  ![filterSpliter](images/filterSpliter.png)
- "troncos vs multiplexação" - custo para instalaer e manter um tronco de alta largura de banda é o mesmo de um tronco de baixa largura de banda entre duas estações de comunicação
  - companihas telefônicas desenvolveram esquemas para multiplexar o uso de um único tronco físico, melhorando a relação de custo e benefício
- FDM (Frequency Division Multiplexing) - espectro de frequência é dividido em bandas de frequência, tendo cada usuário a posse exclusiva de alguma banda
- TDM (Time Division Multiplexing) - os usuários se revezm (em um esquema de rodízio), e cada um obtém preiodicamente a largura de banda interia por um determinado período de tempo
- FDM - 3 canais telefônicos são multiplexados, os filtros limitam a largura de banda utilizável a 3100 Hz por canal de voz

  ![channelsEx](images/channelsEx.png)
- FDM - apesar de haver intervalor entre os canais, há uma certa sobreposição entre canais adjacentes (limites não são nítidos)

  ![channelsEx](images/channelsEx.png)
- Padrão FDM - padrão muito difundido tem 12 canais de voz de 4000 Hz multiplexados na banda de 60 a 108 kHz (grupo)
  - banda de 12 a 60 kHz pode ser utilizada por outro grupo
  - permite que concessionárias de comunicações ofreçam o serviço de linha privada de 48 a 56 kbps baseado no grupo.
- TDM (Time Division Multiplexing) - pode ser inteiramente manipulada por circuitos eletrônicos digitais
  - como só pode ser usada par adados digitais e como os loops locais produzem sinais analógicos, é necessário uma conversão
  - dados de computadores enviados por um modem também são analógicos, então, também é necessário a digitalização
- WDM (Wavelength Division Multiplexing) - quatro fibras chegam juntas e um combinador óptico, cada uma com sua energia presente em um comprimento de onda distinto