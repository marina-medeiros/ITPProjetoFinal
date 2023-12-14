#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../heading/utils.h"

void mostraMenu(){
    printf("\n--------------------Menu--------------------\n");
    printf("Digite o número correspondente à operação:\n");
    printf("1. Criar uma tabela\n");
    printf("2. Listar todas as tabelas\n");
    printf("3. Criar uma nova linha na tabela\n");
    printf("4. Listar todos os dados de uma tabela\n");
    printf("5. Pesquisar valor em uma tabela\n");
    printf("6. Apagar uma linha\n");
    printf("7. Apagar uma tabela\n");
    printf("8. Sair\n");
    printf("--------------------------------------------\n");
}