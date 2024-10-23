// (búsqueda lineal) Implementar una función que reciba un vector, su longitud, un número objetivo
// a buscar y retorne un puntero a la posición en la que se encuentra. ¿Qué ocurre en caso que el
// objetivo no se encuentre y qué se retorna? Implemente 2 versiones de la función, utilizando los
// siguientes prototipos:

// const int * busqueda_lineal(const int * v, size_t n, int objetivo);
// bool busqueda_lineal(int * v, size_t n, int objetivo, int ** resultado);

#include <stddef.h>
#include <stdbool.h>

/**
 * @brief Realiza una búsqueda lineal en un arreglo para encontrar un número objetivo.
 *
 * Esta función recorre un arreglo de enteros y busca un valor objetivo. Si el valor
 * objetivo se encuentra, la función devuelve un puntero a la posición en el arreglo
 * donde se encuentra dicho valor. Si el objetivo no se encuentra en el arreglo, la
 * función devuelve NULL.
 *
 * @param v Puntero al arreglo donde se realizará la búsqueda.
 * @param n Longitud del arreglo.
 * @param objetivo El número a buscar en el arreglo.
 * @return Puntero a la posición del arreglo donde se encuentra el objetivo, o NULL si
 *         el objetivo no se encuentra o si el arreglo es NULL o de longitud cero.
 */
const int* busqueda_lineal(const int* v, size_t n, int objetivo) {
    if (v == NULL || n == 0) {
        return NULL;
    }

    
    for (size_t i = 0; i < n; i++) {
        if (*(v + i) == objetivo) {
            return (v + i); // Retornar la dirección del elemento encontrado
        }
    }

    return NULL;
}


/**
 * @brief Realiza una búsqueda lineal en un arreglo para encontrar un número objetivo.
 *
 * Esta función recorre un arreglo de enteros buscando un valor objetivo. Si el valor
 * objetivo se encuentra, la función asigna un puntero al elemento correspondiente en el
 * parámetro de salida `resultado` y devuelve true. Si el objetivo no se encuentra, 
 * asigna NULL a `resultado` y devuelve false.
 *
 * @param v Puntero al arreglo donde se realizará la búsqueda.
 * @param n Longitud del arreglo.
 * @param objetivo El número a buscar en el arreglo.
 * @param resultado Doble puntero para almacenar la dirección del elemento encontrado.
 * @return true si el objetivo se encuentra en el arreglo, false en caso contrario o si
 *         el arreglo es NULL o de longitud cero.
 */
bool busqueda_lineal(int *v, size_t n, int objetivo, int **resultado) {
    if (v == NULL || n == 0 || resultado == NULL) {
        *resultado = NULL;
        return false;
    }

    for (size_t i = 0; i < n; i++) {
        if (*(v + i) == objetivo) {
            *resultado = (v + i); 
            return true;
        }
    }
    
    *resultado = NULL;
    return false;
}