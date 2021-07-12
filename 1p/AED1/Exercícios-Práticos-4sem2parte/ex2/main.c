#include <stdio.h>
#include <stdlib.h>
#include "listadin.h"

void insert_aluno(Lista *p) {
    int faltas;
    unsigned int matricula;
    float media;
    char nome[20];
    printf("Digite a matricula do aluno que deseja inserir: ");
    scanf("%u", &matricula);
    printf("Digite o nome do aluno que deseja inserir: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", nome);
    printf("Digite a media do aluno que deseja inserir: ");
    scanf("%f", &media);
    printf("Digite as faltas do aluno que deseja inserir: ");
    scanf("%d", &faltas);
    if(insere_elem(p, matricula, nome, media, faltas)) 
        printf("\nElemento adicionado com sucesso!");
    else 
        printf("\nElemento nao adicionado!");
}

void remove_aluno(Lista *p) {
    unsigned int matricula;
    printf("Digite a matricula do aluno que deseja remover: ");
    scanf("%u", &matricula);
    if(remove_elem(p, matricula)) 
        printf("\nElemento removido com sucesso!");
    else 
        printf("\nElemento nao removido!");
}

void print_alunos(Lista p) {
    int i, tam = size_lista(p), faltas;
    unsigned int matricula;
    float media;
    char nome[20];
    printf("\n-----IMPRIMINDO ALUNOS-----");
    for(i = 0; i < tam; i++) {
        printf("\n%do ALUNO", i + 1);
        get_pos(p, i, &matricula, nome, &media, &faltas);
        printf("\nMatricula: %u", matricula);
        printf("\nNome: %s", nome);
        printf("\nMedia: %.2f", media);
        printf("\nFaltas: %d", faltas);
    }
}

int main() {
    Lista alunos;
    alunos = inicializar_lista();
    int escolha;
    do {
        printf("\n------LISTA DE ALUNOS-------\n");
        printf("(1) Inserir aluno na lista\n(2) Remover aluno da lista\n(3) Imprimir lista\nDigite a sua escolha: ");
        scanf("%d", &escolha);
        printf("\n");
        switch(escolha) {
            case 1:
                insert_aluno(&alunos);
                break;
            case 2:
                remove_aluno(&alunos);
                break;
            case 3:
                print_alunos(alunos);
                break;
            default:
                printf("Saindo do programa...");
                break;
        }
    } while(escolha > 0 && escolha < 4);
    return 0;
}
