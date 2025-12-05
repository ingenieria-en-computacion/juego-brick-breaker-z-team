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
#include "brick.h

#define BRICK_ROWS 5
#define BRICK_COLS 10

typedef struct {
    int active;     // 1 si el ladrillo existe, 0 si está destruido
} Brick;

// Inicializa la matriz de ladrillos
void bricks_init();

// Devuelve un puntero a la matriz de ladrillos
Brick (*bricks_get())[BRICK_COLS];

// Marca un ladrillo como destruido
void brick_destroy(int row, int col);

#endif


#include "brick.h"


