# Arquitetura de Redes TCP/IP

- Objetivo: mostrar a "atmosfera" e a terminologia das redes TCP/IP:
  - usar a internet como exemplo

## Introdução (Parte 1)

### O que é a internet? (visão basica)

- Milhões de dispositivos de computação conectados: hospedeiros = sistemas finais
  - rodando aplicações de rede
- Enlaces de comunicação (meios em que a informação navega, é transportada)
  - fibra, cobre, radio, satelite
  - taxa de transmisão = largura de banda
- roteadores: encaminham pacotes (pedaços de dados)

#### Internet: uma visão de serviço

- Infraestrutura de comunicação, possibilita aplicações distribuidas
  - Web, VoIP, e-mail, jogos, e-commerce, compartilhamento de arquivos, streaming de video, multimidia
- Servições de comunicação fornecidos as aplicações:
  - entrega de dados confiavel de origem ao destino
  - entrega de dados pelo "melhor esforço" (não confiavel)

### O que é um protocolo?

#### Protocolo

- protoculos humanos:
  - "que horas são?"
  - "tenho uma pergunta"
- Introduções:
  - mensagens especificadas enviadas
  - açoes especificas tomadas quando mensagens recebidas são traduzidas
- Define:
  - O formato e a ordem das mensagens trocadas entre duas ou mais entidades comunicantes
  - As ações tomadas na transmissão e/ou recebimento de uma mensagem ou outro evento

### Borda de Rede

#### Visão da estrutura e rede

- borda de rede: servidores de aplicações e hospdeiros
- redes de acesso, meios fisicos: enlaces de comunicação com e sem fio
- nucleo da rede

#### Borda da rede

- sistemas finais (hospedeiros):
  - executar programas de aplicação
  - p.e. Web, e-mail
  - na "borda da rede"
- modelo cliente/servidor
  - hospedeiro cliente solicita, recebe serviço de servidor sempre ativo
  - p.e. navegador/servidor Web; cliente/servidor de e-mail
- modelo peer-peer
  - uso minimo (ou nenhum) de servidor dedicados
  - p.e. Skype, BitTorrent

#### Redes de acesso e meios fisicos

- Como conectar sistemas finais ao roteador da borda?
  - redes de acesso residencial
  - redes de acesso institucional (escola, empresa);
  - redes de acesso movel (WiFi, 4g e 5g)

#### Digital Subscriber Line (DSL) 

- Usa infraestrutura de telefone para central DSLAM (digital subscriber line access multiplexer)
- Taxas de transmissão:
  - downstream: 24Mbps e 52Mbps
  - upstream: 3,5 ate 16Mbps
- Linha fisica dedicada central telefonica

#### Modem a cabo

- Multiplexação por divisão de frequência: diferentes canais transmitem em diferentes bandas de frequências
- Sistema Hybrid Fiber Coax (HFC):
  - Assimetrico: 30Mbps para downstream e 2 Mbps para a taxa de upstream
- Rede a cabo e fibra inseridos na residência para o roteador do ISP
  - As casas compartilham o acesso para as Centrais
  - Diferente do DSL (no qual tem link dedicado com a central)

#### Rede de acesso sem fio

- compartilhado conecta sistema final ao roteador
  - via estação base, tambem conhecida como "ponto de acesso"
- Wireless LANs:
  - 802.11 b/g/n (WIFI): 11, 54 e 450 Mbps como taxa de transmissão
- Wide-area wireless access
  - Fornecido pela empresa de telecom: 1 and 10 Mbps
  - 3G, 4G

#### Acesso a Internet por Ethernet

- normalmente usado em empresas, universidade etc.
- Ethernet a 10 Mbps, 100 Mbps, 1 Gbps e 10 Gbps
- hoje, os sistemas finais normalmente se conectam ao comutador Ethernet

#### Host: envio de pacotes de dados

- Funções do hospedeiro:
  - Pega mensagem da aplicação;
  - Divide em partes, conhecido com pacotes de tamanho L bits;
  - Transmite pacotes para a rede em uma taxa de transmissão de R;
  - Taxa do enlace de transmissão, capacidade e largura de banda
- Atraso na tranmissão de pacotes = Tempo necessario para transmitir L bits do pacote dentro o enlace = L (bits) / R (bits/sec)

#### Meios fisicos

- bit: propaga entre pares de transmissor/receptor
- enlace fisico: o que fica entre transmissor e receptor
- meio guiado:
  - sinais se propagam em meio solido: cobre, fibra e coaxial
