typedef struct queue* Queue;

Queue cria_fila();
int fila_vazia(Queue);
int insere_fim(Queue, char *nome, unsigned int vol, float preco);
int remove_ini(Queue, char *nome, unsigned int *vol, float *preco);
int apaga_fila(Queue*);
int esvazia_fila(Queue);