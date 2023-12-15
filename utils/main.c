#include <stdio.h>
#include <string.h>
#include <conio.h>

#include "../heading/functions.h"
#include "../heading/utils.h"

int main(){
    int escolha;
    int continuar = 1;

    while(continuar){
        mostraMenu();
        scanf("%d", &escolha);

        switch(escolha){

            case 1:
                system("cls");
                printf("----------------------------------------\n");
                printf("Você escolheu: 1. Criar nova tabela\n");
                printf("----------------------------------------\n");
                criaTabela();
                printf("----------------------------------------\n");
                printf("Função finalizada! Digite 0 para encerrar ou 1 para continuar.\n");
                scanf("%d", &continuar);
                system("cls");
            break;

            case 2: 
                system("cls");
                printf("----------------------------------------\n");
                printf("Você escolheu: 2. Listar todas as tabelas\n");
                printf("----------------------------------------\n");
                listaTabelas(); 
                printf("----------------------------------------\n");
                printf("Função finalizada! Digite 0 para encerrar ou 1 para continuar.\n");
                scanf("%d", &continuar);
                system("cls");
            break;
            
            case 3: 
                system("cls");
                printf("----------------------------------------\n");
                printf("Você escolheu: 3. Criar uma nova linha na tabela\n");
                printf("----------------------------------------\n");
                criaLinha(); 
                printf("----------------------------------------\n");
                printf("Função finalizada! Digite 0 para encerrar ou 1 para continuar.\n");
                scanf("%d", &continuar);
                system("cls");
            break;
        
            case 4: 
                system("cls");
                printf("----------------------------------------\n");
                printf("Você escolheu: 4. Listar todos os dados de uma tabela\n");
                printf("----------------------------------------\n");
                listaDadosTabela();
                printf("----------------------------------------\n");
                printf("Função finalizada! Digite 0 para encerrar ou 1 para continuar.\n");
                scanf("%d", &continuar);
                system("cls");
            break;
            
            case 5: 
                system("cls");
                printf("----------------------------------------\n");
                printf("Você escolheu: 5. Pesquisar valor em uma tabela\n");
                printf("----------------------------------------\n");
                pesquisaValor();
                printf("----------------------------------------\n");
                printf("Função finalizada! Digite 0 para encerrar ou 1 para continuar.\n");
                scanf("%d", &continuar);
                system("cls");
            break;

            case 6: 
                system("cls");
                printf("----------------------------------------\n");
                printf("Você escolheu: 6. Apagar uma linha\n");
                printf("----------------------------------------\n"); 
                apagaLinha();    
                printf("----------------------------------------\n");
                printf("Função finalizada! Digite 0 para encerrar ou 1 para continuar.\n");
                scanf("%d", &continuar);
                system("cls");
            break;
            
            case 7:
                system("cls");
                printf("----------------------------------------\n");
                printf("Você escolheu: 7. Apagar uma tabela\n");
                printf("----------------------------------------\n");
                apagaTabela();
                printf("----------------------------------------\n");
                printf("Função finalizada! Digite 0 para encerrar ou 1 para continuar.\n");
                scanf("%d", &continuar);
                system("cls");
            break;
            
            case 8: continuar = 0; break;

            default: printf("Valor inválido. Por favor, digite novamente.\n"); break;
        }
    }

    return 0;
}