#include <stdio.h>
#include <stdlib.h>

void errorHandler(const char* message) {
  printf("%s\n", message);
  int c = getchar();
  exit(1);
}

int main() {
  FILE *arq = fopen("compra.txt", "r");
  if (arq == NULL) errorHandler("Erro ao abrir o arquivo!");
  char name[50];
  int qnt;
  float price, tot = 0;
  while(1) {
    fscanf(arq, "%s %d %f", name, &qnt, &price);
    if(feof(arq)) break;
    tot += price * qnt;
  }
  fclose(arq);
  printf("Total: %.2f\n", tot);
  return 0;
}