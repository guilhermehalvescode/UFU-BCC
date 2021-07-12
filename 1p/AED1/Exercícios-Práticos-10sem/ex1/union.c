#include <stdio.h>
#include <stdlib.h>
#include "union.h"
#define MAX 30

struct nota {
    int letra;
    union {
        char nota_char;
        float nota_float;
    } info;
};

struct lista {
    struct nota no[MAX];
    int size;
};

Lista criar_lista() {
    Lista list;
    list = (Lista) malloc(sizeof(struct lista));
    if(list != NULL) 
        list->size = 0;
    
    return list;
}

int lista_tam(Lista list) {
    if(list == NULL)
        return -1;
    return list->size;
}

int lista_vazia(Lista list){
    if(list == NULL)
        return -1;
    return list->size == 0;
}

int lista_cheia(Lista list){
    if(list == NULL)
        return -1;
    return list->size == MAX;
}

int insere_elem(Lista list, float nota, char conceito, int key) {
    if(list == NULL || lista_cheia(list) || (key != 0 && key != 1))
        return 0;
    list->no[list->size].letra = key;
    if(key) 
        list->no[list->size].info.nota_char = conceito;
    else
        list->no[list->size].info.nota_float = nota;
    list->size++;
    return 1;
}

int remove_elem(Lista list, float nota, char conceito) {
    if(list == NULL || lista_vazia(list))
        return -1;
    if(list->no[list->size - 1].letra) {
        if(list->no[list->size - 1].info.nota_char == conceito) {
            list->size--;
            return 1;
        }
    } else if(list->no[list->size - 1].info.nota_float == nota) {
        list->size--;
        return 0;
    }
    int i, aux = 0, flag;
    while(aux < list->size) {
        if(list->no[aux].letra) {
            if(list->no[aux].info.nota_char == conceito)
                break;
        } else {
            if(list->no[aux].info.nota_float == nota)
                break;
        }
        aux++;
    }
    flag = list->no[aux].letra;
    if(aux == list->size)
        return -1;
    for(i = aux + 1; i < list->size; i++)
        list->no[i - 1] = list->no[i];
    list->size--;
    return flag;
}

int get_posicao(Lista list, int i, float* var, char* letra) {
    if(var < 0 || list == NULL || i < 0 || i > list->size - 1)
        return -1;
    if(list->no[i].letra) {
        *letra = list->no[i].info.nota_char;
        return 1;
    }
    *var = list->no[i].info.nota_float;
    return 0;
}