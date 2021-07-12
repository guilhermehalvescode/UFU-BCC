#include <stdio.h>
#include <stdlib.h>
#include "listaest.h"

void insert_string(Lista p) {
    char string[11];
    printf("Digite a string que deseja inserir: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", string);
    if(insere_elem(p, string)) 
        printf("\nElemento adicionado com sucesso!");
    else 
        printf("\nElemento nao adicionado!");
}

void remove_string(Lista p) {
    char string[11];
    printf("Digite a string que deseja remover: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", string);
    if(remove_elem(p, string)) 
        printf("\nElemento removido com sucesso!");
    else 
        printf("\nElemento nao removido!");
}

void print_strings(Lista p) {
    int i = 0;
    char string[11];
    printf("\n-----IMPRIMINDO STRINGS-----");
    while(get_pos(p, i, string)) {
        printf("\nString %d: %s", i + 1, string);
        i++;
    }
}

int main() {
    Lista strings;
    strings = inicializar_lista();
    if(strings == NULL) {
        printf("Erro na inicializacao da lista!!");
        exit(1);
    }
    int escolha;
    do {
        printf("\n------LISTA DE STRINGS-------\n");
        printf("(1) Inserir string na lista\n(2) Remover string da lista\n(3) Imprimir lista\nDigite a sua escolha: ");
        scanf("%d", &escolha);
        printf("\n");
        switch(escolha) {
            case 1:
                insert_string(strings);
                break;
            case 2:
                remove_string(strings);
                break;
            case 3:
                print_strings(strings);
                break;
            default:
                printf("Saindo do programa...");
                break;
        }
    } while(escolha > 0 && escolha < 4);
    return 0;
}
