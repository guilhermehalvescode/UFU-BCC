#include <stdio.h>
#include "./btree/index.h"
#include "./pager/index.h"

int main()
{
  /*
  printf("sizeof NoInterno: %lu\n", sizeof(NoInterno));
  printf("sizeof Alternativa1: %lu\n", sizeof(Alternativa1));
  printf("sizeof Pagina: %lu\n", sizeof(Pagina));
  */
  while (1)
  {
    printf("Menu:");
    printf("1 - Criar arvore");
    printf("2 - ");
    printf("3 - ");
    printf("4 - ");
    printf("5 - ");
    int escolha = 0;
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
      // func
      break;

    default:
      printf("Entrada invalida");
      break;
    }
  }

  return 0;
}