#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *vet, int n, int valor) {
  int i;
  for(i = 0; i < n; i++) {
    if(valor == vet[i]) return i;
  }
  return -1;
}


int linearOrderedSearch(int *vet, int n, int valor) {
  int i;
  for(i = 0; i < n; i++) {
    if(valor == vet[i]) {
      return i;
    } else if(valor < vet[i]){
      return -1;
    }
  }
  return -1;
}

int binarySearch(int *vet, int n, int valor) {
  int inicio = 0, meio, fim = n - 1;

  while(inicio <= fim) {
    meio = (inicio + fim)/ 2;
    if(valor == vet[meio]) {
      return meio;
    } else if(valor > vet[meio]) {
      inicio = meio + 1;
    } else {
      fim = meio - 1;
    }
    

  }
  return -1;
}


int main() {
  int v[10] = {1,5,8,10,15,20,25,58,68,70};
  int num;
  printf("Digite o valor para busca: ");
  scanf("%d", &num);
  int pos = linearOrderedSearch(v, 10, num);
  printf("A posicao encontrada foi: %d\n", pos);
  return 0;
}