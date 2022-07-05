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
// Entrada tem 6 ou 8 bytes(depende se e x32 ou x64)

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

FILE *openPageFile(long int pageSize);

void *getFolha(FILE *file, int chave);

void printRegistro(Registro *registro);

void *getIntervalo(FILE *file, int chave1, int chave2);

unsigned int treeSearch(FILE *file, unsigned int pageIndex, int chave);

int startTree(FILE *file);
