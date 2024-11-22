// Implemente el TDA complejo.

#include <stdlib.h>
#include <limits.h>

/**
 * @brief Estructura que representa un número complejo.
 */
typedef struct {
    double re; 
    double im;
} complejo_t;

/**
 * @brief Crea un nuevo número complejo.
 *
 * @param re Parte real del número complejo.
 * @param im Parte imaginaria del número complejo.
 * @return Un puntero a la nueva instancia de `complejo_t`, o NULL si ocurre un error de memoria.
 */
complejo_t *complejo_crear(double re, double im) {
    complejo_t *nuevo = malloc(sizeof(complejo_t));
    if (nuevo == NULL) {
        return NULL;
    }
    nuevo->re = re;
    nuevo->im = im;
    return nuevo;
}

/**
 * @brief Libera la memoria asociada a un número complejo.
 *
 * @param complejo Puntero al número complejo a liberar. Si es NULL, no hace nada.
 */
void complejo_destruir(complejo_t *complejo) {
    if (complejo != NULL) {
        free(complejo);
    }
}

/**
 * @brief Copia los valores de un número complejo a otro.
 *
 * @param dest Puntero al número complejo destino.
 * @param orig Puntero al número complejo origen.
 * @return Puntero al número complejo destino, o NULL si alguno de los punteros es inválido.
 */
complejo_t *complejo_copiar(complejo_t *dest, const complejo_t *orig) {
    if (dest == NULL || orig == NULL) {
        return NULL;
    }
    dest->re = orig->re;
    dest->im = orig->im;
    return dest;
}

/**
 * @brief Crea una copia de un número complejo.
 *
 * @param orig Puntero al número complejo a clonar.
 * @return Un nuevo puntero con los mismos valores, o NULL si ocurre un error de memoria.
 */
complejo_t *complejo_clonar(const complejo_t *orig) {
    if (orig == NULL) {
        return NULL;
    }
    complejo_t *nuevo = malloc(sizeof(complejo_t));
    if (nuevo == NULL) {
        return NULL;
    }
    nuevo->re = orig->re;
    nuevo->im = orig->im;
    return nuevo;
}

/**
 * @brief Obtiene la parte real de un número complejo.
 *
 * @param compl Puntero al número complejo.
 * @return La parte real del número complejo, o LONG_MAX si el puntero es NULL.
 */
double complejo_get_real(const complejo_t *compl) {
    return (compl != NULL) ? compl->re : LONG_MAX;
}

/**
 * @brief Obtiene la parte imaginaria de un número complejo.
 *
 * @param compl Puntero al número complejo.
 * @return La parte imaginaria del número complejo, o LONG_MAX si el puntero es NULL.
 */
double complejo_get_imag(const complejo_t *compl) {
    return (compl != NULL) ? compl->im : LONG_MAX;
}

/**
 * @brief Establece la parte real de un número complejo.
 *
 * @param compl Puntero al número complejo.
 * @param re Nuevo valor de la parte real.
 */
void complejo_set_real(complejo_t *compl, double re) {
    if (compl != NULL) {
        compl->re = re;
    }
}

/**
 * @brief Establece la parte imaginaria de un número complejo.
 *
 * @param compl Puntero al número complejo.
 * @param im Nuevo valor de la parte imaginaria.
 */
void complejo_set_imag(complejo_t *compl, double im) {
    if (compl != NULL) {
        compl->im = im;
    }
}

/**
 * @brief Conjuga un número complejo (invierte el signo de su parte imaginaria).
 *
 * @param compl Puntero al número complejo a conjugar.
 * @return El mismo puntero si es válido, o NULL si el puntero es inválido.
 */
complejo_t *complejo_conjugar(complejo_t *compl) {
    if (compl == NULL) {
        return NULL;
    }
    compl->im = -compl->im;
    return compl;
}