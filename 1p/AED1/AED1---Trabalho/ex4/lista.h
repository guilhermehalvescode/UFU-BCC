typedef struct lista *Lista;
int lista_vazia(Lista *);
Lista cria_lista();

int insere_ord(Lista *, char);
int remove_ord(Lista *, char);
int remove_pos(Lista *, int, char *);

int obtem_valor_elem(Lista *, int, char *);
int obtem_tamanho(Lista *);

int listas_iguais(Lista *, Lista *);
int maior_elem(Lista *, char *);
int esvazia_lista(Lista *);
int intercalar(Lista *, Lista *, Lista *);