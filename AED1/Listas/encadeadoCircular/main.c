#include <stdio.h>
#include <stdlib.h>
#include "encadeadoCircular.h"

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
        if(!insere_final(list, vet[i])) 
            break;
    }
}

void remove_lista(Lista *list) {
    int valor;
    if(remove_inicio(list, &valor)) 
        printf("\nElemento %d foi removido da lista!!\n", valor);
    else
        printf("\nElemento nao existe!!\n");
}

int main() {
    int vet[20] = {4, 8, -1, 19, 2, 7, 8, 5, 9, 22, 45};
    Lista encadCirc;
    encadCirc = cria_lista();
    imprimir_lista(encadCirc);
    inserindo(&encadCirc, vet);
    imprimir_lista(encadCirc);
    remove_lista(&encadCirc);
    imprimir_lista(encadCirc);
    return 0;
}