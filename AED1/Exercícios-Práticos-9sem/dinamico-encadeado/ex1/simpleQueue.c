#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "simpleQueue.h"

struct bebida {
    char nome[20];
    unsigned int volume;
    float preco;
};

struct node {
    struct bebida info;
    struct node* next;
};

struct queue {
    struct node* start;
    struct node* end;
};

Queue cria_fila() {
    Queue q = (Queue) malloc(sizeof(struct queue));
    if(q != NULL) {
        q->start = NULL;
        q->end = NULL;
    }
    return q;
}

int fila_vazia(Queue q) {
    return q->start == NULL;
}

int insere_fim(Queue q, char *nome, unsigned int vol, float preco) {
    if(strlen(nome) > 19 || preco < 0 )
        return 0;
    struct node* n = (struct node*) malloc(sizeof(struct node));
    if(n == NULL) 
        return 0;
    strcpy((n->info).nome, nome);
    (n->info).volume = vol;
    (n->info).preco = preco;
    n->next = NULL;
    if(fila_vazia(q)) 
        q->start = n;
    else 
        (q->end)->next = n;
    
    q->end = n;
    return 1;
}

int remove_ini(Queue q, char *nome, unsigned int *vol, float *preco) {
    if(fila_vazia(q) ) 
        return 0;
    struct node* aux = q->start;
    strcpy(nome, (aux->info).nome);
    *vol = (aux->info).volume;
    *preco = (aux->info).preco;
    if(q->start == q->end) 
        q->end = NULL;
    q->start = aux->next;
    free(aux);
    return 1;
}

int apaga_fila(Queue *q) {
    if(fila_vazia(*q)) {
        free(*q);
        *q = NULL;
        return 0;
    }
    struct node *aux = (*q)->start, *aux2;
    while(aux != NULL) {
        aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
    free(*q);
    *q = NULL;
    return 1;
}

int esvazia_fila(Queue q) {
    if(fila_vazia(q)) 
        return 0;
    struct node *aux = q->start, *aux2;
    while(aux != NULL) {
        aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
    q->start = NULL;
    q->end = NULL;
    return 1;
}