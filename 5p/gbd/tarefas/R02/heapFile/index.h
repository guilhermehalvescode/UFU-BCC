#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MEM_SIZE 8000000000 // 8GM mem size = 8*10^9 bytes
#define NUM_REGISTERS (MEM_SIZE * 5 / sizeof(Aluno)) + 50
#define NUM_REGISTERS_PER_PAGE 100000

typedef struct Aluno
{
  int seqAluno;
  char codigoCurso[3];
  char nomeAluno[43];
} Aluno;

typedef Aluno *Alunos;

typedef long long int lli;
typedef FILE *HEAP_FILE;

Alunos generateAlunos(lli quantidadeAlunos, lli startIndex);

HEAP_FILE createHeapFile(lli numberOfRegisters);