#include <stdlib.h>
#include "FILA.h"

struct no {
    registro info;
    struct no* next;
};

Fila criar() {
    return NULL;
}

int fila_vazia(Fila q) {
    return q == NULL;
}

int insereFila(Fila *q, registro elem) {
    Fila no = (Fila) malloc(sizeof(struct no));
    if(no == NULL) 
        return 0;
    no->info = elem;
    if(fila_vazia(*q)) {
        no->next = no;
        *q = no;
    } else {
        no->next = (*q)->next;
        (*q)->next = no;
        *q = no;
    }
    return 1;
}

int removeFila(Fila *q) {
    if(fila_vazia(*q)) 
        return 0;
    Fila aux = (*q)->next;
    if(*q == (*q)->next) 
        *q = NULL;
    else
        (*q)->next = aux->next;
    free(aux);
    return 1;
}