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
  - comunicaão
  - segurança
  - métricas
  - recuperação de falhas
  - transações
  - composição de serviços