#include <stdio.h>
#include <stdlib.h>

int main() {
  int *v = NULL, n, i;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  
  v = (int*) malloc(n * sizeof(int));
  if(v == NULL) return 1;
  
  for(i = 0; i < n; i++) {
    printf("\nDigite o valor da posicao %d: ", (i + 1));
    scanf("%d", (v + i));

    if(i > 0 && v[i - 1] > v[i]) {
      printf("\nNAO ORDENADO");
      return 0;
    }
  }
  printf("\nORDENADO\n");
  return 0;
}
