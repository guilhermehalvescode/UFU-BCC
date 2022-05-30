#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// linux
// #include <linux/kernel.h>
// #include <linux/sys.h>
// #include <sys/sysinfo.h>

// windows
// #include <windows.h>

#define MEM_SIZE 8000000000                               // 8GM mem size = 8*10^9 bytes
#define NUM_REGISTERS (MEM_SIZE * 5 / sizeof(Aluno)) + 50 // use in case os is "windows"

typedef struct Aluno
{
  int seqAluno;
  char codigoCurso[3];
  char nomeAluno[43];
} Aluno;

typedef long long int lli;
typedef FILE *HEAP_FILE;

Aluno *generateAluno(lli quantidadeAlunos);

HEAP_FILE createHeapFile(lli numberOfRegisters);