#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../heading/functions.h"
#include "../heading/utils.h"
#include "../heading/definitions.h"

void apagaLinha(){
    char nomeTabela[50];
    char path[60];
    char pkEntrada[30], pkLida[30];
    char linha[200], linhaApagar[200];
    int c, qtdLinhas;

    printf("Insira o nome da tabela que contém a linha a ser apagada:");

    while ((c = getchar()) != '\n' && c != EOF) {}
    scanf("%[^\n]", nomeTabela);

    if(validaTabela(nomeTabela) == 0){
        printf("Ops! Parece que a tabela %s não existe!\n", nomeTabela);
        printf("----------------------------------------\n");
        return;
    }else{
        strcpy(path, "tabelasIndividuais/");
        strcat(path, nomeTabela);
        strcat(path, ".txt");

        FILE *table = fopen(path, "r");

        if(table == NULL){
            printf("Erro ao abrir arquivo na função 'apagaLinha'\n");
            return;
        }

        printf("Insira o valor da chave primária da linha a ser apagada:");

        while ((c = getchar()) != '\n' && c != EOF) {}
        scanf("%[^\n]", pkEntrada);

        printf("ok\n");

        if(validaChavePrimaria(nomeTabela, pkEntrada) == 1){
            printf("Ops! Não existe um registro com essa chave primária na tabela %s\n", nomeTabela);
            return;
        }else{
            printf("a pk está ok\n");
        }

        printf("ok3\n");

        qtdLinhas = (contaLinhas(path));

        char linhasTab[qtdLinhas][200];

        FILE *tabela = fopen(path, "r");

        if(tabela == NULL){
            printf("Erro ao abrir arquivo tabela na função 'apagaLinha'\n");
            return;
        }

        printf("ok3\n");

        for(int i = 0; i < qtdLinhas; i++){
            fscanf(tabela, "%s", linhasTab[i]); //agora o vetor linhas tem o conteúdo da tabela em questão
            printf("zz %s\n", linhasTab[i]);
        }

        fclose(tabela);

        FILE *tabelasNovo = fopen(path, "w");

        if(tabelasNovo == NULL){
            printf("Erro ao abrir arquivo tabelasNovo na função 'apagaTabela'\n");
            return;
        }

        for(int i = 0; i < qtdLinhas; i++){
            fgets(linha, 200, tabelasNovo);
            strcpy(pkLida, strtok(linha, "|"));
            printf("num %s\n", pkLida);

            if(i > 2 && strcmp(pkLida, pkEntrada) == 0){
                strcpy(linhaApagar, linha);
                printf("me apague: %s\n", linhaApagar);
                break; //chave inválida
            }
        }

        for(int i = 0; i < qtdLinhas; i++){
            if(strcmp(linhasTab[i], linhaApagar) != 0){
                fprintf(tabelasNovo, "%s\n", linhasTab[i]);
            }
        }

        fclose(tabelasNovo);
    }


}