#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"

int main(){
    complex *c1, *c2, *c3;
    double real, imag;

    printf("Digite a parte real do numero complexo 1: ");
    scanf("%lf", &real);
    printf("Digite a parte imaginaria do numero complexo 1: ");
    scanf("%lf", &imag);
    printf("\n");
    c1 = cria_nro(real, imag);
    if(c1 == NULL) {
        printf("\nErro na criacao do numero!!");
        exit(1);
    }
    printf("Digite a parte real do numero complexo 2: ");
    scanf("%lf", &real);
    printf("Digite a parte imaginaria do numero complexo 2: ");
    scanf("%lf", &imag);
    printf("\n");
    c2 = cria_nro(real, imag);
    if(c2 == NULL) {
        printf("\nErro na criacao do numero!!");
        exit(1);
    }
    printf("Digite a parte real do numero complexo 3: ");
    scanf("%lf", &real);
    printf("Digite a parte imaginaria do numero complexo 3: ");
    scanf("%lf", &imag);
    printf("\n");
    c3 = cria_nro(real, imag);
    if(c3 == NULL) {
        printf("\nErro na criacao do numero!!");
        exit(1);
    }

    complex* res = mult(sub(c1, c3),c2);
    if(res == NULL) {
        printf("\nErro na conta!!");
        exit(1);
    }
    if(get_complex(res, &real, &imag)) {
        printf("\nO resultado e: %.2lf + (%.2lf)i", real, imag);
    } else {
        printf("\nErro ao pegar os valores do numero complexo!");
    }
    libera_nro(&c1);
    libera_nro(&c2);
    libera_nro(&c3);
    return 0;
}
