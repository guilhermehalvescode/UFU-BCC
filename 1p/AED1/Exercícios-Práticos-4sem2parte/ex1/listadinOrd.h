typedef struct no *Lista;
Lista inicializar_lista();
int lista_vazia(Lista);
int insere_ord(Lista *, int);
int remove_ord(Lista *, int);
int get_pos(Lista, int indice, int *);
int remove_pos(Lista *, int indice, int *);
