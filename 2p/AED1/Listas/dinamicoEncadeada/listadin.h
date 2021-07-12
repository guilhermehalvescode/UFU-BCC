typedef struct no* Lista;
Lista cria_lista();
int lista_vazia(Lista);
int insere_elem(Lista*, char);
int remove_elem(Lista*, char);
int obtem_posicao(Lista, int indice, char*);
int limpa_lista(Lista*);
