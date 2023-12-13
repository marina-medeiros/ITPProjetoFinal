#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../heading/functions.h"
#include "../heading/utils.h"
#include "../heading/definitions.h"

void listaDadosTabela(){
    char nomeTabela[30];
    char path[40];
    char formatar[50];
    char linha[200];
    int c, qtdLinhas, qtdColunas, maiorStrlen;

    printf(">>>Insira o nome da tabela: ");

    while ((c = getchar()) != '\n' && c != EOF) {}
    scanf("%[^\n]", nomeTabela);

    if(validaTabela(nomeTabela) == 0){
        printf(">>>Ops! A tabela %s não existe!\n", nomeTabela);
        return;
    }else{
        strcpy(path, "tabelasIndividuais/");
        strcat(path, nomeTabela);
        strcat(path, ".txt");

        qtdLinhas = contaLinhas(path);

        FILE *file = fopen(path, "r");
          
        if(file == NULL){
            printf(">>>Erro ao abrir arquivo na função 'listaDadosTabela'\n");
            return;
        }

        fscanf(file, "%d", &qtdColunas);

        printf(" |");

        for(int i = 0; i < qtdLinhas; i++){
            fgets(linha, 200, file);

            if(i == 3){
                for(int j = 0; j < (qtdColunas * 22 - 1); j++){
                    printf("-");
                }
                printf("|\n |");
            }

            if(i > 0){
                strcpy(formatar, strtok(linha, "|"));
                printf("%20s |", linha);

                for(int k = 0; k < qtdColunas-1; k++){
                    strcpy(formatar, strtok(NULL, "|"));
                    printf("%20s |", formatar);
                }
                strcpy(formatar, strtok(NULL, "|"));
                printf("%20s |", formatar);
            }
        }

        printf("\n");
    }
    

}