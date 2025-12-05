/*#include "ball.h"

static Ball ball;

void ball_init() {
    // TODO: posicionar la pelota al centro y darle velocidad inicial
}

void ball_update() {
    // TODO: mover la pelota y actualizar colisiones generales
}

Ball* ball_get() {
    return &ball;
}*/

#ifndef BALL_H
#define BALL_H

typedef struct {
    int x, y;       // Posición
    int dx, dy;     // Dirección
} Ball;

void ball_init();
void ball_update();

// Devuelve un puntero a la pelota global
Ball* ball_get();

#endif


