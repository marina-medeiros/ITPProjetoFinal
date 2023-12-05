#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../heading/functions.h"
#include "../heading/utils.h"
#include "../heading/definitions.h"

void apagaTabela(){
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
        strcpy(path, "tabelasIndividuais/");
        strcat(path, nomeTabela);
        strcat(path, ".txt");

        FILE *table = fopen(path, "r");

        if(table == NULL){
            printf("Erro ao abrir arquivo table na função 'apagaTabela'\n");
            return;
        }else{
            printf("Sucesso ao abrir arquivo table na função 'apagaTabela'\n");
        }

        //Excluir arquivo individual da tabela:

        if(remove(path) == 0){
            printf("Sucesso ao apagar arquivo table na função 'apagaTabela'\n");
        }else{
            printf("Erro ao apagar arquivo table na função 'apagaTabela'\n");
            return;
        }



    }


}