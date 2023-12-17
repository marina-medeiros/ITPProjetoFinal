#include <stdio.h>
#include <string.h>
#include "../heading/utils.h"
#include "../heading/definitions.h"
#include <locale.h>

void criaTabelaArquivo(Tabela novaTabela, Coluna *arrayColunas){
    setlocale(LC_ALL, "Portuguese");
    FILE *inputs = fopen("tabelas.txt", "a"); 

    if(inputs == NULL){
        printf("Erro ao abrir arquivo inputs na função 'criaTabelaArquivo'\n");
        return;
    }

    fprintf(inputs, "%s\n", novaTabela.nome);
    fclose(inputs);

    /*
        Cada tabela vai ter um arquivo individual cujo nome será o nome da tabela.
        Esse arquivo conterá:
            -uma linha com a quantidade de colunas
            -Uma linha com os nomes das colunas
            -Uma linha com os tipos de cada coluna
            -As seguintes linhas, cada uma correspondendo a um registro
    */ 

    char path[60];

    strcpy(path, "tabelasIndividuais/");
    strcat(path, novaTabela.nome);
    strcat(path, ".txt");

    FILE *table = fopen(path, "w");

    if(table == NULL){
        printf("Erro ao abrir arquivo table na função 'criaTabelaArquivo'\n");
        return;
    }

    fprintf(table, "%d\n", novaTabela.colunas);
    for(int i = 0; i < novaTabela.colunas; i++){
        fprintf(table, "%s|", arrayColunas[i].nome);
    }
    fprintf(table, "\n");
    for(int i = 0; i < novaTabela.colunas; i++){
        fprintf(table, "%s|", arrayColunas[i].tipo);
    }
    fprintf(table, "\n");

    fclose(table);

}