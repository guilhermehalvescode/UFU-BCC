typedef struct no *Lista;

Lista criar_lista();
int lista_vazia(Lista list);
int insere_ord(Lista *lista, float elem);
int remove_ord(Lista *lista, float elem);
int obtem_valor(Lista *lista, float *elem, size_t pos);
int esvaziar_lista(Lista *lista);
int remove_pos(Lista *lista, size_t pos, float *elem);
int listas_iguais(Lista *lista_1, Lista *lista_2);
int maior_valor(Lista *lista, float *elem);
int tamanho_lista(Lista *lista);
int intercalar_listas(Lista *lista_1, Lista *lista_2, Lista *lista_3);
