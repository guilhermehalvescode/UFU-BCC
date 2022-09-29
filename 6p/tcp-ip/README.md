# Arquitetura de Redes TCP/IP

- Objetivo: mostrar a "atmosfera" e a terminologia das redes TCP/IP:
  - usar a internet como exemplo

## Introdução

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
- Atraso "fim-a-fim"

#### Comutação de pacotes: Atraso de fila e perda

- Enfileramento e perde: se a taxa de chegada (em bits) para o enlace excede a taxa de transmissão do enlace durante um periodo de tempo
  - os pacotes irão criar uma fila e irão aguentar para serem transmitidos no enlace
  - os pacotes podem ser "dropped" (perdidos) se a memoria (buffer) for excedida

#### Comutação de pacotes: Funções
