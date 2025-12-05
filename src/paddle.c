#include "paddle.h"

/*static Paddle paddle;

void paddle_init() {
    // TODO: colocar el paddle centrado
}

void paddle_update(int direction) {
    // TODO: mover el paddle según la dirección (-1 izquierda, 1 derecha)
}

Paddle* paddle_get() {
    return &paddle;
}*/

static Paddle paddle;

void paddle_init() {
    // TODO: colocar el paddle centrado
    paddle.width = 7;
    paddle.x = 40; // centro aproximado
}

void paddle_update(int direction) {
    // TODO: mover el paddle según la dirección (-1 izquierda, 1 derecha)
     //paddle.x += direction*2; // mover 2 unidades por paso este paso lo hace muy lento 
    paddle.x += direction*5; // mover  5 unidades por paso este paso lo hace muy lento 
    if (paddle.x - paddle.width/2 < 0) paddle.x = paddle.width/2;
    if (paddle.x + paddle.width/2 > 79) paddle.x = 79 - paddle.width/2;

}

Paddle* paddle_get() {
    return &paddle;
}

