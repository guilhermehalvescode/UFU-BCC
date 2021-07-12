#include "../../graph.h"

struct graph {
  int weighted;
  int n_vertex;
  int max_degree;
  int** vertexes;
  float** weights;
  int* degrees;
};

void prim(Graph *gr, int orig, int *pai) {
  int i, j, dest, primeiro, NV = gr->n_vertex;
  double menorPeso;
  for(i = 0; i < NV; i++) {
    pai[i] = -1;
  }
  pai[orig] = orig;
  while(1) {
    primeiro = 1;
    //Search is O(n³) complexity, priority queues reduces to O(A log V)
    for(i = 0; i < NV; i++) {
      if(pai[i] != -1) {
        for(j = 0; j < gr->max_degree[i]; j++) {
          if(pai[gr->vertexes[i][j] == -1) {
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
    }
    if(primeiro == 1) break;
    pai[dest] = orig;
  }
}