#include <stdio.h>
#include <stdlib.h>
#include "esfera.h"

int main() {
    esfera *esf;
    double x1, y1, z1, x2, y2, z2;
    printf("Digite (x, y, z) do centro do raio: ");
    scanf("%lf %lf %lf", &x1, &y1, &z1);
    printf("Digite (x, y, z) de um ponto da extremidade: ");
    scanf("%lf %lf %lf", &x2, &y2, &z2);
    esf = cria_esfera(x1, y1, z1, x2, y2, z2);
    if(esf == NULL) {
        printf("\nErro na criacao da esfera!!");
        exit(1);
    }
    double r = raio(esf);
    printf("\nO tamanho do raio e: %.2lf", r);
    printf("\nA area da esfera e: %.2lf", area(r));
    printf("\nO volume da esfera e: %.2lf", volume(r));
    libera_esfera(&esf);
    return 0;
}
