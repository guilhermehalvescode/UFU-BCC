//Definicao de tamanhos
#define max 30
//Expondo lista
typedef struct deque *Deque;
//Metodos das estruturas
Deque cria_deque();
int deque_vazio(Deque);
int deque_cheio(Deque);
int push(Deque, int);      //insert end
int pop(Deque, int *);     //remove end
int shift(Deque, int *);   //remove beg
int unshift(Deque, int);   //insert beg
int libera_deque(Deque *); //apaga tudo
int get_size(Deque);
// printf("1: Criar deque\n");
// printf("2: Insere no comeco\n");
// printf("3: Remove no comeco\n");
// printf("4: Insere no final\n");
// printf("5: Remove no final\n");
// printf("6: Print\n");
// printf("7: Apaga deque\n");
// printf("8: Sair\n");