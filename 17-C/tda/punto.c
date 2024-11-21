// Implemente el TDA punto para un punto en R2.
// Utilice, como representación interna, la siguiente definición:

// struct punto {
//     double x;
//     double y;
// };

#include <stdlib.h>
#include <math.h>
 
/**
 * @brief Estructura para representar un punto en el plano cartesiano.
 */
typedef struct {
    double x; 
    double y; 
} punto_t;

/**
 * @brief Crea un nuevo punto en el plano cartesiano.
 *
 * @param x Coordenada X del punto.
 * @param y Coordenada Y del punto.
 * @return Un puntero al nuevo punto, o NULL si no se pudo asignar memoria.
 *
 * @note Es responsabilidad del usuario liberar la memoria con `punto_destruir`.
 */
punto_t *punto_crear(double x, double y) {
    punto_t *punto = malloc(sizeof(punto_t));
    if (punto == NULL) {
        return NULL;
    }
    punto->x = x;
    punto->y = y;
    return punto;
}

/**
 * @brief Libera la memoria asignada a un punto.
 *
 * @param punto Puntero al punto a destruir. Si es NULL, no realiza ninguna acción.
 */
void punto_destruir(punto_t *punto) {
    if (punto != NULL) {
        free(punto);
    }
}

/**
 * @brief Copia las coordenadas de un punto origen a un punto destino.
 *
 * @param dest Puntero al punto destino.
 * @param orig Puntero al punto origen.
 * @return Un puntero al punto destino, o NULL si alguno de los punteros es NULL.
 *
 * @note Ambos punteros deben apuntar a memoria válida.
 */
punto_t *punto_copiar(punto_t *dest, const punto_t *orig) {
    if (dest == NULL || orig == NULL) {
        return NULL;
    }
    dest->x = orig->x;
    dest->y = orig->y;
    return dest;
}

/**
 * @brief Crea una copia de un punto existente.
 *
 * @param orig Puntero al punto origen.
 * @return Un puntero al nuevo punto clonado, o NULL si no se pudo asignar memoria 
 *         o si el puntero origen es NULL.
 *
 * @note Es responsabilidad del usuario liberar la memoria del clon con `punto_destruir`.
 */
punto_t *clonar_punto(const punto_t *orig) {
    if (orig == NULL) {
        return NULL;
    }
    punto_t *dest = malloc(sizeof(punto_t));
    if (dest == NULL) {
        return NULL;
    }
    dest->x = orig->x;
    dest->y = orig->y;
    return dest;
}

/**
 * @brief Obtiene la coordenada X de un punto.
 *
 * @param punto Puntero al punto del cual obtener la coordenada X.
 * @return La coordenada X del punto, o 0.0 si el puntero es NULL.
 */
double punto_get_x(const punto_t *punto) {
    if (punto != NULL) {
        return punto->x;
    }
}

/**
 * @brief Obtiene la coordenada Y de un punto.
 *
 * @param punto Puntero al punto del cual obtener la coordenada Y.
 * @return La coordenada Y del punto, o 0.0 si el puntero es NULL.
 */
double punto_get_y(const punto_t *punto) {
    if (punto != NULL) {
        return punto->y;
    }
}

/**
 * @brief Establece un nuevo valor para la coordenada X de un punto.
 *
 * @param punto Puntero al punto al cual establecer la coordenada X.
 * @param x Nuevo valor para la coordenada X.
 *
 * @note Si el puntero es NULL, no realiza ninguna acción.
 */
void punto_set_x(punto_t *punto, double x) {
    if (punto == NULL) {
        return;
    }
    punto->x = x;
}

/**
 * @brief Establece un nuevo valor para la coordenada Y de un punto.
 *
 * @param punto Puntero al punto al cual establecer la coordenada Y.
 * @param y Nuevo valor para la coordenada Y.
 *
 * @note Si el puntero es NULL, no realiza ninguna acción.
 */
void punto_set_y(punto_t *punto, double y) {
    if (punto == NULL) {
        return;
    }
    punto->y = y;
}

/**
 * @brief Suma las coordenadas de un punto a otro punto.
 *
 * @param res Puntero al punto que se modificará con el resultado de la suma.
 * @param punto Puntero al punto que se sumará al punto `res`.
 * @return Un puntero al punto `res`, o NULL si alguno de los punteros es NULL.
 */
punto_t *punto_sumar(punto_t *res, const punto_t *punto) {
    if (res == NULL || punto == NULL) {
        return NULL;
    }

    res->x += punto->x;
    res->y += punto->y;
    return res;
}

/**
 * @brief Resta las coordenadas de un punto a otro punto.
 *
 * @param res Puntero al punto que se modificará con el resultado de la resta.
 * @param punto Puntero al punto que se restará al punto `res`.
 * @return Un puntero al punto `res`, o NULL si alguno de los punteros es NULL.
 */
punto_t *punto_restar(punto_t *res, const punto_t *punto) {
    if (res == NULL || punto == NULL) {
        return NULL;
    }

    res->x -= punto->x;
    res->y -= punto->y;
    return res;
}

/**
 * @brief Calcula la distancia euclidiana entre dos puntos en el plano.
 *
 * @param p Puntero al primer punto.
 * @param q Puntero al segundo punto.
 * @return La distancia euclidiana entre los puntos `p` y `q`, o -1.0 si alguno de los punteros es NULL.
 *
 * @note La distancia siempre será un valor no negativo, excepto en caso de punteros NULL donde se retorna -1.0.
 */
double punto_distancia(const punto_t *p, const punto_t *q) {
    if (p == NULL || q == NULL) {
        return -1.0;
    }

    double dx = p->x - q->x;
    double dy = p->y - q->y;

    return sqrt(dx * dx + dy * dy);
}

/**
 * @brief Calcula la norma (módulo) de un punto en el plano, interpretado como un vector.
 *
 * @param p Puntero al punto cuyo módulo se desea calcular.
 * @return La norma del punto `p`, o -1.0 si el puntero es NULL.
 *
 * @note La norma es siempre un valor no negativo, excepto en caso de punteros NULL donde se retorna -1.0.
 */
double punto_norma(const punto_t *p) {
    if (p == NULL) {
        return -1.0;
    }

    return sqrt(p->x * p->x + p->y * p->y);
}