- meio não guiado:
  - sinais se propagam livremente, p.e., sinal de radio
- Par Trançado (TP)
  - dois fios de sobre isolados
    - categoria 3: fios de telefone tradicionais, Ethernet a 10 Mbps
    - categoria 5: Ethernet a 100 Mbps
    - categoria 6: 1 Gbps

#### Meio fisico: cabo coaxial e fibra (meio guiado)

- cabo coaxial:
  - dois condutores de cobre concêntricos
  - Bidirecional
  - banda base:
    - unico canal no cabo
    - Ethernet legado (automação)
  - banda larga:
    - multiplos canais no cabo
    - HFC
- cabo de fibra otica
  - fibra de vidro conduzindo pulsos de luz
  - cada pulso um bit
  - operação em alta velocidade
    - tranmissão em alta velocidade ponto a ponto

#### Meio fisico: radio (meio não guiado)

- Radio
  - Sinal transportado no espectro eletromagnetico
  - Nenhum "fio" fisico
  - Bidirecional
  - Efeitos no ambiente de propagação
    - reflexão
    - obstrução por objetos
    - interferência
- Tipo de sinal:
  - micro-ondas terrestre
    - canais de 45 Mbps
  - LAN
    - 11 MBPS, 54 Mbps
  - area ampla
    - celular 3G: 1 Mbps
  - satelite
    - canal de Kbps ate 45Mbps (ou multiplos canais menores)
    - atraso fim a fim de 270 ms
    - geoestacionario

### Nucleo da rede

#### O nucleo a rede

- Malha de roteadores interconectados
- Questão: como os dados são transferidos pela rede?
- Comutação de circuitos

#### Nucleo da rede: comutação de circuitos

- recursos de rede (p.e., largura de banda) divididos em "pedaços"

#### Comutação de circuitos: FDM e TDM

- FDM: ocorre a multiplexação por divisão de frequência
- TDM: ocorre a multiplexação por divisão de tempo, usuario recebe toda frequência em um periodo de tempo

#### Nucleo da rede: comutação de pacotes

- comutação e pacotes: dados enviados pela rede em "pedaços" discretos
- Encaminham pacotes de um roteador para o seguinte, atraves de ligações no caminho da origem ate o destino
- cada pacote transmitido na capacidade total do enlace

#### Comutação de pacotes: store-and-forward

- Taxa de L/R segundos para transmitir (push out) o pacote de L bits no enlace em R bps
- Store-and-forward: pacote inteiro deve chegar ao roteador antes que possa ser transmitido no proximo enlace
- Atraso "fim-a-fim" = tempo 2L/R o hospedeiro tera recebido o 1º

#### Comutação de pacotes: Atraso de fila e perda

- Enfileramento e perde: se a taxa de chegada (em bits) para o enlace excede a taxa de transmissão do enlace durante um periodo de tempo:
  - os pacotes irão criar uma fila e irão aguentar para serem transmitidos no enlace
  - os pacotes podem ser "dropped" (perdidos) se a memoria (buffer) for preenchida

#### Comutação de pacotes: Funções

- Roteamento: determina a rota de origem e destino tomada por pacotes
- Encaminhamento: mover os pacotes da entrada do roteador para a saida do roteador apropriado

#### Comutação de pacotes versus Comutação de Circuitos

- Coputação de pacote permite mais usuarios usar a rede de computadores

- Exemplo:
  - Link (enlace): 1Mbps
  - Cada usuario:
    - 100Kbps quando ativo
    - Ativo 10% do tempo
  - Comutação circuito:
    - 10 usuarios
  - Comutação pacote:
    - Quando ha 35 usuarios, probabilidade > 10 ativo

#### A comutação de pacotes e a "grande vencedora"?

- otima para dados em rajadas
- compartilhamento de recursos
- mais simples, sem configuração de chamada
- congestionamento excessivo: atraso e perda de pacotes:
  - Demanda protocolos para transferência de dados confiavel e controle de congestionamento
- Como fornecer comportamento do tipo circuito?
  - Ter largura de banda garantida necessaria para aplicações e audio/video
  
> ainda um problema não resolvido

- Exemplo: Analogia humana - recursos reservados (comutação de circuitos) versus alocação por demanda (comutação de pacotes)?

#### Estrutura da Internet: rede de redes

> Tendo dados gerado em milhões de ISPs de acesso, como conecta-los entre si?

