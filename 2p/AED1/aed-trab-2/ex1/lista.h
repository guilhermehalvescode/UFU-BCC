#ifndef LISTA_H
#define LISTA_H

typedef struct pilha * Pilha; 

Pilha cria();

int vazia(Pilha list);

int cheia(Pilha list);

int esvazia(Pilha pil);

int push(Pilha pil, int elem);

int pop(Pilha pil, int *elem);

int le_topo(Pilha pil, int *elem);

#endif