#include <stdio.h>
#include <stdlib.h>
#include "encadeadoRecursivo.h"

void imprimir_lista(Lista list) {
    double valor;
    printf("\n----LISTA----\n");
    int i = 0;
    while(obtem_elem(list, i, &valor)) {
        if(i != 0) printf(" ");
        printf("[%.2lf]", valor);
        i++;
    }
    printf("\n");
}

void inserindo(Lista *list, double *vet) {
    int i;
    for(i = 0; i < 11; i++) {
        if(!insere_ord(list, vet[i])) 
            break;
    }
}

void remove_lista(Lista *list, double elem) {
    if(remove_ord(list, elem)) 
        printf("\nElemento foi removido da lista!!\n");
    else
        printf("\nElemento nao existe!!\n");
}

int main() {
    double vet[20] = {4, 8, -1, 19, 2, 7, 8, 5, 9, 22, 45};
    Lista EncOrdenado;
    EncOrdenado = cria_lista();
    imprimir_lista(EncOrdenado);
    inserindo(&EncOrdenado, vet);
    imprimir_lista(EncOrdenado);
    remove_lista(&EncOrdenado, 8.0);
    imprimir_lista(EncOrdenado);
    return 0;
}