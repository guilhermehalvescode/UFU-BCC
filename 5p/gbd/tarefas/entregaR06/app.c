#include <stdio.h>
#include "./btree/index.h"
#include "./pager/index.h"

int main()
{

  printf("sizeof NoInterno: %lu\n", sizeof(NoInterno));
  printf("NO_INTERNO_TAM: %lu\n", NO_INTERNO_TAM);
  printf("QNT_ENTRADAS: %lu\n", QNT_ENTRADAS);
  printf("ALT1_QNT_REGISTROS: %lu\n", ALT1_QNT_REGISTROS);
  printf("ALT1_TAM_PAGINA: %lu\n", ALT1_TAM_PAGINA);
  printf("sizeof Entrada: %lu\n", sizeof(Entrada));
  printf("sizeof Registro: %lu\n", sizeof(Registro));
  printf("sizeof Pagina: %lu\n", sizeof(Pagina));
  return 0;
}