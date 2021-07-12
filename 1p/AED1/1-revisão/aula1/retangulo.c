#include <stdio.h>

struct ponto {
    int x, y;
};

struct retangulo{
    struct ponto inicio, fim;
};

int absolute(int n) {
    return ((n < 0) * (n*-1)) + ((n >= 0) * n);
}

int area(struct retangulo* ret){
    if(ret->inicio.x == ret->fim.x || ret->inicio.y == ret->fim.y) 
        return 0;
    int base = absolute(ret->inicio.x - ret->fim.x); 
    int altura = absolute(ret->inicio.y - ret->fim.y); 
    return altura * base;
}

int main() {
    struct retangulo ret;
    scanf("%d %d %d %d", &ret.inicio.x, &ret.inicio.y, &ret.fim.x, &ret.fim.y);
    printf("\n%d", area(&ret));
    return 0;
}