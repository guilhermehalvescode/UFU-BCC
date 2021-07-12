#include <stdlib.h>
#include <stdio.h>
#include "FILA.h"

int elimina_elem(Fila *q, int faltas) {
    if(*q == NULL) 
        return 0;
    if(fila_vazia(*q)) {
        printf("Fila vazia!!");
        return 0;
    }
    if(faltas < 1) {
        printf("Limite inferior a 1!!");
        return 0;
    }
    struct alunos aux;
    Fila auxiliar = cria_fila();
    int contador = 0;
    while(remover(q, &aux)) {
        if(aux.faltas > faltas){
            contador++;
            continue;
        }
        if(!insere(&auxiliar, aux)) {
            printf("Erro em inserir!!");
            return 0;
        }
    }
    while(remover(&auxiliar, &aux)) {
        if(insere(q, aux)) {
            printf("Erro em inserir!!");
            return 0;
        }
    }
    
    printf("\nForam removidos %d alunos", contador);
    return 1;
}