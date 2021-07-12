#include <stdio.h>
#include "ponto.h"

int main(){
    Ponto *point1, *point2;
    double x, y;
    printf("Digite as coordenadas do ponto 1!\n");
    printf("Digite x e y: ");
    scanf("%lf %lf", &x, &y);
    point1 = Cria_pto(x, y);
    printf("\nDigite as coordenadas do ponto 2!\n");
    printf("Digite x e y: ");
    scanf("%lf %lf", &x, &y);
    point2 = Cria_pto(x, y);
    printf("\nA distancia entre esses dois pontos e: %.3lf", Distancia_pto(point1, point2));
    Libera_pto(&point1);
    Libera_pto(&point2);
    return 0;
}