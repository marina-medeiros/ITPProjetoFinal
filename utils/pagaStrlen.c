#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../heading/functions.h"
#include "../heading/utils.h"
#include "../heading/definitions.h"

int pegaStrlen(char *path, int qtdLinhas, int qtdColunas){
    char linha[200];
    char formatar[40];
    int maiorStrlen = 0;

    FILE *file = fopen(path, "r");

    for(int i = 0; i < qtdLinhas; i++){
        fgets(linha, 200, file);

        if(i > 0){
            strcpy(formatar, strtok(linha, "|"));
            if(strlen(formatar) > maiorStrlen){
                maiorStrlen = strlen(formatar);
            }

            for(int j = 0; j < qtdColunas; j++){
                strcpy(formatar, strtok(NULL, "|"));
                if(strlen(formatar) > maiorStrlen){
                    maiorStrlen = strlen(formatar);
                }
            }
        }
    }
    
    printf("maiorStrlen %d\n", maiorStrlen);
    return maiorStrlen;

}