#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int particiona(char *str, int inicio, int fim) {
  int esq = inicio, dir = fim, aux;
  int pivo = str[inicio];
  while(esq < dir) {
    while(esq <= fim && str[esq] >= pivo) 
      esq++;
    
    while(dir >= 0 && str[dir] < pivo) 
      dir--;
    if(esq < dir) {
      aux = str[esq];
      str[esq] = str[dir];
      str[dir] = aux;
    }
  }
  str[inicio] = str[dir];
  str[dir] = pivo;
  return dir;
}

void quickSort(char *str, int inicio, int fim) {
  int pivo;
  if(inicio < fim) {
    pivo = particiona(str, inicio, fim);
    quickSort(str, inicio, pivo - 1);
    quickSort(str, pivo + 1, fim);
  }
}

int main() {
  char string[50];
  printf("Digite uma string: ");
  scanf("%[^\n]s", string);
  quickSort(string, 0, strlen(string) - 1);
  printf("\nString saída: %s", string);
  return 0;
}