// Dado un arreglo de enteros y su longitud, escribir en lenguaje C una función que devuelva el 
// mayor elemento del arreglo.

#include <stdio.h>
#include <limits.h>

/*
 * Encuentra el mayor elemento de un arreglo de enteros desde un índice dado hasta el final.
 *
 * Parámetros:
 *   arr - Puntero al arreglo de enteros (const int *).
 *   len - Longitud del arreglo (size_t).
 *   d   - Índice de inicio para la búsqueda (size_t).
 *
 * Retorno:
 *   El mayor elemento encontrado desde el índice dado hasta el final del arreglo.
 */

int mayor_desde(const int *arr, size_t len, size_t d) {
    if (d == len - 1) {
        return arr[d];
    }
    int mayor_actual = mayor_desde(arr, len, d + 1);
    return (mayor_actual > arr[d]) ? mayor_actual : arr[d];
}

/*
 * Encuentra el mayor elemento de un arreglo de enteros.
 *
 * Parámetros:
 *   arr - Puntero al arreglo de enteros (const int *).
 *   len - Longitud del arreglo (size_t).
 *
 * Retorno:
 *   El mayor elemento del arreglo o INT_MIN si el arreglo es nulo o está vacío.
 */

int mayor(const int *arr, size_t len) {
    if (arr == NULL || len == 0) {
        fprintf(stderr, "Error: El arreglo es nulo o está vacío.\n");
        return INT_MIN;
    }
    return mayor_desde(arr, len, 0);
}

int main(void) {
    int arr[] = {3, 5, 1, 8, 2};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    int resultado = mayor(arr, len);

    if (resultado == INT_MIN) {
        printf("No se pudo determinar el mayor elemento (arreglo vacío o nulo).\n");
    } else {
        printf("Mayor: %d\n", resultado);
    }
    return 0;
}