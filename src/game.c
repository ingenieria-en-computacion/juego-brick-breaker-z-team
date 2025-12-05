#include "game.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "render.h"
#include "input.h"
#include "score.h"
#include <stdio.h> //para ciertas funciones

/* Aquí pueden declararse variables globales del estado del juego.
// Los estudiantes deben completar esto.
static int game_over = 0;

void game_init() {
    // TODO: Inicializar paddle, pelota, matriz de ladrillos, puntaje, vidas, etc.
}

void game_loop_step() {
    // TODO:
    // 1. Leer entrada con input_update()
    // 2. Actualizar pelota, paddle y colisiones
    // 3. Verificar si la pelota cae → restar vida
    // 4. Llamar a render_frame()
}

int game_is_over() {
    // TODO: retornar si el juego terminó
    return game_over;
}
*/

// Aquí pueden declararse variables globales del estado del juego.
// Los estudiantes deben completar esto.
static int game_over = 0;
int opt;

int lives = 3;  // número de vidas del jugador


void game_init() {
    // TODO: Inicializar paddle, pelota, matriz de ladrillos, puntaje, vidas, etc.
    paddle_init();
    ball_init();
    bricks_init();
    score_init("scores.txt");
    game_over = 0;
    lives = 3;
}

void game_loop_step() {
    // TODO:
   // 1. Leer entrada con input_update()
    int dir = input_update();

    // 2. Actualizar pelota, paddle y colisiones
    paddle_update(dir);
    ball_update();

    // 3. Verificar si la pelota cae → restar vida
    Ball *b = ball_get();
    if (b->y > 23) {   // fila más baja, la pelota cayó
        lives--;  // Restamos una vida
        if (lives <= 0) {
            game_over = 1;  // Si no hay vidas, termina el juego
            printf("Game Over! Final Score: %d\n", score_get());
        } else {
            ball_init();  // reinicia la pelota y coloca el paddle en su posición inicial
            paddle_init();  // Reinicia la posición del paddle
        }
    }

    // 4. Llamar a render_frame()
    render_frame();
}

int game_is_over() {
    // TODO: retornar si el juego terminó
    return game_over;
}

