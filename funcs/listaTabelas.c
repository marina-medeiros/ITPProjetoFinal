#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../heading/functions.h"
#include "../heading/utils.h"
#include "../heading/definitions.h"

void listaTabelas(){
    int qtdLinhas = contaLinhas("tabelas.txt");
    char aux[50];
    
    FILE *file = fopen("tabelas.txt", "r");

    if(file == NULL){
        printf("Erro ao abrir arquivo na função 'listaTabelas'\n");
        return;
    }

    for(int i = 0; i < qtdLinhas; i++){
        fscanf(file, "%s", aux);
        printf("%s\n", aux);
    }

    fclose(file);
}