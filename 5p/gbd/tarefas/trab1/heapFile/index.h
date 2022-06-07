#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
// linux
// #include <linux/kernel.h>
// #include <linux/sys.h>
// #include <sys/sysinfo.h>

// windows
// #include <windows.h>

#define MEM_SIZE 1073741824
// Fonte: https://www.convertunits.com/from/GB/to/byte
// #define MEM_SIZE 8589934592                               // 8GM mem size = 8*10^9 bytes 8589934592
#define NUM_REGISTERS (MEM_SIZE * 5 / sizeof(Aluno)) + 50 // use in case os is "windows"

typedef long int li;

typedef struct
{
  li seqAluno;
  char codigoCurso[3];
  char nomeAluno[43];
} Aluno;

typedef FILE *HEAP_FILE;

/* utils.c */
Aluno *generateAluno(li id);
li generateRandomNumber(li min, li max);
void printAluno(Aluno *aluno);

/* heapFile.c */
HEAP_FILE createHeapFile(li numberOfRegisters);
int readRandom(HEAP_FILE file, li seqAluno, li numberOfRegisters);
int insertAtEnd(HEAP_FILE file, li numberOfRegisters);
int updateRandom(HEAP_FILE file, li seqAluno, li numberOfRegisters);
int readPages(HEAP_FILE file, li registersPerPage);
Aluno *deleteRandom(HEAP_FILE file, li seqAluno, li numberOfRegisters);
