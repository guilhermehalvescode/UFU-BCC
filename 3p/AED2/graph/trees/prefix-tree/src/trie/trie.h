typedef struct Trie* Trie;
Trie* criaTrie();
void liberaTrie(Trie* tr);
int insereTrie(Trie* tr, char *str);
int buscaTrie(Trie* tr, char *str);
int removeTrie(Trie* tr, char *str);

//imprime todas as palavras armazenadas
void imprimeTrie(Trie* tr); 
//imprime todas as palavras que começam com “prefixo”
void autocompletarTrie(Trie* tr, char *prefixo);