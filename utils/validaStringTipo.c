#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include "../heading/utils.h"
#include "../heading/definitions.h"

int validaStringTipo(char *tipo){
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