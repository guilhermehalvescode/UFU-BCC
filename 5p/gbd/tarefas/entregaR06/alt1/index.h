
#include "../defs.h"

#define ALT1_OVERHEAD sizeof(int) + (2 * sizeof(off_t))
#define ALT1_QNT_REGISTROS (TAM_UNION - ALT1_OVERHEAD) / sizeof(Registro)
#define ALT1_TAM_PAGINA (sizeof(Registro) * ALT1_QNT_REGISTROS) + ALT1_OVERHEAD

typedef struct Alternativa1
{
  off_t anterior;
  Registro registro[ALT1_QNT_REGISTROS];
  off_t proximo;
  int quantidadeRegistros;
} Alternativa1;