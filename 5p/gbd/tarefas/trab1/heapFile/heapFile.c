#include "index.h"

HEAP_FILE createHeapFile(li numberOfRegisters)
{
  if (numberOfRegisters < 0)
    return NULL;

  li ids;
  HEAP_FILE file;
  Aluno *aluno;

  // if file exists, open it
  if ((file = fopen64("./heapFile.bin", "r+b")) != NULL)
  {
    return file;
  }

  // else create it
  if ((file = fopen64("./heapFile.bin", "w+b")) == NULL)
  {
    perror("[ERROR] createHeapFile fopen64 as write binary heapFile");
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

  if (fseeko64(file, seqAluno * sizeof(Aluno), SEEK_SET) != 0)
  {
    perror("[ERROR] readRandom fseeko64");
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

  if (fseeko64(file, 0, SEEK_END) != 0)
  {
    perror("[ERROR] insertAtEnd fseeko64");
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

  if (fseeko64(file, seqAluno * sizeof(Aluno), SEEK_SET) != 0)
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

  if (fseeko64(file, seqAluno * sizeof(Aluno), SEEK_SET) != 0)
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
  if (fseeko64(file, -sizeof(Aluno), SEEK_CUR) != 0)
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

int readSinglePage(HEAP_FILE file, li page, li registersPerPage, li *numberOfValidBlock, li *numberOfReadBlocks)
{

  Aluno *pageBuffer = (Aluno *)malloc(registersPerPage * sizeof(Aluno));

  if (pageBuffer == NULL)
  {
    perror("[ERROR][readPage] alunos malloc error");
    return -1;
  }

  if (fseeko64(file, page * registersPerPage * sizeof(Aluno), SEEK_SET) != 0)
  {
    perror("[ERROR][readPage] alunos malloc error");
    return -1;
  }

  // fseeko64(file, 0, SEEK_END);
  // _off64_t numOfBytes = ftello64(file);
  // li diffFinalPage = registersPerPage * sizeof(Aluno);
  // calcula tempo de leitura
  // TO-DO read incomplete page
  *numberOfReadBlocks = fread(pageBuffer, sizeof(Aluno), registersPerPage, file);
  // sizeLastPage = tamanho em bytes da última página
  // fread(pageBuffer, sizeLastPage (incomplete), 1, file);

  *numberOfValidBlock = 0;
  for (li i = 0; i < registersPerPage; i++)
  {
    if (pageBuffer[i].seqAluno >= 0)
      (*numberOfValidBlock)++;
  }

  free(pageBuffer);
  return 1;
}

int readPages(HEAP_FILE file, li registersPerPage)
{
  fseeko64(file, 0, SEEK_END);
  _off64_t numOfBytes = ftello64(file);
  li qntRegisters = numOfBytes / sizeof(Aluno);

  li qntPages = ceil(qntRegisters / registersPerPage);
  li numberOfValidBlock = 0, numberOfReadBlocks = 0;
  li temp_nrb, temp_nvb;
  double timeInS = 0;

  clock_t startTime = clock();
  for (li i = 0; i < qntPages; i++)
  {
    if (readSinglePage(file, i, registersPerPage, &temp_nvb, &temp_nrb) == 1)
    {
      numberOfReadBlocks += temp_nrb;
      numberOfValidBlock += temp_nvb;
    }
    else
      return -1;
  }

  timeInS = (clock() - startTime) / CLOCKS_PER_SEC;
  printf("Time: %.2lfs\nRead Blocks: %li\nValid Blocks: %li\n", timeInS, numberOfReadBlocks, numberOfValidBlock);
  return 1;
}