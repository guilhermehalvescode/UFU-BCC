typedef struct node** ArvBin;

ArvBin initBinTree();
void freeBinTree(ArvBin root);
int heightBinTree(ArvBin root);
int numVertexesBinTree(ArvBin root);
void preOrderBinTree(ArvBin root);
void orderedBinTree(ArvBin root);
void posOrderBinTree(ArvBin root);