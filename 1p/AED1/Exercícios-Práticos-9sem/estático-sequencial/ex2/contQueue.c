#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#define MAX 20

struct aluno {
    int matricula, faltas;
    char nome[50];
    float media;
};

struct queue {
    struct aluno no[MAX];
    int ini, cont;
};

Queue queue_start() {
    Queue q = (Queue) malloc(sizeof(struct queue));
    if(q != NULL) {
        q->ini = 0;
        q->cont = 0;
    }
    return q;
}

int queue_empty(Queue q) {
    return !(q->cont);
}

int queue_full(Queue q) {
    return q->cont == MAX;
}

int queue_push(Queue q, int mat, char *name, int faults, float media) {
    if(queue_full(q) || mat < 0 || strlen(name) > 49 || faults < 0 || media < 0)
        return 0;

    int fim = (q->ini + q->cont) % MAX;
    q->no[fim].matricula = mat;
    strcpy(q->no[fim].nome, name);
    q->no[fim].faltas = faults;
    q->no[fim].media = media;
    (q->cont)++;
    return 1;
}

int queue_pop(Queue q, int *mat, char *name, int *faults, float *media) {
    if(queue_empty(q)) 
        return 0;
    *mat = q->no[q->ini].matricula;
    strcpy(name, q->no[q->ini].nome);
    *faults = q->no[q->ini].faltas;
    *media = q->no[q->ini].media;
    q->ini = ((q->ini) + 1) % MAX;
    (q->cont)--;
    return 1;
}