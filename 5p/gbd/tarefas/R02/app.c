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

  int option = 1;

  while (option != 0)
  {
    printf("Number of registers: %li\n\n", numRegisters);
    printf("[0] Exit\n");
    printf("[1] Read Random\n");
    printf("[2] Insert At End\n");
    printf("[3] Update Random\n");
    printf("[4] Delete Random\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      printf("\nDigite a sequencia do aluno: ");
      scanf("%li", &seqAluno);

      if (readRandom(file, seqAluno, numRegisters) != 1)
      {
        printf("[LOG] readRandom failed\n");
      }
      break;
    case 2:

      if (insertAtEnd(file, numRegisters) != -1)
      {
        numRegisters++;
      }
      else
      {
        printf("[LOG] insertAtEnd failed\n");
      }
      break;
    case 3:

      printf("\nDigite a sequencia do aluno: ");
      scanf("%li", &seqAluno);

      if (updateRandom(file, seqAluno, numRegisters) != 1)
      {
        printf("[LOG] updateRandom failed\n");
      }
      break;
    case 4:
      printf("\nDigite a sequencia do aluno: ");
      scanf("%li", &seqAluno);

      aluno = deleteRandom(file, seqAluno, numRegisters);
      if (deleteRandom != NULL)
      {
        printAluno(aluno);
        numRegisters--;
      }
      else
      {
        printf("[LOG] deleteRandom failed\n");
      }
      break;
    default:
      printf("Naoooooooooooooooooooooooo\n");
      break;
    }
  }

  fclose(file);
  return 0;
}