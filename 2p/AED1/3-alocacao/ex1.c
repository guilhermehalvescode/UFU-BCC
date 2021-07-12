#include <stdio.h>
#include <stdlib.h>

void lerVet(int *vet, int n) {
    int i;
    for (i = 0; i < n; i++){
        printf("Digite vet[%d]: ", i + 1);
        scanf("%d", vet + i);
    }
}
void printa(int *vet, int n) {
    int i, soma = 0;
    printf("Vetor: ");
    for (i = 0; i < n; i++){
        if(i != 0) printf(" ");
        printf("[%d]", vet[i]);
        if(vet[i] % 2 != 0) 
            soma += vet[i];
    }
    printf("\n");
    printf("Soma dos valores impares: %d", soma);
}

int main() {
    int i, n, *vet;
    printf("Digite N: ");
    scanf("%d", &n);
    vet = (int*) malloc(n * sizeof(int));
    if(vet == NULL) {
        printf("Sem memoria para alocacao!!");
        exit(1);
    }
    printf("\n");
    lerVet(vet, n);
    printa(vet, n);
    free(vet);
    return 0;
}