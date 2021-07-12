#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
 
#define max 20

struct pilha
{ 
  int vetor[max];
  int topo;
}; 

Pilha cria()
{ 
  // Aloca a pilha na memoria
  Pilha resultado = (Pilha) malloc(sizeof(struct pilha));

  if (resultado){
    // verifica se alocou com sucesso
    resultado->topo = -1;
  }

  return resultado;
}

int vazia(Pilha pil)
{ 
  // verifica se o topo é menor que 0, se sim, a pilha esta vazia
  return pil->topo < 0;
}

int cheia(Pilha pil)
{ 
  // verifica se o topo é igual ao max-1, se sim, a pilha esta cheia
  return (pil->topo == max - 1);
}

int esvazia(Pilha pil)
{ 
  // verifica se esta ja esta vazia
  if (vazia(pil)){
    return -1;
  }
  // Define o topo como -1, esvaziando a pilha
  pil->topo = -1;
  
  return 1;
}

int push(Pilha pil, int elem)
{ 
  // checa se a pilha esta cheia ou é NULL antes de inserir
  if(!cheia(pil) || !pil){
    // adiciona o valor no topo e aumenta o contador
    pil->topo++;
    pil->vetor[pil->topo] = elem;

    return 1;
  } else {
    return 0;
  }
}

int pop(Pilha pil, int *elem)
{ 
  // checa se a pilha esta vazia ou é NULL antes de remover
  if (!pil || vazia(pil))
    return 0;
  // pega o elemento do topo para retornar e diminui o contador
  *elem = pil->vetor[pil->topo];
  pil->topo--;
  
  return 1;
}


int le_topo(Pilha pil, int *elem)
{ 
  // checa se a pilha ta vazia ou é NULL
  if (vazia(pil) || !pil){
    return 0;
  }
  // retorna o elemento no topo da pilha usando o contador
  *elem = pil->vetor[pil->topo];

  return 1;
}