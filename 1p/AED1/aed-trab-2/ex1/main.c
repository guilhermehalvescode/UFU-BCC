#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lista.h"

int converter_para(Pilha pil, int elem, char *result, int base){
  int cont = 0, aux = 0, check;

  if(elem == 0){
    // trata quando for 0
    result[0] = '0';
    result[1] = '\0';
    
    return 1;
  }
  while (elem != 0)
  {
    // faz as divisoes sucessivas pela base, 
    // colocando o resto dentro da pilha como inteiro
    check = push(pil, elem%base);
    if(!check) return -1; // falha ao inserir algo na pilha
    elem /= base;
  }

  while (pop(pil, &aux))
  {
    // esvazia a pilha de cima para baixo pegando os valores na ordem
    // inversa que foram inseridos, e transformandos em CHAR
    if(base == 16 && aux > 9){
      // se for hexa e maior que 9, usa-se caracteres
      result[cont] = 55 + aux;
      cont++;
      
      continue;
    }
    // transforma o numero int em seu respectivo char na tabela ascii
    result[cont] = aux + '0'; 
    cont++;
  }
  result[cont] = '\0';

  return 1;
}

int main()
{
  Pilha pil = cria();
  int elem = 0, check;
  char base, result[30];

  if (!pil){
    printf("Sem memoria!\n");
    return -1;
  };

  while (elem >= 0)  
  {
    printf("Informe o valor a ser convertido: ");
    scanf("%d", &elem);

    if(elem < 0) break;

    printf("Informe a base(B, O, H): ");
    setbuf(stdin, NULL);
    scanf("%c", &base);

    if(base == 'B'){
      check = converter_para(pil, elem, result, 2);
      if(!check) return -1;
      printf("Resultado em binario: %s\n", result);
    }else if(base == 'O'){
      check = converter_para(pil, elem, result, 8);
      if(!check) return -1;
      printf("Resultado em octal: %s\n", result);
    }else if(base == 'H'){
      check = converter_para(pil, elem, result, 16);
      if(!check) return -1;
      printf("Resultado em hexadecimal: %s\n", result);
    }else {
      printf("base invalida!\n");
    }
    
    esvazia(pil);
  };
  
  system("pause");
  return 0;
}