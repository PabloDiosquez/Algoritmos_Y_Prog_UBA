// Implementar una función que reciba 2 vectores y sus longitudes, y copie el contenido de uno en
// el otro, usando el siguiente prototipo y notación de punteros en la implementación, la función
// debe devolver true de poder realizar la operación false en caso contrario:

// bool veccpy(double * dest, size_t ldest, const double * orig, size_t lorig);

#include <stddef.h>
#include <stdbool.h>

/**
 * @brief Copia el contenido de un vector origen a un vector destino.
 *
 * Esta función copia elementos de un arreglo de números de punto flotante (orig)
 * en otro arreglo (dest). La función verifica que ambos punteros sean válidos,
 * que las longitudes de los arreglos sean mayores que cero, y que el arreglo
 * destino tenga suficiente espacio para almacenar los elementos del arreglo
 * origen. Si alguna de estas condiciones no se cumple, la función devuelve
 * false. En caso contrario, realiza la copia y devuelve true.
 *
 * @param dest Puntero al arreglo destino.
 * @param ldest Longitud del arreglo destino.
 * @param orig Puntero al arreglo origen.
 * @param lorig Longitud del arreglo origen.
 * @return true si la operación se realiza con éxito, false en caso contrario.
 */
bool veccpy(double* dest, size_t ldest, const double* orig, size_t lorig) {
    if (orig == NULL || dest == NULL || lorig == 0 || ldest == 0) {
        return false;
    }

    if (ldest < lorig) {
        return false;
    }

    for (size_t i = 0; i < lorig; i++) {
        *(dest + i) = *(orig + i);
    }

    return true;
}