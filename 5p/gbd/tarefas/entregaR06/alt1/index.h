
#include "../defs.h"

#define ALT1_OVERHEAD sizeof(int) + sizeof(unsigned int) + sizeof(unsigned int)
#define ALT1_QNT_REGISTROS (TAM_UNION - ALT1_OVERHEAD) / sizeof(Registro)
#define ALT1_TAM_PAGINA (sizeof(Registro) * ALT1_QNT_REGISTROS) + ALT1_OVERHEAD

typedef struct Alternativa1
{
  unsigned int anterior;
  Registro registro[ALT1_QNT_REGISTROS];
  unsigned int proximo;
  int quantidadeRegistros;
} Alternativa1;