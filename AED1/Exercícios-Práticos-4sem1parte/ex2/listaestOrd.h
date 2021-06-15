typedef struct lista* Lista;

Lista inicializar_lista();
int lista_vazia(Lista);
int lista_cheia(Lista);
int insere_ord(Lista, char *nome, int volume, float preco);
int remove_ord(Lista, char *nome);
int get_pos(Lista, int i, char *nome, int *volume, float *preco);
