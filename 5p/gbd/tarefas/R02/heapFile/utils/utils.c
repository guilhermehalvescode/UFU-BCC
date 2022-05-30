#include "../index.h"

Alunos generateAlunos(lli quantidadeAlunos, lli startIndex)
{
  int indexName;
  lli index;
  Alunos alunos = (Alunos)malloc(quantidadeAlunos * sizeof(Aluno));

  if (alunos == NULL)
  {
    perror("Allocate alunos error");
    return NULL;
  }

  srand(time(NULL));

  for (index = 0; index < quantidadeAlunos; index++)
  {
    alunos[index].seqAluno = startIndex + index;
    alunos[index].codigoCurso[0] = 'C';
    alunos[index].codigoCurso[1] = (rand() % ('9' - '0' + 1)) + '0';
    alunos[index].codigoCurso[2] = '\0';

    for (indexName = 0; indexName < 42; indexName++)
    {
      alunos[index].nomeAluno[indexName] = (rand() % ('z' - 'a' + 1)) + 'a'; // 'a' - 'z'
    }
    alunos[index].nomeAluno[42] = '\0';
    // printf("%d - %s - %s\n", alunos[index].seqAluno, alunos[index].codigoCurso, alunos[index].nomeAluno);
  }

  return alunos;
}