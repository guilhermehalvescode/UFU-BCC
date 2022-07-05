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

void printRegistro(Registro *registro)
{
  printf("Aluno\n");
  printf("seqAluno: %d\n", registro->seqAluno);
  printf("Matricula: %s\n", registro->matriculaAluno);
  printf("nomeAluno: %s\n", registro->nomeAluno);
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
  while (folhaMenor != NULL)
  {
    int quantidadeRegistrosMenoresQueChave2 = 0;
    for (int i = 0; i < folhaMenor->quantidadeRegistros; i++)
    {
      Registro registro = folhaMenor->registro[i];
      if (registro.seqAluno >= chave1 || registro.seqAluno <= chave2)
      {
        quantidadeRegistrosMenoresQueChave2++;
        printRegistro(&registro);
      }
    }

    if (quantidadeRegistrosMenoresQueChave2 == 0)
    {
      // estamos em uma folha que só tem chaves maiores que chave2
      break;
    }
    free(folhaMenor);
    folhaMenor = getPage(file, folhaMenor->proximo, TAM_PAGINA);
  }
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
// arvore
//
int startTree(FILE *file)
{
  NoInterno *noInterno = allocatePage(TAM_PAGINA);
  if (noInterno == NULL)
    return 0;

  noInterno->anterior = -1;
  for (int i = 0; i < QNT_ENTRADAS; i++)
  {
    noInterno->entrada[i].chave = -1;
    noInterno->entrada[i].proximo = -1;
  }
  noInterno->quantidadeEntradas = 0;

  unsigned int raiz = 0;
  FILE *fileRaiz = fopen("./raiz.dat", "w+");
  if (!fileRaiz)
  {
    free(noInterno);
    return 0;
  }
  if (fwrite(&raiz, sizeof(unsigned int), 1, fileRaiz) != 1)
  {
    free(noInterno);
    return 0;
  }

  if (!setPage(file, noInterno, raiz, TAM_PAGINA))
  {
    free(noInterno);
    return 0;
  }
  free(noInterno);

  return 1;
}