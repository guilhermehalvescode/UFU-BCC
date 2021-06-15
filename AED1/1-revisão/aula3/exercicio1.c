#include <stdio.h>
#include <string.h>


typedef struct informacoes {
    char nome[100], tipo[8];
    short ddd;
    double telefone;
} cadastro;

int lerCliente(cadastro* p, int i) {
    char temp[100];
    printf("\n-----------Cliente %d-----------", i + 1);
    printf("\nDigite o nome do cliente %d: ", i + 1);
    if(i != 0) setbuf(stdin, NULL);
    scanf("%[^\n]", temp);
    if(!strcmp(temp, "ACABOU"))
        return 0;
    strcpy(p[i].nome, temp);
    
    printf("\nDigite o DDD do cliente %d: ", i + 1);
    scanf("%d", &p[i].ddd);

    printf("\nDigite o telefone do cliente %d: ", i + 1);
    scanf("%lf", &p[i].telefone);

    printf("\nDigite o tipo do telefone do cliente %d: ", i + 1);
    setbuf(stdin, NULL);
    scanf("%[^\n]", p[i].tipo);
    return 1;
}

void printarClientes(cadastro* p, int n) {
    int i;
    printf("\n-----------CLIENTES-----------");
    for(i = 0; i < n; i++) {
        printf("\nNome do cliente[%d]: %s", i + 1, p[i].nome);
        printf("\nDDD do cliente[%d]: %d", i + 1, p[i].ddd);
        printf("\nTelefone do cliente[%d]: %.0lf", i + 1, p[i].telefone);
        printf("\nTipo do telefone do cliente[%d]: %s", i + 1, p[i].tipo);
    }
}

int main() {
    cadastro pessoas[20];
    int i;
    for(i = 0; i < 20; i++) {
        if(!lerCliente(pessoas, i)) break;
    }
    printarClientes(pessoas, i);
    return 0;
}