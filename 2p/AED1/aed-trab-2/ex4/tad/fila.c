#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "..\headers\fila.h"

typedef struct{
    size_t tempo_atendimento,
    tempo_espera;
    horario horario_entrada;
}Cliente;

struct no {
    Cliente info;
    struct no *prox;
};

struct fila{
    struct no *ini;
    struct no *fim;
};

Fila cria_fila(){
    Fila F = (Fila) malloc(sizeof(struct fila));

    if (F != NULL) {
        F->ini = NULL;
        F->fim = NULL;
    }

    return F;
}

int fila_vazia(Fila fila){
    if (fila->ini == NULL)
        return 1;
    return 0;
}

int insere_fim(Fila fila, size_t tempo_atendimento, size_t tempo_espera, horario horario_entrada){
    struct no *N = (struct no*) malloc(sizeof(struct no));
    if (N == NULL)
        return 0;

    N->info.tempo_atendimento = tempo_atendimento;
    N->info.tempo_espera = tempo_espera;
    N->info.horario_entrada = horario_entrada;
    N->prox = NULL;

    if (fila_vazia(fila))
        fila->ini = N;
    else
        (fila->fim)->prox = N;
    fila->fim = N;

    return 1;
}

int remove_ini(Fila fila, size_t *tempo_atendimento, size_t *tempo_espera, horario horario_entrada){
    if (fila_vazia(fila))
        return 0;
    
    struct no *aux = fila->ini; //aux aponta para o primeiro nó

    //Retorna valor do elemento por referência
    *tempo_atendimento = aux->info.tempo_atendimento;
    *tempo_espera = aux->info.tempo_espera;
    horario_entrada = aux->info.horario_entrada;

    //Verifica se a fila tem um único nó
    if (fila->ini == fila->fim)
        fila->fim = NULL;

    fila->ini = aux->prox; //Retira primeiro nó da fila
    free(aux); //Libera memória

    return 1;
}

int tamanho_fila(Fila fila){
    size_t cont = 0;
    if (fila_vazia(fila))
        return 0;

    struct no *aux = fila->ini;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }

    return cont;
}