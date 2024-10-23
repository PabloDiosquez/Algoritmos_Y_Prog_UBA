// (búsqueda binaria) Implemente una función similar de búsqueda, utilizando búsqueda binaria.
// Prototipos:

// const int * busqueda_binaria(const int * v, /* vector donde buscar */
//                              size_t n,      /* largo del vector */
//                              int objetivo,  /* elemento a buscar */
//                              size_t izq,    /* franja del vector donde buscar, */
//                              size_t der);   /* delimitada por izq y der */

// bool busqueda_binaria(int * v, /* vector donde buscar */
//                        size_t n,      /* largo del vector */
//                        int objetivo,  /* elemento a buscar */
//                        size_t izq,    /* franja del vector donde buscar, */
//                        size_t der,    /* delimitada por izq y der */
//                        int ** resultado);

#include <stddef.h>
#include <stdbool.h>

/**
 * @brief Realiza una búsqueda binaria en un arreglo ordenado para encontrar un número objetivo.
 *
 * La función busca un número en un arreglo de enteros ordenados utilizando el algoritmo
 * de búsqueda binaria. Si el objetivo se encuentra dentro de los límites especificados
 * (izq a der), se devuelve un puntero a la posición del arreglo donde se encuentra.
 * Si no se encuentra, la función devuelve NULL.
 *
 * @param v Puntero al arreglo ordenado donde se realizará la búsqueda.
 * @param n Longitud del arreglo.
 * @param objetivo El número a buscar en el arreglo.
 * @param izq Índice inicial del rango del arreglo donde buscar.
 * @param der Índice final del rango del arreglo donde buscar.
 * @return Puntero a la posición del arreglo donde se encuentra el objetivo, o NULL si
 *         no se encuentra o si el arreglo es NULL o de longitud cero.
 */
const int* busqueda_binaria(const int* v, size_t n, int objetivo, size_t izq, size_t der) {
    if (v == NULL || n == 0 || izq > der) {
        return NULL;
    }

    while (izq <= der) {
        size_t med = izq + (der - izq) / 2;
        
        if (*(v + med) == objetivo) {
            return (v + med);
        }
        else if (*(v + med) < objetivo) {
            izq = med + 1;
        }
        else {
            der = med - 1;
        }
    }
    return NULL;
}

/**
 * @brief Realiza una búsqueda binaria en un arreglo ordenado para encontrar un número objetivo.
 *
 * La función busca un número en un arreglo de enteros ordenados utilizando el algoritmo
 * de búsqueda binaria. Si el objetivo se encuentra dentro de los límites especificados
 * (izq a der), se devuelve un puntero al elemento correspondiente en el parámetro de salida
 * `resultado` y la función retorna true. Si el objetivo no se encuentra, se asigna NULL
 * a `resultado` y la función retorna false.
 *
 * @param v Puntero al arreglo ordenado donde se realizará la búsqueda.
 * @param n Longitud del arreglo.
 * @param objetivo El número a buscar en el arreglo.
 * @param izq Índice inicial del rango del arreglo donde buscar.
 * @param der Índice final del rango del arreglo donde buscar.
 * @param resultado Doble puntero para almacenar la dirección del elemento encontrado.
 * @return true si el objetivo se encuentra en el arreglo, false en caso contrario o si
 *         el arreglo es NULL, de longitud cero, o los índices son inválidos.
 */
bool busqueda_binaria(int* v, size_t n, int objetivo, size_t izq, size_t der, int** resultado) {
    if (v == NULL || n == 0 || izq > der) {
        *resultado = NULL;
        return false;
    }

    while (izq <= der) {
        size_t med = izq + (der - izq) / 2;

        if (*(v + med) == objetivo) {
            *resultado = (v + med); // Asignar la dirección del elemento encontrado a resultado
            return true;
        }
        else if (*(v + med) < objetivo) {
            izq = med + 1;
        }
        else {
            der = med - 1;
        }
    }

    *resultado = NULL;
    return false;
}