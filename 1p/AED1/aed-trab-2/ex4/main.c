#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include ".\headers\fila.h"

typedef struct {
    size_t tempo_atendimento; // Tempo que o cliente ficará no caixa
    size_t tempo_espera; // Tempo que o cliente está esperando na fila
    horario horario_entrada; // Horário em que o cliente entrou na fila
} Cliente;

typedef struct {
    Cliente cliente;
    size_t status; // 1 = aberto; 0 = fechado;
    size_t ocupado; // 1 = com cliente; 0 = sem cliente;
    size_t tempo_atendimento; // Tempo em que o caixa esta atendendo o cliente que está nele
} Caixa;

// Lê somente numeros inteiros e retorna o valor lido
int read_int();

// Imprime a situação atual da fila e dos caixas
void visualizar_cenario(Fila *fila, Caixa *caixas, Cliente cliente);
// Avança 1 unidade de tempo no cenário
void avancar_tempo(Fila *fila, Caixa *caixas, Cliente cliente);
// Otimiza a abertua e o fechamento dos caixas
void otimizar_caixas(Fila *fila, Caixa *caixas, Cliente cliente);

//Função para limpar buffer (fflush causa UB)
void clean_buffer();

int main(){

    int sair = 0;
    Fila fila = NULL;
    Caixa caixas[8];
    Cliente cliente;
    size_t espera = 0;

    while (sair != 1) {
        int op = 0;

        printf("\n\n[1] Inicializar filas e caixas");
        printf("\n[2] Visualizar cenario");
        printf("\n[3] Dar entrada em clientes");
        printf("\n[4] Avancar tempo");
        printf("\n[5] Sair\n");
        scanf("%d", &op);
        clean_buffer();

        switch (op) {
            case 1:
                if (fila != NULL)
                    printf("Fila ja esta criada!");
                else {
                    fila = cria_fila();
                    if (fila == NULL) {
                        printf("ERRO CRITICO. Finalizando programa.");
                        return -1;
                    }
                    
                    for (size_t i = 0; i < 8; i++) {
                        caixas[i].tempo_atendimento = 0;
                        caixas[i].ocupado           = 0;
                        caixas[i].status            = 0;
                    }
                    
                    printf("Fila criada!");
                }
                break;
            case 2:
                if (fila == NULL)
                    printf("Nenhuma fila foi instanciada!");
                else
                    visualizar_cenario(&fila, caixas, cliente);
                break;
            case 3:
                if (fila == NULL)
                    printf("Nenhuma fila foi instanciada!");
                else {
                    printf("Quantos cliente serao inseridos na fila: ");
                    int qnt = read_int();
                    
                    int teste = 0;
                    for (size_t i = 0; i < qnt; i++) {
                        cliente.tempo_atendimento = (size_t) (rand() % (10 - 2 + 1)) + 2;
                        cliente.tempo_espera = 0;

                        time_t hora;
                        time(&hora);
                        cliente.horario_entrada = localtime(&hora);

                        if (!insere_fim(fila, cliente.tempo_atendimento,
                            cliente.tempo_espera, cliente.horario_entrada)) {
                            printf("Nao foi possivel inserir todos os clientes!");
                            teste = 1;
                            break;
                        }

                    }

                    if (!teste)
                        printf("Todos os %d clientes foram inseridos na fila!", qnt);
                }
                break;
            case 4:
                if (fila == NULL)
                    printf("Nenhuma fila foi instanciada!");
                else
                    avancar_tempo(&fila, caixas, cliente);
                break;
            case 5:
                sair = 1;
                break;
            default:
                printf("Opcao invalida!");
                break;
        }

        if (!sair) {
            printf("\n");
            system("pause");
            system("cls");
        }

    };
    return 0;
}

//Funcoes do programa app
int read_int(){
    char input[11]; 
    int inp_error = 1;
    while(inp_error) {
        fgets(input, sizeof(input), stdin);
        //Removendo '\n'
        input[strlen(input) - 1] = '\0';
        //Percorrendo a string a procura de caracteres não numéricos
        for (size_t i = 0; i < strlen(input); i++) {
            // 43 = '+' ASCII
            //sinais quer dizer '-' ou '+'
            //Impedindo de digitar sinas com numero antes
            if((input[i] == 43 || input[i] == '-') && (i >= 1 && isdigit(input[i-1]))) {
                printf("Insira um valor valido (inteiro): ");
                break;    
            }
            //Impedindo de digitar sinas seguidos de nada
            if ((input[i] == 43 || input[i] == '-') && (i < (strlen(input)) && input[i+1] == '\0')) {
                printf("Insira um valor valido (inteiro): ");
                break;
            }
            //Impedindo de digitar qualquer coisa que não seja digito, exceto sinais
            if(!isdigit(input[i]) && input[i] != '-' && input[i] != 43) { // 43 = '+' ASCII
                printf("Insira um valor valido (inteiro): ");
                break;
            }
            if (i == strlen(input) - 1)
                inp_error = 0;
        }
    }
    //Convertendo a string para inteiro
    return strtol(input, NULL, 10);
}


