typedef struct queue* Queue;

Queue cria_fp();
int fp_vazia(Queue);
int fp_cheia(Queue);
int insere(Queue, int matricula, char* nome, int cra, int chs, int ano);
int remove_ord(Queue, int *matricula, char* nome, int *cra, int *chs, int *ano);
int esvazia_fp(Queue);