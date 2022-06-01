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
    perror("[ERROR] createHeapFile fopen as write binary heapFile");
    return NULL;
  }

  printf("Generating %lu students\n", numberOfRegisters);

  for (ids = 0; ids < numberOfRegisters; ids++)
  {
    // printf("Generating student %li student out of %li students\n", ids + 1, numberOfRegisters);

    aluno = generateAluno(ids);

    if (aluno == NULL)
    {
      perror("[ERROR] createHeapFile generate alunos");
      return NULL;
    }

    if (fwrite(aluno, sizeof(Aluno), 1, file) != 1)
    {
      perror("[ERROR] createHeapFile fwrite aluno");
      return NULL;
    }

    // printf("Student %li written in file\n", ids + 1);

    free(aluno);
  }
  return file;
}

int readRandom(HEAP_FILE file, li seqAluno, li numberOfRegisters)
{
  if (file == NULL || seqAluno < 0 || numberOfRegisters < 0 || seqAluno >= numberOfRegisters)
    return -1;

  if (fseek(file, seqAluno * sizeof(Aluno), SEEK_SET) != 0)
  {
    perror("[ERROR] readRandom fseek");
    return -1;
  }

  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
  if (aluno == NULL)
  {
    perror("[ERROR] readRandom malloc");
    return -1;
  }

  if (fread(aluno, sizeof(Aluno), 1, file) != 1)
  {
    perror("[ERROR] readRandom fread");
    return -1;
  }

  printf("[LOG] Aluno at register %lu: \n", seqAluno);
  printAluno(aluno);

  free(aluno);
  return 1;
}

int insertAtEnd(HEAP_FILE file, li numberOfRegisters)
{
  if (file == NULL || numberOfRegisters < 0)
    return -1;

  if (fseek(file, 0, SEEK_END) != 0)
  {
    perror("[ERROR] insertAtEnd fseek");
    return -1;
  }

  Aluno *aluno = generateAluno(numberOfRegisters);
  if (aluno == NULL)
  {
    perror("[ERROR] insertAtEnd generateAluno");
    return -1;
  }

  if (fwrite(aluno, sizeof(Aluno), 1, file) != 1)
  {
    perror("[ERROR] insertAtEnd fwrite aluno");
    return -1;
  }

  free(aluno);
  return 1;
}

int updateRandom(HEAP_FILE file, li seqAluno, li numberOfRegisters)
{
  if (file == NULL || seqAluno < 0 || numberOfRegisters < 0 || seqAluno >= numberOfRegisters)
    return -1;

  li regIndex = seqAluno;

  if (fseek(file, regIndex * sizeof(Aluno), SEEK_SET) != 0)
  {
    perror("[ERROR] updateRandom lseek");
    return -1;
  }

  Aluno *aluno = generateAluno(seqAluno);
  if (aluno == NULL)
  {
    perror("[ERROR] updateRandom generateAluno");
    return -1;
  }

  if (fwrite(aluno, sizeof(Aluno), 1, file) != 1)
  {
    perror("[ERROR] updateRandom fwrite");
    return -1;
  }

  return 1;
}

Aluno *deleteRandom(HEAP_FILE file, li seqAluno, li numberOfRegisters)
{
  if (file == NULL || seqAluno < 0 || numberOfRegisters < 0 || seqAluno >= numberOfRegisters)
    return NULL;

  li registerOffset = seqAluno * sizeof(Aluno);

  printf("[LOG] Deletando pageBuffer com a sequencia = %li\n", seqAluno);

  if (fseek(file, registerOffset, SEEK_SET) != 0)
  {
    perror("[ERROR] deleteRandom first lseek");
    return NULL;
  }

  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

  if (aluno == NULL)
  {
    perror("[ERROR] deleteRandom malloc");
    return NULL;
  }

  if (fread(aluno, sizeof(Aluno), 1, file) != 1)
  {
    perror("[ERROR] deleteRandom fread");
    return NULL;
  }

  // already deleted
  if (aluno->seqAluno < 0)
  {
    return aluno;
  }

  aluno->seqAluno = abs(aluno->seqAluno) * -1;

  // return after reading
  if (fseek(file, -sizeof(Aluno), SEEK_CUR) != 0)
  {
    perror("[ERROR] deleteRandom second lseek");
    return NULL;
  }

  if (fwrite(aluno, sizeof(Aluno), 1, file) != 1)
  {
    perror("[ERROR] deleteRandom fwrite aluno error");
    return NULL;
  }

  return aluno;
}

// dúvidas ilmério
// não conseguimos acessar o final do arquivo usando fopen (biblioteca dele)
//
int readPage(HEAP_FILE file, int registersPerPage, int *numberOfValidBlock, int *numberOfReadBlocks, double *timeInMs)
{
  clock_t startTime = clock();
  long int page = 0;

  while (1)
  {
    li pageSize = sizeof(Aluno) * registersPerPage;
    Aluno *pageBuffer = (Aluno *)malloc(pageSize);

    if (pageBuffer == NULL)
    {
      perror("[ERROR][readPage] alunos malloc error");
      return -1;
    }

    if (fseek(file, page * pageSize, SEEK_SET) != 0)
    {
      perror("[ERROR][readPage] alunos malloc error");
      return -1;
    }

    int registersReaded = fread(pageBuffer, sizeof(Aluno), registersPerPage, file) != registersPerPage;

    if (registersReaded == 0)
    {
      perror("[ERROR][readPage] fread");

      return -1;
    }

    page++;
  }

  clock_t endTime = clock();
  *timeInMs = (startTime - endTime) * 1000 / CLOCKS_PER_SEC;
}
