// Implemente el TDA punto para un punto en R2.
// Utilice, como representación interna, la siguiente definición:

// struct punto {
//     double x;
//     double y;
// };

// Implemente además las siguientes primitivas:

// punto_t * punto_crear(double, double);

// void punto_destruir(punto_t *);

// punto_t * punto_copiar(punto_t *, const punto_t *);

// punto_t * punto_clonar(const punto_t *);

// double punto_get_x(const punto_t *);

// double punto_get_y(const punto_t *);

// double punto_set_x(punto_t *, double);

// double punto_set_y(punto_t *, double);

// punto_t * punto_sumar(punto_t *, const punto_t *);

// punto_t * punto_restar(punto_t *, const punto_t *);

// double punto_distancia(const punto_t *, const punto_t *);

// double punto_norma(const punto_t *);

#include <stdlib.h>

typedef struct {
    double x;
    double y;
} punto_t;

punto_t *punto_crear(double x, double y){
    punto_t *punto = malloc(sizeof(punto_t));
    if(punto == NULL){
        return NULL;
    }
    punto->x = x;
    punto->y = y;
    return punto;
}

void punto_destruir(punto_t *punto){
    if(punto != NULL){
        free(punto);
    }
}

punto_t *punto_copiar(punto_t *dest, const punto_t *orig){
    if(dest == NULL || orig == NULL){
        return NULL;
    }
    dest->x = orig->x;
    dest->y = orig->y;
    return dest;
}

punto_t *clonar_punto(const punto_t *orig){
    
}