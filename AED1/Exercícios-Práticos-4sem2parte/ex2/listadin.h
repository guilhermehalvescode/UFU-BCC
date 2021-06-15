typedef struct no* Lista;
Lista inicializar_lista();
int lista_vazia(Lista);
int size_lista(Lista list);
int insere_elem(Lista *list, unsigned int matricula, char *nome, float media, int faltas);
int remove_elem(Lista*, unsigned int matricula);
int get_pos(Lista list, int indice, unsigned int *matricula, char *nome, float *media, int *faltas);