#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dinamicStackCHAR.h"
#include "dinamicStackFLOAT.h"

//Verifica se o char é um operador
int op(char opDel) {
    return opDel == '+' || opDel == '-' || opDel == '/' || opDel == '*' || opDel == '^';
}
//Verifica se o char é um operando
int operando(char opDel) {
    return (opDel >= 'a' && opDel <= 'z') || (opDel >= 'A' && opDel <= 'Z');
}
//Verifica se o char é um delimitador de abertura
int delAber(char opDel) {
    return opDel == '{' || opDel == '[' || opDel == '(';
}

//Verifica se o char é um delimitador de fechamento
int delFecha(char opDel) {
    return opDel == '}' || opDel == ']' || opDel == ')';
}

//Olha se a precedencia do delimitador do topo
//é maior ou igual a que eu quero inserir
int precedencia(char topo, char atual) {
    return topo >= atual;
}

//Ordem de precedencia dos operadores aritméticos
//e delimitadores
int compare(char op) {
    if(op == '^')
        return 6;
    if(op == '*' || op == '/')
        return 5;
    if(op == '+' || op == '-')
        return 4;
    if(op == '{')
        return 3;
    if(op == '[')
        return 2;
    if(op == '(')
        return 1;
    return 0;    
}

//Olha se a precedencia dos operadores do topo
//é maior ou igual a que eu quero inserir
int precedencia_converte(char topo, char atual) {
    int top = compare(topo), comp = compare(atual);
    return top >= comp;
}

//Realiza a operação entre dois números
//conforme o operador passado
float opCorresp(float op1, float op2, char op) {
    switch(op) {
        case '+':   
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        case '^':
            return pow(op1, op2);
    }
}

//Retornos: 
//-1 == precedência nao é obedecida 
//0 == ordem dos fechamentos divergem da ordem das aberturas
//1 == expressão válida
int valida_escopo(char *exp) {
    DinStack delimitadores = dstack_start();
    //Inicializo a flag com 2 para que verifique no final se ela 
    //foi alterada no processo 
    int i, flag = 2; 
    //Percorro a expressão
    for(i = 0; i < strlen(exp); i++) {
        //Se for um delimitador de abertura, eu coloco esse na pilha
        if(delAber(exp[i])) {
            //Olho no topo da pilha pra ver se existe um delimitador
            //de abertura, inicializo com 124 para o caso em que a pilha
            //esta vazia e que a função precedencia permita colocar o delimitador
            //atual na pilha, já que '|' >= '{' (124 >= 123)
            char topo = '|';
            dget_top(&delimitadores, &topo);  
            if(precedencia((char) topo, exp[i])) {
                if(!dpush(&delimitadores, exp[i])) {
                    printf("Erro no push!");
                    esvazia_pilha(&delimitadores);
                    return 0;
                }
            } else {
                //flag -1 == precedência nao é obedecida
                flag = -1;
                break;
            }
        }
        //Se for um delimitador de fechamento, eu retiro o de abertura correspondente
        //da pilha
        if(delFecha(exp[i])) {
            char del;
            //Olho o elemento do topo da pilha, se der errado, é porque
            //a expressão está inválida, pois, tem um delimitador de fechamento
            //na expressão e a pilha já está vazia
            if(!dget_top(&delimitadores, &del)) {
                //flag 0 == ordem dos fechamentos divergem da ordem das aberturas
                flag = 0;
                break;
            }
            //Olho se o delimitador de fechamento da expressão está na pilha 
            //de delimitadores de abertura. Se não estiver, quer dizer que
            //o escopo está inválido, já que ocorreu um fechamento de escopo
            //sem se quer ter sua abertura correspondente
            if((del == '{' && exp[i] == '}') || (del == '[' && exp[i] == ']') || (del == '(' && exp[i] == ')')) 
                dpop(&delimitadores, &del);
            else {
                //flag 0 == ordem dos fechamentos divergem da ordem das aberturas
                flag = 0;
                break;
            }
        }
    }
    //Se a pilha estiver vazia e não tiver entrado em algum erro,
    //o escopo é válido
    if(dempty_stack(delimitadores) && flag == 2) 
        return 1;
    //A pilha não está vazia, então precisamos esvazia-la 
    //e retornar que o escopo é inválido
    esvazia_pilha(&delimitadores);
    return flag;
}

