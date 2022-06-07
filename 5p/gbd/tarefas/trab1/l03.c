#include "./heapFile/index.h"

int main()
{
  srand(time(NULL));
  li seqAluno, numRegisters = NUM_REGISTERS;
  Aluno *aluno;
  HEAP_FILE file = createHeapFile(numRegisters);

  if (file == NULL)
  {
    return -1;
  }

  fseeko64(file, 0, SEEK_END);
  _off64_t numOfBytes = ftello64(file);
  numRegisters = numOfBytes / sizeof(Aluno);

  printf("Resultados pagina com 1 registro:\n");
  readPages(file, 1);

  printf("\nResultados pagina com 10 registros:\n");
  readPages(file, 10);

  printf("\nResultados pagina com 100 registros:\n");
  readPages(file, 100);

  printf("\nResultados pagina com 1000 registros:\n");
  readPages(file, 1000);

  printf("\nResultados pagina com 10000 registros:\n");
  readPages(file, 10000);

  printf("\nResultados pagina com 100000 registros:\n");
  readPages(file, 100000);

  printf("\nResultados pagina com 1000000 registros:\n");
  readPages(file, 1000000);

  fclose(file);
  return 0;
}