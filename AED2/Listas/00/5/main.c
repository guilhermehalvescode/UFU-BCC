#include <stdio.h>
#include <stdlib.h>


void errorHandler(const char* message) {
  printf("%s\n", message);
  int c = getchar();
  exit(1);
}

int countArqCharacters(FILE *file, char caracter) {
  int count = 0;
  char c;
  while (1) {
    c = fgetc(file);
    if(feof(file)) break;
    if(c == caracter) count++;
  }
  return count;
}


int main() {
  char nomeArq[50], caracter;
  printf("Digite o nome do arquivo: ");
  scanf("%[^\n]", nomeArq);
  FILE *arq = fopen(nomeArq, "r");
  if(arq == NULL) errorHandler("Erro na abertura do arquivo!");
  printf("Digite a letra: ");
  setbuf(stdin, NULL);
  scanf("%c", &caracter);
  printf("Caracter (%c) aparece %d veze(s) no arquivo %s!\n", caracter, countArqCharacters(arq, caracter), nomeArq);
  fclose(arq);
  return 0;
}