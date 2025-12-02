#include "menu.h"
#include <stdio.h>

// TODO: El estudiante debe completar el menú
void menu_show() {
    printf("\n======== BRICK BREAKER ========\n");
    printf("1) Jugar\n"); 
    printf("2) Instrucciones\n");
    printf("3) Salir\n");
    printf("Seleccione una opción: ");
    scanf("%i",&opt);
}

int menu_get_option() {
    int opt;
    if(opt>3){
        printf("Opción invalida)
        }
    else{
    // TODO: Completar la lectura de la opción. 
    while(opt!=3){
    case 1:
        break;
    case 2:
        break;
    }
    }
    return opt;
}
