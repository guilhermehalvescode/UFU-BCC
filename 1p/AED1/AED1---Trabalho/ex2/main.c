#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void imprime(Lista list)
{
  printf("Imprimindo lista...\n");
  for (size_t i = 0; i < tamanho(list); i++)
  {
    printf("Lista[%d] = %d\n", i, posicao(list, i));
  }
}

int chose_list(void){
  int choice = 0;

  while (choice < 1 || choice > 2)
  {
    printf("Em qual lista deseja fazer essa operacao(1 ou 2)? ");
    scanf("%d", &choice);
  }
  
  return choice-1;
}
 
int main()
{
  int opcao = 0, value = 0, escolha;

  Lista list[3];
  list[0] = cria();
  list[1] = cria();
  list[2] = cria();

  while (opcao != 8)  
  {
    printf("Escolha uma opcao:\n");
    printf("[1] Inserir valor\n");
    printf("[2] Maior valor\n");
    printf("[3] Tamanho\n");
    printf("[4] Esvaziar\n");
    printf("[5] Intercalar\n");
    printf("[6] Imprimir\n");
    printf("[7] Remover pares\n");
    printf("[8] Sair\n");
    printf("Opcao: ");
    setbuf(stdin, NULL);
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      escolha = chose_list();
      printf("Digite o valor a ser inserido: ");
      scanf("%d", &value);
      inserir(list[escolha], value);

      break;
    case 2:
      escolha = chose_list();
      
      if(tamanho(list[escolha])){
        value = maior(list[escolha]);

        printf("Menor valor na lista: %d\n", value);
      }
      else
        printf("Lista vazia!\n");

      break;
    case 3:
      escolha = chose_list();
      value = tamanho(list[escolha]);

      printf("Tamanho da lista: %d\n", value);
      
      break;
    case 4:
      escolha = chose_list();
      esvaziar(list[escolha]);

      break;
    case 5:
      printf("Escolha qual lista sera a base\n");
      escolha = chose_list();
      list[2] = intercalar(list[escolha], list[!escolha]);
      printf("Resultado:\n");
      imprime(list[2]);
      esvaziar(list[2]);
      list[2] = NULL;

      break;
    case 6:
      escolha = chose_list();

      imprime(list[escolha]);

      break;
    case 7:
      escolha = chose_list();

      remove_pares(list[escolha]);

      break;
    case 8:
      break;
    default:
      printf("Opcao invalida!\n");
      break;
    }
  };

  libera(list[0]);
  libera(list[1]);

  system("pause");
  return 0;
}