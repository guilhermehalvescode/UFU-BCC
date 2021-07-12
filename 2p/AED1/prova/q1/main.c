#define NUM_MAX_ITENS 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct{
  int dia;
  int mes;
  int ano;
} Data;

typedef struct{
  char nome[50];              
  Data dataNascimento;
  char cidadeOrigem[50];
  char paisOrigem[50];
} Ficha;

typedef struct{
  Ficha item[NUM_MAX_ITENS];
  int   nItens;
} ListaSeq;

// Protótipos de funções
int lista_vazia(ListaSeq *list);
int lista_cheia(ListaSeq *list);
int inserir(ListaSeq *pLista, Ficha pNovaFicha);
int main()
{
  ListaSeq cadastro;
  Ficha minhaFicha;
  int opcao,i;
  cadastro.nItens=0;
  do{
    system("cls");
    printf("[1] Incluir uma nova ficha\n");
    printf("[2] Listar todas as fichas\n");
    printf("[3] Sair do programa\n");
    printf("\n");
    printf("Opcao desejada: ");  
    scanf("%d",&opcao);
    if (opcao==1)
    {
       printf("\n");
       printf("Nome: "); 
       scanf("%s",minhaFicha.nome); 
       printf("Cidade: "); 
       scanf("%s",minhaFicha.cidadeOrigem);
       printf("Pais: "); 
       scanf("%s",minhaFicha.paisOrigem);
       printf("Data Nascimento: "); 
       scanf("%d",&minhaFicha.dataNascimento.dia);
       scanf("%d",&minhaFicha.dataNascimento.mes);
       scanf("%d",&minhaFicha.dataNascimento.ano);

       int r = inserir(&cadastro, minhaFicha);
       if (r==1) printf("\nInsercao bem sucedida !\n");
       else if (r==0) printf("\nMemoria insuficiente !\n");
       printf("\n\n"); system("pause");
    }
    if (opcao==2){
       printf("\n\n");
       for (i=0; i<cadastro.nItens; i++)
       {
         printf ("item[%d] = %s %s %s %d %d %d\n",i,cadastro.item[i].nome,
           cadastro.item[i].cidadeOrigem,                                            
           cadastro.item[i].paisOrigem,
           cadastro.item[i].dataNascimento.dia,
           cadastro.item[i].dataNascimento.mes,
           cadastro.item[i].dataNascimento.ano);
       }
       printf("\n\n"); system("pause");
    }

  } while (opcao != 3);
  return 0;
}


int lista_cheia(ListaSeq *list){
    return list->nItens == NUM_MAX_ITENS;
}

int lista_vazia(ListaSeq *list){
    return list->nItens == 0;
}

int inserir(ListaSeq *pLista, Ficha pNovaFicha) {
    if(pLista == NULL || lista_cheia(pLista))
        return 0;
    if(lista_vazia(pLista) == 1 || strcmp(pNovaFicha.nome, pLista->item[pLista->nItens - 1].nome) >= 0) {
        pLista->item[pLista->nItens] = pNovaFicha;
    } else {
        int i, aux = 0;
        while(strcmp(pNovaFicha.nome, pLista->item[aux].nome) >= 0) 
            aux++;
        for(i = pLista->nItens; i > aux; i--)
            pLista->item[i] = pLista->item[i - 1];
        pLista->item[aux] = pNovaFicha;
    }
    pLista->nItens++;
    return 1;
}