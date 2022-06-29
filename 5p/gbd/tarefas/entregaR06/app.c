#include <stdio.h>
#include <stdio.h>
#include "./btree/index.h"
#include "./pager/index.h"

int main()
{

  printf("sizeof page: %lu\n", sizeof(page));
  printf("sizeof register: %lu\n", sizeof(Register));
  printf("sizeof entrada: %lu\n", sizeof(Entrada));
  printf("sizeof NoInterno: %lu\n", sizeof(NoInterno));
  return 0;
}