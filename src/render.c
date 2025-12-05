/* #include "render.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include <stdio.h>

void render_frame() {
    // TODO:
    // 1. limpiar pantalla
    // 2. dibujar ladrillos
    // 3. dibujar pelota
    // 4. dibujar paddle
    // 5. mostrar puntaje y vidas
} */

#include "render.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include "score.h"
#include <stdio.h>
#include <windows.h>  // Necesario para Sleep()

extern int lives; // Declaramos la variable global de vidas en game.c

void render_frame()
{
    // 1. Limpiar pantalla
    printf("\033[2J\033[H");

    // 2. Dibujar paredes laterales y techo
    for (int y = 1; y <= 24; y++) {
        printf("\033[%d;%dH|", y, 1);   // Pared izquierda
        printf("\033[%d;%dH|", y, 80);  // Pared derecha
    }
    for (int x = 1; x <= 80; x++) {
        printf("\033[%d;%dH-", 1, x);   // Techo
        // opcional: suelo (no es necesario )
        // printf("\033[%d;%dH-", 24, x);  
    }

    // 3. Dibujar ladrillos
    Brick(*b)[BRICK_COLS] = bricks_get();
    for (int i = 0; i < BRICK_ROWS; i++)
    {
        for (int j = 0; j < BRICK_COLS; j++)
        {
            if (b[i][j].active)
                // Desplazar los ladrillos para que no se dibujen sobre las paredes
                printf("\033[%d;%dH#", i + 2, j * 8 + 2); // Ajuste para no chocar con paredes
        }
    }

    // 4. Dibujar pelota
    Ball *ball = ball_get();
    // Desplazamos la pelota por las coordenadas correctas
    printf("\033[%d;%dHo", ball->y + 1, ball->x + 1); // Se ajusta la posición de la pelota

    // 5. Dibujar paddle
    Paddle *p = paddle_get();
    // El paddle se dibuja en la fila 24 (debajo del tablero), aseguramos el ajuste
    for (int i = -p->width / 2; i <= p->width / 2; i++)
        printf("\033[24;%dH=", p->x + i);  // Ajustamos la posición del paddle en la fila 24

    // 6. Mostrar puntaje y vidas
    printf("\033[1;2HScore: %d   Lives: %d", score_get(), lives);

    // 7. Pausar la ejecución por 50ms entre frames
    Sleep(150);  // Pausa de 150 milisegundos
}
