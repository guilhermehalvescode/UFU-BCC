typedef struct no* Lista;

Lista cria_lista();
int lista_vazia(Lista);
int insere_elem(Lista, int);
int remove_elem(Lista, int);
int obtem_valor_elem(Lista, int indice, int *elem);