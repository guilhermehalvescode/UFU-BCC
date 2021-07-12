#include <stdio.h>
#include <stdlib.h>

void errorHandler(const char* message) {
  printf("%s\n", message);
  int c = getchar();
  exit(1);
}

void processFile(FILE* file, const char* outputName) {
  FILE *arq = fopen(outputName, "w");
  if(arq == NULL) errorHandler("Erro na abertura do arquivo!");
  //Colocando no final do arquivo
  fseek(file, 0, SEEK_END);
  char c;
  int first = 1;
  while(1) {
    if(first) {
      fseek(file, -1, SEEK_CUR) != 0;
      first = 0;
    } else if (fseek(file, -2, SEEK_CUR) != 0) break;
    c = fgetc(file);
    fputc(c, arq);
  }
  fclose(arq);
}

int main() {
  char arqs[2][50], caracter;
  printf("Digite o nome do arquivo de entrada: ");
  scanf("%[^\n]", arqs[0]);
  setbuf(stdin, NULL);
  FILE *arq = fopen(arqs[0], "r");
  if(arq == NULL) errorHandler("Erro na abertura do arquivo!");
  printf("Digite o nome do arquivo de saida: ");
  scanf("%[^\n]", arqs[1]);
  processFile(arq, arqs[1]);
  fclose(arq);
}