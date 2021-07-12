#ifndef DOADOR_H
#define DOADOR_H

typedef struct no_doador * ListaDoadores; 

ListaDoadores cria_lista_doadores();

int vazia_doadores(ListaDoadores l);

int tamanho_doadores(ListaDoadores l);

int inserir_doador(ListaDoadores *l, char nome[], int orgaos[]);

int posicao_doador(ListaDoadores l, int pos, char *nome, char **orgaos);

int verifica_pacientes(ListaDoadores *l, char name[], int orgao);

#endif