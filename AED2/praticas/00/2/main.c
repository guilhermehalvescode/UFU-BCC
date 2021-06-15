#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[50];
  float nota;
} Aluno;

void errorHandler(const char* message) {
  printf("%s\n", message);
  int c = getchar();
  exit(1);
}

int main() {
  FILE *arq = fopen("notas.txt", "r");
  if (arq == NULL) errorHandler("Erro ao abrir o arquivo!");
  char temp[50], nome[50];
  Aluno maiorNota;

  int qnt = 0;
  float sum = 0, nota;
  while(!feof(arq)) {
    fscanf(arq, "%s %s %s %f", temp, nome, temp, &nota);
    if(qnt == 0) {
      strcpy(maiorNota.nome, nome);
      maiorNota.nota = nota;
    } else if(nota > maiorNota.nota) {
      strcpy(maiorNota.nome, nome);
      maiorNota.nota = nota;
    }
    qnt++;
    sum += nota;
  }
  fclose(arq);
  printf("A média da turma e: %.2f\n", sum / qnt);
  printf("O aluno %s tem a maior nota (%.2f)!\n", maiorNota.nome, maiorNota.nota);
  return 0;
}