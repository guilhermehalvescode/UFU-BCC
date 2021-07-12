typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista);
int insere_inicio(Lista*, int);
int insere_final(Lista*, int);
int remove_inicio(Lista*, int *elem);
int remove_final(Lista*, int *elem);
int obtem_valor_elem(Lista, int indice, int *elem);