//Retornos:
//1 == sucesso
//0 == erro
int converte_expressao(char *exp, char *posfix) {
    DinStack stack = dstack_start();
    int i, aux = 0;
    //Percorro a expressão
    for(i = 0; i < strlen(exp); i++) {
        //Se for um operando, eu imprimo esse
        if(operando(exp[i])) {
            posfix[aux] = exp[i];
            aux++;
        }
        //Se for um operador, eu coloco esse na pilha
        if(op(exp[i])) {
            //Olho no topo da pilha, inicializo com 0 para o caso em que a pilha
            //esta vazia e que a função precedencia_converte nao permita retirar o elemento
            //do topo da pilha
            char topo = 0;
            dget_top(&stack, &topo);  
            //Enquanto a precedencia do topo for maior ou igual ao elemento atual
            while(precedencia_converte(topo, exp[i])) {
                //Eu desempilho e imprimo os operadores 
                //Se estiver vazia, eu paro
                if(!dpop(&stack, &topo)) break;
                posfix[aux] = topo;
                aux++;
                dget_top(&stack, &topo);  
            }
            //Após desempilhar e imprimir eu simplesmente empilho o operador
            if(!dpush(&stack, exp[i])) {
                printf("Erro no push!");
                esvazia_pilha(&stack);
                return 0;
            } 
        }
        //Se for um delimitador de abertura, eu coloco esse na pilha
        if(delAber(exp[i])) {
            //Olho no topo da pilha pra ver se existe um delimitador
            //de abertura, inicializo com 123 para o caso em que a pilha
            //esta vazia e que a função precedencia_converte permita colocar o delimitador
            //atual na pilha, já que '{' >= '{' (123 >= 123)
            char topo = '{';
            dget_top(&stack, &topo);  
            if(precedencia_converte(topo, exp[i])) {
                if(!dpush(&stack, exp[i])) {
                    printf("Erro no push!");
                    esvazia_pilha(&stack);
                    return 0;
                }
            } else
                //Nao segue a precedencia dos delimitadores
                return 0;            
        }
        //Se for um delimitador de fechamento, eu retiro tudo até chegar
        //no delimitador de abertura correspondente
        if(delFecha(exp[i])) {
            char del, atual;
            //Associo o delimitador de fechamento ao de 
            //abertura correspondente
            if(exp[i] == '}') atual = '{';
            if(exp[i] == ']') atual = '[';
            if(exp[i] == ')') atual = '(';
            do {
                //Se a pilha estiver vazia eu paro
                if(!dpop(&stack, &del)) break;
                //Se o elemento removido da pilha for um delimitador de 
                //abertura diferente do atual, a expressão é inválida
                if(del != atual && (del == '{' || del == '[' || del == '('))
                    return 0;
                //Delimitador de abertura não é impresso
                if(del != atual) {
                    posfix[aux] = del;
                    aux++;
                }
            } while(del != atual);
        }
    }
    //Se a pilha não estiver vazia
    //eu desempilho e imprimo tudo
    if(!dempty_stack(stack)) {
        char op;
        do {
            dpop(&stack, &op);
            posfix[aux] = op;
            aux++;
        } while(!dempty_stack(stack));
    }
    return 1;
}

//Retornos: 
//-1 == número de operadores não é adequado 
//0 == número de operandos não é adequado
//1 == avaliação da expressão foi correta
int avalia_expressao(char *posfix, float *resultado) {
    FloatStack stack = start_stk();
    int i; 
    //Percorro a expressao
    for(i = 0; i < strlen(posfix); i++) {
        //Se for um operando, leio ele e coloco na pilha
        if(operando(posfix[i])) {
            float valor;
            printf("Digite o valor de %c: ", posfix[i]);
            scanf("%f", &valor);
            if(!stack_push(&stack, valor)){
                printf("Erro no push!");
                esvazia_pilha(&stack);
                return 0;
            }
        }
        //Se for um operador eu retiro os dois ultimos da pilha
        //e efetuo a operação correspondente
        if(op(posfix[i])) {
            float op1, op2, res;
            if(!stack_pop(&stack, &op2) || !stack_pop(&stack, &op1)) {
                esvazia_pilha(&stack);
                return 0;
            }
            res = opCorresp(op1, op2, posfix[i]);
            //Depois de calcular o resultado, coloco esse na pilha
            if(!stack_push(&stack, res)){
                printf("Erro no push!");
                esvazia_pilha(&stack);
                return 0;
            }
        }
    }
    //Após percorrer, o resultado deve estar no
    //topo da pilha
    float res;
    stack_pop(&stack, &res);
    //Se após, a pilha estiver vazia,
    //a expressão foi avaliada com sucesso
    if(stack_empty(stack)){
        //Passo o resultado
        *resultado = res;
        return 1;
    }
    //Se não estiver vazia, ocorreu um erro e
    //deve esvaziar a pilha, retornando erro
    free_stack(&stack);
    return -1;
}

int main() {
    int escolha = 0, valida = -2, avaliacao = -2;
    float eval;
    char expressao[100] = "", posfix[100] = "";
    printf("Digite a expressao: ");
    scanf("%[^\n]", expressao);

    do {
        if(escolha) printf("\n");
        printf("\nEXPRESSAO: %s\n", expressao);
        printf("(1)Validar escopo\n");
        printf("(2)Converter expressao\n");
        printf("(3)Avaliar expressao\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        switch(escolha) {
            case 1:
                if(valida == -2)
                    valida = valida_escopo(expressao);            
                if(valida == 1) 
                    printf("\nO escopo da expressao e valida");
                else if(valida == 0)
                    printf("\nOrdem dos fechamentos divergem da ordem das aberturas da expressao");
                else
                    printf("\nA precedencia nao e obedecida na expressao");
                break;
            case 2:
                if(valida == -2) 
                    printf("\nVerifique se a expressao e valida primeiro!");
                else if(valida != 1)
                    printf("\nExpressao invalida, impossivel converter!");
                else if(strcmp(posfix, "")) 
                    printf("\nExpressao ja esta convertida: %s", posfix);
                else if(converte_expressao(expressao, posfix)) 
                    printf("\nConvertido com sucesso! -> %s", posfix);
                else
                    printf("\nNao foi possivel converter");
                break;
            case 3: 
                if(!strcmp(posfix, "")) 
                    printf("\nConverta a expressao primeiro!", posfix);
                else{
                    printf("\nEXPRESSAO: %s\n", expressao);
                    avaliacao = avalia_expressao(posfix, &eval);
                }
                if(avaliacao == 1) 
                    printf("\nO resultado dessa expressao e: %.2f", eval);
                else if(avaliacao == 0)
                    printf("\nNumero de operandos nao e adequado");
                else if(avaliacao == -1)
                    printf("\nNumero de operadores nao e adequado");

                break;
            default: 
                printf("\nSaindo do programa...");
        }
        printf("\n\n");
        system("pause");
        system("cls");
    } while(escolha > 0 && escolha < 4);
    return 0;
}