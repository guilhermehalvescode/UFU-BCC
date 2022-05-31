#include "index.h"

HEAP_FILE createHeapFile(li numberOfRegisters)
{
  if (numberOfRegisters < 0)
    return NULL;

  li ids;
  HEAP_FILE file;
  Aluno *aluno;

  // if file exists, open it
  if ((file = fopen("./heapFile.bin", "r+b")) != NULL)
  {
    return file;
  }

  // else create it
  if ((file = fopen("./heapFile.bin", "w+b")) == NULL)
  {
    perror("createHeapFile fopen as write binary heapFile error");
    return NULL;
  }

  printf("Generating %lu students\n", numberOfRegisters);

  for (ids = 0; ids < numberOfRegisters; ids++)
  {
    // printf("Generating student %li student out of %li students\n", ids + 1, numberOfRegisters);

    aluno = generateAluno(ids);

    if (aluno == NULL)
    {
      perror("createHeapFile generate alunos error");
      return NULL;
    }

    if (fwrite(aluno, sizeof(Aluno), 1, file) != 1)
    {
      perror("createHeapFile fwrite aluno error");
      return NULL;
    }

    // printf("Student %li written in file\n", ids + 1);

    free(aluno);
  }
  rewind(file);
  return file;
}

int readRandom(HEAP_FILE file, li seqAluno, li numberOfRegisters)
{
  if (file == NULL || numberOfRegisters < 0)
    return -1;

  if (fseek(file, seqAluno * sizeof(Aluno), SEEK_SET) != 0)
  {
    perror("readRandom lseek error");
    return -1;
  }

  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
  if (aluno == NULL)
  {
    perror("readRandom malloc error");
    rewind(file);
    return -1;
  }

  if (fread(aluno, sizeof(Aluno), 1, file) != 1)
  {
    perror("readRandom fread error");
    rewind(file);
    return -1;
  }

  printf("Aluno at register %lu: \n", seqAluno);
  printAluno(aluno);

  free(aluno);
  rewind(file);
  return 1;
}

int insertAtEnd(HEAP_FILE file, li numberOfRegisters)
{
  if (file == NULL || numberOfRegisters < 0)
    return -1;

  if (fseek(file, 0, SEEK_END) != 0)
  {
    perror("insertAtEnd fseek error");
    return -1;
  }

  Aluno *aluno = generateAluno(numberOfRegisters);
  if (aluno == NULL)
  {
    perror("insertAtEnd generateAluno error");
    rewind(file);
    return -1;
  }

  if (fwrite(aluno, sizeof(aluno), 1, file) != 1)
  {
    perror("insertAtEnd fwrite aluno error");
    rewind(file);
    return -1;
  }
  rewind(file);
  free(aluno);
  return 1;
}

int updateRandom(HEAP_FILE file, li numberOfRegisters, li seqAluno)
{
  if (file == NULL || numberOfRegisters < 0)
    return -1;

  li regIndex = seqAluno; // generateRandomNumber(0, numberOfRegisters);

  if (fseek(file, regIndex * sizeof(Aluno), SEEK_SET) != 0)
  {
    perror("updateRandom lseek error");
    return -1;
  }
  Aluno *aluno = generateAluno(seqAluno);
  if (fwrite(aluno, sizeof(Aluno), 1, file) != 1)
  {
    perror("updateRandom fwrite aluno error");
    rewind(file);
    return -1;
  }
  rewind(file);
  return 1;
}

Aluno *deleteRandom(HEAP_FILE file, li seqAluno)
{
  if (file == NULL)
    return NULL;

  li registerIndex = seqAluno * sizeof(Aluno);

  printf("[DEBUG] Deletando aluno com a sequencia = %li\n", seqAluno);

  if (fseek(file, registerIndex, SEEK_SET) != 0)
  {
    perror("[ERROR] deleteRandom lseek error");
    return NULL;
  }

  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

  if (aluno == NULL)
  {
    perror("[ERROR] deleteRandom malloc error");
    rewind(file);
    return NULL;
  }

  if (fread(aluno, sizeof(Aluno), 1, file) != 1)
  {
    perror("[ERROR] deleteRandom fread");
    rewind(file);
    return NULL;
  }

  aluno->seqAluno = abs(aluno->seqAluno) * -1;

  if (fwrite(aluno, sizeof(Aluno), 1, file) != 1)
  {
    perror("[ERROR] deleteRandom fwrite aluno error");
    rewind(file);
    return NULL;
  }
  rewind(file);
  return aluno;
}