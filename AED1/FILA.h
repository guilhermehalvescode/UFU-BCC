struct alunos {
    long int matricula;
    int faltas;
    float nota;
};

typedef struct queue* Fila;
Fila cria_fila();
int fila_vazia(Fila);
int insere(Fila*, struct alunos elem);
int remover(Fila*, struct alunos *elem);