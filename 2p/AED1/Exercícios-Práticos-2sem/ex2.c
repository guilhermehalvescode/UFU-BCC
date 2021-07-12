#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    int volume;
    float preco;
} bebida;

void aloca(bebida** *ref) {
    int i;
    (*ref) = (bebida**) malloc(20 * sizeof(bebida*));
    if((*ref) == NULL) {
        printf("Erro ao alocar!!");
        exit(1);
    }
    for(i = 0; i < 20; i++) {
        (*ref)[i] = NULL;
    }
}

void alocaBebida(bebida* *ref) {
    (*ref) = (bebida*) malloc(sizeof(bebida));
    if((*ref) == NULL) {
        printf("Erro ao alocar!!");
        exit(1);
    }
}

void insert(bebida* *ref, int *n) {
    if((*n) > 19) { 
        printf("\nNao e possivel adicionar mais de 20 bebidas!\n");
        return;
    }
    alocaBebida(&ref[(*n)]);
    printf("\nInserindo %do bebida!!", (*n) + 1);
    setbuf(stdin, NULL);
    printf("\nDigite o nome da %do bebida: ", (*n) + 1);
    scanf("%[^\n]", ref[(*n)]->nome);
    do {
        printf("Digite o volume da %do bebida(ml): ", (*n) + 1);
        scanf("%d", &ref[(*n)]->volume);
    } while(ref[(*n)]->volume < 0);
    do {
        printf("Digite o preco da %do bebida: ", (*n) + 1);
        scanf("%f", &ref[(*n)]->preco);
    } while (ref[(*n)]->preco < 0);
    printf("\nBebida inserida com sucesso!\n");
    (*n)++;
}

void erase(bebida* *ref, int *n) {
    if((*n) == 0){
        printf("\n-------SEM BEBIDAS-------\n");
        return;
    } 
    free(ref[(*n)]);
    ref[(*n)] = NULL;
    printf("\nBebida removida com sucesso!\n");
    (*n)--;
}

void show(bebida* *ref, int *n) {
    int i;
    if((*n) == 0){
        printf("\n-------SEM BEBIDAS-------\n");
        return;
    } 
    printf("\n-----------BEBIDAS-----------\n");
    for(i = 0; i < (*n); i++) {
        printf("\nBebida %do", i + 1);
        printf("\nNome da bebida: %s", ref[i]->nome);
        printf("\nVolume da bebida: %d", ref[i]->volume);
        printf("\nPreco da bebida: %.2f\n", ref[i]->preco);
    }
}

void freeAll(bebida** *ref) {
    int i;
    for(i = 0; i < 20; i++) {
        free((*ref)[i]);
    }
    free(*ref);
}

int main() {
    bebida* *vetor = NULL;
    int escolha, registros = 0;
    aloca(&vetor);
    printf("BEBIDAS");
    do{
        printf("\n[1] Inserir registro\n[2] Apagar ultimo registro\n[3] Imprimir tabela\n[4] Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        switch (escolha) {
        case 1:
            insert(vetor, &registros);
            break;
        case 2:
            erase(vetor, &registros);
            break;
        case 3:
            show(vetor, &registros);
            break;
        }
    } while (escolha != 4);
    freeAll(&vetor);
    return 0;
}