#include <stdio.h>
#include <stdlib.h>
#include "listaestOrd.h"

void insert_bebida(Lista p) {
    char nome[11];
    int volume;
    float preco;
    printf("Digite o nome da bebida que deseja inserir: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", nome);
    printf("Digite o volume da bebida que deseja inserir: (ml) ");
    scanf("%d", &volume);
    printf("Digite o preco da bebida que deseja inserir: ");
    scanf("%f", &preco);
    if(insere_ord(p, nome, volume, preco)) 
        printf("\nElemento adicionado com sucesso!");
    else 
        printf("\nElemento nao adicionado!");
}

void remove_bebida(Lista p) {
    char nome[11];
    printf("Digite a nome da bebida que deseja remover: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", nome);
    if(remove_ord(p, nome)) 
        printf("\nElemento removido com sucesso!");
    else 
        printf("\nElemento nao removido!");
}

void print_bebidas(Lista p) {
    char nome[11];
    int i = 0, volume;
    float preco;
    printf("\n-----IMPRIMINDO BEBIDAS-----");
    while(get_pos(p, i, nome, &volume, &preco)) {
        printf("\nBEBIDA %d", i + 1);
        printf("\nNome da bebida: %s", nome);
        printf("\nVolume da bebida: %d", volume);
        printf("\nNome da bebida: %.2f", preco);
        i++;
    }
}

int main() {
    Lista bebidas;
    bebidas = inicializar_lista();
    if(bebidas == NULL) {
        printf("Erro na inicializacao da lista!!");
        exit(1);
    }
    int escolha;
    do {
        printf("\n------LISTA DE BEBIDAS-------\n");
        printf("(1) Inserir bebida na lista\n(2) Remover bebida da lista\n(3) Imprimir lista\nDigite a sua escolha: ");
        scanf("%d", &escolha);
        printf("\n");
        switch(escolha) {
            case 1:
                insert_bebida(bebidas);
                break;
            case 2:
                remove_bebida(bebidas);
                break;
            case 3:
                print_bebidas(bebidas);
                break;
            default:
                printf("Saindo do programa...");
                break;
        }
    } while(escolha > 0 && escolha < 4);
    return 0;
}
