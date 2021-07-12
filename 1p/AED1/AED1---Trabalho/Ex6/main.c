#include <stdio.h>
#include <stdlib.h>
#include ".\headers\lista.h"

//Lê todos os caracteres presentes no STDIN
void clean_buffer(){
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n');
}

int main(){

    int sair = 0;
    int pos, ch;
    int elem;
    Lista listas[2];
    listas[0] = criar_lista(); //Lista 1
    listas[1] = criar_lista(); //Lista 2

    while (sair != 1) {
        int op = 0;
        printf("\n\n[1] Imprimir lista");
        printf("\n[2] Inserir elemento");
        printf("\n[3] Remover elemento");
        printf("\n[4] Tamanho da lista");
        printf("\n[5] Remover todas as ocorrencias de um elemento");
        printf("\n[6] Remover o maior elemento da lista");
        printf("\n[7] Esvaziar lista");
        printf("\n[8] Inverter lista 1");
        printf("\n[9] Inserir multiplos de 3 da lista 1 na lista 2");
        printf("\n[10] Sair\n");
        scanf("%d", &op);
        clean_buffer();

        switch (op) {
            int lista, ind, removidos;
            //Imprimir lista
            case 1:
                system("cls");
                printf("Qual lista deseja imprimir (1 ou 2): ");
                do {
                    scanf(" %d", &lista);
                    clean_buffer();
                    if (lista != 1 && lista != 2)
                        printf("Insira um valor valido (1 ou 2): ");
                    
                } while (lista != 1 && lista != 2);
                ind = lista-1;

                if (lista_vazia(listas[ind]) == 1) {
                    printf("A lista esta vazia!!");
                } else {
                    printf("Lista %d: [", lista);
                    size_t pos = 0;
                    while (obtem_valor(&listas[ind], &elem, pos) == 1) {
                        printf(" %d ", elem);
                        pos++;
                    }
                    printf("]");
                }
                break;
            //Inserir elemento
            case 2:
                system("cls");
                printf("SO E POSSIVEL INSERIR ELEMENTOS NA LISTA 1");
                printf("\nQual o elemento que deseja inserir: ");
                scanf(" %d", &elem);
                if(insere_elem(&listas[0], elem) == 0)
                    printf("Nao foi possivel inserir o elemento!");
                else
                    printf("Elemento inserido!");
                break;
            //Remover elemento
            case 3:
                system("cls");
                printf("Em qual lista deseja REMOVER um elemento (1 ou 2): ");
                do {
                    scanf(" %d", &lista);
                    clean_buffer();
                    if (lista != 1 && lista != 2)
                        printf("Insira um valor valido (1 ou 2): ");
                    
                } while (lista != 1 && lista != 2);
                ind = lista-1;

                printf("Qual elemento deseja remover: ");
                scanf(" %d", &elem);
                if (remove_elem(&listas[ind], elem) == 0)
                    printf("Falha ao remover elemento. Ele pode nao estar na lista!!");
                else
                    printf("Elemento removido!");
                
                break;
            //Tamanho da lista
            case 4:
                system("cls");
                printf("De qual lista deseja saber o tamanho (1 ou 2): ");
                do {
                    scanf(" %d", &lista);
                    clean_buffer();
                    if (lista != 1 && lista != 2)
                        printf("Insira um valor valido (1 ou 2): ");
                    
                } while (lista != 1&& lista != 2);
                ind = lista-1;

                int tam = tamanho_lista(&listas[ind]);
                if ((tam) == 0)
                    printf("A lista esta vazia!");
                else
                    printf("A lista %d tem %d elementos.", lista, tam);
                break;
            //Remove todos as ocorrências de um elemento na lista
            case 5:
                system("cls");
                printf("Em qual lista deseja REMOVER TODAS as ocorrencias de um elemento (1 ou 2): ");
                do {
                    scanf(" %d", &lista);
                    clean_buffer();
                    if (lista != 1 && lista != 2)
                        printf("Insira um valor valido (1 ou 2): ");
                    
                } while (lista != 1 && lista != 2);
                ind = lista-1;

                printf("Qual elemento deseja remover: ");
                scanf(" %d", &elem);
                removidos = remover_todos(&listas[ind], elem);
                if (removidos == 0)
                    printf("Falha ao remover elemento. Ele pode nao estar na lista!!");
                else
                    printf("Foram removidos %d elementos!", removidos);
                break;
            //Remove o maior elemendo da lista indicada
            case 6:
                system("cls");
                printf("Deseja REMOVER o maior elemento de qual lista (1 ou 2): ");
                do {
                    scanf(" %d", &lista);
                    clean_buffer();
                    if (lista != 1 && lista != 2)
                        printf("Insira um valor valido (1 ou 2): ");
                    
                } while (lista != 1 && lista != 2);
                ind = lista-1;
                if(remove_maior(&listas[ind]) == 0)
                    printf("Erro: Nao foi possivel encontrar o maior elemento");
                else
                    printf("O maior elemento foi removido!");
                break;
            //Limpar lista
            case 7:
                system("cls");
                printf("Qual lista deseja LIMPAR (1 ou 2): ");
                do {
                    scanf(" %d", &lista);
                    clean_buffer();
                    if (lista != 1 && lista != 2)
                        printf("Insira um valor valido (1 ou 2): ");
                    
                } while (lista != 1 && lista != 2);
                ind = lista-1;

                if (esvaziar_lista(&listas[ind]) == 0)
                    printf("Erro! A lista pode ja estar limpa!");
                else
                    printf("Lista limpa!");
                break;
            //Insere os elementos de lista 1 na lista 2 em ordem inversa
            case 8:
                system("cls");
                if(inverter_lista(&listas[0], &listas[1]) == 0)
                    printf("Nao foi possivel inverter a lista 1");
                else
                    printf("Lista 1 invertida com sucesso. Resultado armazenado na lista 2");
                break;
            //Insere os multiplos de 3 em lista 1 na lista 2
            case 9:
                system("cls");
                printf("Se a lista 2 possuir algum conteudo, ele sera limpo!");
                if (multiplos_tres(&listas[0], &listas[1]) == 0)
                    printf("\nNao foi possivel realizar a operacao!");
                else
                    printf("\nMultiplos de 3 em lista 1 foram armazenados na lista 2!");
                break;
            //Sair do programa
            case 10:
                sair = 1;
                break;
            default:
                system("cls");
                printf("Opcao invalida!");
                break;
        }
    };

    return 0;
}