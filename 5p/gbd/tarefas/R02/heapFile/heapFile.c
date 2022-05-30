#include "index.h"

HEAP_FILE createHeapFile(lli numberOfRegisters)
{
  lli index;
  HEAP_FILE file;
  Aluno *aluno;

  // if file exists, open it
  if ((file = fopen("./heapFile.bin", "r+b")) != NULL)
  {
    return file;
  }

  // else create it
  if ((file = fopen("./heapFile.bin", "wb")) == NULL)
  {
    perror("Fopen as write binary heapFile error");
    return NULL;
  }

  // printf("Generating %lli students\n", numberOfRegisters);

  for (index = 0; index < numberOfRegisters; index++)
  {
    // printf("Generating student %lli student out of %lli students\n", index + 1, numberOfRegisters);

    aluno = generateAluno(numberOfRegisters);

    if (aluno == NULL)
    {
      perror("Generate alunos error");
      return NULL;
    }

    if (fwrite(aluno, sizeof(Aluno), 1, file) != 1)
    {
      perror("Fwrite aluno error");
      return NULL;
    }

    // printf("Student %lli written in file\n", index + 1);

    free(aluno);
  }
  return file;
}

void readRandom(HEAP_FILE file)
{
}