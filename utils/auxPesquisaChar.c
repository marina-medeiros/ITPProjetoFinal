#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "../heading/functions.h"
#include "../heading/utils.h"
#include "../heading/definitions.h"

void auxPesquisaChar(char *path, int qtdLinhas, int numColuna, int opcao, char *valor){
    setlocale(LC_ALL, "Portuguese");
    char linha[200];
    char pedaco[40];
    char *aux;
    String valoresConvertidos[qtdLinhas-3][2];
    int indiceMaisProximo;
    int qtdValidados = 0;
    int melhorPontuacao = 0;


    FILE *file = fopen(path, "r");

    for(int i = 0; i < qtdLinhas; i++){
        fgets(linha, 200, file);
        if(i > 2){
            strcpy(valoresConvertidos[i-3][1].texto, strtok(linha, "|"));

            if(numColuna > 1){
                for(int k = 0; k < numColuna-2; k++){
                    strcpy(pedaco, strtok(NULL, "|"));
                }
                strcpy(valoresConvertidos[i-3][0].texto, strtok(NULL, "|"));
            }

        }
    }

    switch(opcao){
    case 1:
        for(int i = 0; i < qtdLinhas-3; i++){
            if(strcmp(valoresConvertidos[i][0].texto, valor) > 0){
                printf("PK: %s   Valor: %s\n", valoresConvertidos[i][1].texto, valoresConvertidos[i][0].texto);
                qtdValidados++;
            }
        }
    break;
    case 2:
        for(int i = 0; i < qtdLinhas-3; i++){
            if(strcmp(valoresConvertidos[i][0].texto, valor) >= 0){
                printf("PK: %s   Valor: %s\n", valoresConvertidos[i][1].texto, valoresConvertidos[i][0].texto);
                qtdValidados++;
            }
        }
    break;
    case 3:
        for(int i = 0; i < qtdLinhas-3; i++){
            if(strcmp(valoresConvertidos[i][0].texto, valor) == 0){
                printf("PK: %s   Valor: %s\n", valoresConvertidos[i][1].texto, valoresConvertidos[i][0].texto);
                qtdValidados++;
            }
        }
    break;
    case 4:
        for(int i = 0; i < qtdLinhas-3; i++){
            if(strcmp(valoresConvertidos[i][0].texto, valor) < 0){
                printf("PK: %s   Valor: %s\n", valoresConvertidos[i][1].texto, valoresConvertidos[i][0].texto);
                qtdValidados++;
            }
        }
    break;
    case 5:
        for(int i = 0; i < qtdLinhas-3; i++){
            if(strcmp(valoresConvertidos[i][0].texto, valor) <= 0){
                printf("PK: %s   Valor: %s\n", valoresConvertidos[i][1].texto, valoresConvertidos[i][0].texto);
                qtdValidados++;
            }
        }
    break;
    case 6:
        qtdValidados++;
        for(int i = 0; i < qtdLinhas-3; i++){
            int pontos = 0;
            for(int j = 0; valor[j] != '\0' && valoresConvertidos[i][0].texto[j] != '\0'; j++){
                if(valor[j] == valoresConvertidos[i][0].texto[j]){
                    pontos++;
                }
            }
            if(pontos >= melhorPontuacao){
                melhorPontuacao = pontos;
                indiceMaisProximo = i;
            }
        }
        printf("O valor mais próximo a %s na tabela é:\n", valor);
        printf("PK: %s   Valor: %s\n", valoresConvertidos[indiceMaisProximo][1].texto, valoresConvertidos[indiceMaisProximo][0].texto);
    break;
    }

    if(qtdValidados == 0){
        printf(">>> Ops! Não existem valores correpondentes à pesquisa nessa tabela!\n");
    }
    
    fclose(file);
}