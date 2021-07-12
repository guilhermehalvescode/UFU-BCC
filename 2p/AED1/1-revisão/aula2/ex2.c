#include <stdio.h>

int verificar(int n) {
    return (1 * (n > 0)) + (-1 * (n < 0)) + (0 * (n == 0)); 
}
int main() {
    int num; 
    scanf("%d", &num);
    printf("\nRetorno: %d", verificar(num));
    return 0;
}