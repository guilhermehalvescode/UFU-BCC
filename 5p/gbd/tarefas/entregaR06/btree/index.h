#include "../defs.h"
#include "../alt1/index.h"

#define NO_INTERNO_OVERHEAD sizeof(unsigned int) + sizeof(int)
#define QNT_ENTRADAS (TAM_UNION - NO_INTERNO_OVERHEAD) / sizeof(Entrada)
#define NO_INTERNO_TAM (sizeof(Entrada) * QNT_ENTRADAS) + NO_INTERNO_OVERHEAD

typedef struct Entrada
{
  int chave;
  unsigned int proximo;
} Entrada;

typedef struct NoInterno
{
  unsigned int anterior;
  Entrada entrada[QNT_ENTRADAS];
  int quantidadeEntradas;
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