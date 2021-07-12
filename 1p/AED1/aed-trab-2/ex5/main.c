#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

struct aluno {
    int matricula, cra, chs, ano;
    char nome[56];
};

//-1 == fila já criada 
//0 == falta de memória
//1 == fila criada
int cria_alunos(Queue *fil) {
    //Se a fila já está criada, não permito sua criação
    if(*fil != NULL) 
        return -1;
    //Crio a fila
    *fil = cria_fp();
    if(*fil == NULL) 
        return 0;
    return 1;
}

//-1 == fila não criada 
//0 == erro na inserção
//1 == aluno inserido
int insere_aluno(Queue fil) {
    if(fil == NULL) 
        return -1;
    
    int matricula, cra, chs, ano;
    char nome[56];
    do {
        printf("\nDigite a matricula do aluno: ");
        scanf("%d", &matricula);
    } while(matricula < 0);
    setbuf(stdin, NULL);
    do {
        printf("Digite o nome do aluno: ");
        scanf("%[^\n]", nome);
    } while(!strcmp(nome, ""));
    do {
        printf("Digite o CRA do aluno: ");
        scanf("%d", &cra);
    } while(cra < 0);
    do {
        printf("Digite a carga horaria semanal do aluno: ");
        scanf("%d", &chs);
    } while(cra < 0);
    do {
        printf("Digite o ano de ingresso do aluno: ");
        scanf("%d", &ano);
    } while(ano < 0);

    return insere(fil, matricula, nome, cra, chs, ano);
}

//-1 == fila não criada 
//0 == erro na remoção
//1 == aluno removido
int remove_aluno(Queue fil) {
    if(fil == NULL) 
        return 0;
    int matricula, cra, chs, ano;
    char nome[56];    
    if(remove_ord(fil, &matricula, nome, &cra, &chs, &ano)) {
        printf("\nO aluno removido foi ->\n");
        printf("Matricula: %d\n", matricula);
        printf("Nome: %s\n", nome);
        printf("CRA: %d\n", cra);
        printf("Carga horaria semanal: %d\n", chs);
        printf("Ano de ingresso: %d\n", ano);
    } else {
        printf("\nNao foi possivel remover o aluno!");
    }
    return 1;
}
void imprimir_alunos(Queue fil) {
    if(fil == NULL) {
        printf("\nCrie a fila primeiramente!");
        return;
    } 
    if(fp_vazia(fil)) {
        printf("\n----FILA VAZIA----\n");
        return;
    } 
    struct aluno v[20];
    printf("\n----FILA----\n");
    int i = 0;
    while(remove_ord(fil, &v[i].matricula, v[i].nome, &v[i].cra, &v[i].chs, &v[i].ano)) {
        printf("\nAluno %d:\nMatricula: %d\nNome: %s\nCRA: %d\nCarga horaria semanal: %d\nAno de ingresso: %d\n", i + 1, v[i].matricula, v[i].nome, v[i].cra, v[i].chs, v[i].ano);
        i++;
    }
    printf("\n");
    int j;
    for(j = 0; j < i; j++) 
        insere(fil, v[j].matricula, v[j].nome, v[j].cra, v[j].chs, v[j].ano);
    
}

int main() {
    Queue queue = NULL;
    int escolha = 0, criada = 0, res;
    do {
        if(escolha) printf("\n\n");
        printf("* Alunos! *\n");
        printf("(1) Criar fila de alunos\n");
        printf("(2) Inserir aluno na fila\n");
        printf("(3) Remover aluno da fila\n");
        printf("(4) Imprimir alunos da fila\n");
        printf("(5) Esvaziar fila de alunos\n");
        printf("(6) Sair do sistema\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                criada = cria_alunos(&queue);
                if(criada == 1)
                    printf("\nFila criada com sucesso!");
                else if(criada == -1)
                    printf("\nFila ja existe!");
                else {
                    printf("\nFalta de memória!");
                    return 1;
                }
                break;
            case 2:
                res = insere_aluno(queue);
                if(res == 1)
                    printf("\nAluno inserido com sucesso!");
                else if (res == -1)
                    printf("\nCrie a fila primeiramente!");
                else {
                    printf("\nErro na inserção!");
                    return 1;
                }
                break;
            case 3:
                if(!remove_aluno(queue))
                    printf("\nCrie a fila primeiramente!");
                break;
            case 4:
                imprimir_alunos(queue);
                break;
            case 5:
                if(!esvazia_fp(queue))
                    printf("\nCrie a fila primeiramente!");
                break;
            default:
                break;
        }
        printf("\n");
        system("pause");
        system("cls");
    } while(escolha != 6);
    return 0;
}