#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // SOMENTE PARA SISTEMAS SUPERIORES
#include "lista.h"
#define tam 3
int main(int argc, char const *argv[])
{
  int option = 1, continuar = 1, tmp = 0, tmp2 = 0, qnt_lista = 0;
  char letra;
  Lista lst[tam];
  int lst_ocupados[tam] = {0};
  while (continuar)
  {
    printf("1: Criar lista lst\n2: Insere na lista\n3: Remove primeira ocorrencia\n4: Remove segundo a posicao\n5: Imprimir lista\n6: Limpar uma lista\n7: Tamanho e uma lista\n8: Ver se as listas sao iguais\n9: Exibir maior elemento de uma lista\n10: Intercalar duas listas em uma terceira\n11: Sair\n\nOpcao: ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      /* CRIANDO LISTA */
      if (qnt_lista < tam)
      {
        int i;
        for (i = 0; i < tam; i++)
        {
          if (lst_ocupados[i] == 0)
            break;
        }

        lst[i] = cria_lista();
        printf("Lista %d criada com sucesso\n", i);
        lst_ocupados[i]++;
        qnt_lista++;
      }
      else
      {
        printf("Quantidade maximas de listas criadas tente outro comando\n");
      }
      sleep(2);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;

    case 2:
      /* INSERINDO NA LISTA */

      printf("Em qual lista deseja inserir");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d", &tmp);
      printf("Insira a letra que deseja inserir na lista %d: ", tmp);
      setbuf(stdin, NULL);
      scanf("%c", &letra);
      if (insere_ord(&lst[tmp], letra))
      {
        printf("Sucesso");
        sleep(0.3);
        system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      }
      else
      {
        printf("Erro");
        sleep(2);
        system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      }

      break;

    case 3:
      printf("Em qual lista deseja remover");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d", &tmp);
      printf("Insira o numero que deseja remover: ");
      setbuf(stdin, NULL);
      scanf("%c", &letra);
      remove_ord(&lst[tmp], letra);

      sleep(2);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;
    case 4:
      /* REMOVENDO POSIÇÃO */
      printf("Em qual lista deseja remover");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d", &tmp);

      printf("Insira a posicao que deseja remover: ");
      scanf("%d", &tmp2);
      if (remove_pos(&lst[tmp], tmp2, &letra))
        printf("%c foi removido\n", letra);
      else
        printf("Erro ao remover na posicao %d\n", tmp2);
      sleep(2);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;
    case 5:
      /* IMPRIMINDO LISTA */
      printf("Qual lista deseja imprimir");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d", &tmp);
      size_t i = 0;
      while (obtem_valor_elem(&(lst[tmp]), i, &letra))
      {
        printf("%c ", letra);
        i++;
      }
      printf("\n");
      sleep(2);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;

    case 6:
      printf("Qual lista deseja limpar");
      for (size_t i = 0; i < qnt_lista; i++)
      {
        if (lst_ocupados[i] == 1)
          printf(" %ld", i);
      }
      printf(": ");
      scanf("%d", &tmp);
      esvazia_lista(&lst[tmp]);
      lst_ocupados[tmp]--;
      sleep(2);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;
    case 7:
      //TAMANHO
      printf("Qual lista deseja ver o tamanho");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d", &tmp);
      printf("Tamanho da lista %d: %d", tmp, obtem_tamanho(&lst[tmp]));

      sleep(2);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES

      break;
    case 8:
      //VER SE AS LISTAS SAO IGUAIS
      printf("Quais lista vai comparar");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d %d", &tmp, &tmp2);
      if (listas_iguais(&lst[tmp], &lst[tmp2]))
        printf("Listas iguais\n");
      else
        printf("Listas diferentes\n");
      sleep(1);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES

      break;
    case 9:
      //MAIOR ELEMENTO
      printf("Qual lista deseja ver o tamanho");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d", &tmp);
      if (maior_elem(&lst[tmp], &letra))
        printf("Maior elemento %c\n", letra);
      else
        printf("Nao consegui achar o maior elemento\n");
      sleep(1);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;
    case 10:
      //INTERCALAR
      printf("Quais lista serao intercaladas");
      for (size_t i = 0; i < qnt_lista; i++)
        printf(" %ld", i);
      printf(": ");
      scanf("%d %d", &tmp, &tmp2);
      int tmp3 = 3;
      printf("Qual lista recebera a lista resultante (sera apagada antes de receber os valores): ");
      scanf("%d", &tmp3);
      esvazia_lista(&lst[tmp3]);
      if (intercalar(&lst[tmp], &lst[tmp2], &lst[tmp3]))
        printf("Listas intercaladas com sucesso\n");
      else
        printf("Erro\n");
      sleep(1);
      system("clear"); //MUDAR PRA CLS PRA SISTEMAS INFERIORES
      break;
    case 11:
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
