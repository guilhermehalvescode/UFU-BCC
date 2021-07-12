#include "../../graph.h"

struct graph {
  int weighted;
  int n_vertex;
  int max_degree;
  int** vertexes;
  float** weights;
  int* degrees;
};

void kruskal(Graph *gr, int orig, int *pai) {
  int i, j, dest, primeiro, NV = gr->n_vertex;
  double menorPeso;
  int* arv = (int *) malloc(NV * sizeof(int));
  for(i = 0; i < NV; i++) {
    arv[i] = i;
    pai[i] = -1;
  }
  pai[orig] = orig;
  while(1) {
    primeiro = 1;
    //Search is O(v³) complexity, using union find reduces to O(A log V)
    for(i = 0; i < NV; i++) {
      for(j = 0; j < gr->max_degree[i]; j++) {
        //Não olha entre as mesmas árvores
        if(arv[i] != arv[gr->vertexes[i][j]) {
          if(primeiro) {
            menorPeso = gr->weights[i][j];
            orig = i;
            dest = gr->vertexes[i][j];
            primeiro = 0;
          } else if(menorPeso > gr->weights[i][j]) {
            menorPeso = gr->weights[i][j];
            orig = i;
            dest = gr->vertexes[i][j];
          }
        }
      }
    }
    if(primeiro == 1) break;
    if(pai[orig] == -1) pai[orig] = dest;
    else pai[dest] = orig;

    for(i = 0; i < NV; i++) {
      if(arv[i] == arv[dest]) {
        arv[i] = arv[orig];
      }
    }
  }
  free(arv);
}