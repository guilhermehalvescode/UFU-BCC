#include <stdio.h>
#include "ponto.h"

int main(){
    Ponto *point1, *point2;
    double x, y, z;
    printf("Digite as coordenadas do ponto 1!\n");
    printf("Digite x, y e z: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    point1 = Cria_pto(x, y, z);
    printf("\nDigite as coordenadas do ponto 2!\n");
    printf("Digite x, y e z: ");
    scanf("%lf %lf %lf", &x, &y, &z);
    point2 = Cria_pto(x, y, z);
    printf("\nA distancia entre esses dois pontos e: %.3lf", Distancia_pto(point1, point2));
    Libera_pto(&point1);
    Libera_pto(&point2);
    return 0;
}
