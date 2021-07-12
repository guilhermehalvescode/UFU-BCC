typedef struct lista* Lista;

Lista criar_lista();
int lista_tam(Lista);
int lista_vazia(Lista);
int lista_cheia(Lista);
int insere_elem(Lista, float nota, char conceito, int key);
int remove_elem(Lista, float nota, char conceito);
int get_posicao(Lista, int i, float* var, char* letra);
