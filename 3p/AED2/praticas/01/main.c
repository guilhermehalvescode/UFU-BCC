#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "ListaSequencial.h"
#include "ListaDinEncad.h"

#define N 3000

int main(){
    Lista* seq = cria_lista();
    int i;
    struct aluno n[N] = {12, "joao", 12.4, 25.3, 18.9};
    clock_t inicio, fim;
    unsigned long int tempo;
    inicio = clock();
    for(i = 0; i < N; i++) {
        insere_lista_final(seq, n[i]);
    }
    fim = clock();
    tempo = (fim - inicio)*1000/CLOCKS_PER_SEC;
    printf("Tempo: %lu milisegundo\n", tempo);
    char c = getchar();
    return 0;
}
