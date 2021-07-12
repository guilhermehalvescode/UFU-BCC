#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // SOMENTE PARA SISTEMAS SUPERIORES
#include "deque.h"
#define tam 3
int main(int argc, char const *argv[])
{
  int option = 1, continuar = 1, tmp = 0, tmp2 = 0, qnt_lista = 0;
  float elemento;
  Deque lst[tam];
  int lst_ocupados[tam] = {0};
  while (continuar)
  {
  get_back_here:
    printf("1: Criar lista\n");
    printf("2: Insere no comeco\n");
    printf("3: Remove no comeco\n");
    printf("4: Insere no final\n");
    printf("5: Remove no final\n");
    printf("6: Print\n");
    printf("7: Apaga lista\n");
    printf("8: Sair\n");
    printf("\nOpcao: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      /* CRIANDO DEQUE */
      if (qnt_lista < tam)
      {
        int i;
        for (i = 0; i < tam; i++)
        {
          if (lst_ocupados[i] == 0)
            break;
        }

        lst[i] = cria_deque();
        printf("Lista %d criada com sucesso\n", i + 1);
        lst_ocupados[i]++;
        qnt_lista++;
      }
      else
      {
        printf("Quantidade maximas de listas criadas tente outro comando\n");
      }
      sleep(1);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;

    case 2:
      /* INSERINDO NO COMECO */
      if (qnt_lista == 0)
        goto get_back_here;

      printf("Em qual comeco de lista deseja inserir");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i + 1);
      printf(": ");
      scanf("%d", &tmp);
      printf("Insira o num que deseja inserir na lista %d: ", tmp);
      tmp--;
      setbuf(stdin, NULL);
      scanf("%f", &elemento);
      if (unshift(lst[tmp], elemento))
      {
        printf("Sucesso\n");
        sleep(0.3);
        system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      }
      else
      {
        printf("Erro");
        sleep(1);
        system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      }

      break;

    case 3:
      /* REMOVENDO NO COMECO */
      if (qnt_lista == 0)
        goto get_back_here;
      /* REMOVE NO COMECO */
      printf("Em qual comeco de lista deseja remover");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i + 1);
      printf(": ");
      scanf("%d", &tmp);
      tmp--;
      if (shift(lst[tmp], &elemento))
        printf("%f foi removido\n", elemento);
      else
        printf("Erro ao remover na posicao %d\n", tmp2);
      sleep(1);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;
    case 4:
      if (qnt_lista == 0)
        goto get_back_here;
      /* INSERE NO FINAL */
      printf("Em qual final de lista deseja inserir");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i + 1);
      printf(": ");
      scanf("%d", &tmp);
      printf("Insira o num que deseja inserir na lista %d: ", tmp);
      setbuf(stdin, NULL);
      scanf("%f", &elemento);
      setbuf(stdin, NULL);
      tmp--;
      if (push(lst[tmp], elemento))
      {
        printf("Sucesso\n");
        sleep(0.3);
        system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      }
      else
      {
        printf("Erro\n");
        sleep(1);
        system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      }
      break;
    case 5:
      /* REMOVE NO FINAL */
      if (qnt_lista == 0)
        goto get_back_here;
      printf("Em qual final de lista deseja remover");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i + 1);
      printf(": ");
      scanf("%d", &tmp);
      setbuf(stdin, NULL);
      tmp--;
      if (pop(lst[tmp], &elemento))
        printf("%.2f foi removido\n", elemento);
      else
        printf("Erro ao remover\n");
      sleep(1);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;

    case 6:
      /* IMPRIMINDO LISTA */
      if (qnt_lista == 0)
        goto get_back_here;
      printf("Qual lista deseja imprimir");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i + 1);
      printf(": ");
      scanf("%d", &tmp);
      tmp--;
      //alocando um array pra guardar os elementos q retirar
      Deque deque_auxiliar = cria_deque();
      while (!deque_vazio(lst[tmp]))
      {
        shift(lst[tmp], &elemento);
        push(deque_auxiliar, elemento);
        printf("[%.2f] ", elemento);
      }
      while (!deque_vazio(deque_auxiliar))
      {
        shift(deque_auxiliar, &elemento);
        push(lst[tmp], elemento);
      }
      libera_deque(&deque_auxiliar);
      printf("\n");
      sleep(1);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;

    case 7:
      /*APAGANDO UMA LISTA*/
      if (qnt_lista == 0)
        goto get_back_here;
      /* APAGANDO UMA LISTA*/
      printf("Qual lista deseja apagar");
      for (size_t i = 0; i < qnt_lista; i++)
      {
        if (lst_ocupados[i] == 1)
          printf(" %ld", i + 1);
      }
      printf(": ");
      scanf("%d", &tmp);
      tmp--;
      libera_deque(&lst[tmp]);
      lst_ocupados[tmp]--;
      qnt_lista--;
      printf("\n");
      sleep(1);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;
    case 8:
      //SAIR DO LOOP
      continuar = 0;
      break;
    default:
      printf("Opcao invalida, tente novamente\n");
      sleep(1);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;
    }
  }
  return 0;
}
