#include <stdio.h>
#include <stdlib.h>

void ordena(int *v, int *tam, int num) {
    int i = 0, j = 0;
    for (i = 0; i < *tam; i++) { 
        if(num < v[i]) {
            for(j = (*tam); j > i; j--) 
                v[j] = v[j - 1];    
            break;
        }
    }
    v[i] = num;
    (*tam)++;
}

void printa(int *v, int tam) {
    int i;
    printf("\n-------------VETOR ORDENADO-------------\n");
    for(i = 0; i < tam; i++) {
        printf(" [%d]", v[i]);
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Parametro de entrada main errado!");
        return 0;
    }
    int tam = atoi(argv[1]);
    if (tam > 30)
    {
        printf("Não é permitido maior que 30 numeros!");
        return 0;
    }
    int vetor[30], num, ordenaTam = 0, i;
    for (i = 0; i < tam; i++) {
        printf("\nDigite o numero para ordena-lo no vetor: ");
        scanf("%d", &num);
        ordena(vetor, &ordenaTam, num);
    }
    printa(vetor, tam);
    return 0;
}