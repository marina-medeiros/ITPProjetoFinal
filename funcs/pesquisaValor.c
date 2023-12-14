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
    int c, qtdColunas, colunaEscolhida, opcaoPesquisa;
    char valor[30];

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
    
    int qtdLinhas = contaLinhas(path);
    printf("qtd de linhas: %d\n", qtdLinhas);

    /////////////////Pega as colunas//////////////////

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

    fclose(table);

    /////////////////////////////////////////////////////

    printf(">>>As colunas disponíveis são:\n");

    for(int i = 0; i < qtdColunas; i++){
        printf(">>> %d: '%s' de tipo '%s'\n", (i+1), colunasTabela[i].nome, colunasTabela[i].tipo);
    }

    printf(">>>Insira o número da coluna em que você quer pesquisar\n");
    scanf("%d", &colunaEscolhida);

    while(colunaEscolhida < 1 || colunaEscolhida > qtdColunas){
        printf(">>>Ops! Essa coluna não existe na tabela. Tente novamente.");
        scanf("%d", &colunaEscolhida);
        if(colunaEscolhida > 0 && colunaEscolhida < qtdColunas){
            break;
        }
    }

    printf(">>>A coluna escolhida foi: '%s' de tipo '%s'\n", colunasTabela[colunaEscolhida-1].nome, colunasTabela[colunaEscolhida-1].tipo);

    printf(">>>Insira o valor a ser pesquisado\n");
    while ((c = getchar()) != '\n' && c != EOF) {}
    scanf("%[^\n]", valor);

    printf("Opções de pesquisa:\n");
    printf(" 1. Valores maiores que %s\n", valor);
    printf(" 2. Valores maiores ou iguais a %s\n", valor);
    printf(" 3. Valores iguais a %s\n", valor);
    printf(" 4. Valores menores que %s\n", valor);
    printf(" 5. Valores menores ou iguais a %s\n", valor);
    printf(" 6. Valores próximos a %s\n", valor);

    opcaoPesquisa = 0;

    while(opcaoPesquisa < 1 || opcaoPesquisa > 6){
        printf(">>>Insira o número da opção de pesquisa\n");
        scanf("%d", &opcaoPesquisa);

        if(opcaoPesquisa < 1 || opcaoPesquisa > 6){
            printf(">>>Ops! Opção inválida. Tente novamente.");
        }
        if(opcaoPesquisa > 0 && colunaEscolhida < 7){
            break;
        }
    }

    char *aux2;
    double floatValor = strtod(valor, &aux2);

    printf(">>>Resultado da pesquisa:\n");
    if(validaStringTipo(colunasTabela[colunaEscolhida-1].tipo) == 1){
        auxPesquisaNum(path, qtdLinhas, colunaEscolhida, opcaoPesquisa, floatValor);
    }
    if(validaStringTipo(colunasTabela[colunaEscolhida-1].tipo) == 2){
        auxPesquisaChar(path, qtdLinhas, colunaEscolhida, opcaoPesquisa, valor);
    }
}