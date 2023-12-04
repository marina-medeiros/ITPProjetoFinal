#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../heading/utils.h"
#include "../heading/definitions.h"

//NÃO FUNCIONA!!!!!!!

int validaChavePrimaria(char *nomeTabela, char *pkEntrada){
    char path[40];
    char lixo[30];
    //int pkEntrada = atoi(pkString);
    char pkLida[30];
    int c, pk;

    strcpy(path, nomeTabela);
    strcat(path, ".txt");

    int qtdRegistros = contaLinhas(path) - 3;

    FILE *file = fopen(path, "r");
          
    if(file == NULL){
        printf("Erro ao abrir arquivo na função 'validaChavePrimaria'\n");
        return -1;
    }

    //lê as 3 primeiras linhas da tabela
    while ((c = getchar()) != '\n' && c != EOF) {}
    fscanf(file, "%[^\n]", lixo);
    printf("lixo1: %s\n", lixo);
    while ((c = getchar()) != '\n' && c != EOF) {}
    fscanf(file, "%[^\n]", lixo);
    printf("lixo2: %s\n", lixo);
    while ((c = getchar()) != '\n' && c != EOF) {}
    fscanf(file, "%[^\n]", lixo);
    printf("lixo3: %s\n", lixo);

    for(int i = 0; i < qtdRegistros; i++){
        while ((c = getchar()) != '\n' && c != EOF) {}
        fscanf(file, "%[^\n]", lixo);
        printf("lixo4: %s\n", lixo);
        strcpy(pkLida, strtok(lixo, "|"));

        printf("Chave lida: %s\n", pkLida);

        if(strcmp(pkLida, pkEntrada) == 0){
            return 0; //chave inválida
            break;
        }
    }

    return 1; //chave válida
}