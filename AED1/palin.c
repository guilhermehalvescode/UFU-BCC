#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "PILHA.h"

int letra(char letra) {
    return (letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z');
}

int palindrome(char* palavra) { 
    Pilha pil = cria_pilha();
    if(pil == NULL) {
        printf("Erro na pilha!!");
        return 0;
    }
    int i, tam = strlen(palavra);
    char* temp = (char*) malloc(sizeof(char) * tam);
    if(temp == NULL) {
        printf("Erro na temp!!");
        return 0;
    }
    for(i = 0; i < tam; i++) {
        if(letra(palavra[i])) {
            if(!push(pil, palavra[i])) {
                printf("Erro no push!!");
                return 0;
            }
        }
    }
    char carac;
    i = 0;
    while(pop(pil, &carac)) {
        temp[i] = carac;
        i++;
    }
    if(strcmp(temp, palavra)) {
        free(temp);
        return 0;
    }

    return 1;
}