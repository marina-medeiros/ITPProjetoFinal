#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../heading/functions.h"
#include "../heading/utils.h"
#include "../heading/definitions.h"

Coluna* pegaColunas(char *path){
    char aux[100];
    int qtdColunas;

    FILE *table = fopen(path, "r");

    if(table == NULL){
        printf(">>>Erro ao abrir arquivo table na função 'criaLinha'\n");
        return;
    }

    fscanf(table, "%d", &qtdColunas);

    Coluna *colunasTabela = (Coluna*)malloc(sizeof(Coluna) * qtdColunas);

    fscanf(table, "%s", aux); //Lê a segunda linha da tabela, que contém os nomes das colunas

    strcpy(colunasTabela[0].nome, strtok(aux, "|"));

    for(int i = 1; i < qtdColunas; i++){
        strcpy(colunasTabela[i].nome, strtok(NULL, "|"));
    }

    fscanf(table, "%s", aux); //Lê a terceira linha da tabela, que contém os tipos das colunas

    strcpy(colunasTabela[0].tipo, strtok(aux, "|"));

    for(int i = 1; i < qtdColunas; i++){
        strcpy(colunasTabela[i].tipo, strtok(NULL, "|"));
    }

    fclose(table);

    return colunasTabela;
}