#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"
//inicializa o polinomio
void inicializa(Lista *lst) {
    if(lista_vazia(*lst)) {
        if(insere_ord(lst, 0, 0))
            printf("Polinomio foi (re)inicializado com sucesso!\n\n");
        else
            printf("Nao foi possivel (re)inicializar o polinomio!\n\n");        
    } else 
        printf("O polinomio ja se encontra inicializado!\n\n");
}
//insere o termo no polinomio
void insere(Lista *lst) {
    int expo, coefic;
    do {
        printf("Digite o valor do expoente: ");
        scanf("%d", &expo);
    } while(expo < 0);
    printf("Digite o valor do coeficiente: ");
    scanf("%d", &coefic);
    int coeficiente;
    if(obtem_valor(*lst, expo, &coeficiente)) {
        remove_ord(lst, expo);
        coefic += coeficiente;
    } 
    if(!insere_ord(lst, expo, coefic)) {
        printf("(Overflow na memoria) Nao e possivel inserir o termo!\n\n");
        return;
    }
    printf("Termo inserido com sucesso!\n\n");
    return;
}


void print_polinome(Lista lst) {
    printf("Polinomio: ");
    int i = 0, expo, coeficiente;
    while(obtem_posicao(lst, i, &expo, &coeficiente)) {
        if(i != 0) 
            printf(" ");
        if(coeficiente != 0) {
            if(coeficiente > 0) 
                printf("+");
            if(coeficiente != 1)
                printf("%d", coeficiente);
            if(expo != 0)
                printf("x");
            if(expo > 1) 
                printf("^%d", expo);
        }
        i++;
    }
    printf("\n\n");
}

void remove_termo(Lista *lst) {
    int k;
    printf("Digite k: ");
    scanf("%d", &k);
    if(remove_ord(lst, k)) 
        printf("Elemento removido com sucesso!\n\n");
    else 
        printf("Elemento nao se encontra na lista!\n\n");
    return;
}

void reinicializar(Lista *lst) {
    limpa_lista(lst);
    inicializa(lst);
}

void calcular_px(Lista lst) {
    int i = 0, x, expo, coeficiente, res = 0;
    printf("Digite x: ");
    scanf("%d", &x);
    while(obtem_posicao(lst, i, &expo, &coeficiente)) {
        res += coeficiente * pow(x, expo);
        i++;
    }
    printf("P(%d) = %d\n\n", x, res);
}

int main() {
    Lista polinome;
    polinome = cria_lista();
    int escolha;
    do {
        printf("------Polinomios-------\n");
        printf("(1) Inicializar P(x)\n");
        printf("(2) Inserir um novo termo em P(x)\n");
        printf("(3) Imprimir P(x)\n");
        printf("(4) Remover o termo da k-esima potencia de P(x)\n");
        printf("(5) Reinicializar P(x)\n");
        printf("(6) Calcular P(x), dado um valor x\n");
        printf("(7) Sair do sistema\n");
        printf("Digite a sua escolha: ");
        scanf("%d", &escolha);
        printf("\n");
        switch(escolha) {
            case 1:
                inicializa(&polinome);
                break;
            case 2:
                insere(&polinome);
                break;
            case 3:
                print_polinome(polinome);
                break;
            case 4:
                remove_termo(&polinome);
                break;
            case 5:
                reinicializar(&polinome);
                break;
            case 6:
                calcular_px(polinome);
                break;
            case 7:
                printf("Saindo do programa...");
                return 1;
            default:
                break;
        }
    } while(1);
    return 0;
}