#include "../index.h"

li generateRandomNumber(li min, li max)
{
  return (rand() % (max - min + 1)) + min;
}

void printAluno(Aluno *aluno)
{
  printf("-----------------------------\nSeqAluno: %li\nCurso: %s\nNome: %s\n-------------------\n", aluno->seqAluno, aluno->codigoCurso, aluno->nomeAluno);
}

Aluno *generateAluno(li id)
{
  int indexName;
  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));

  if (aluno == NULL)
  {
    perror("[ERROR] generateAluno allocate Aluno");
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
