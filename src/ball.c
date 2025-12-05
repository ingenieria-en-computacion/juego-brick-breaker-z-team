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
#include "brick.h"
#include "paddle.h"
#include "score.h"


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
    
    // colisión con la raqueta
    Paddle *p = paddle_get();
    if (ball.y == 23) {
        if (ball.x >= p->x - p->width/2 && ball.x <= p->x + p->width/2)
            ball.dy = -ball.dy;
    }
        // colisión con ladrillos
    Brick (*b)[BRICK_COLS] = bricks_get();
    for (int i=0; i<BRICK_ROWS; i++) {
        for (int j=0; j<BRICK_COLS; j++) {
            if (b[i][j].active) {
                int brick_x = j*8 + 4;
                int brick_y = i*2 + 2;
                if (ball.x >= brick_x-3 && ball.x <= brick_x+3 &&
                    ball.y == brick_y) {
                    brick_destroy(i,j);
                    ball.dy = -ball.dy;
                    score_add(10);
                    }
                }
            }
        }

}

Ball* ball_get() {
    return &ball;
}
