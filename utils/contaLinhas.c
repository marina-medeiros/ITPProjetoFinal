#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "../heading/utils.h"
#include "../heading/definitions.h"

int contaLinhas(char *arquivo){
    setlocale(LC_ALL, "Portuguese");
    int qtdLinhas = 0;
    char aux;

    FILE *file = fopen(arquivo, "r");

    if(file == NULL){
        printf("Erro ao abrir arquivo na função 'contaLinhas'");
        return -1;
    }
    
    while(!feof(file)){
        aux = fgetc(file);
        if(aux == '\n'){
            qtdLinhas++;
        }
    }
    
    fclose(file);
    return qtdLinhas;
}