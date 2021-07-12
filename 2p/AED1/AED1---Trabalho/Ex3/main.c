#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//Lê todos os caracteres presentes no STDIN
void clean_buffer(){
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n');
}

int main(){

    int sair = 0;
    int pos, ch;
    float elem;
    Lista listas[3];
    listas[0] = criar_lista(); //Lista 1
    listas[1] = criar_lista(); //Lista 2
    listas[2] = criar_lista(); //Lista 3

    while (sair != 1) {
        int op = 0;
        printf("\n\n[1] Imprimir lista");
        printf("\n[2] Inserir elemento");
        printf("\n[3] Remover elemento");
        printf("\n[4] Remover elemento de uma posicao (1o, 2o, 3o... No)");
        printf("\n[5] Exibir tamanho da lista");
        printf("\n[6] Verificar igualdade entre lista 1 e lista 2");
        printf("\n[7] Exibir maior elemento da lista");
        printf("\n[8] Esvaziar lista");
        printf("\n[9] Intercalar lista 1 e lista 2");
        printf("\n[10] Sair\n");
        scanf("%d", &op);
        clean_buffer();

        switch (op) {
            int lista, ind;
            //Imprimir lista
            case 1:
                system("cls");
                printf("Qual lista deseja imprimir (1, 2 ou 3): ");
                do {
                    scanf(" %d", &lista);
                    clean_buffer();
                    if (lista < 1 || lista > 3)
                        printf("Insira um valor valido (1, 2 ou 3): ");
                    
                } while (lista < 1 || lista > 3);
                ind = lista-1;

                if (lista_vazia(listas[ind]) == 1) {
                    printf("A lista esta vazia!!");
                } else {
                    printf("Lista %d: [", lista);
                    size_t pos = 0;
                    while (obtem_valor(&listas[ind], &elem, pos) == 1) {
                        printf(" %.2lf ", elem);
                        pos++;
                    }
                    printf("]");
                }
                break;
            //Inserir elemento
            case 2:
                system("cls");
                printf("Em qual lista deseja INSERIR um elemento (1 ou 2): ");
                do {
                    scanf("%d", &lista);
                    clean_buffer();
                    if (lista != 1 && lista != 2)
                        printf("Insira um valor valido (1 ou 2): ");
                    
                } while (lista != 1 && lista != 2);
                ind = lista-1;

                printf("Qual o elemento que deseja inserir: ");
                scanf(" %f", &elem);
                if(insere_ord(&listas[ind], elem) == 0)
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
                scanf(" %f", &elem);
                if (remove_ord(&listas[ind], elem) == 0)
                    printf("Falha ao remover elemento. Ele pode nao estar na lista!!");
                else
                    printf("Elemento removido!");
                break;
            //Remover elemento em determinada posição
            case 4:
                system("cls");
                printf("Em qual lista deseja REMOVER um elemento (1 ou 2): ");
                do {
                    scanf(" %d", &lista);
                    clean_buffer();
                    if (lista != 1 && lista != 2)
                        printf("Insira um valor valido (1 ou 2): ");
                    
                } while (lista != 1 && lista != 2);
                ind = lista-1;

                printf("Qual a posicao do elemento que deseja remover: ");
                scanf(" %d", &pos);
                if (remove_pos(&listas[ind], pos, &elem) == 0)
                    printf("Erro ao remover elemento: lista vazia ou nao ha elemento na posicao!!");
                else
                    printf("O elemento removido foi: %d", elem);
                break;
            //Tamanho da lista
            case 5:
                system("cls");
                printf("De qual lista deseja saber o tamanho (1, 2 ou 3): ");
                do {
                    scanf(" %d", &lista);
                    clean_buffer();
                    if (lista > 3 || lista < 1)
                        printf("Insira um valor valido (1, 2 ou 3): ");
                    
                } while (lista > 3 || lista < 1);
                ind = lista-1;

                int tam = tamanho_lista(&listas[ind]);
                if ((tam) == 0)
                    printf("A lista esta vazia!");
                else
                    printf("A lista %d tem %d elementos.", lista, tam);
                system("cls");
                break;
            //Verificar igualdade entre lista_1 e lista_2
            case 6:
                if (listas_iguais(&listas[0], &listas[1]) == 0)
                    printf("As listas sao diferentes ou estao vazias!");
                else 
                    printf("As listas sao iguais!");
                break;
            //Exibir o maior elemendo da lista indicada
            case 7:
                system("cls");
                printf("Deseja saber o maior elemento de qual lista (1, 2 ou 3): ");
                do {
                    scanf(" %d", &lista);
                    clean_buffer();
                    if (lista < 1 || lista > 3)
                        printf("Insira um valor valido (1, 2 ou 3): ");
                    
                } while (lista < 1 || lista > 3);
                ind = lista-1;
                if(maior_valor(&listas[ind], &elem) == 0)
                    printf("Erro: Nao foi possivel encontrar o maior elemento");
                else
                    printf("O maior elemento da lista %d e: %lf", lista, elem);
                break;
            //Limpar lista
            case 8:
                system("cls");
                printf("Qual lista deseja LIMPAR (1, 2 ou 3): ");
                do {
                    scanf(" %d", &lista);
                    clean_buffer();
                    if (lista < 1 || lista > 3)
                        printf("Insira um valor valido (1, 2 ou 3): ");
                    
                } while (lista < 1 || lista > 3);
                ind = lista-1;

                if (esvaziar_lista(&listas[ind]) == 0)
                    printf("Erro! A lista pode ja estar limpa!");
                else
                    printf("Lista limpa!");
                break;
            //Intercalar duas listas
            case 9:
                system("cls");
                if(intercalar_listas(&listas[0], &listas[1], &listas[2]) == 0)
                    printf("Nao foi possivel intercalar as listas");
                else
                    printf("Listas intercalada com sucesso. Resultado armazenado na lista 3");
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