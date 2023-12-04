#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../heading/functions.h"
#include "../heading/utils.h"
#include "../heading/definitions.h"

void criaLinha(){
    char nomeTabela[30];
    char path[60];
    char aux[100];
    char entrada[30];
    int c, qtdColunas;

    printf("Insira o nome da tabela: ");

    while ((c = getchar()) != '\n' && c != EOF) {}
    scanf("%[^\n]", nomeTabela);

    if(validaTabela(nomeTabela) == 0){
        printf("Ops! Parece que a tabela %s não existe!\n", nomeTabela);
        printf("----------------------------------------\n");
        return;
    }else{
        strcpy(path, nomeTabela);
        strcat(path, ".txt");

        FILE *table = fopen(path, "r");

        if(table == NULL){
            printf("Erro ao abrir arquivo table na função 'criaLinha'\n");
            return;
        }else{
            printf("Sucesso ao abrir arquivo table na função 'criaLinha'\n");
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

        FILE *tableA = fopen(path, "a");

        printf("Insira um valor de tipo inteiro sem sinal para a chave primária '%s'\n", colunasTabela[0].nome);
        while ((c = getchar()) != '\n' && c != EOF) {}
        scanf("%[^\n]", entrada);

        printf("lixo1: %10s", entrada);

        //printf("xxx %d\n", validaChavePrimaria(nomeTabela, entrada));

        fprintf(tableA, "%s |", entrada); //espaço dps da chve primária para facilitar na hora de pegar esse valor

        for(int i = 1; i < qtdColunas; i++){
            printf("Insira um valor de tipo %s para a coluna '%s'\n", colunasTabela[i].tipo, colunasTabela[i].nome);
            while ((c = getchar()) != '\n' && c != EOF) {}
            scanf("%[^\n]", entrada);
            fprintf(tableA, "%s|", entrada);
        }
        fprintf(tableA, "\n");

        fclose(tableA);
    }
}