/*
  Integrantes:
  Guilherme Alves Carvalho - 11921BCC016
  João Batista de Sousa Paula - 11911BCC008
  Pedro Leale - 11921BCC008
*/

#include <stdio.h>
#include <string.h>
#include "hashTable.h"
#define QNT_ALUNOS 2287 //Constante para quantidade de alunos
#include <ctype.h>
#include <stdlib.h>

//Matricula vai ser passada como chave na tabela hash
struct aluno {
  char nome[50];
  int notas[3];
};

int main() {
  Hash *hashTable = criaHash(QNT_ALUNOS, sizeof(struct aluno));
  if (hashTable == NULL)
    return 0;

  FILE *arq = fopen("alunos.txt", "r");
  if (arq == NULL)
    return 0;

  int mat, notas[3];
  char nome[50];
  struct aluno al;
  while (1) {
    if (feof(arq))
      break;
    fscanf(arq, "%d %s %d %d %d", &mat, nome, notas, notas + 1, notas + 2);
    strcpy(al.nome, nome);
    al.notas[0] = notas[0];
    al.notas[1] = notas[1];
    al.notas[2] = notas[2];
    if (insereHash(hashTable, mat, &al)) {
      printf("Insercao do aluno %d feita com sucesso!\n", mat);
    } else {
      printf("Nao e possivel mais inserir na tabela!\n");
      break;
    }
  }

  char resposta;
  do {
    printf("\n\nDeseja consultar um aluno na tabela (s,n)? ");
    scanf(" %c", &resposta);
    resposta = tolower(resposta);
    if (resposta == 's') {

      do {
          printf("Digite a matricula do aluno: ");
        scanf("%d", &mat);
        
      } while (mat < 0);
      if (buscaHash(hashTable, mat, &al)) {
        printf("\n\nAluno(%d) -> Nome: \"%s\" | Notas = [%d, %d, %d]\n", mat, al.nome, al.notas[0], al.notas[1], al.notas[2]);
      } else
        printf("\n\nO aluno com matricula %d nao existe!\n", mat);
      // system("pause"); //windows
      setbuf(stdin, NULL); //linux
      int c = getchar(); //linux
      system("clear"); //linux
      //system("cls"); //windows
    }
    else
      break;

  } while (resposta != 'n');
  free(arq);
  liberaHash(hashTable);
  return 0;
}
