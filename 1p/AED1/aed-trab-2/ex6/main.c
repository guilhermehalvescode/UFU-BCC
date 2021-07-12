#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "doador.h"

void imprimir_pacientes(Fila *fil){
  Fila copia = cria();
  char nome[30];
  int grau = 0, idade = 0, orgao = 0;

  if(vazia(*fil))
  {
    printf("Fila vazia!\n");
    
    return;
  }

  while (!vazia(*fil))
  {
    remover_inicio(fil, nome, &idade, &orgao, &grau);
    printf("\tNome: %s\tIdade: %d\n\tOrgao: %d\n\tGrau: %d\n", nome, idade, orgao, grau);
    inserir(&copia, nome, idade, orgao, grau);
    printf("-----------------------------------\n");
  };

  while (!vazia(copia))
  {
    remover_inicio(&copia, nome, &idade, &orgao, &grau);
    inserir(fil, nome, idade, orgao, grau);
  };
  esvaziar(&copia);
}

void imprimir_doadores(ListaDoadores doadores){
  if(vazia_doadores(doadores)){
    printf("Lista vazia!\n");
      return;
  }
  
  char nome[30];
  char *orgaos[5];
  int i = 0;

  for (size_t i = 0; i < 5; i++)
  {
    orgaos[i] = (char *) malloc(sizeof(char)*30);
    if(!orgaos[i]){
      printf("Compra memoria!\n");
      return;
    }
  }

  while(posicao_doador(doadores, i, nome, orgaos)){
    printf("\tDoador: %s", nome);
    for (int j = 0; j < 5; j++)
    {
      printf("\tOrgao[%d] = ", j);
      if(orgaos[j][0] == '0')
        printf("Nao doador!\n");
      else if(orgaos[j][0] == '1')
        printf("Disponivel!\n");
      else
        printf("Doado para o paciente de nome: %s", orgaos[j]);
    }
    printf("------------------------\n");
    i++;
  }
}

int main()
{
  Fila fil[5];
  ListaDoadores doadores = cria_lista_doadores();

  for (size_t i = 0; i < 5; i++)
  {
    // inicializa as filas de cada orgao
    fil[i] = cria();
  }
  
  char nome[30];
  int grau = 0, idade = 0, orgao = 0, opcao = 0, orgaos[5];

  while (opcao != 7)  
  {
    printf("Escolha uma opcao:\n");
    printf("[1] Inserir paciente\n");
    printf("[2] Remover paciente\n");
    printf("[3] Imprimir pacientes\n");
    printf("[4] Esvaziar lista de pacientes\n");
    printf("[5] Inserir doador\n");
    printf("[6] Imprimir doadores\n");
    printf("[7] Sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      printf("Digite o nome do paciente: ");
      setbuf(stdin, NULL);
      fgets(nome, 30, stdin);
      printf("Digite a idade: ");
      scanf("%d", &idade);
      printf("Digite o grau: ");
      scanf("%d", &grau);
      printf("Digite o orgao necessitado\n(0-coracao, 1-figado, 2-rins, 3-corneas e 4-pulmoes): ");
      scanf("%d", &orgao);
      if (orgao < 0 || orgao > 4)
      {
        printf("\tOrgao invalido!\n");
        break;
      }
      
      if(verifica_pacientes(&doadores, nome, orgao)){
        printf("Orgao ja disponivel pro paciente, transplante feito!\n");

        break;
      }

      if(inserir(&fil[orgao], nome, idade, orgao, grau))
        printf("\tPaciente adicionado com sucesso!\n");
      else
        printf("\tFalha ao adicionar, sem memória!\n");
      break;
    case 2:
      printf("Digite o orgao da fila a ser removido\n(0-coracao, 1-figado, 2-rins, 3-corneas e 4-pulmoes): ");
      scanf("%d", &orgao);
      if (orgao < 0 || orgao > 4)
      {
        printf("\tOrgao invalido!\n");
        break;
      }
      if (remover_inicio(&fil[orgao], nome, &idade, &orgao, &grau))
        printf("\tPaciente removido: %s\tIdade: %d\n\tOrgao: %d\n\tGrau: %d\n", nome, idade, orgao, grau);
      else 
        printf("\tFalha ao remover, lista vazia!\n");

      break;
    case 3:
      printf("Digite a fila de orgaos a ser impressa\n(0-coracao, 1-figado, 2-rins, 3-corneas e 4-pulmoes): ");
      scanf("%d", &orgao);
      if (orgao < 0 || orgao > 4)
      {
        printf("\tOrgao invalido!\n");
        break;
      }
      imprimir_pacientes(&fil[orgao]);

      break;
    case 4:
      printf("Digite a fila de orgaos a ser esvaziada\n(0-coracao, 1-figado, 2-rins, 3-corneas e 4-pulmoes): ");
      scanf("%d", &orgao);
      if (orgao < 0 || orgao > 4)
      {
        printf("\tOrgao invalido!\n");
        break;
      }
      if(esvaziar(&fil[orgao]))
        printf("\tFila esvaziada com sucesso!\n");
      else
        printf("\tErro ao esvaziar fila!\n");

      break;
    case 5:
      printf("Digite o nome do doador: ");
      setbuf(stdin, NULL);
      fgets(nome, 30, stdin);
      printf("Responda com (1) para sim, e (0) para nao:\n");
      printf("O paciente ira doar coracao: ");
      scanf("%d", &orgaos[0]);
      printf("O paciente ira doar figado: ");
      scanf("%d", &orgaos[1]);
      printf("O paciente ira doar rins: ");
      scanf("%d", &orgaos[2]);
      printf("O paciente ira doar cornea: ");
      scanf("%d", &orgaos[3]);
      printf("O paciente ira doar pulmao: ");
      scanf("%d", &orgaos[4]);

      inserir_doador(&doadores, nome, orgaos);

      // verifica se tem paciente precisando de algum orgao desse doador
      for (size_t i = 0; i < 5; i++)
      {
        if(orgaos[i] && !vazia(fil[i])){
          // tem paciente necessitado nessa fila de orgaos
          // doar o orgao pra esse paciente
          remover_inicio(&fil[i], nome, &idade, &orgao, &grau);
          
          if(verifica_pacientes(&doadores, nome, orgao))
            printf("Orgao %d doado para %s", orgao, nome);
        }
      }
      
      break;
    case 6:
      imprimir_doadores(doadores);

      break;
    case 7:
      break;
    default:
      printf("\tOpcao invalida!\n");
      break;
    }
  };

  for (size_t i = 0; i < 5; i++)
  {
    free(fil[i]);
  }

  return 0;
}