#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "../heading/functions.h"
#include "../heading/utils.h"
#include "../heading/definitions.h"

void apagaTabela(){
    setlocale(LC_ALL, "Portuguese");
    char nomeTabela[50];
    char path[60];
    int c, qtdLinhas;

    printf(">>>Aqui está a lista de tabelas:\n");

    listaTabelas();

    printf(">>>Insira o nome da tabela: ");

    while ((c = getchar()) != '\n' && c != EOF) {}
    scanf("%[^\n]", nomeTabela);

    if(validaTabela(nomeTabela) == 0){
        printf(">>>Ops! Parece que a tabela %s não existe!\n", nomeTabela);
        return;
    }else{
        strcpy(path, "tabelasIndividuais/");
        strcat(path, nomeTabela);
        strcat(path, ".txt");

        //Excluir arquivo individual da tabela:
        if(remove(path) != 0){
            printf(">>>Erro ao apagar arquivo table na função 'apagaTabela'\n");
            return;
        }

        //Excluir a linha com o nome da tabela de "tabelas.txt"
        qtdLinhas = (contaLinhas("tabelas.txt"));

        char nomesTabelas[qtdLinhas][50];

        FILE *tabelas = fopen("tabelas.txt", "r");

        if(tabelas == NULL){
            printf(">>>Erro ao abrir arquivo tabelas no inicio da função 'apagaTabela'\n");
            return;
        }

        for(int i = 0; i < qtdLinhas; i++){
            fscanf(tabelas, "%s", nomesTabelas[i]);
        }

        fclose(tabelas);

        FILE *tabelasNovo = fopen("tabelas.txt", "w");

        if(tabelasNovo == NULL){
            printf(">>>Erro ao abrir arquivo tabelasNovo na função 'apagaTabela'\n");
            return;
        }

        for(int i = 0; i < qtdLinhas; i++){
            if(strcmp(nomesTabelas[i], nomeTabela) != 0){
                fprintf(tabelasNovo, "%s\n", nomesTabelas[i]);
            }
        }

        fclose(tabelasNovo);

        printf(">>>Tabela apagada com sucesso!\n");
    }


}