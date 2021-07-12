#include <stdio.h>
#include <stdlib.h>
#include "listadinOrd.h"

void imprimir_lista(Lista list)
{
    char carac;
    printf("\n----LISTA----\n");
    int i = 0;
    while (obtem_posicao(list, i, &carac))
    {
        if (i != 0)
            printf(" ");
        printf("[%c]", carac);
        i++;
    }
    printf("\n");
}

void inserindo(Lista *list, char *vet)
{
    int i;
    for (i = 0; i < 9; i++)
    {
        if (!insere_ord(list, vet[i]))
        {
            break;
        }
    }
}

void remove_valor(Lista *list, char valor)
{
    if (!remove_ord(list, valor))
    {
        printf("\nElemento nao existe!!\n");
    }
}

int main()
{
    char vet[20] = {'d', 'f', 'a', 'A', 'G', 'y', 'm', 'o', 'P'};
    Lista lista_dinamica_enc;
    lista_dinamica_enc = cria_lista();
    imprimir_lista(lista_dinamica_enc);
    inserindo(&lista_dinamica_enc, vet);
    imprimir_lista(lista_dinamica_enc);
    remove_valor(&lista_dinamica_enc, 'M');
    remove_valor(&lista_dinamica_enc, 'm');
    imprimir_lista(lista_dinamica_enc);
    limpa_lista(&lista_dinamica_enc);
    imprimir_lista(lista_dinamica_enc);
    return 0;
}
