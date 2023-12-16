#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "../heading/utils.h"
#include "../heading/definitions.h"

int validaStringTipo(char *tipo){
    setlocale(LC_ALL, "Portuguese");
    for(int i = 0; i < strlen(tipo); i++){
        tipo[i] = tolower(tipo[i]);
    }

    if(strcmp(tipo, "int") == 0 ||strcmp(tipo, "float") == 0 ||strcmp(tipo, "double") == 0){
        return 1;
    }
    if(strcmp(tipo, "char") == 0 ||strcmp(tipo, "string") == 0){
        return 2;
    }
    
    return 0;
}