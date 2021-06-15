typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista);
int insere_ord(Lista *, char);
int remove_ord(Lista *, char);
int obtem_posicao(Lista, int indice, char *);
int limpa_lista(Lista *);
