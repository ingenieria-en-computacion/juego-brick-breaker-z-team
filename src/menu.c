#include "menu.h"
#include "game.h" // para llamar al juego
#include "score.h" //para guaradar los puntajes
#include <stdio.h>

/*// TODO: El estudiante debe completar el menú
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
}*/



static int opt = 0;  // Declaración de la opción seleccionada

void menu_show() {
    printf("\n======== BRICK BREAKER ========\n");
    printf("1) Jugar\n");
    printf("2) Instrucciones\n");
    printf("3) Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opt);  // Obtener la opción seleccionada
}

int menu_get_option() {
    do {
        menu_show();  // Mostrar el menú
        switch (opt) {
            case 1:  // Opción para jugar
                // Inicializa el sistema de puntajes
                score_init("scores.txt");

                // Inicializa el juego (ladrillos, pelota, paddle, etc.)
                game_init();

                // Bucle principal del juego
                while (!game_is_over()) {
                    game_loop_step();
                }

                // Guarda la puntuación al final del juego
                score_save("scores.txt");

                printf("\nJuego terminado. Volviendo al menú...\n\n");
                break;

            case 2:  // Opción para mostrar las instrucciones
                // Mostrar instrucciones
                printf("\nInstrucciones:\n");
                printf("- Mover paddle con 'A' y 'D'\n");
                printf("- Destruir todos los ladrillos\n");
                printf("- Evitar que la pelota caiga\n");
                printf("- Si la pelota cae perderás una vida\n");
                printf("- Perder las 3 vidas GAME OVER\n\n");
                break;

            case 3:  // Opción para salir
                printf("\nGracias por jugar. ¡Hasta la próxima!\n");
                break;

            default:  // Opción inválida
                printf("\nOpción inválida. Intente nuevamente.\n");
                break;
        }
    } while (opt < 1 || opt > 3);  // Repetir si la opción no es válida

    return opt;  // Retorna la opción seleccionada
}
