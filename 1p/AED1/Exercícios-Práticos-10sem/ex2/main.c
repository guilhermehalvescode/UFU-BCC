#include <stdio.h>
#include <stdlib.h>
#include "void.h"

void cria_notas(Lista *q) {
    if(*q != NULL) {
        printf("Lista ja esta criada!"); 
        return;
    }
    *q = cria_lista();
    printf("Lista foi criada!");
}

void insert_nota(Lista *p) {
    int letra;
    do {
        printf("Digite (1) para conceito e (0) para nota: ");
        scanf("%d", &letra);
    }while(letra != 0 && letra != 1);
    char let = '\0'; 
    float nota = -1;
    setbuf(stdin, NULL);
    if(letra) {
        printf("Digite o conceito: ");
        scanf("%c", &let);
    } else {
        printf("Digite a nota: ");
        scanf("%f", &nota);
    }
    if(insere_elem(p, nota, let, letra)) 
        printf("\nElemento adicionado com sucesso!");
    else 
        printf("\nElemento nao adicionado!");
}

void remove_nota(Lista *p) {
    int letra;
    do {
        printf("Digite (1) para conceito e (0) para nota para remover: ");
        scanf("%d", &letra);
    } while(letra != 0 && letra != 1);
    char let = '\0'; 
    float nota = -1;
    setbuf(stdin, NULL);
    if(letra) {
        printf("Digite o conceito para remover: ");
        scanf("%c", &let);
    } else {
        printf("Digite a nota para remover: ");
        scanf("%f", &nota);
    }
    int ret = remove_elem(p, nota, let);
    if(ret == 1) 
        printf("%c removido com sucesso!", let);
    else if(ret == 0)
        printf("%.2f removido com sucesso!", nota);
    else
        printf("Elemento nao removido!");
}

void print_notas(Lista p) { 
    if(lista_vazia(p)) {
        printf("----LISTA VAZIA----");
        return;
    }
    int i = 0;
    int ret;
    char letra;
    float nota;
    printf("----LISTA----\n");
    while(1) {
        ret = obtem_posicao(p, i, &nota, &letra);
        if(ret == -1) break;
        if(i != 0) printf(" ");
        if(ret) 
            printf("[%c]", letra);
        else 
            printf("[%.2f]", nota);
        i++;
    }
    printf("\n");
}

int main() {
    Lista notas = NULL;
    int escolha;
    do {
        printf("\n------LISTA DE NOTAS-------\n");
        printf("(1) Cria lista\n(2) Inserir nota na lista\n(3) Remover nota da lista\n(4) Imprimir notas\nDigite a sua escolha: ");
        scanf("%d", &escolha);
        printf("\n");
        switch(escolha) {
            case 1:
                cria_notas(&notas);
                break;
            case 2:
                insert_nota(&notas);
                break;
            case 3:
                remove_nota(&notas);
                break;
            case 4:
                print_notas(notas);
                break;
            default:
                printf("Saindo do programa...");
                break;
        }
    } while(escolha > 0 && escolha < 5);
    return 0;
}