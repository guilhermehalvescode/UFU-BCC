#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trie.h"
#define MAX_CHARS 26

#define hashChar(c) tolower(c) - 97
#define getChar(i) (char) (i + 97)
struct Trie {
  struct Trie *child[MAX_CHARS];
  unsigned short int end;
};

//Função auxiliar que cria um nó a árvore
Trie startNode();
//Função recursiva para liberar os nós
void freeNodes(Trie tr);
//Função auxiliar para vericar se é uma folha na árvore
int isLeaf(Trie tr);
//Função recursiva auxiliar para printar trie
void imprimeSubTrie(Trie tr, char *word, int tam);
//Função auxiliar para recuperar nó raiz da árvore com o prefixo passado
Trie arvorePrefixo(Trie tr, char *prefixo);


Trie* criaTrie() {
  Trie* root = (Trie*) malloc(sizeof(Trie));
  if(root) {
    //Inicializa trie com um nó inicial, o qual é a string vazia
    *root = startNode(); 
    if(!(*root)) {
      free(root);
      root = NULL;
    }
  }
  return root;
}

void liberaTrie(Trie *tr) {
  if(!tr) return;
  freeNodes(*tr);
  *tr = NULL;
  free(tr);
}

int insereTrie(Trie *tr, char *str) {
  if (!tr || !str)
    return 0;
  Trie node = *tr;
  //Pega a primeira letra da string
  char letter = *str; 
  //Se for o caractere terminador, a string foi inserida na trie
  if (letter == '\0') {
    //Ao inserir, marca o nó como terminador
    node->end = 1;
    return 1;
  }
  if(isalpha(letter)) {
    int pos = hashChar(letter), noCriado = 0;
    //Se for letra, olha nos filhos se já existe a letra no nó
    if(!node->child[pos]) {
      //Se não existir, cria a letra na trie
      Trie newNode = startNode();
      if(!newNode)
        return 0;
      node->child[pos] = newNode;
      noCriado = 1;
    }
    //Desçe na árvore e avança o ponteiro para o próximo caractere da string a inserir
    if(!insereTrie(&(node->child[pos]), str + 1)) {
      //Caso tenha ocorrido algum erro na inserção, 
      //se um filho foi criado, precisa ser deletado
      if(noCriado) {
        free(node->child[pos]); 
        node->child[pos] = NULL;
      }
      return 0;
    }
    return 1;
  } else 
    // Se não for letra, ignora, e avança o ponteiro para o próximo caractere da string a inserir
    return insereTrie(tr, str + 1); 
}

int buscaTrie(Trie *tr, char *str) {
  if (!tr || !str)
    return 0;
  Trie node = *tr;
  //Pega primeira letra
  char letter = *str;

  //Se primeira letra for o caractere terminador e o nó for terminado, string está na árvore
  if (letter == '\0' && node->end) 
    return 1;
    
  if(isalpha(letter)) { 
    int pos = hashChar(letter);
    //Se não tiver filho com a respectiva letra, string não está na trie
    if (!node->child[pos])
      return 0;
    //Desçe na árvore e avança o ponteiro para o próximo caractere da string a procurar
    return buscaTrie(&(node->child[pos]), str + 1);
  } else 
    //Ignora caracteres não alfa na string
    return buscaTrie(tr, str + 1);
}


int removeTrie(Trie *tr, char *str) {
  if (!tr || !str)
    return 0;
  Trie node = *tr;
  //Pega primeira letra
  char letter = *str;

  //Se primeira letra for o caractere terminador e o nó for terminado, string está na árvore
  if (letter == '\0' && node->end){ 
    node->end = 0;
    return 1;
  }
  if(isalpha(letter)) { 
    int pos = hashChar(letter);
    //Se não tiver filho com a respectiva letra, string não está na trie
    if (!node->child[pos])
      return 0;
    //Desçe na árvore e avança o ponteiro para o próximo caractere da string a procurar
    if(removeTrie(&(node->child[pos]), str + 1)){
      if(isLeaf(node->child[pos]) && !(node->child[pos]->end)){
        free(node->child[pos]);
        node->child[pos] = NULL;
      }
        return 1;
    } 
    return 0;
  } else 
    //Ignora caracteres não alfa na string
    return removeTrie(tr, str + 1);
}

void imprimeTrie(Trie *tr) {
  if (!tr) return;
  //Cria um vetor auxiliar para imprimir a trie;
  char word[256];
  //Imprime a subTrie com o seu tamanho (chamada inicial: string vazia com tamanho 0) 
  imprimeSubTrie(*tr, word, 0);
}

void autocompletarTrie(Trie *tr, char *prefixo) {
  if(!tr || !prefixo) return;
  //arvorePrefixo desce na Trie até a subTrie com o prefixo passado, retornando o nó raiz dela
  //para a imprimiSubTrie que imprime uma árvore
  char word[256];
  strcpy(word, prefixo);
  imprimeSubTrie(arvorePrefixo(*tr, prefixo), word, strlen(word));
}


/* FUNÇÕES AUXILIARES */
Trie startNode() {
  Trie node = (Trie) malloc(sizeof(struct Trie));
  if (node) {
    for (size_t i = 0; i < MAX_CHARS; i++)
      node->child[i] = NULL;
    node->end = 0;
  }
  return node;
}

void freeNodes(Trie tr) {
  if (!tr)
    return;
  for (size_t i = 0; i < MAX_CHARS; i++) {
    if (tr->child[i])
      freeNodes(tr->child[i]);
  }
  free(tr);
}

void imprimeSubTrie(Trie tr, char *word, int tam) {
  if(!tr || !word || tam < 0) return;
  //Se for um nó terminador, printo a word
  if(tr->end) {
    word[tam] = '\0';
    printf("%s\n", word);
  }
  //Se tiver filho, coloco o caractere para printar
  for(size_t i = 0; i < MAX_CHARS; i++) {
    if(tr->child[i]) {
      word[tam] = getChar(i);
      imprimeSubTrie(tr->child[i], word, tam + 1);
    }
  }
}

Trie arvorePrefixo(Trie tr, char *prefixo) {
  if(!tr || !prefixo) return NULL;
  //Pego a primeira letra do prefixo
  char letter = *prefixo;
  //Se for o caractere terminador, a arvoré tr é a desse prefixo
  if (letter == '\0') 
    return tr;
  if(isalpha(letter)) {
    int pos = hashChar(letter);
    if(tr->child[pos]) {
      //Busco o prefixo na árvore descendo nela 
      return arvorePrefixo(tr->child[pos], prefixo + 1);
    } else return NULL; //prefixo não encontrado, retorna NULL
  } else
    //Ignora caracteres não alfa na string
    return arvorePrefixo(tr, prefixo + 1);
}

int isLeaf(Trie tr){
  for(size_t i = 0;i < MAX_CHARS;i++){
    if(tr->child[i] != NULL)
      return 0;
  }
  return 1;
}
