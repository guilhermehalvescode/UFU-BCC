#include <stdio.h>
#include <stdlib.h>

void printarVet(int* v);
int* prodVet(int* vet1, int* vet2);
void lerVet(int* v);

int main() {
    int vet1[10], vet2[10];
    lerVet(vet1);
    lerVet(vet2);
    int* vetRes = prodVet(vet1, vet2);
    printarVet(vetRes);
    return 0;
}

int* prodVet(int* vet1, int* vet2) {
    int i, *res;
    res = (int*) malloc(10 * sizeof(int));
    for(i = 0; i < 10; i++) 
        res[i] = vet1[i] * vet2[i];
    return res;
}

void lerVet(int* v) {
    int i;
    for(i = 0; i < 10; i++) 
        scanf("%d", v + i);
}

void printarVet(int* v) {
    int i;
    for(i = 0; i < 10; i++) 
        printf(" [%d]", v[i]);
}