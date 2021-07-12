#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include ".\headers\fila.h"
#define qnt_boxes 5

int read_int();

void inserir(Fila *boxes, Fila fila_espera);
void remover(Fila *boxes, Fila fila_espera);
void imprimir(Fila *boxes, Fila fila_espera);
void clean_buffer();

int main(){

    int sair = 0, fila_criada = 0;
    Fila boxes[qnt_boxes];
    Fila fila_espera;

    while (sair != 1) {
        int op = 0;

        printf("\n\n[1] Inicializar estacionamento");
        printf("\n[2] Entrada de veiculo");
        printf("\n[3] Saida de veiculo");
        printf("\n[4] Visualizacao do cenario");
        printf("\n[5] Sair\n");
        scanf("%d", &op);
        clean_buffer();

        switch (op) {
            case 1:
                if (fila_criada)
                    printf("Estacionamento ja esta inicializado!");
                else {
                    for (size_t i = 0; i < qnt_boxes; i++) {
                        boxes[i] = cria_fila();
                        if (boxes[i] == NULL) {
                            printf("Erro ao inicilizar!!");
                            return -1;
                        }
                    }
                    
                    fila_espera = cria_fila();
                    if (fila_espera == NULL) {
                        printf("Erro ao inicilizar!!");
                        return -1;
                    }

                    fila_criada = 1;
                    printf("Estacionamento inicializado!");
                }
                break;
            case 2:
                if (!fila_criada)
                    printf("Nao ha estacionamento inicializado!");
                else
                    inserir(boxes, fila_espera);
                break;
            case 3:
                if (!fila_criada) {
                    printf("Nao ha estacionamento inicializado!");
                    break;
                } else
                    remover(boxes, fila_espera);
                break;
            case 4:
                if (!fila_criada)
                    printf("Nao ha estacionamento inicializado!");
                else
                    imprimir(boxes, fila_espera);
                break;
            case 5:
                sair = 1;
                break;
            default:
                printf("Opcao invalida!");
                break;
        }

        if (!sair) {
            printf("\n");
            system("pause");
            system("cls");
        }

    };

    return 0;
}

// ==== Funções do programa aplicativo ==== //

//Inserir
void inserir(Fila *boxes, Fila fila_espera){
    char placa[9];
    printf("Qual a placa do veiculo que deseja dar entrada: ");
        scanf(" %8[^\n]", placa);
        clean_buffer();

        size_t box = 0, menor = tamanho(boxes[0]);
        for (size_t i = 1; i < qnt_boxes; i++) {
            if (tamanho(boxes[i]) < menor) {
                menor = tamanho(boxes[i]);
                box = i;
            }
        }

        if (menor == max) {
            if (!insere_fim(fila_espera, placa))
                printf("Estacionamento cheio!");
            else
                printf("Boxes cheios! Veiculo esta na lista de espera!");
        } else {
            insere_fim(boxes[box], placa);
            printf("Veiculo inserido no box %d", box+1);
        }
}

//Remover
void remover(Fila *boxes, Fila fila_espera){
    char placa[9], remover[9];
    printf("Insira a placa do veiculo que deseja remover: ");
    scanf(" %8[^\n]", remover);
    clean_buffer();
    
    strcpy(placa, "\0");
    // Percorrer a lista de espera em busca do veiculo
    if (tamanho(fila_espera) > 0) {
        for (size_t i = 0; i < tamanho(fila_espera); i++) {
            remove_ini(fila_espera, placa);
            if (strcmp(remover, placa) == 0) {
                printf("Veiculo de placa %s foi removido do estacionamento. Estava na fila de espera.", placa);
                return;
            }
            insere_fim(fila_espera, placa);
        }
    }

    for (size_t i = 0; i < qnt_boxes; i++) {
        for (size_t j = 0; j < tamanho(boxes[i]); j++) {
            remove_ini(boxes[i], placa);
            if (strcmp(remover, placa) == 0) {
                printf("Veiculo de placa %s foi removido do estacionamento. Estava no box %d.", placa, i+1);
                if (tamanho(fila_espera) > 0) {
                    remove_ini(fila_espera, placa);
                    insere_fim(boxes[i], placa);
                    printf("\nVeiculo %s foi removido da fila de espera e colocado no box %d.", placa, i+1);
                }
                return;
            }
            insere_fim(boxes[i], placa);
        }
    }

    printf("Veiculo de placa %s nao esta no estacionamento!", remover);
}

//Imprimir
void imprimir(Fila *boxes, Fila fila_espera){
    char placa[9];

    for (size_t i = 0; i < qnt_boxes; i++) {
        if (fila_vazia(boxes[i]))
            printf("\nBOX %d esta vazio!", i+1);
        else {
            printf("\n   BOX 0%d   ", i+1);
            for (size_t j = 0; j < tamanho(boxes[i]); j++) {
                remove_ini(boxes[i], placa);
                printf("\n| %-8s |", placa);
                insere_fim(boxes[i], placa);
            }
            
        }
    }

    if (fila_vazia(fila_espera))
            printf("\nNao ha carros na fila de espera!");
    else {
        printf("\nFila de espera:");
        for (size_t j = 0; j < tamanho(fila_espera); j++) {
            remove_ini(fila_espera, placa);
            printf("\n| %-8s |", placa);
            insere_fim(fila_espera, placa);
        }
    }
}

//Função para limpar buffer (fflush causa UB)
void clean_buffer(){
    int c;
    while((c = getchar()) != EOF && c != '\n');
}
