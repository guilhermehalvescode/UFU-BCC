
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct no {
    char string[50];
    struct no *prox;
};
Lista cria_lista() {
    return NULL;
};

int lista_vazia(Lista list) {
    return list == NULL;
}

int remove_inicio(Lista *list, char *elem) {
    if(lista_vazia(*list))
        return 0;
    Lista aux = (*list)->prox;
    strcpy(elem, aux->string);
    if(*list == (*list)->prox) 
        *list = NULL;
     else 
        (*list)->prox = aux->prox;
    free(aux);
    return 1;
}