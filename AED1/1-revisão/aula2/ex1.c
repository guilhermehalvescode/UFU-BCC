#include <stdio.h>

double elevado(int a, int b) {
    int i;
    double res = 1;
    for(i = 0; i < b; i++) 
        res = res * a;
    
    return res;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("\n%.0lf", elevado(a, b));
    return 0;
}