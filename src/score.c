/* #include "score.h"
#include <stdio.h>

static int score = 0;

void score_init(const char *filename) {
    // TODO: Crear archivo si no existe o cargar mejores puntajes
}

void score_add(int points) {
    // TODO: sumar puntos al puntaje actual
}

int score_get() {
    return score;
}

void score_save(const char *filename) {
    // TODO: guardar puntaje final del jugador en el archivo
}
*/ 
#include "score.h"
#include <stdio.h>

static int score = 0;
extern int lives;

// Estructura para almacenar puntajes e iniciales
typedef struct {
    char initials[4]; // 3 letras + '\0'
    int points;
} Score;

void score_init(const char *filename) {
    // Crear archivo si no existe
    FILE *f = fopen(filename,"a+");
    if (f) fclose(f);
    score = 0;
}

void score_add(int points) {
    score += points;
}

int score_get() {
    return score;
}

void score_save(const char *filename) {
    Score scores[8];    // almacenar los primeros 8 puntajes
    int count = 0;

    // Inicializar el arreglo para evitar basura
    for (int i=0;i<8;i++) {
        scores[i].points = 0;
        scores[i].initials[0] = '\0';
    }

    // Leer puntajes existentes
    FILE *f = fopen(filename,"r");
    if (f) {
        while (count < 8 && fscanf(f, "%3s %d", scores[count].initials, &scores[count].points) == 2) {
            count++;
        }
        fclose(f);
    }

    // Pedir iniciales al jugador
    char player[4];
    printf("Ingrese sus iniciales (3 letras): ");
    scanf("%3s", player);

    // Convertir a mayúsculas
    for (int i=0;i<3;i++) {
        if (player[i] >= 'a' && player[i] <= 'z') player[i] -= 32;
    }
    player[3] = '\0';

    // Agregar nuevo puntaje
    if (count < 8) {
        for (int i=0;i<3;i++) scores[count].initials[i] = player[i];
        scores[count].initials[3] = '\0';
        scores[count].points = score;
        count++;
    } else {
        // Reemplaza el menor si el nuevo es mayor
        int min_idx = 0;
        for (int i=1;i<8;i++)
            if (scores[i].points < scores[min_idx].points) min_idx = i;
        if (score > scores[min_idx].points) {
            for (int i=0;i<3;i++) scores[min_idx].initials[i] = player[i];
            scores[min_idx].initials[3] = '\0';
            scores[min_idx].points = score;
        }
    }

    // Ordenar puntajes de mayor a menor usando burbuja
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-1-i; j++) {
            if (scores[j].points < scores[j+1].points) {
                Score temp = scores[j];
                scores[j] = scores[j+1];
                scores[j+1] = temp;
            }
        }
    }

    // Guardar en el archivo
    f = fopen(filename,"w");
    if (!f) return;
    for (int i=0;i<count && i<8;i++) {
        fprintf(f,"%s %d\n", scores[i].initials, scores[i].points);
    }
    fclose(f);
}
