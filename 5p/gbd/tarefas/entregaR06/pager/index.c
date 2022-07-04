#include "index.h"

void *allocatePage(size_t pageSize)
{
  void *page = malloc(pageSize);
  if (!page)
    perror("allocatePage: Nao foi possivel alocar");

  return page;
}

void *getPage(FILE *file, unsigned int pageIndex, unsigned int pageSize)
{
  if (fseeko(file, pageIndex * pageSize, SEEK_SET) == -1)
  {
    perror("getPage: Nao foi possivel ir ate a pagina");
    return NULL;
  }

  void *page = allocatePage(pageSize);
  if (!page)
  {
    perror("getPage: Nao foi possivel alocar");
    return NULL;
  }

  if (fread(page, pageSize, 1, file) != 1)
  {
    perror("getPage: Nao foi possivel ler a pagina");
    return NULL;
  }

  return page;
}

int setPage(FILE *file, void *page, unsigned int pageIndex, unsigned int pageSize)
{
  if (fseeko(file, pageIndex * pageSize, SEEK_SET) == -1)
  {
    perror("setPage: Nao foi ir ate a pagina");
    return 0;
  }

  if (fwrite(page, pageSize, 1, file) != 1)
  {
    perror("setPage: Nao foi possivel escrever a pagina");
    return 0;
  }

  return 1;
}