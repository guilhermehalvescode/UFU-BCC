/*
  Integrantes:
  Guilherme Alves Carvalho - 11921BCC016
  João Batista de Sousa Paula - 11911BCC008
  Pedro Leale - 11921BCC008
*/

#include <stdio.h>
#include <stdlib.h>
#include "./trie/trie.h"
int main() {
  Trie *trie = criaTrie();
  if (trie == NULL) {
    printf("Problemas para criar a arvore\n");
    return 0;
  }
  FILE *arq = fopen("./test/words.txt", "r");
  if (arq == NULL) {
    printf("Erro a abrir o arquivo\n");
    return 0;
  }

  //Insercao das palavras----------------------------------------------------------------
  char palavra[50];
  while (1) {
    if (feof(arq))
      break;
    fscanf(arq, "%s", palavra);
    insereTrie(trie, palavra);
  }
  //-------------------------------------------------------------------------------------
  int op;
  while(1) {
    printf("1-Inserir palavra\n2-Buscar palavra\n3-Remover palavra\n4-Imprimir Trie\n5-Imprimir prefixo");
    printf("\n6-Finalizar execucao\nQual opcao?: ");
    scanf("%i", &op);
    switch (op) {
      //-------------------------------------------------------------------------------------
      case 1:
        printf("Qual palavra deseja inserir?\n");
        scanf("%s", palavra);
        setbuf(stdin, NULL); 
        if (insereTrie(trie, palavra)) {
          printf("Sucesso na insercao de %s\n", palavra);
        } else {
          printf("Falha na insercao %s\n", palavra);
        }
        break;
      //-------------------------------------------------------------------------------------
      case 2:
        printf("Qual palavra deseja buscar?\n");
        scanf("%s", palavra);
        setbuf(stdin, NULL); 
        if (buscaTrie(trie, palavra)) {
          printf("Esta palavra esta na arvore\n");
        } else {
          printf("Esta palavra nao esta na arvore\n");
        }
        break;
      //-------------------------------------------------------------------------------------
      case 3:
        printf("Qual palavra deseja remover?\n");
        scanf("%s",palavra);
        setbuf(stdin, NULL); 
        if(removeTrie(trie, palavra))
          printf("Sucesso na remocao\n");
        else
          printf("Falha na remocao\n");  
        break;
      //-------------------------------------------------------------------------------------
      case 4:
        imprimeTrie(trie);
        break;
      //-------------------------------------------------------------------------------------
      case 5:
        printf("Qual palavra deseja utilizar?\n");
        scanf("%s", palavra);
        setbuf(stdin, NULL); 
        autocompletarTrie(trie, palavra);
        break;
      //-------------------------------------------------------------------------------------
      case 6:
        printf("Liberando a arvore\n");
        liberaTrie(trie);
        printf("Fim da execucao\n");
        return 0;
      default: 
        printf("Opcao invalida!\n");
        break;
    }
     system("pause"); //windows
     system("cls"); //windows
  }
  liberaTrie(trie);
  free(arq);
  return 0;
}