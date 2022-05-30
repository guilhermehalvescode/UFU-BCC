#include "index.h"

HEAP_FILE createHeapFile(lli numberOfRegisters)
{
  lli remainingRegisters = numberOfRegisters;
  HEAP_FILE file;
  Alunos alunos;

  if ((file = fopen("./heapFile.bin", "wb")) == NULL)
  {
    perror("Fopen as write binary heapFile error");
    return NULL;
  }

  printf("Generating %lli students, %lli per page\n", numberOfRegisters, NUM_REGISTERS_PER_PAGE);

  while (remainingRegisters > 0)
  {
    lli pageIndex = (numberOfRegisters - remainingRegisters) / NUM_REGISTERS_PER_PAGE;

    printf("Generating page %lli\n", pageIndex);
    Alunos alunos = generateAlunos(NUM_REGISTERS_PER_PAGE, pageIndex * NUM_REGISTERS_PER_PAGE);

    if (alunos == NULL)
    {
      perror("Generate alunos error");
      return NULL;
    }

    if (fwrite(alunos, sizeof(Aluno), NUM_REGISTERS_PER_PAGE, file) != NUM_REGISTERS_PER_PAGE)
    {
      perror("Fwrite alunos error");
      return NULL;
    }

    free(alunos);
    remainingRegisters -= remainingRegisters - NUM_REGISTERS_PER_PAGE < 0 ? 0 : NUM_REGISTERS_PER_PAGE;
    pageIndex++;
  }
  return file;
}