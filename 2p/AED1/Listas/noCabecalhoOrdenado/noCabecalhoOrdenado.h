typedef struct no* Lista;

Lista cria_lista();
int lista_vazia(Lista);
int insere_ord(Lista, int);
int remove_ord(Lista, int);
int obtem_valor_elem(Lista, int indice, int *elem);