#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../heading/utils.h"
#include "../heading/definitions.h"

int validaChavePrimaria(char *nomeTabela, char *pkEntrada){
    char path[40];
    char linha[200];
    char pkLida[30];
    int c, pk;

    strcpy(path, "tabelasIndividuais/");
    strcat(path, nomeTabela);
    strcat(path, ".txt");

    int qtdLinhas = contaLinhas(path);

    FILE *file = fopen(path, "r");
          
    if(file == NULL){
        printf("Erro ao abrir arquivo na função 'validaChavePrimaria'\n");
        return -1;
    }

    for(int i = 0; i < qtdLinhas; i++){
        fgets(linha, 200, file);
        strcpy(pkLida, strtok(linha, "|"));

        if(i > 2 && strcmp(pkLida, pkEntrada) == 0){
            return 0; //chave inválida
        }
    }

    return 1; //chave válida
}