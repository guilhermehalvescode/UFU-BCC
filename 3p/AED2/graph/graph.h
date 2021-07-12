typedef struct graph Graph;

Graph* createGraph(int qntVertexes, int max_degree, int isWeigheted);
void freeGraph(Graph* gr);
int insertVertex(Graph* gr, int orig, int dest, int digraph, float weight);
int hasVertex(Graph* gr, int orig, int dest);