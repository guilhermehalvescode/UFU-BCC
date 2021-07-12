#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct graph {
  int weighted;
  int n_vertex;
  int max_degree;
  int** vertexes;
  float** weights;
  int* degrees;
};

Graph* createGraph(int qntVertexes, int max_degree, int isWeigheted) {
  Graph* gr = (Graph*) malloc(sizeof(struct graph));
  if(gr == NULL) return NULL;
  int i;
  gr->n_vertex = qntVertexes;
  gr->max_degree = max_degree;
  gr->weighted = (isWeigheted != 0) ? 1 : 0;
  gr->degrees = calloc(qntVertexes, sizeof(int));
  gr->vertexes = (int **) malloc(qntVertexes * sizeof (int *));
  for(i = 0; i < qntVertexes; i++) {
    gr->vertexes[i] = (int *) malloc(max_degree * sizeof(int));
  }
  if(gr->weighted) {
    gr->weights = (float **) malloc(qntVertexes * sizeof(float *));
    for(i = 0; i < qntVertexes; i++) {
      gr->weights[i] = (float*) malloc(max_degree * sizeof(float));
    }
  }
  return gr;
}

void freeGraph(Graph* gr) {
  if(gr == NULL) return;
  int i;
  for(i = 0; i < gr->n_vertex; i++) {
    free(gr->vertexes[i]);
  }
  free(gr->vertexes);
  if(gr->weighted) {
    for(i = 0; i < gr->n_vertex; i++) {
      free(gr->weights[i]);
    }
    free(gr->weights);
  }
  free(gr->degrees);
  free(gr);
}

int insertVertex(Graph* gr, int orig, int dest, int digraph, float weight) {
  if(gr == NULL) return 0;
  if(orig < 0 || orig >= gr->n_vertex) return 0;
  if(dest < 0 || dest >= gr->n_vertex) return 0;

  gr->vertexes[orig][gr->degrees[orig]] = dest;
  if(gr->weighted) 
    gr->weights[orig][gr->degrees[orig]] = weight;
  gr->degrees[orig]++;

  if(digraph == 0) 
    insertVertex(gr, dest, orig, 1, weight);

  return 1;
}

int hasVertex(Graph* gr, int orig, int dest) {
  if(gr == NULL) return 0;
  if(orig < 0 || orig >= gr->n_vertex) return 0;
  if(dest < 0 || dest >= gr->n_vertex) return 0;
  int i;
  for(i = 0; i < gr->degrees[orig]; i++) {
    if(gr->vertexes[orig][i] == dest) {
      return 1;
    }
  }
  return 0;
}