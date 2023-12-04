#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../heading/functions.h"
#include "../heading/utils.h"
#include "../heading/definitions.h"

void criaTabela(){
    Tabela novaTabela;
    int qtdColunas = 0;
    char entradaCol[40];
    char tipo[10];
    int c;
    Coluna *arrayColunas = (Coluna*)malloc(sizeof(Coluna) * 1);
    
    printf("Insira o nome da tabela: ");

    while ((c = getchar()) != '\n' && c != EOF) {}
    scanf("%[^\n]", novaTabela.nome);

    if(validaTabela(novaTabela.nome) == 1){
        printf("Ops! Parece que já existe uma tabela com o nome %s!\n", novaTabela.nome);
        printf("----------------------------------------\n");
        return;
    }else{
        printf("----------------------------------------\n");
        printf("A primeira coluna da tabela será a chave primaria, ela será do tipo inteiro sem sinal\n");
        printf("Insira o nome da coluna de chave primária: ");

        while ((c = getchar()) != '\n' && c != EOF) {}
        scanf("%[^\n]", arrayColunas[qtdColunas].nome);

        strcpy(arrayColunas[qtdColunas].tipo, "int");

        qtdColunas++;

        printf("----------------------------------------\n");
        printf("Agora, vamos cadastrar as demais colunas, conforme o exemplo: string nome\n");
        printf("Os tipos disponíveis são: INT, CHAR, FLOAT, DOUBLE e STRING\n");
        printf("----------------------------------------\n");
        do{
            arrayColunas = realloc(arrayColunas, sizeof(Coluna) * (qtdColunas + 1));

            while ((c = getchar()) != '\n' && c != EOF) {}
            scanf("%[^\n]", entradaCol);

            strcpy(tipo, strtok(entradaCol, " "));

            if(strcmp(tipo, "FIM") != 0 && validaStringTipo(tipo) == 0){
                printf("Ops! O tipo inserido não é válido!\n");
                printf("----------------------------------\n");
                return;
            }
            else{

                strcpy(arrayColunas[qtdColunas].tipo, tipo);
                
                if(strcmp(arrayColunas[qtdColunas].tipo, "FIM") == 0){
                    break;
                }

                strcpy(arrayColunas[qtdColunas].nome, strtok(NULL, " "));

                qtdColunas++;
            }

        }while(strcmp(arrayColunas[qtdColunas].tipo, "FIM") != 0);
    }

    novaTabela.colunas = qtdColunas;

    criaTabelaArquivo(novaTabela, arrayColunas);
}