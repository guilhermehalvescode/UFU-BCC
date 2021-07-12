#include <stdio.h>
#include <stdlib.h>

void errorHandler(const char* message) {
  printf("%s", message);
  int c = getchar();
  exit(1);
}

int main() {
  FILE *p = fopen("matriz.txt", "r");
  if(p == NULL) errorHandler("Erro na leitura do arquivo!");
  int linhas, colunas, quantPos, i, j;
  fscanf(p, "%d %d %d", &linhas, &colunas, &quantPos);
  int **mat = (int **) malloc(linhas * sizeof(int*));

  if(mat == NULL) errorHandler("Erro na alocacao!");

  for(i = 0; i < colunas; i++) {
    mat[i] = (int *) malloc(sizeof(int));
    if(mat[i] == NULL) errorHandler("Erro na alocacao");
  }

  for(i = 0; i < linhas; i++) {
    for(j = 0; j < colunas; j++) {
      mat[i][j] = 1;
    }
  }
  
  int a, b;
  for(i = 0; i < quantPos; i++) {
    fscanf(p, "%d %d", &a, &b);
    printf("%d %d\n", a, b);
    mat[a][b] = 0;
  }

  fclose(p);
  p = fopen("matriz_saida.txt", "w");
  if(p == NULL) errorHandler("Erro na leitura do arquivo!");


  for(i = 0; i < linhas; i++) {
    for(j = 0; j < colunas; j++) {
      fprintf(p, "%d ", mat[i][j]);
    }
    fprintf(p, "\n");
  }

  fclose(p);
  return 0;
}