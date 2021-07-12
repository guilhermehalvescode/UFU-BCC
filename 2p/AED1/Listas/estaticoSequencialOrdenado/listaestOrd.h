typedef struct lista* Lista;

Lista criar_lista();
int lista_tam(Lista);
int lista_vazia(Lista);
int lista_cheia(Lista);
int insere_ord(Lista, float elem);
int remove_ord(Lista, float elem);
int limpa_lista(Lista);
int get_posicao(Lista, int i, float* var);
