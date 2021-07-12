typedef struct deque *Deque;
//Metodos das estruturas
Deque cria_deque();
int deque_vazio(Deque);
int push(Deque, float);    //insert end
int pop(Deque, float *);   //remove end
int shift(Deque, float *); //remove beg
int unshift(Deque, float); //insert beg
int libera_deque(Deque *); //apaga tudo
int get_size(Deque queue);
// printf("1: Criar deque\n");
// printf("2: Insere no comeco\n");
// printf("3: Remove no comeco\n");
// printf("4: Insere no final\n");
// printf("5: Remove no final\n");
// printf("6: Print\n");
// printf("7: Apaga deque\n");
// printf("8: Sair\n");