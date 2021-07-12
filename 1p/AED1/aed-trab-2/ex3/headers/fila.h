typedef struct fila *Fila;
#define max 10

Fila cria_fila();
int fila_vazia(Fila fila);
int fila_cheia(Fila fila);
int insere_fim(Fila fila, char *placa);
int remove_ini(Fila fila, char *placa);
size_t tamanho(Fila fila);