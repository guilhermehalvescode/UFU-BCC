
typedef struct hash Hash;
Hash* criaHash(int TABLE_SIZE, int TAMANHO_TIPO);
void liberaHash(Hash* ha);
int insereHash(Hash* ha, int chave, void *dados);
int buscaHash(Hash* ha, int chave, void *dados);