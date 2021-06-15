#include <stdio.h>
#include <stdlib.h>
#include "simpleQueue.h"

void cria_bebidas(Queue *q) {
    if(*q != NULL) {
        printf("Fila ja esta criada!"); 
        return;
    }
    *q = cria_fila();
    if(*q == NULL) 
        printf("Nao foi possivel criar a lista!");
    else
        printf("Lista foi criada!");
}

void insert_bebida(Queue p) {
    if(p == NULL) {
        printf("----FILA NAO INICIALIZADA----\n");
        return;
    } 
    unsigned int volume;
    float preco;
    char nome[20];
    printf("Digite o nome da bebida que deseja inserir: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", nome);
    printf("Digite o volume da bebida que deseja inserir: ");
    scanf("%u", &volume);
    printf("Digite a preco da bebida que deseja inserir: ");
    scanf("%f", &preco);
    if(insere_fim(p, nome, volume, preco)) 
        printf("\nElemento adicionado com sucesso!");
    else 
        printf("\nElemento nao adicionado!");
}

void remove_bebida(Queue p) {
    if(p == NULL) {
        printf("----FILA NAO INICIALIZADA----\n");
        return;
    } 
    unsigned int volume;
    float preco;
    char nome[20];
    if(remove_ini(p, nome, &volume, &preco)) 
        printf("[{%s, %u, %.2f}] removido com sucesso!", nome, volume, preco);
    else 
        printf("Elemento nao removido!");
}

void print_bebidas(Queue p) {
    if(p == NULL) {
        printf("----FILA NAO INICIALIZADA----\n");
        return;
    } 
    if(fila_vazia(p)) {
        printf("----FILA VAZIA----");
        return;
    }
    unsigned int volume;
    float preco;
    char nome[20];
    Queue temp = cria_fila(); 
    if(temp == NULL) {
        printf("Nao foi possivel imprimir!");
        return;
    }
    printf("----FILA----\n");
    int i = 0;
    while(remove_ini(p, nome, &volume, &preco)) {
        if(i != 0) printf(" ");
        printf("[{%s, %u, %.2f}]", nome, volume, preco);
        insere_fim(temp, nome, volume, preco);
        i++;
    }
    printf("\n");
    while(remove_ini(temp, nome, &volume, &preco)) 
        insere_fim(p, nome, volume, preco);
    apaga_fila(&temp);
}

int main() {
    Queue bebidas = NULL;
    int escolha;
    do {
        printf("\n------FILA DE BEBIDAS-------\n");
        printf("(1) Cria fila\n(2) Inserir bebida na fila\n(3) Remover bebida da fila\n(4) Imprimir fila\n(5) Apagar fila\n(6) Esvaziar fila\nDigite a sua escolha: ");
        scanf("%d", &escolha);
        printf("\n");
        switch(escolha) {
            case 1:
                cria_bebidas(&bebidas);
                break;
            case 2:
                insert_bebida(bebidas);
                break;
            case 3:
                remove_bebida(bebidas);
                break;
            case 4:
                print_bebidas(bebidas);
                break;
            case 5:
                if(bebidas == NULL) 
                    printf("----FILA NAO INICIALIZADA----\n");
                else {
                    apaga_fila(&bebidas);
                    printf("Fila apagada!");
                }
                break;
            case 6:
                if(bebidas == NULL) 
                    printf("----FILA NAO INICIALIZADA----\n");
                else {
                    esvazia_fila(bebidas);
                    printf("Fila esvaziada!");
                }
                break;
            default:
                printf("Saindo do programa...");
                break;
        }
    } while(escolha > 0 && escolha < 7);
    return 0;
}
