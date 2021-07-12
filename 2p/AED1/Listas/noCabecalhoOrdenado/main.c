#include <stdio.h>
#include <stdlib.h>
#include "noCabecalhoOrdenado.h"

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

void inserindo(Lista list, int *vet) {
    int i;
    for(i = 0; i < 11; i++) {
        if(!insere_ord(list, vet[i])) {
            break;
        }
    }
}

void remove_valor(Lista list, int valor) {
    if(!remove_ord(list, valor)) {
        printf("\nElemento nao existe!!\n");
    }
}

int main() {
    int vet[20] = {4, 8, -1, 19, 2, 7, 8, 5, 9, 22, 45};
    Lista noCab;
    noCab = cria_lista();
    if(noCab == NULL) {
        printf("Erro ao inicializar!!");
        exit(1);
    }
    imprimir_lista(noCab);
    inserindo(noCab, vet);
    imprimir_lista(noCab);
    remove_valor(noCab, 8);
    imprimir_lista(noCab);
    return 0;
}