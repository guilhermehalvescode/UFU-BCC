#include "../index.h"

Aluno *generateAluno(lli quantidadeAluno)
{
  int indexName;
  lli index;
  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

  if (aluno == NULL)
  {
    perror("Allocate Aluno error");
    return NULL;
  }

  srand(time(NULL));

  aluno->seqAluno = rand() % quantidadeAluno;
  aluno->codigoCurso[0] = 'C';
  aluno->codigoCurso[1] = (rand() % ('9' - '0' + 1)) + '0';
  aluno->codigoCurso[2] = '\0';

  for (indexName = 0; indexName < 42; indexName++)
  {
    aluno->nomeAluno[indexName] = (rand() % ('z' - 'a' + 1)) + 'a'; // 'a' - 'z'
  }
  aluno->nomeAluno[indexName] = '\0';
  // printf("%d - %s - %s\n", Aluno[index].seqAluno, Aluno[index].codigoCurso, Aluno[index].nomeAluno);
  return aluno;
}