#include <stdio.h>
#include "./index.h"
#include "../defs.h"
#include "../pager/index.h"

FILE *openPageFile(long int pageSize)
{
  FILE *file;
  // if file exists, open it
  if ((file = fopen("./heapFile.bin", "r+b")) != NULL)
  {
    return file;
  }

  // else create it
  if ((file = fopen("./heapFile.bin", "w+b")) == NULL)
  {
    perror("[ERROR] createHeapFile fopen as write binary heapFile");
    return NULL;
  }

  return file;
}

void *getFolha(FILE *file, int chave)
{
  unsigned int pageIndex = treeSearch(file, 0, chave);

  return getPage(file, pageIndex, TAM_PAGINA);
}

void *getIntervalo(FILE *file, int chave1, int chave2)
{
  if (chave1 > chave2)
  {
    int aux = chave2;
    chave2 = chave1;
    chave1 = aux;
  }

  Alternativa1 *folhaMenor = getFolha(file, chave1);
  Alternativa1 *folhaMaior = getFolha(file, chave2);
}

unsigned int treeSearch(FILE *file, unsigned int pageIndex, int chave)
{
  Pagina *pagina = getPage(file, pageIndex, TAM_PAGINA);
  if (!pagina)
  {
    return -1;
  }

  if (pagina->ehFolha)
  {
    free(pagina);
    return pageIndex;
  }

  NoInterno noInterno = (pagina->conteudo).noInterno;
  if (chave < noInterno.entrada[0].chave)
  {
    free(pagina);
    return noInterno.anterior;
  }

  int i = 1;
  while (i < noInterno.quantidadeEntradas && chave >= noInterno.entrada[i].chave)
    i++;

  if (chave < noInterno.entrada[i].chave)
  {
    free(pagina);
    return noInterno.entrada[i - 1].proximo;
  }

  // FINAL PAGINA
  free(pagina);
  return noInterno.entrada[i - 1].proximo;
}

int startTree(FILE *file)
{
  NoInterno *noInterno = allocatePage(TAM_PAGINA);
  if (noInterno == NULL)
    return 0;
  pagina->raiz = -1;

  if (!setPage(file, pagina, 0, TAM_PAGINA))
  {
    free(pagina);
    return 0;
  }
  free(pagina);

  return 1;
}