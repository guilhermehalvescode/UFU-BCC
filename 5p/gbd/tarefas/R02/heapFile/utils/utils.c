#include "../index.h"

li generateRandomNumber(li min, li max)
{
  return (rand() % (max - min + 1)) + min;
}

void printAluno(Aluno *aluno)
{
  printf("%d - %s - %s\n", aluno->seqAluno, aluno->codigoCurso, aluno->nomeAluno);
}

Aluno *generateAluno(li id)
{
  int indexName;
  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

  if (aluno == NULL)
  {
    perror("generateAluno allocate Aluno error");
    return NULL;
  }

  aluno->seqAluno = id;
  aluno->codigoCurso[0] = 'C';
  aluno->codigoCurso[1] = generateRandomNumber('0', '9');
  aluno->codigoCurso[2] = '\0';

  for (indexName = 0; indexName < 42; indexName++)
  {

    aluno->nomeAluno[indexName] = generateRandomNumber('a', 'z');
  }
  aluno->nomeAluno[indexName] = '\0';

  return aluno;
}
