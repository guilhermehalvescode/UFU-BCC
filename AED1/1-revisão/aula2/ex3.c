#include <stdio.h>
#include <math.h>

int quadPerfeito(int n) {
    double raiz = sqrt(n);
    double quadrado = pow(raiz, 2);
    if(quadrado == n) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("\nResposta: %s", quadPerfeito(n) ? "E quadrado perfeito" : "Nao e quadrado perfeito");    
    return 0;
}