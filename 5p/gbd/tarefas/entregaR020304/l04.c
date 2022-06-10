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

  fseeko(file, 0, SEEK_END);
  __off64_t numOfBytes = ftello(file);
  numRegisters = numOfBytes / sizeof(Aluno);

  printf("Resultados busca de 1%% (%li) dos registros (%li):\n", (li)(0.01 * numRegisters), numRegisters);
  readRandomOnePercent(file);

  fclose(file);
  return 0;
}