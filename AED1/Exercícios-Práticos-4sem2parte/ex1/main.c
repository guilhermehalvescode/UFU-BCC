#include <stdio.h>
#include <stdlib.h>
#include "listadinOrd.h"

void insert_num(Lista *p) {
    int n;
    printf("Digite o numero que deseja inserir: ");
    scanf("%d", &n);
    if(insere_ord(p, n)) 
        printf("\nElemento adicionado com sucesso!");
    else 
        printf("\nElemento nao adicionado!");
}

void remove_num(Lista *p) {
    int n;
    printf("Digite o numero que deseja remover: ");
    scanf("%d", &n);
    if(remove_ord(p, n)) 
        printf("\nElemento removido com sucesso!");
    else 
        printf("\nElemento nao removido!");
}

void rmv_pos(Lista *p) {
    int i, n;
    printf("Digite a posicao do numero que deseja remover: ");
    scanf("%d", &i);
    if(remove_pos(p, i - 1, &n)) 
        printf("\nElemento %d removido com sucesso!", n);
    else 
        printf("\nElemento nao removido!");
}

void print_nums(Lista p) {
    int i = 0;
    int num;
    printf("\n-----IMPRIMINDO NUMEROS-----");
    while(get_pos(p, i, &num)) {
        printf("\n%do Numero : %d", i + 1, num);
        i++;
    }
}

int main() {
    Lista numeros;
    numeros = inicializar_lista();
    int escolha;
    do {
        printf("\n------LISTA DE NUMEROS-------\n");
        printf("(1) Inserir numero na lista\n(2) Remover numero da lista\n(3) Remover elemento por sua posicao na lista\n(4) Imprimir lista\nDigite a sua escolha: ");
        scanf("%d", &escolha);
        printf("\n");
        switch(escolha) {
            case 1:
                insert_num(&numeros);
                break;
            case 2:
                remove_num(&numeros);
                break;
            case 3:
                rmv_pos(&numeros);
                break;
            case 4:
                print_nums(numeros);
                break;
            default:
                printf("Saindo do programa...");
                break;
        }
    } while(escolha > 0 && escolha < 5);
    return 0;
}
