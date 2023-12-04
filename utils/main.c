#include <stdio.h>
#include <string.h>

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
                printf("----------------------------------------\n");
                printf("Você escolheu: 1. Criar nova tabela\n");
                printf("----------------------------------------\n");
                criaTabela(); 
            break;

            case 2: 
                printf("----------------------------------------\n");
                printf("Você escolheu: 2. Listar todas as tabelas\n");
                printf("----------------------------------------\n");
                listaTabelas(); 
            break;
            
            case 3: 
                printf("----------------------------------------\n");
                printf("Você escolheu: 3. Criar uma nova linha na tabela\n");
                printf("----------------------------------------\n");
                criaLinha(); 
            break;
        
            
            //case 4: listaDadosTabela(); break;
            
            //case 5: pesquisaValor(); break;
            
            //case 6: apagaLinha(); break;
            
            //case 7: apagaTabela(); break;
            
            case 8: continuar = 0; break;

            default: printf("Valor inválido. Por favor, digite novamente.\n"); break;
        }
    }

    return 0;
}