// Após uma pesquisa, descobriu-se que o cliente  fica satisfeito  quando o tempo de  espera na fila  não ultrapassa 30 unidades de tempo e a fila não têm mais que 15 pessoas. Portanto, um novocaixa é aberto quando a fila tem 80% dessa capacidade de pessoas e o tempo médio de espera dos últimos 5 clientes é de 90% do limite especificado. Por outro lado, um caixa é fechado quando ambas as métricas está abaixode 60%.
void otimizar_caixas(Fila *fila, Caixa *caixas, Cliente cliente){
    if (fila_vazia(*fila))
        return;

    size_t qnt = tamanho_fila(*fila);
    int soma_espera = 0;

    for (size_t i = 0; i < qnt; i++) { // Percorre os clientes na fila
        if (!remove_ini(*fila, &cliente.tempo_atendimento, &cliente.tempo_espera, cliente.horario_entrada))
            break;
        
        // Soma o tempo de espera dos ultimos 5 clientes da fila
        if (qnt > 5 && i >= qnt-5) 
            soma_espera += cliente.tempo_espera;

        insere_fim(*fila, cliente.tempo_atendimento, cliente.tempo_espera, cliente.horario_entrada);
    }
    
    if (soma_espera <= 0)
        return;

    // Media do tempo de espera dos ultimos 5 clientes da fila
    float media_espera = (float) soma_espera / 5.0;
    
    //Verifica se é necessário a abertura de caixas pelo critério da questão
    if (media_espera >= (30 * 0.9) && qnt >= (15 * 0.8)) {
        for (size_t i = 0; i < 8; i++) {
            if (caixas[i].status == 0) {
                caixas[i].status = 1;
                caixas[i].ocupado = 0;
                break;
            }
        }
    }
    
    // 60% de 30 = 18
    //Verifica se é necessário fechar caixas pelo critério da questão
    if (media_espera <= 18 && qnt <= (15 * 0.6)) {
        for (size_t i = 0; i < 8; i++) {
            if (caixas[i].status == 1 && !caixas[i].ocupado) {
                caixas[i].status = 0; 
                break;
            }
        }
    }
}

void avancar_tempo(Fila *fila, Caixa *caixas, Cliente cliente){

    for (size_t i = 0; i < 8; i++) {
        if (caixas[i].status && caixas[i].ocupado) // Verifica se o caixa tem esta aberto e com cliente
            caixas[i].tempo_atendimento++; // Aumenta o tempo do atendimento atual do caixa
    }

    size_t qnt = tamanho_fila(*fila);
    for (size_t i = 0; i < qnt; i++) { // Percorre a fila aumentando o tempo de espera de cada cliente na fila
        if (!remove_ini(*fila, &cliente.tempo_atendimento, &cliente.tempo_espera, cliente.horario_entrada))
            break;
        cliente.tempo_espera++;
        insere_fim(*fila, cliente.tempo_atendimento, cliente.tempo_espera, cliente.horario_entrada);
    }


    for (size_t i = 0; i < 8; i++) {
        if (caixas[i].status && !caixas[i].ocupado) { // Verifica se tem caixa aberto apos a otimização
            // Se há caixa aberto, inserir o primeiro cliente na fila nele
            if(!remove_ini(*fila, &cliente.tempo_atendimento, &cliente.tempo_espera, cliente.horario_entrada))
                break;
            
            cliente.tempo_espera = 0;
            
            caixas[i].cliente = cliente;
            
            caixas[i].ocupado = 1;
            
            caixas[i].tempo_atendimento = 0;
        }
        // Verificar se há caixa aberto que ja bateu o tempo de atendimento com o cliente
        if (caixas[i].status && caixas[i].ocupado && 
        (caixas[i].tempo_atendimento == caixas[i].cliente.tempo_atendimento)){
            Cliente temp;
            caixas[i].cliente = temp; // Esvaziando cliente;
            caixas[i].ocupado = 0;
        }
    }
    printf("\nTempos de espera e de atendendimento em caixa avancaram em 1 unidade!");

    // Otimiza os caixas após o tempo avançar
    otimizar_caixas(fila, caixas, cliente);
}

void visualizar_cenario(Fila *fila, Caixa *caixas, Cliente cliente){
    if (fila_vazia(*fila)) {
        printf("A fila esta vazia!!");
    } else {
            printf("=== CAIXAS ===");
        for (size_t i = 0; i < 8; i++) {
            printf("\nCaixa %d:", i+1);
            if (caixas[i].status && caixas[i].ocupado) {
                printf("\n - Status: aberto");
                printf("\n - Tempo atentendo cliente atual: %d u.t.", caixas[i].tempo_atendimento);
                printf("\n - Tempo de atendimento do cliente: %d u.t.", caixas[i].cliente.tempo_atendimento);
            } else
                printf("\n - Status: fechado");
        }
        
        printf("\n\n === FILA DE CLIENTES ===");

        size_t i = 0, soma_antendimento = 0;
        size_t qnt = tamanho_fila(*fila);
        for (size_t i = 0; i < qnt; i++) {
            if (!remove_ini(*fila, &cliente.tempo_atendimento, &cliente.tempo_espera, cliente.horario_entrada))
                break;

            printf("\n\n - Cliente %d", i+1);
            printf("\nTempo de espera na fila: %d u.t.", cliente.tempo_espera);
            printf("\nHorario de entrada: %dh%dmin%ds",
                cliente.horario_entrada->tm_hour,
                cliente.horario_entrada->tm_min,
                cliente.horario_entrada->tm_sec
            );
            
            if (qnt > 5 && i < 5) 
                soma_antendimento += cliente.tempo_atendimento;

            insere_fim(*fila, cliente.tempo_atendimento, cliente.tempo_espera, cliente.horario_entrada);
        }

        if (qnt >= 5)
            printf("\n\nMedia de tempo de atendimento dos 5 primeiros clientes: %.2f", soma_antendimento / 5.0);
    }
}

void clean_buffer(){
    int c;
    while((c = getchar()) != EOF && c != '\n');
}
