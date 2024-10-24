/* Escribir una función que convierta un número que representa una cantidad de segundos, 
a su equivalente en horas, minutos y segundos, retornando las partes por la interfaz, 
bool por el nombre, indicando el resultado de la operación, true de ser posible false si no.
Realizar las validaciones pertinentes.
*/

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Convierte una cantidad de segundos a su equivalente en horas, minutos y segundos.
 *
 * La función toma un número entero que representa una cantidad de segundos y lo convierte
 * en su equivalente en horas, minutos y segundos. Los resultados se almacenan en las variables 
 * apuntadas por `h`, `m` y `s`. La función retorna `true` si la conversión es exitosa y `false` 
 * si ocurre algún error (por ejemplo, si el número de segundos es negativo o los punteros son nulos).
 *
 * @param segundos La cantidad de segundos a convertir. Debe ser no negativo.
 * @param h Puntero a una variable donde se almacenará el número de horas.
 * @param m Puntero a una variable donde se almacenará el número de minutos.
 * @param s Puntero a una variable donde se almacenará el número de segundos restantes.
 * @return `true` si la conversión fue exitosa, `false` si hubo un error (segundos negativos o punteros nulos).
 */
bool a_hms(int segundos, int* h, int* m, int* s) {
    if (segundos < 0) return false;

    if (h == NULL || m == NULL || s == NULL) return false;

    *h = segundos / 3600;
    *m = (segundos % 3600) / 60;
    *s = (segundos % 3600) % 60;
    return true;
}