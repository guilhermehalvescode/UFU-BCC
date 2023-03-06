# Sistemas Distribuídos

## Introdução

### Definição

- Um sistema distribuído é um conjunto de computadores independentes, interligados por uma rede de comunicação, que cooperam para realizar uma tarefa.
- Coleção de sistemas computacionais autônomos que se apresentam ao usuário como um sistema único coerente.

### Características

- Sistemas computacionais autônomos ou nós
  - dispositivos de hardware ou processos de software
- Sistema único coerente
  - percebido como um único sistema => nós colaboram na execução da tarefa

### Nós autônomos

- Comportamento independente
- Cada nó tem sua própria noção de tempo
  - sem relógio global
  - problemas fundamentais de sicronização e coordenação
- Comunicação
  - memória compartilhada
  - mensagens
- Em uma coleção de nós:
  - como se faz o gerenciamento de grupos
  - como se garante comunicação com um membro não autorizado

### Sistemas Distribuídos e o Middleware

- Equivalente ao "sistema operacional" de um sistema distribuído
- Oferece diversos serviços:
  - comunicação
  - segurança
  - métricas
  - recuperação de falhas
  - transações
  - composição de serviços

### Escalabilidade em Sistemas Distribuídos

- Pelo menos 3 componentes a considerar

1. Número de usuários ou processos (escalabilidade de tamanho)
2. Distância máxima entre nós (escalabilidade geográfica)
3. Número de domínios administrativos (escalabilidade administrativa)

- Maioria dos sistemas se preocupam apenas com o primeiro caso

---

#### Soluções
  
1. Scale up (vertical scaling): aumentar a capacidade de um dispositivo
   - custo exponencial
   - limitado
2. Scale out: agregar o poder computacional de diversos computadores "baratos"
   - capacidade limitada de crescimento (em teoria)
   - diversos desafios teóricos

---

- Scale Out - desafios:
  - Escalabilidade:
    - Necessidade de aplicar as técnicas de computação distribuída e superar barreiras para conseguir atender o número crescente de clientes
  - Tolerância a falhas:
    - Capacidade de um sistema se manter no ar
    - Implica em redundância, o que fatadicamente implica em distribuição e em Sistemas Distribuídos
- Conclusão:
  - principais razões para se desenvolver sistemas distribuídos são alcançar escalabilidade e tolerância a falhas, ambas resultantes da agregação do poder computacional de múltiplos componentes

### Técnicas para prover escalabilidade

- Mover a computação para o cliente
  - antigamente verificações de formulários eram feitas nos servidores
  - atualmente verificações são realizadas no navegador do cliente utilizando javascript
    - diminui quantidade de requisições ao servidor, evitando sobrecarga do mesmo
- Particionar dados e computação em diversas máquinas
  - DNS é um exemplo, pois funciona de forma hierárquica
- Outros exemplos de técnicas:
  - Bancos de dados e servidores de arquivos replicados
  - Web sites espelhados
  - Caches em navegadores e proxies
  - Caches de arquivos (servidores e clientes)

### Desafios relacionados à replicação

- Principais dificuldades
  - Múltiplas cópias levam a inconsistências: como lidar com escritas e caches
  - Manter cópias consistentes requer sincronização global a cada modificação do estado
  - Sincronização global previne soluções de larga escala
- Observação
  - Se um sistema pode tolerar inconsistências, a necessidade de sincronização global pode ser reduzida:
    - Depende da aplicação

### Desafios no desenvolvimento de sistemas distribuídos

- Muitos sistemas se tornam complexos sem necessidade:
  - Muitas vezes devido a "consertos" de erros detectados
- Algumas suposições falsas durante o desenvolvimento
  - A rede é confiável
  - A rede é segura
  - A rede é homogênea
  - A topologia não muda
  - A latência é zero
  - A banda é infinita
  - Existe apenas um administrador

### Tipos de sistemas distribuídos

- Sistemas de computação (de alta performance)
- Sistemas de informação
- Sistemas de computação pervasiva

### Sistemas de Computação (de alta perf.)

- Teve início com a computação paralela
  - Computadores multiprocessadores
- Memória compartilhada
- Memória privada
- Nunca atingiu expectativa dos programadores
  - pouco usado hoje em dia

#### Clusters

- Coleção de nós similares
- Mesmo sistema operacional

#### Grids

- Federação de sistemas computacionais
- Diferente domínios administrativos
- Componentes fracamente acoplados
- Muito usadas até meados da década passada
- Membros de uma associação disponibilizam capacidade computacional a um pool
- Hardware, software e tecnologias de rede podem ser diferente entre os componentes da grade
- Exemplo
  - SETI@home: pessoas doavam tempo ocioso do seu computador para analisar sinais de rádio recebidos do espaço

#### Cloud

- Modelo de computação utilitária:
  - Fornecimento de recursos computacionais por provedores em troca de um pagamento proporcional à quantidade de recursos utilizados
  - Similar a fornecimento de água ou eletricidade
  - Facilidade para construir infraestrutura
- Infraestrutura para outros sistemas distribuídos
- Complexas peças de engenharia com diversos subsistemas:
  - sincronização de relógios
  - monitoração de falhas, tolerância a falhas e coleta de logs
  - roteamento eficiente

## Socket

- Conexão direta entre dois hosts
- Definição do protocolo:
  - Camada 3: AF_INET ou PF_INET - identifica unicamente o host a se conectar
  - Camada 4: SOCK_STREAM - TCP