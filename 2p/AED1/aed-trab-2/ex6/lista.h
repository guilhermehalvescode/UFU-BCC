#ifndef LISTA_H
#define LISTA_H

typedef struct no * Fila; 

Fila cria();

int vazia(Fila list);

int esvaziar(Fila *fil);

int inserir(Fila *fil, char nome[], int idade, int orgao, int grau);

int remover_inicio(Fila *fil, char nome[], int *idade, int *orgao, int *grau);

#endif