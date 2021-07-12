typedef struct fila *Fila;
typedef struct tm *horario;

Fila cria_fila();
int fila_vazia(Fila fila);
int insere_fim(Fila fila, size_t tempo_atendimento, size_t tempo_espera, horario horario_entrada);
int remove_ini(Fila fila, size_t *tempo_atendimento, size_t *tempo_espera, horario horario_entrada);
int tamanho_fila(Fila fila);
