#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../heading/functions.h"
#include "../heading/utils.h"
#include "../heading/definitions.h"

void pesquisaValor(){
    char nomeTabela[50];
    char path[60];
    char aux[100];
    int c, qtdColunas, colunaEscolhida;

    printf(">>>Insira o nome da tabela: ");

    while ((c = getchar()) != '\n' && c != EOF) {}
    scanf("%[^\n]", nomeTabela);

    if(validaTabela(nomeTabela) == 0){
        printf(">>>Ops! Parece que a tabela %s não existe!\n", nomeTabela);
        return;
    }

    strcpy(path, "tabelasIndividuais/");
    strcat(path, nomeTabela);
    strcat(path, ".txt");

    FILE *table = fopen(path, "r");

    if(table == NULL){
        printf(">>>Erro ao abrir arquivo table na função 'criaLinha'\n");
        return;
    }

    //Pega as colunas:

    fscanf(table, "%d", &qtdColunas);

    Coluna *colunasTabela = (Coluna*)malloc(sizeof(Coluna) * qtdColunas);

    fscanf(table, "%s", aux); //Lê a segunda linha da tabela, que contém os nomes das colunas

    strcpy(colunasTabela[0].nome, strtok(aux, "|"));

    for(int i = 1; i < qtdColunas; i++){
        strcpy(colunasTabela[i].nome, strtok(NULL, "|"));
    }

    fscanf(table, "%s", aux); //Lê a terceira linha da tabela, que contém os tipos das colunas

    strcpy(colunasTabela[0].tipo, strtok(aux, "|"));

    for(int i = 1; i < qtdColunas; i++){
        strcpy(colunasTabela[i].tipo, strtok(NULL, "|"));
    }

    ///////////////////////////////

    fclose(table);

    printf(">>>As colunas disponíveis são:\n");

    for(int i = 0; i < qtdColunas; i++){
        printf(">>>%d: '%s' de tipo '%s'\n", (i+1), colunasTabela[i].nome, colunasTabela[i].tipo);
    }

    colunaEscolhida = 1;

    while(colunaEscolhida < 1 || colunaEscolhida > qtdColunas){
        printf(">>>Insira o número da coluna em que você quer pesquisar\n");
        scanf("%d", &colunaEscolhida);

        if(colunaEscolhida < 1 || colunaEscolhida > qtdColunas){
            printf(">>>Ops! Essa coluna não existe na tabela. Tente novamente.");
            return;
        }
    }


    

}