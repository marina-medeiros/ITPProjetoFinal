#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "../heading/utils.h"
#include "../heading/definitions.h"

int validaTabela(char *nomeTabela){
    setlocale(LC_ALL, "Portuguese");
    int qtdLinhas = contaLinhas("tabelas.txt");
    char aux[50];
    
    FILE *file = fopen("tabelas.txt", "r");

    if(file == NULL){
        printf("Erro ao abrir arquivo na função 'validaTabela'\n");
        return -1;
    }

    for(int i = 0; i < qtdLinhas; i++){
        fscanf(file, "%s", aux);

        if(strcmp(aux, nomeTabela) == 0){
            return 1; // se existir, retorna 1
            break;
        }
    }

    fclose(file);

    return 0;
}