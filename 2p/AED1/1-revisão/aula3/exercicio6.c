#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int matricula, nota;
    char nome[50];
} info;


info* lerAlunos(char* qntAluno) {
    int qntAlunos = atoi(qntAluno);
    info *var;
    var = (info*) malloc(qntAlunos * sizeof(info));
    if(var == NULL) {
        printf("Erro na alocacao!!");
        exit(1);
    }
    int i;
    for(i = 0; i < qntAlunos; i++) {
        if(i != 0) printf("\n");
        printf("Digite o numero de matricula do aluno %d: ", i + 1);
        scanf("%d", &var[i].matricula);
        printf("Digite o nome do aluno %d: ", i + 1);
        setbuf(stdin, NULL);
        scanf("%[^\n]s", var[i].nome);
        printf("Digite a nota final do aluno %d: ", i + 1);
        scanf("%d", &var[i].nota);
    }
    return var;
}

void gravarAlunos(info* alunos, char* nome, char* qntAluno) {
    strcat(nome, ".txt");
    int qntAlunos = atoi(qntAluno);
    FILE* arq;
    arq = fopen(nome, "w");
    if(arq == NULL) {
        printf("\nErro na abertura do arquivo!!");
        exit(1);
    }
    int i;
    fprintf(arq, "-----------LISTA DE ALUNOS-----------\n");
    for(i = 0; i < qntAlunos; i++) {
        fprintf(arq, "\nALUNO %d\n", i + 1);
        fprintf(arq, "\nMATRICULA: %d", alunos[i].matricula);
        fprintf(arq, "\nNOME: %s", alunos[i].nome);
        fprintf(arq, "\nNOTA FINAL: %d\n", alunos[i].nota);
    }
    fclose(arq);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Quantidade de argumentos errado!");
        return 0;
    } 
    info *alunos = lerAlunos(argv[2]); 
    gravarAlunos(alunos, argv[1], argv[2]);
    free(alunos);
    return 0;
}