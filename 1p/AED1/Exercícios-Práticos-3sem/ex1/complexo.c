#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"

struct num {
    double real, imag;
};

//procedimento que cria uma número real
complex* cria_nro(double real, double imag) {
    complex *z;
    //cria um número complexo composto pela parte imaginária e real.
    z = (complex*) malloc(sizeof(complex));
    if(z != NULL) {
        //atribui os valores passados para a função na estrutura criada
        //se a aloção for bem sucedida.
        z->real = real;
        z->imag = imag;
    }
    //retorna o endereço do númeoro imaginário se foi sucedida sua criação
    //senão, retorna NULL
    return z;
}

//procedimento que elimina um número complexo
void libera_nro(complex* *z) {
    //desaloca a memória usada pelo número
    free(*z);
    //desreferência o número para não ser mais acessado
    *z = NULL;
}

//procedimento que soma dois números complexos
complex* soma(complex *a, complex *b) {
    //verifica se um dos números é valido
    if(a == NULL || b == NULL){
        return NULL;
    }
    //retora o endereço do número imaginário criado na soma
    return cria_nro(a->real + b->real, a->imag + b->imag);
}

//procedimento que subtrai dois números complexos
complex* sub(complex *a, complex *b) {
    //verifica se um dos números é valido
    if(a == NULL || b == NULL){
        return NULL;
    }
    //retora o endereço do número imaginário criado na soma
    return cria_nro(a->real - b->real, a->imag - b->imag);
}

//procedimento que multiplica dois números complexos
complex* mult(complex *a, complex *b) {
    //verifica se um dos números é valido
    if(a == NULL || b == NULL){
        return NULL;
    }
    //retora o endereço do número imaginário criado na soma
    double real = (a->real * b->real) - (a->imag * b->imag);
    double imag = (a->real * b->imag) + (a->imag * b->real);
    return cria_nro(real, imag);
}

int get_complex(complex *a, double *real, double *imag) {
    if(a == NULL) {
        return 0;
    }
    *real = a->real;
    *imag = a->imag;
    return 1;
}
