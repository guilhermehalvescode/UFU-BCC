#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#define MAX 21

struct aluno {
    int matricula, cra, chs, ano;
    char nome[56];
};

struct queue {
    struct aluno no[MAX];
    int ini, fim;
};

//Função que realiza o decremento circular
int decCircular(int i) {
    if(i < 0) return MAX - 1;
    return i;
}

//Verifica se os dados da estrutura são válidos
int verificaAluno(int matricula, char* nome, int cra, int chs, int ano) {
    return matricula >= 0 && strlen(nome) < 56 && cra >= 0 && chs >= 0 && ano >= 0;
}

Queue cria_fp() {
    Queue q = (Queue) malloc(sizeof(struct queue));
    if(q != NULL) {
        q->ini = 0;
        q->fim = 0;
    }
    return q;
}

int fp_vazia(Queue q) {
    if(q == NULL) return -1;
    return q->ini == q->fim;
}

int fp_cheia(Queue q) {
    if(q == NULL) return -1;
    return q->ini == ((q->fim) + 1) % MAX;
}

int insere(Queue q, int matricula, char* nome, int cra, int chs, int ano) {
    if(q == NULL || fp_cheia(q) || !verificaAluno(matricula, nome, cra, chs, ano))
        return 0;
    q->no[q->fim].matricula = matricula;
    strcpy(q->no[q->fim].nome, nome);
    q->no[q->fim].cra = cra;
    q->no[q->fim].chs = chs;
    q->no[q->fim].ano = ano;
    q->fim = ((q->fim) + 1) % MAX;
    return 1;
}

//Remoção ordenada crescente
int remove_ord(Queue q, int *matricula, char* nome, int *cra, int *chs, int *ano) {
    if(q == NULL || fp_vazia(q)) 
        return 0;
    //Preciso percorrer a lista para saber qual elemento é
    //o menor para remover
    int i;
    //Inicializo para pegar o menor
    int pos = q->ini, menorAno = q->no[pos].ano;
    for(i = (q->ini + 1) % MAX; i != q->fim; i = (i + 1) % MAX) {
        if(q->no[i].ano < menorAno) {
            pos = i;
            menorAno = q->no[pos].ano;
        } 
    }
    //Agora preciso retornar o removido, e tirá-lo da fila
    *matricula = q->no[pos].matricula;
    strcpy(nome, q->no[pos].nome);
    *cra = q->no[pos].cra;
    *chs = q->no[pos].chs;
    *ano = q->no[pos].ano;
    //Faço o shift dos elementos
    for(i = (pos + 1) % MAX; i != q->fim; i = (i + 1) % MAX)
        q->no[decCircular(i - 1)] = q->no[i];
    
    q->fim = decCircular(q->fim - 1);
    return 1;
}

//Procedimento que esvazia a pilha
int esvazia_fp(Queue q) {
    if(q == NULL) 
        return 0;
    if(fp_vazia(q)) 
        return 1;
    //Para que esteja vazia, basta fazer o fim e o inicio
    //serem iguais
    q->fim = 0;
    q->ini = 0;
    return 1;
}