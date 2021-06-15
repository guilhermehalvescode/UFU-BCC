#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "esfera.h"
#define pi 3.1415926

struct reta {
    Ponto *p1, *p2;
};
//procedimento para criação de esfera
esfera* cria_esfera(double x1, double y1, double z1, double x2, double y2, double z2) {
    esfera* reta;
    reta = (esfera*) malloc(sizeof(esfera));
    if(reta != NULL) {
        reta->p1 = Cria_pto(x1, y1, z1);
        reta->p2 = Cria_pto(x2, y2, z2);
    }
    return reta;
}

void libera_esfera(esfera* *reta) {
    free((*reta)->p1);
    (*reta)->p1 = NULL;
    free((*reta)->p2);
    (*reta)->p2 = NULL;
    free(*reta);
    *reta = NULL;
}

double raio(esfera *reta) {
    if(reta == NULL)
        return -1;
    double dist = Distancia_pto(reta->p1, reta->p2);
    return dist;
}

double area(double raio) {
    if(raio < 0)
        return -1;
    return 4 * pi * raio * raio;
}

double volume(double raio) {
    if(raio < 0)
        return -1;
    return (4 * pi * raio * raio * raio)/3;
}





