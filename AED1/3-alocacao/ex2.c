#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* alocaStr(int n) {
    char *temp = (char*) malloc(n * sizeof(char));
    if(temp == NULL){
        printf("Falta de memória para alocacao!!");
        exit(1);
    }
    return temp;
}

void printa(char *str, int n) {
    int i;
    printf("A string digitada sem as vogais e: ");
    for(i = 0; i < n; i++) {
        if(tolower(str[i]) != 'a' && tolower(str[i]) != 'e' && tolower(str[i]) != 'i' && tolower(str[i]) != 'o' && tolower(str[i]) != 'u') {
            printf("%c", str[i]);
        }
    }
}

int main() {
    int n;
    printf("Digite N: ");
    scanf("%d", &n);
    char *str = alocaStr(n);
    setbuf(stdin, NULL);
    printf("Digite a string: ");
    scanf("%[^\n]", str);
    printa(str, strlen(str));
    free(str);
    return 0;
}