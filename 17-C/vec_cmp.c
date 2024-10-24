// Implementar una función que reciba 2 vectores y sus longitudes, y retorne un valor booleano,
// por la interfaz, si los vectores son iguales.

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

/**
 * @brief Compara dos vectores para verificar si son iguales.
 * 
 * Esta función verifica si dos vectores de la misma longitud contienen
 * los mismos elementos. Si las longitudes son diferentes o si cualquiera
 * de los punteros es NULL, la función retorna false.
 * 
 * @param arr1 Puntero al primer arreglo.
 * @param arr2 Puntero al segundo arreglo.
 * @param len1 Longitud del primer arreglo (en número de elementos).
 * @param len2 Longitud del segundo arreglo (en número de elementos).
 * @param tam_elemento Tamaño en bytes de cada elemento del arreglo.
 * @return true Si los arreglos son iguales.
 * @return false Si los arreglos son diferentes o si hay algún error en los parámetros.
 */
bool son_iguales(const void* arr1, const void* arr2, size_t len1, size_t len2, size_t tam_elemento) {
    if (arr1 == NULL || arr2 == NULL || len1 != len2 || tam_elemento == 0) {
        return false;
    }

    return memcmp(arr1, arr2, len1 * tam_elemento) == 0;
}