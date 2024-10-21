// Escribir una función que reciba un arreglo de números y la cantidad de elemen-
// tos, y devuelva el promedio.

#include <stdio.h>

/**
 * Calcula el promedio de un arreglo de números de tipo float.
 *
 * @param numeros Un puntero al arreglo de números.
 * @param len La cantidad de elementos en el arreglo.
 * @return El promedio de los elementos del arreglo. Si el arreglo está vacío (len = 0),
 *         la función devuelve 0.0 y muestra un mensaje de advertencia.
 */
float obtener_promedio(float* numeros, size_t len) {
    if (len == 0) {
        printf("No se puede calcular el promedio de un arreglo vacío.\n");
        return 0.0;
    }

    float s = 0.0;
    for (size_t i = 0; i < len; i++) {
        s += numeros[i];
    }
    return s / len;
}