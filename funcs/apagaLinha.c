#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "../heading/functions.h"
#include "../heading/utils.h"
#include "../heading/definitions.h"

void apagaLinha(){
    setlocale(LC_ALL, "Portuguese");
    char nomeTabela[50];
    char path[60];
    char pkEntrada[30], pkLida[30];
    char linhaAux[200], linhaApagar[200];
    char formatar[50];
    char linha[200];
    int c, qtdLinhas, qtdColunas;

    printf(">>>Aqui está a lista de tabelas:\n");

    listaTabelas();

    printf(">>>Insira o nome da tabela que contém a linha a ser apagada:");

    while ((c = getchar()) != '\n' && c != EOF) {}
    scanf("%[^\n]", nomeTabela);

    if(validaTabela(nomeTabela) == 0){
        printf(">>>Ops! Parece que a tabela %s não existe!\n", nomeTabela);
        return;
    }else{
        strcpy(path, "tabelasIndividuais/");
        strcat(path, nomeTabela);
        strcat(path, ".txt");

        FILE *table = fopen(path, "r");

        if(table == NULL){
            printf(">>>Erro ao abrir arquivo na função 'apagaLinha'\n");
            return;
        }
        
        qtdLinhas = (contaLinhas(path));

        printf(">>>Aqui está a tabela escolhida:\n");
        
        fscanf(table, "%d", &qtdColunas);

        for(int i = 0; i < qtdLinhas; i++){
            fgets(linha, 200, table);

            if(i == 3){
                for(int j = 0; j < (qtdColunas * 22); j++){
                    printf("-");
                }
                printf("\n ");
            }

            if(i > 0){
                strcpy(formatar, strtok(linha, "|"));
                printf("%20s |", formatar);

                for(int k = 0; k < qtdColunas-1; k++){
                    strcpy(formatar, strtok(NULL, "|"));
                    printf("%20s |", formatar);
                }
                strcpy(formatar, strtok(NULL, "|"));
                printf("%20s ", formatar);
            }
        }

        printf("\n>>>Insira o valor da chave primária da linha a ser apagada:");

        while ((c = getchar()) != '\n' && c != EOF) {}
        scanf("%[^\n]", pkEntrada);


        if(validaChavePrimaria(nomeTabela, pkEntrada) == 1){
            printf(">>>Ops! Não existe um registro com essa chave primária na tabela %s\n", nomeTabela);
            return;
        }

        fclose(table);


        char linhasTab[qtdLinhas][200];

        FILE *tabelaR = fopen(path, "r");

        if(tabelaR == NULL){
            printf(">>>Erro ao abrir arquivo tabela na função 'apagaLinha'\n");
            return;
        }

        for(int i = 0; i < qtdLinhas; i++){
            fgets(linhasTab[i], 200, tabelaR);
            strcpy(linhaAux, linhasTab[i]);

            if(i > 2){
                strcpy(pkLida, strtok(linhaAux, "|"));

                if(strcmp(pkLida, pkEntrada) == 0){
                    strcpy(linhaApagar, linhasTab[i]);
                }
            }
        }

        fclose(tabelaR);

        FILE *tabelaW = fopen(path, "w");

        if(tabelaW == NULL){
            printf(">>>Erro ao abrir arquivo tabelaW na função 'apagaTabela'\n");
            return;
        }

        for(int i = 0; i < qtdLinhas; i++){
            if(strcmp(linhasTab[i], linhaApagar) != 0){
                fprintf(tabelaW, "%s", linhasTab[i]);
            }
        }

        fclose(tabelaW);
    }


}