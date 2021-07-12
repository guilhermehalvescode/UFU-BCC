#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

struct filalunos {
    int mat, faltas;
    char nome[50];
    float media;
};

void imprimir_fila(Queue fil) {
    if(queue_empty(fil)) {
        printf("\n----FILA VAZIA----\n");
        return;
    } 
    struct filalunos temp[4];
    printf("\n----FILA----\n");
    int i = 0;
    while(queue_pop(fil, &temp[i].mat, temp[i].nome, &temp[i].faltas, &temp[i].media)) {
        if(i != 0) printf(" ");
        printf("[{%d, '%s', %d, %.2f}]", temp[i].mat, temp[i].nome, temp[i].faltas, temp[i].media);
        i++;
    }
    printf("\n");
    int j;
    for(j = 0; j < i; j++) 
        queue_push(fil, temp[j].mat, temp[j].nome, temp[j].faltas, temp[j].media);
    
}

void remove_fila(Queue fil) {
    char value[10];
    struct filalunos temp;
    if(queue_pop(fil, &temp.mat, temp.nome, &temp.faltas, &temp.media)) 
        printf("\nElemento {%d, '%s', %d, %.2f} foi removido da fila!!\n", temp.mat, temp.nome, temp.faltas, temp.media);
    else
        printf("\nNao e possivel remover da fila!\n");
}

void prepara(struct filalunos* v) {
    v[0].mat = 1;
    strcpy(v[0].nome, "Cleber");
    v[0].faltas = 0;
    v[0].media = 7.45;

    v[1].mat = 2;
    strcpy(v[1].nome, "Joao");
    v[1].faltas = 1;
    v[1].media = 9.45;

    v[2].mat = 3;
    strcpy(v[2].nome, "Felipe");
    v[2].faltas = 4;
    v[2].media = 8.9;

    v[3].mat = 4;
    strcpy(v[3].nome, "Victor");
    v[3].faltas = 7;
    v[3].media = 5.48;
}

int main() {
    struct filalunos vet[4];
    prepara(vet);
    Queue queue = queue_start();
    if(queue == NULL) return 1;
    imprimir_fila(queue);
    int i;
    for(i = 0; i < 4; i++) {
        if(!queue_push(queue, vet[i].mat, vet[i].nome, vet[i].faltas, vet[i].media)) 
            break;
    }
    imprimir_fila(queue);
    remove_fila(queue);
    imprimir_fila(queue);
    return 0;
}