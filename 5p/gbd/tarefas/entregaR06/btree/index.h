#include <stdlib.h>
#define PAGE_SIZE 2048

typedef struct Entrada
{
  int chave;
  off_t proximo;
} Entrada;

typedef struct NoInterno
{
  off_t anterior;
  Entrada entrada[127];
} NoInterno;

typedef struct Register
{
  int seqAluno;
  char matriculaAluno[12];
  char nomeAluno[36];
} Register;

typedef struct page
{
  int ehFolha;
  union conteudo
  {
    Register registro[39];
    NoInterno noInterno;
  } conteudo;
} page;

// 4 + 16*n <= 2048