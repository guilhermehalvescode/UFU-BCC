#include <stdio.h>
#include <stdlib.h>

float mediaVet(char const **argumentosVetor, int argumentos) {
    int i;
    float soma = 0;
    for(i = 1; i < argumentos; i++) 
        soma += atoi(argumentosVetor[i]);
    soma /= (argumentos - 1);
    return soma;
}

int maioresMedia(char const **argumentosVetor, int argumentos, float media) {
    int i, cont = 0;
    for(i = 1; i < argumentos; i++) {
        if(atof(argumentosVetor[i]) > media)
            cont++;
    }
    return cont;
}

int main(int argc, char const *argv[]){
    int i;
    if(argc >= 17) {
        printf("A quantidade de parametros excede!!\n");
        return 0;
    }
    if(argc == 1) {
        printf("Sem parametros!!\n");
        return 0;
    }
    float media = mediaVet(argv, argc);
    printf("%d numeros e(sao) maior(es) que a media!\n", maioresMedia(argv, argc, media));
    return 0;
}
