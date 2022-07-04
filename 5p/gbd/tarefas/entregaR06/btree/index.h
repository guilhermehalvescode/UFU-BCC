#include "../defs.h"
#include "../alt1/index.h"

#define NO_INTERNO_OVERHEAD sizeof(off_t)
#define QNT_ENTRADAS (TAM_UNION - NO_INTERNO_OVERHEAD) / sizeof(Entrada)
#define NO_INTERNO_TAM sizeof(Entrada) * QNT_ENTRADAS + NO_INTERNO_OVERHEAD

typedef struct Entrada
{
  int chave;
  off_t proximo;
} Entrada;

typedef struct NoInterno
{
  off_t anterior;
  Entrada entrada[QNT_ENTRADAS];
} NoInterno;

typedef struct Pagina
{
  int ehFolha;
  union conteudo
  {
    NoInterno noInterno;
    Alternativa1 folha;
  } conteudo;
} Pagina;