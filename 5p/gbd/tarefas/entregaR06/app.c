#include <stdio.h>
#include "./btree/index.h"
#include "./pager/index.h"

int main()
{
  printf("sizeof NoInterno: %lu\n", sizeof(NoInterno));
  printf("sizeof Alternativa1: %lu\n", sizeof(Alternativa1));
  printf("sizeof Pagina: %lu\n", sizeof(Pagina));

  return 0;
}