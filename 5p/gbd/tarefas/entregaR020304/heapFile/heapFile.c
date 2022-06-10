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

  if (fseeko(file, seqAluno * sizeof(Aluno), SEEK_SET) != 0)
  {
    perror("[ERROR] readRandom fseeko");
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

Aluno *readRandomAndGetAluno(HEAP_FILE file, li seqAluno, li numberOfRegisters)
{
  if (file == NULL || seqAluno < 0 || numberOfRegisters < 0 || seqAluno >= numberOfRegisters)
    return NULL;

  if (fseeko(file, seqAluno * sizeof(Aluno), SEEK_SET) != 0)
  {
    perror("[ERROR] readRandomAndGetAluno fseeko");
    return NULL;
  }

  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
  if (aluno == NULL)
  {
    perror("[ERROR] readRandomAndGetAluno malloc");
    return NULL;
  }

  if (fread(aluno, sizeof(Aluno), 1, file) != 1)
  {
    perror("[ERROR] readRandomAndGetAluno fread");
    return NULL;
  }

  return aluno;
}

int insertAtEnd(HEAP_FILE file, li numberOfRegisters)
{
  if (file == NULL || numberOfRegisters < 0)
    return -1;

  if (fseeko(file, 0, SEEK_END) != 0)
  {
    perror("[ERROR] insertAtEnd fseeko");
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

  if (fseeko(file, seqAluno * sizeof(Aluno), SEEK_SET) != 0)
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

  if (fseeko(file, seqAluno * sizeof(Aluno), SEEK_SET) != 0)
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
  if (fseeko(file, -sizeof(Aluno), SEEK_CUR) != 0)
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

int readSinglePage(HEAP_FILE file, li page, li qntPages, li registersPerPage, __off64_t numOfBytes, li *numberOfValidRegs)
{

  size_t PAGE_SIZE = registersPerPage * sizeof(Aluno);

  Aluno *pageBuffer = (Aluno *)malloc(PAGE_SIZE);
  if (pageBuffer == NULL)
  {
    perror("[ERROR][readPage] alunos malloc error");
    return -1;
  }

  size_t pageOffset = page * PAGE_SIZE;
  if (fseeko(file, pageOffset, SEEK_SET) != 0)
  {
    perror("[ERROR][readPage] alunos malloc error");
    return -1;
  }

  if (page == qntPages - 1)
  {
    li remainingRegs = (numOfBytes / sizeof(Aluno)) % registersPerPage;

    if (remainingRegs)
      registersPerPage = remainingRegs;

    fread(pageBuffer, sizeof(Aluno), registersPerPage, file);
  }
  else
  {
    fread(pageBuffer, sizeof(Aluno), registersPerPage, file);
  }

  *numberOfValidRegs = 0;
  for (li i = 0; i < registersPerPage; i++)
  {
    if (pageBuffer[i].seqAluno >= 0)
      (*numberOfValidRegs)++;
  }

  free(pageBuffer);
  return 1;
}

int readPages(HEAP_FILE file, li registersPerPage)
{
  fseeko(file, 0, SEEK_END);
  __off64_t numOfBytes = ftello(file);
  li qntRegisters = numOfBytes / sizeof(Aluno);

  li qntPages = ceil(qntRegisters / (double)registersPerPage);
  li numberOfValidRegs = 0, numberOfReadBlocks = 0;
  li temp_nvr;
  double timeInS = 0;

  clock_t startTime = clock();
  for (li pageIndex = 0; pageIndex < qntPages; pageIndex++)
  {
    if (readSinglePage(file, pageIndex, qntPages, registersPerPage, numOfBytes, &temp_nvr) == 1)
    {
      numberOfValidRegs += temp_nvr;
      numberOfReadBlocks++;
    }
  }

  timeInS = (clock() - startTime) / CLOCKS_PER_SEC;
  printf("Time: %.2lfs\nRead Pages: %li\nValid Registers: %li\n", timeInS, numberOfReadBlocks, numberOfValidRegs);
  return 1;
}

int readRandomOnePercent(HEAP_FILE file)
{
  fseeko(file, 0, SEEK_END);
  __off64_t numOfBytes = ftello(file);
  li qntRegisters = numOfBytes / sizeof(Aluno);
  li numberOfValidRegs = 0, numberOfInvalidRegs = 0;

  double timeInS = 0;
  clock_t startTime = clock();
  li numberOfRegistersToRead = 0.01 * qntRegisters;

  while (numberOfRegistersToRead > 0)
  {
    li seqAluno = generateRandomNumber(0, qntRegisters - 1);
    Aluno *aluno = readRandomAndGetAluno(file, seqAluno, qntRegisters);
    if (!aluno)
      return -1;
    if (aluno->seqAluno >= 0)
      numberOfValidRegs++;
    else
      numberOfInvalidRegs++;
    numberOfRegistersToRead--;
    free(aluno);
  }

  timeInS = (clock() - startTime) / CLOCKS_PER_SEC;
  printf("Time: %.2lfs\nValid Registers: %li\nInvalid Registers: %li\n", timeInS, numberOfValidRegs, numberOfInvalidRegs);

  return 1;
}