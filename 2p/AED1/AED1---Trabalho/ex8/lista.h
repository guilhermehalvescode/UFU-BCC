typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista);
int insere_ord(Lista*, int expo, int coefic);
int remove_ord(Lista*, int expo);
int obtem_posicao(Lista, int indice, int *expo, int *coefic);
int obtem_valor(Lista, int expo, int *coefic);
int limpa_lista(Lista *);
