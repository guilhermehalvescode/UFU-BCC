#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

struct node {
  int info;
  struct node* left;
  struct node* right;
};


ArvBin initBinTree() {
  ArvBin root = (ArvBin) malloc(sizeof(struct node*));

  if(root != NULL) 
    *root = NULL;
  
  return root;
}

void freeNode(struct node* node) {
  if(node == NULL) return;
  freeNode(node->left);
  freeNode(node->right);
  free(node);
  node = NULL; //Precisa disso??
}

void freeBinTree(ArvBin root) {
  if(root == NULL) return;
  freeNode(*root);
  free(root);
}

int heightBinTree(ArvBin root) {
  if(root == NULL || *root == NULL) return 0;
  int h_left = heightBinTree(&((*root)->left));
  int h_right = heightBinTree(&((*root)->right));
  return h_left > h_right ? h_left + 1 : h_right + 1;
}

int numVertexesBinTree(ArvBin root) {
  if(root == NULL || *root) return 0;
  int numVertexesLeft = numVertexesBinTree(&((*root)->left));
  int numVertexesRight = numVertexesBinTree(&((*root)->right));
  return numVertexesLeft + numVertexesRight + 1;
}

void preOrderBinTree(ArvBin root) {
  if(root == NULL) return;
  if(*root != NULL) {
    printf("%d\n", (*root)->info);
    preOrderBinTree(&((*root)->left));
    preOrderBinTree(&((*root)->right));
  }
}

void orderedBinTree(ArvBin root) {
  if(root == NULL) return;
  if(*root != NULL) {
    orderedBinTree(&((*root)->left));
    printf("%d\n", (*root)->info);
    orderedBinTree(&((*root)->right));
  }
}

void posOrderBinTree(ArvBin root) {
  if(root == NULL) return;
  if(*root != NULL) {
    posOrderBinTree(&((*root)->left));
    posOrderBinTree(&((*root)->right));
    printf("%d\n", (*root)->info);
  }
}