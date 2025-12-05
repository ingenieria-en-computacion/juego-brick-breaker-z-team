#include "input.h"
#include "library_compat.h"
/*
int input_update() {
    // TODO:
    // Leer teclas 'a' y 'd', regresar -1 o 1
    // Si no se presiona nada, regresar 0
    return 0;
}*/
int input_update() {
    // Leer teclas 'a' y 'd', regresar -1 o 1
    if (!kbhit_compat()) return 0;   // ⚠ usar kbhit_compat
    int c = getch_compat();          // correcto
    if (c == 'a' || c == 'A') return -1;
    if (c == 'd' || c == 'D') return 1;

    // Si no se presiona nada, regresar 0
    return 0;
}
