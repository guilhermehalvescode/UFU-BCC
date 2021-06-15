#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto{
  double x, y, z;
};

Ponto* Cria_pto(double x, double y, double z) {
  struct ponto *ponto = NULL;
  ponto = (Ponto*) malloc(sizeof(Ponto));
  if(ponto != NULL) {
    ponto->x = x;
    ponto->y = y;
    ponto->z = z;
  }
  return ponto;
}

void Libera_pto(Ponto **p) {
  free(*p);
  *p = NULL;
}

double Distancia_pto(Ponto *p1, Ponto *p2) {
  if(p1 == NULL || p2 == NULL) {
    return -1; // estou retornando -1 porque a distancia entre dois pontos pode ser 0
  }
  return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) + pow(p1->z - p2->z, 2));
}
