#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "../heading/functions.h"
#include "../heading/utils.h"
#include "../heading/definitions.h"

void auxPesquisaNum(char *path, int qtdLinhas, int numColuna, int opcao, double valor, char *tipo){
    setlocale(LC_ALL, "Portuguese");
    char linha[200];
    char pedaco[40];
    char *aux;
    double valoresConvertidos[qtdLinhas-3][2];
    int qtdValidados = 0;

    FILE *file = fopen(path, "r");

    for(int i = 0; i < qtdLinhas; i++){
        fgets(linha, 200, file);
        if(i > 2){
            strcpy(pedaco, strtok(linha, "|"));
            valoresConvertidos[i-3][1] = strtod(pedaco, &aux); //pega a chave primária

            if(numColuna > 1){
                for(int k = 0; k < numColuna-2; k++){
                    strcpy(pedaco, strtok(NULL, "|"));
                }
                strcpy(pedaco, strtok(NULL, "|"));
            }

            valoresConvertidos[i-3][0] = strtod(pedaco, &aux); //converte para double
        }
    }

    if(strcmp(tipo, "int") == 0){
        switch(opcao){
            case 1:
                for(int i = 0; i < qtdLinhas-3; i++){
                    if(valoresConvertidos[i][0] > valor){
                        printf("PK:%.0lf Valor:%.0lf\n", valoresConvertidos[i][1], valoresConvertidos[i][0]);
                        qtdValidados++;
                    }
                }
            break;
            case 2:
                for(int i = 0; i < qtdLinhas-3; i++){
                    if(valoresConvertidos[i][0] >= valor){
                        printf("PK:%.0lf Valor:%.0lf\n", valoresConvertidos[i][1], valoresConvertidos[i][0]);
                        qtdValidados++;
                    }
                }
            break;
            case 3:
                for(int i = 0; i < qtdLinhas-3; i++){
                    if(valoresConvertidos[i][0] == valor){
                        printf("PK:%.0lf Valor:%.0lf\n", valoresConvertidos[i][1], valoresConvertidos[i][0]);
                        qtdValidados++;
                    }
                }
            break;
            case 4:
                for(int i = 0; i < qtdLinhas-3; i++){
                    if(valoresConvertidos[i][0] < valor){  
                        printf("PK:%.0lf Valor:%.0lf\n", valoresConvertidos[i][1], valoresConvertidos[i][0]);
                        qtdValidados++;
                    }
                }
            break;
            case 5:
                for(int i = 0; i < qtdLinhas-3; i++){
                    if(valoresConvertidos[i][0] <= valor){
                        printf("PK:%.0lf Valor:%.0lf\n", valoresConvertidos[i][1], valoresConvertidos[i][0]);
                        qtdValidados++;
                    }
                }
            break;
        }
    }else{
        switch(opcao){
            case 1:
                for(int i = 0; i < qtdLinhas-3; i++){
                    if(valoresConvertidos[i][0] > valor){
                        printf("PK:%.0lf Valor:%.2lf\n", valoresConvertidos[i][1], valoresConvertidos[i][0]);
                        qtdValidados++;
                    }
                }
            break;
            case 2:
                for(int i = 0; i < qtdLinhas-3; i++){
                    if(valoresConvertidos[i][0] >= valor){
                        printf("PK:%.0lf Valor:%.2lf\n", valoresConvertidos[i][1], valoresConvertidos[i][0]);
                        qtdValidados++;
                    }
                }
            break;
            case 3:
                for(int i = 0; i < qtdLinhas-3; i++){
                    if(valoresConvertidos[i][0] == valor){
                        printf("PK:%.0lf Valor:%.2lf\n", valoresConvertidos[i][1], valoresConvertidos[i][0]);
                        qtdValidados++;
                    }
                }
            break;
            case 4:
                for(int i = 0; i < qtdLinhas-3; i++){
                    if(valoresConvertidos[i][0] < valor){  
                        printf("PK:%.0lf Valor:%.2lf\n", valoresConvertidos[i][1], valoresConvertidos[i][0]);
                        qtdValidados++;
                    }
                }
            break;
            case 5:
                for(int i = 0; i < qtdLinhas-3; i++){
                    if(valoresConvertidos[i][0] <= valor){
                        printf("PK:%.0lf Valor:%.2lf\n", valoresConvertidos[i][1], valoresConvertidos[i][0]);
                        qtdValidados++;
                    }
                }
            break;
        }
    }

    

    if(qtdValidados == 0){
        printf("Ops! Não existem valores correpondentes à pesquisa nessa tabela!\n");
    }

    fclose(file);
}