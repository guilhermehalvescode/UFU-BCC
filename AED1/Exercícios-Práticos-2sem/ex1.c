#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    double media;
    int faltas;
} info;



void selectionSort(info *vet, int n) {
    int i, ordenados;
    for(ordenados = 0; ordenados < n - 1; ordenados++) {
        int menor = ordenados;
        for(i = ordenados + 1; i < n; i++) {
            if(vet[i].media < vet[menor].media) menor = i;
        }
        if(ordenados != menor) {
            info aux = vet[ordenados];
            vet[ordenados] = vet[menor];
            vet[menor] = aux;
        }
    }
}

info* aloca(int n) {
    info *pointer;
    pointer = (info*) malloc(n * sizeof(info));
    if(pointer == NULL){
        printf("Erro na alocacao!!");
        exit(1);
    }
    return pointer;
}

void preenche(info *pointer, int n) {
    int i; 
    printf("\n");
    for(i = 0; i < n; i++) {
        setbuf(stdin, NULL);
        printf("Digite o nome do aluno(a) %d: ", i + 1);
        scanf("%[^\n]", pointer[i].nome);
        do {
            printf("Digite a nota do aluno(a) %d: ", i + 1);
            scanf("%lf", &pointer[i].media);
        } while(pointer[i].media < 0);
        do {
            printf("Digite as faltas do aluno(a) %d: ", i + 1);
            scanf("%d", &pointer[i].faltas);
        } while(pointer[i].faltas < 0);
        printf("\n");
    }
}

void show(info *pointer, int n) {
    int i;
    printf("\n------------ALUNOS ORDENADOS------------\n");
    for(i = 0; i < n; i++) {
        printf("%do aluno: %s\n", i + 1, (pointer+i)->nome);
        printf("Nota do %do aluno: %.2f\n", i + 1, (pointer+i)->media);
        printf("Faltas do %do aluno: %d\n\n", i + 1, (pointer+i)->faltas);
    }
}

int main() {
    int n;
    info *alunos;
    do {
        printf("Digite o numero de alunos: ");
        scanf("%d", &n);
    } while (n < 0);
    alunos = aloca(n);   
    preenche(alunos, n);
    selectionSort(alunos, n);
    show(alunos, n);
    free(alunos);
    return 0;
}