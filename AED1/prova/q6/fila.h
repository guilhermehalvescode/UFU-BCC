typedef struct {
    char titulo[50], autor[50], lang[50];
    int anoC;
} registro; 

typedef struct no* Fila;

Fila criar();
int fila_vazia(Fila);
int insereFila(Fila*, registro elem);
int removeFila(Fila*);