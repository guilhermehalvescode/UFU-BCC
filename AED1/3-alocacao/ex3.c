#include <stdio.h>
#include <stdlib.h>
 
int** alocaMat(int n) {
    int i = 0, **mat;
    mat = (int**) malloc(n * sizeof(int*));
    if(mat == NULL) {
        printf("Erro na alocacao!!");
        exit(1);
    }
    for(i = 0; i < n; i++) {
        mat[i] = (int*) malloc(n * sizeof(int));
        if(mat[i] == NULL) {
            printf("Erro na alocacao!!");
            exit(1);
        }
    }
    return mat;
}
 
void lerMat(int **m, int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("Digite mat[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}
 
void imprimir(int **m, int n) {
    int i, j;
    printf("Elementos acima da diagonal principal: ");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(!(j < i)) {
                if(j != 0) printf(" ");
                printf("[%d]", m[i][j]);
            }
        }
    }
}
 
void liberaMat(int **m, int n) {
    int i;
    for(i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
}
int main() {
    int n, **mat;
    printf("Digite N: ");
    scanf("%d", &n);
    mat = alocaMat(n);
    lerMat(mat, n);
    imprimir(mat, n);
    liberaMat(mat, n);
    return 0;
}
