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
#include "ball.h"


static Ball ball;   // pelota global

void ball_init() {
    // posicionar la pelota al centro y darle velocidad inicial
    ball.x = 40;  // centro horizontal aproximado
    ball.y = 12;  // centro vertical aproximado
    ball.dx = 1;  // velocidad inicial horizontal
    ball.dy = -1; // velocidad inicial vertical
}

void ball_update() {

    // mover la pelota
    ball.x += ball.dx;
    ball.y += ball.dy;

    // colisiones con paredes laterales
    if (ball.x <= 0 || ball.x >= 79)
        ball.dx = -ball.dx;

    // colisión con parte superior
    if (ball.y <= 0)
        ball.dy = -ball.dy;


}

Ball* ball_get() {
    return &ball;
}
