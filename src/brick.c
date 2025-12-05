/*#include "brick.h"

// Matriz global de ladrillos
static Brick bricks[BRICK_ROWS][BRICK_COLS];

void bricks_init() {
    // TODO: Inicializar todos los ladrillos como activos
}

Brick (*bricks_get())[BRICK_COLS] {
    return bricks;
}

void brick_destroy(int row, int col) {
    // TODO: Marcar un ladrillo como destruido
}
*/
#include "brick.h"

// Matriz global de ladrillos
static Brick bricks[BRICK_ROWS][BRICK_COLS];

void bricks_init()
{
    // TODO: Inicializar todos los ladrillos como activos
    for (int i = 0; i < BRICK_ROWS; i++)
        for (int j = 0; j < BRICK_COLS; j++)
            bricks[i][j].active = 1;
}

Brick (*bricks_get()) [BRICK_COLS]
{
    return bricks;
}

void brick_destroy(int row, int col)
{
    // TODO: Marcar un ladrillo como destruido
    bricks[row][col].active = 0;
}
