#include <stdio.h>
#include <string.h>
#include "../heading/utils.h"
#include "../heading/definitions.h"

int validaStringTipo(char *tipo){
    if(strcmp(tipo, "int") == 0 ||strcmp(tipo, "float") == 0 ||strcmp(tipo, "double") == 0 ||strcmp(tipo, "char") == 0 ||strcmp(tipo, "string") == 0){
        return 1;
    }
    
    return 0;
}