#include <stdio.h>

unsigned long long int fatorial(int n) {
    if (n == 0)
        return 1;
    return (n * fatorial(n - 1));
}

int formula(int m, int p) {
    if (p > m)
        return -1;
    else
        return fatorial(m) / (fatorial(p) * fatorial(m - p));
}
int main(){
    int p, m;
    printf("Digite m e p: ");
    scanf("%d %d", &m, &p);
    printf("\nO valor da combinacao e: %d", formula(m, p));
}