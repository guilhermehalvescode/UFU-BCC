#include <stdio.h>
#include <stdlib.h>
#include "listaestOrd.h"

void imprimir_lista(Lista list) {
    int i;
    float valor;
    printf("\n----LISTA----\n");
    for(i = 0; i < lista_tam(list); i++) {
        if(i != 0) printf(" ");
        get_posicao(list, i, &valor);
        printf("[%.2f]", valor);
    }
    printf("\n");
}

void inserindo(Lista list, float *vet) {
    int i;
    for(i = 0; i < 11; i++) {
        if(!insere_ord(list, vet[i]))
            break;
    }
}

void remove_valor(Lista list, float valor) {
    if(!remove_ord(list, valor)) {
        printf("\nElemento nao existe!!\n");
    }
}


int main() {
    float vet[20] = {4, 8.5, -1.1, 19, 2.5, 7, 8.45, 7, -9, 22, 45.7};
    Lista lista_estatica_seq;
    lista_estatica_seq = criar_lista();
    if(lista_estatica_seq == NULL) {
        printf("Erro na criação da lista!!");
        exit(1);
    }
    imprimir_lista(lista_estatica_seq);
    inserindo(lista_estatica_seq, vet);
    imprimir_lista(lista_estatica_seq);
    remove_valor(lista_estatica_seq, 7);
    imprimir_lista(lista_estatica_seq);
    remove_valor(lista_estatica_seq, 8.55);
    imprimir_lista(lista_estatica_seq);
    limpa_lista(lista_estatica_seq);
    imprimir_lista(lista_estatica_seq);
    return 0;
}
