#include <stdio.h>
#include <stdlib.h>
#define K 100
void bubbleSort(int *v, int n) {
  int i, j, aux, cont;
  for(i = 0; cont != 0; i++, n--) {
    for(j = 0, cont = 0; j < n - 1; j++) {
      if(v[j] < v[j + 1]) {
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
        cont = 1;
      }
    }
  }
  return;
}

void selectionSort(int *v, int n) {
  int i, j, maior, troca;
  for(i = 0; i < n - 1; i++) {
    maior = i;
    for(j = i + 1; j < n; j++) {
      if(v[j] > v[maior])
        maior = j;
    }
    if(maior != i) {
      troca = v[maior];
      v[maior] = v[i];
      v[i] = troca;
    }
  }
}

void insertionSort(int *v, int n) {
  int i, j, aux;
  for(i = 1; i < n; i++) {
    aux = v[i];
    for(j = i; j > 0 && aux < v[j - 1]; j--) {
      v[j] = v[j - 1];
    }
    v[j] = aux;
  }
}

void merge(int *vet, int inicio, int meio, int fim) {
  int *temp, p1, p2, tamanho, i, j; 
  int fim1 = 0, fim2 = 0; 
  tamanho = fim - inicio + 1;
  p1 = inicio;
  p2 = meio + 1;
  temp = (int *) malloc (tamanho*sizeof(int));
  if(temp != NULL) {
    for(i = 0; i < tamanho; i++) {
      if(!fim1 && !fim2) {
        temp[i] = vet[p1] < vet[p2] ? vet[p1++] : vet[p2++];
        if(p1 > meio) fim1 = 1;
        if(p2 > fim) fim2 = 1;
      } else {
        temp[i] = !fim1 ? vet[p1++] : vet[p2++];
      }
    }
    for(i = 0, j = inicio; i < tamanho; i++, j++) 
      vet[j] = temp[i];
  }
  free(temp);
}

void mergeSort(int *vet, int inicio, int fim) {
  int meio;
  if(inicio < fim) {
    meio = (inicio + fim) / 2; // Calcula o meio do vetor
    mergeSort(vet, inicio, meio);
    mergeSort(vet, meio+1, fim);
    merge(vet, inicio, meio, fim);
  }
}

int getPivo(int *vet, int inicio, int fim) {
  int esq, dir, pivo, aux;
  esq = inicio;
  dir = fim;
  pivo = vet[inicio];
  while(esq < dir) {
    while(esq <= fim && vet[esq] <= pivo) 
      esq++;

    while(dir >= 0 && vet[dir] > pivo) 
      dir--;

    if(esq < dir) {
      aux = vet[esq];
      vet[esq] = vet[dir];
      vet[dir] = aux;
    }
  }
  vet[inicio] = vet[dir];
  vet[dir] = pivo;
  return dir;
}

void quickSort(int *vet, int inicio, int fim) {
  int pivo;
  if(inicio < fim) {
    pivo = getPivo(vet, inicio, fim);
    quickSort(vet, inicio, pivo - 1);
    quickSort(vet, pivo + 1, fim);
  }
}

void countingSort(int *vet, int n) {
  int i, j, k;
  int aux[K];
  for(i = 0; i < K; i++) {
    aux[i] = 0;
  }
  for(i = 0; i < n; i++) {
    aux[vet[i]]++;
  }
  for(i = 0, j = 0; j < K; j++) {
    for(k = aux[j]; k > 0; k--)
      vet[i++] = j;
  }
}

#define TAM 5 //tamanho do balde
struct balde {
  int qtd;
  int valores[TAM];
};

void bucketSort(int *vet, int n) {
  int i, j, maior, menor, nroBaldes, pos;
  struct balde *bd;

  maior = menor = vet[0];
  for(i = 1; i < n; i++) {
    if(vet[i] > maior) maior = vet[i];
    if(vet[i] < menor) menor = vet[i];
  }

  nroBaldes = (maior - menor) / TAM + 1;
  bd = (struct balde *) malloc(nroBaldes * sizeof(struct balde));
  for(i = 0; i < nroBaldes; i++) {
    bd[i].qtd = 0;
  }
  for(i = 0; i < n; i++) {
    pos = (vet[i] - menor) / TAM;
    bd[pos].valores[bd[pos].qtd] = vet[i];
    bd[pos].qtd++;
  }
  pos = 0;
  for(i = 0; i < nroBaldes; i++) {
    insertionSort(bd[i].valores, bd[i].qtd);
    printf("Balde %d: ", i + 1);
    for(j = 0; j < bd[i].qtd; j++) {
      vet[pos++] = bd[i].valores[j];
    }
    printf("\n");
  }
  free(bd);
}

int main() {
  int *v = NULL, n, i;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  
  v = (int*) malloc(n * sizeof(int));
  if(v == NULL) return 1;
  
  for(i = 0; i < n; i++) {
    printf("\nDigite o valor da posicao %d: ", (i + 1));
    scanf("%d", (v + i));
  }
  // bubbleSort(v, n);
  // selectionSort(v, n);
  // insertionSort(v, n);
  // mergeSort(v, 0, n - 1);
  // quickSort(v, 0, n - 1);
  // countingSort(v, n);
  bucketSort(v, n);
  for(i = 0; i < n; i++) {
    printf(" [%d]", *(v + i));
  }
  return 0;
}
