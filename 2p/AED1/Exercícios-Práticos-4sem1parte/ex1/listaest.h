typedef struct lista* Lista;

Lista inicializar_lista();
int lista_vazia(Lista);
int lista_cheia(Lista);
int insere_elem(Lista, char *elem);
int remove_elem(Lista, char *elem);
int get_pos(Lista, int i, char *var);
