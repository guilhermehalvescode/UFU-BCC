#include <stdio.h>
#include <stdlib.h>
#include "encadeadoDuplo.h"

void imprimir_lista(Lista list) {
    int valor;
    printf("\n----LISTA----\n");
    int i = 0;
    while(obtem_valor_elem(list, i, &valor)) {
        if(i != 0) printf(" ");
        printf("[%d]", valor);
        i++;
    }
    printf("\n");
}

void inserindo(Lista *list, int *vet) {
    int i;
    for(i = 0; i < 11; i++) {
        if(!insere_elem(list, vet[i])) 
            break;
    }
}

void remove_lista(Lista *list, int elem) {
    if(remove_elem(list, elem)) 
        printf("\nElemento foi removido da lista!!\n");
    else
        printf("\nElemento nao existe!!\n");
}

int main() {
    int vet[20] = {4, 8, -1, 19, 2, 7, 8, 5, 9, 22, 45};
    Lista dplEnc;
    dplEnc = cria_lista();
    imprimir_lista(dplEnc);
    inserindo(&dplEnc, vet);
    imprimir_lista(dplEnc);
    remove_lista(&dplEnc, 8);
    imprimir_lista(dplEnc);
    return 0;
}