- Solução: Aproximadamente hierarquica
- No centro tem os ISPs de "nivel 1" (exemplo: Verizon, Spring, AT&T, etc)
- Tratam os ISPs em niveis iguais

#### ISPs de nível 1

- Sprint

#### ISPs de nível 2

- conectam a um ou mais ISPs de nível 1, possivelmente também a outros ISPs de nível 2
- ISP de nível 2 paga ao ISP nível 1 por conectividade com restante da internet
- ISPs de nível 2 também olham de forma privada uns para os outros

#### ISPs de nível 3 e ISPs locais

- rede do último salto ("acesso"), mais próxima dos sistemas finais
- ISPs locais e de nível 3 são clientes de ISPs de camada mais alta conectando-os ao restante da Internet

## Introdução (Parte 2)

Objetivo

- Mostrar a "atmosfera" e a terminologia das redes TCP/IP

### Desempenho

#### Como ocorre a perda e o atraso?

- Pacotes se enfileiram nos buffers dos roteadores:
  - Devido a taxa de chegada dos pacotes ao enlace ultrapassarem a capacidade de saida do enlace
- Pacotes se enfileiram e esperam por sua vez

#### Quatro fontes de atraso do pacote

- Dnodal = Dproc + Dqueue + Dtrans + Dprop
  
1. (Dproc) processamento nodal:
   1. verificação de erros de bits
   2. Determinar o enlace de saida
   3. Normalmente em microssegundos
2. (Dqueue) enfileiramento
   1. tempo esperando para transmissão do enlace de saida
   2. depende do nivel de congestionamento do roteador
3. (Dtrans) atraso de transmissão:
   1. R = largura de banda do enlace (bps)
   2. L = tamanho do pacote(bits)
   3. Tempo para enviar bits no enlace por L/R
4. (Dprop) atraso de propagação:
   1. d = tamanho do enlace fisico
   2. s = velocidade de propagação no meio (~2x10⁸)
   3. atraso de propagação = d/s

> Nota: s e R são quantidade muito diferentes!

#### Comparação entre atraso de transmissão e propagação: analogia da caravana

- Carros se propagam a 100 km/h
- Cabines de pedagio levam 12 segundos para atender um carro (tempo de transmissão)
- Analogia: Carro ~ bit e caravana ~ pacote
- Quanto tempo leva para a caravana formar fila antes da 2º cabine?
  - O tempo para "empurrar" a caravana inteira pela cabine para proxima estrada:
    - 10 carros / (5 carros / minuto) = 2 minutos
  - Tempo para o ultimo carro se propagar da 1º a 2º cabine de pedagio:
    - 100 km com 100 km/h = 1h
  - Resposta: 62 minutos
- Se os carros se "propagam" a uma velocidade de 1000 km/h
- Cabine leva 1 minuto para atender um carro
- Os carros chegarão a 2º cabine antes que todos os carros sejam atendidos na 1º cabine?
  - O 1º carro (bit) da caravana (pacote) pode chegar a 2º cabine (roteador) antes que a caravana seja totalmente transmitida na 1º cabine (roteador)?
  - Se 1000 km/h -> temos 6 minutos para 100km
  - Tambem devemos considerador 1 minuto pela cabine

#### Atraso de enfileiramento

- R = largura de banda do enlace (bps)
- L = tamanho do pacote (bits)
- a = taxa media de chegada de pacote
  
> Intensidade e trafego -> La/R

- La/R ~ 0 : pequeno atraso de enfileiramento medio
- La/R <= 1 : atrasos tornam-se grandes (rajadas)
- La/R >= 1 : mais "trabalho" chegando do que se pode ser atendido, atraso medio infinito

#### Atrasos e rotas "reais" da Internet

Como são os atrasos e perdas "reais" da Internet?

- Programa Traceroute: fornece medida do atraso da origem ao roteador ao longo do caminho de fim a fim da Internet para o destino
- Para todo i:
  - envia três pacotes que alcançarão o roteador i no caminho para o destino
  - roteador i retornara os pacotes ao emissor
  - emissor temporiza o intervalo entre a transmissão e a resposta

#### Perda de pacote

- Fila (ou buffer) antes do enlace tem capacidade finita
- Pacote chegando a fila cheia e descartado (ou perdido)
- Ultimo pacote pode ser retransmitido pelo no anterior, pela origem ou de forma nenhuma

#### Vazão (Throughput)

- Vazão: taxa (bits/unidade de tempo) em que os bits são transferidos entre emissor/receptor
  - instântanea: taxa em determinado ponto no tempo
  - media: taxa por periodo de tempo maior

