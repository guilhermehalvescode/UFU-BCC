#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define MAX_BRIDGES 100
int main() {
  int v, queries, i;
  int op, a, b;
  scanf("%d %d", &v, &queries);
  Graph* graph = createGraph(v, MAX_BRIDGES, 0);
  if(graph == NULL) return 0;
  for(i = 0; i < queries; i++) {
    scanf("%d %d %d", &op, &a, &b);
    if(op == 0) {
      if(hasVertex(graph, a-1, b-1)) 
        printf("1\n");
      else 
        printf("0\n");
    } else {
      insertVertex(graph, a-1, b-1, 0, 0);
      insertVertex(graph, b-1, a-1, 0, 0);
    }
  }
  freeGraph(graph);
  return 0;
}