typedef struct no* Lista;

Lista cria_lista();
int lista_vazia(Lista);
int lista_tam(Lista);
int insere_nome(Lista*, char* nome);
int remove_pos(Lista*, int pos, char* nomeSoldado);
int avanca_lista(Lista*, int pos);
int avanca_lista_nome(Lista*, char *name);
int obtem_valor_elem(Lista, int indice, char *elem);