#### Vazão

- Rs < Rc Qual e a vazão media de fim a fim? Rs
- Rs > Rc Qual e a vazão de fima a fim? Rc
  
> enlace de gargalo: enlace no caminho de fim a fim que restringe a vazão de fim a fim

#### Vazão: cenario da Internet

- Pratica: Rc ou Rs normalmente e um gargalo
- A vazão de fim a fim por conexão = min(Rc, Rs, R/10)

### Camadas de protocolo, modelos de serviço

#### "Camadas" de protocolo: Revisão

Redes são complexas!

- muitas "partes":
  - hospedeiros
  - roteadores
  - enlaces de varios meios fisicos
  - aplicações
  - protocolos
  - hardware

- Camadas: cada etapa implementa um serviço
  - por meio de suas proprias ações internas na camada
  - contando com serviços fornecidos pela camada abaixo

#### Por que usar camadas?

- E um sistema complexo:
  - estrutura explicita permite identificação e relação entre partes complexas do sistema
  - modelo de referência em camadas
- Modularização facilita manutenção e atualização do sistema:
  - mudança de implementação do serviço da camada transparente ao restante do sistema
  - Ex. mudanças no procedimento de porta não afeta o restante do sistema
- O uso da camada e considerado prejudicial
  - Ex. pode ocorrer a duplicação do serviço

#### Pilha de protocolos da Internet

- aplicação: suporte a aplicações de rede
  - FTP, SMTP e HTTP
- transporte: transferência de dados processo-processo
  - TCP e UDP
- rede: roteamento de datagramas da origem ao destino
  - IP e protocolos de roteamento
- enlace: transferência de dados entre elementos vizinhos da rede
  - PPP e Ethernet
- fisica: bits "nos fios"

#### Modelo de referência ISO/OSI

- apresentação: permite que as aplicações interpretem o significado dos dados
  - Ex. criptografia, compactação, conveções especificas da maquina
- session: sincronização, verificação, recuperação de troca de dados
- Pilha da Internet "faltando" essas camadas
  - Estes serviços, se necessarios, devem ser implementados na aplicação
  - Se necessario a aplicação

### Segurança

#### Segurança de rede

- o campo da segurança de rede trata de:
  - como defender as redes contra ataques
  - como maus sujeitos atacam as redes de computadores
  - como projetar arquiteturas imunes a ataques
- Internet não foi criada originalmente com (muita) segurança em "mente"
  - visão original: "um grupo de usuarios mutuamente confiaveis conectados a uam rede transparente"
  - projetistas de protocolos da Internet brincando de "contar novidades"
  - considerações de segurança em todas as camadas!

#### Maus sujeitos podem colocar malware em hospedeiros via Internet

- Malware (programas maliciosos) pode entrar em um hospedeiro por virus, worm ou cavalo de troia
- O malware do tipo spyware pode registrar toques de teclas, sites visitados na Web, enviar informações para sites de coleta
- Um hospedeiro infectado pode ser "alistado" em um botnet, usado para spam e ataques de DoS (negação de serviços)
- O malware normalmente e auto replicavel: de um hospedeiro infectado, busca entrada em outros hospedeiros

- cavalo de Troia
  - parte oculta de algum software util
  - hoje, normalmente em uma pagina Web (Active-X, plug-in)
- virus
  - infecção ao receber objeto (p.e., anexo de um e-mail), executando ativamente
  - autorreplicavel: propaga-se para outros hospedeiros e usuarios
- worm:
  - infecção recebendo passivamente objeto a ser executdo
  - Auto replicavel: propaga-se para outros hospedeiros, usuarios

#### Maus sujeitos podem atacar servidores e infraestrutura de rede

- Denial of Service (DoS): atacantes deixam recursos (servidor, largura de banda) indisponiveis ao trafego legitimo, sobrecarregando recurso com trafego

1. selecionar o alvo
2. invadir os hospedeiros na rede (ver botnet)
3. enviar pacotes para o alvo a partir dos hospedeiros compremetidos

#### Maus sujeitos podem farejar pacotes

- Farejamento de pacotes:
  - meio de broadcast (Ethernet compartilhada, sem fio)
  - interface de rede analisa (le/registra) todos os pacotes (p.e., incluindo senhas!) passando por
- Software Wireshark usado para laboratorio do farejador de pacotes (gratuito)

#### Maus sujeitos podem usar endereços de origem falso

- IP spoofing: enviar pacote com endereço de origem falso

### Historia