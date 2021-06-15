typedef struct no* Lista;
Lista cria_lista();
int lista_vazia(Lista);
int insere_elem(Lista*, float nota, char conceito, int key);
int remove_elem(Lista*, float nota, char conceito);
int obtem_posicao(Lista, int indice, float* var, char* letra);