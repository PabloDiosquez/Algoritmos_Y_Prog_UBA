/*  Implementar funciones que reciban un arreglo de números y su longitud y realicen las operaciones
    detalladas abajo. Utilice notación de punteros exclusivamente.

    completar el vector con ceros
    completar el vector con unos
    calcular y retornar la suma por la interfaz
    calcular y retornar la media por la interfaz
    retornar el valor máximo del arreglo por la interfaz
    retornar el valor mínimo del arreglo por la interfaz
    modificar los elementos del vector reemplazándolos por sus valores al cuadrado
    modificar los elementos del arreglo reemplazando cada elemento por su signo.  
    modificar los elementos del arreglo reemplazándolos por las diferencias finitas de primer orden.
    Para hacer esto, usando como caso de ejemplo el primer y segundo elemento               
        *(v + 0) = *(v + 1) - *(v + 0);
        *(v + 1) = *(v + 2) - *(v + 1);
*/

#include <stddef.h>

/**
 * @brief Llena el arreglo con ceros.
 * 
 * Esta función modifica el contenido del arreglo, estableciendo todos los 
 * elementos a cero.
 * 
 * @param arr Puntero al arreglo de enteros.
 * @param len Longitud del arreglo.
 * 
 * @note Si el arreglo es NULL o la longitud es cero, la función no realiza ninguna acción.
 */
void llenar_con_ceros(int* arr, size_t len) {
    if (arr == NULL || len == 0) return;

    for (size_t i = 0; i < len; i++) {
        *(arr + i) = 0;
    }
}

/**
 * @brief Llena el arreglo con unos.
 * 
 * Esta función modifica el contenido del arreglo, estableciendo todos los 
 * elementos a uno.
 * 
 * @param arr Puntero al arreglo de enteros.
 * @param len Longitud del arreglo.
 * 
 * @note Si el arreglo es NULL o la longitud es cero, la función no realiza ninguna acción.
 */
void llenar_con_unos(int* arr, size_t len) {
    if (arr == NULL || len == 0) return;

    for (size_t i = 0; i < len; i++) {
        *(arr + i) = 1;
    }
}

/**
 * @brief Calcula la suma de los elementos del arreglo.
 * 
 * Esta función recorre el arreglo y calcula la suma de sus elementos, 
 * almacenando el resultado en la variable proporcionada por el usuario.
 * 
 * @param arr Puntero al arreglo de enteros.
 * @param len Longitud del arreglo.
 * @param suma Puntero a la variable donde se almacenará la suma.
 * 
 * @note Si el arreglo es NULL o la longitud es cero, la función no realiza ninguna acción.
 */
void calcular_suma(const int* arr, size_t len, int* suma) {
    if (arr == NULL || len == 0 || suma == NULL) return;

    *suma = 0;
    for (size_t i = 0; i < len; i++) {
        *suma += *(arr + i);
    }
}

/**
 * @brief Calcula la media de los elementos del arreglo.
 * 
 * Esta función calcula el promedio de los elementos del arreglo y almacena el 
 * resultado en la variable proporcionada por el usuario.
 * 
 * @param arr Puntero al arreglo de enteros.
 * @param len Longitud del arreglo.
 * @param media Puntero a la variable donde se almacenará la media.
 * 
 * @note Si el arreglo es NULL, la longitud es cero, o media es NULL, la función no realiza ninguna acción.
 */
void calcular_media(const int* arr, size_t len, float* media) {
    if (arr == NULL || len == 0 || media == NULL) return;

    int suma = 0;
    for (size_t i = 0; i < len; i++) {
        suma += *(arr + i);
    }

    *media = (float)suma / len;
}

/**
 * @brief Encuentra el valor máximo en el arreglo.
 * 
 * Esta función recorre el arreglo para determinar el valor máximo y lo almacena
 * en la variable proporcionada por el usuario.
 * 
 * @param arr Puntero al arreglo de enteros.
 * @param len Longitud del arreglo.
 * @param maximo Puntero a la variable donde se almacenará el valor máximo.
 * 
 * @note Si el arreglo es NULL, la longitud es cero, o maximo es NULL, la función no realiza ninguna acción.
 */
void encontrar_maximo(const int* arr, size_t len, int* maximo) {
    if (arr == NULL || len == 0 || maximo == NULL) return;

    *maximo = *arr;
    for (size_t i = 1; i < len; i++) {
        if (*(arr + i) > *maximo) {
            *maximo = *(arr + i);
        }
    }
}

/**
 * @brief Encuentra el valor mínimo en el arreglo.
 * 
 * Esta función recorre el arreglo para determinar el valor mínimo y lo almacena
 * en la variable proporcionada por el usuario.
 * 
 * @param arr Puntero al arreglo de enteros.
 * @param len Longitud del arreglo.
 * @param minimo Puntero a la variable donde se almacenará el valor mínimo.
 * 
 * @note Si el arreglo es NULL, la longitud es cero, o minimo es NULL, la función no realiza ninguna acción.
 */
void encontrar_minimo(const int* arr, size_t len, int* minimo) {
    if (arr == NULL || len == 0 || minimo == NULL) return;

    *minimo = *arr;
    for (size_t i = 1; i < len; i++) {
        if (*(arr + i) < *minimo) {
            *minimo = *(arr + i);
        }
    }
}

/**
 * @brief Eleva al cuadrado cada elemento del arreglo.
 * 
 * Esta función modifica el contenido del arreglo, elevando al cuadrado 
 * cada uno de sus elementos.
 * 
 * @param arr Puntero al arreglo de enteros.
 * @param len Longitud del arreglo.
 * 
 * @note Si el arreglo es NULL o la longitud es cero, la función no realiza ninguna acción.
 */
void elevar_al_cuadrado(int* arr, size_t len) {
    if (arr == NULL || len == 0) return;

    for (size_t i = 0; i < len; i++) {
        *(arr + i) *= *(arr + i);
    }
}

/**
 * @brief Reemplaza cada elemento del arreglo por su signo.
 * 
 * Esta función modifica el contenido del arreglo, estableciendo cada elemento 
 * a 1 si es positivo o 0, y a -1 si es negativo.
 * 
 * @param arr Puntero al arreglo de enteros.
 * @param len Longitud del arreglo.
 * 
 * @note Si el arreglo es NULL o la longitud es cero, la función no realiza ninguna acción.
 */
void reemplazar_por_signo(int* arr, size_t len) {
    if (arr == NULL || len == 0) return;

    for (size_t i = 0; i < len; i++) {
        *(arr + i) = (*(arr + i) >= 0) ? 1 : -1;
    }
}

/**
 * @brief Calcula las diferencias finitas de primer orden.
 * 
 * Esta función reemplaza cada elemento del arreglo con la diferencia 
 * entre el siguiente elemento y el elemento actual.
 * 
 * @param arr Puntero al arreglo de enteros.
 * @param len Longitud del arreglo.
 * 
 * @note Si el arreglo es NULL o la longitud es menor a 2, la función no realiza ninguna acción.
 */
void calcular_diferencias_finitas(int* arr, size_t len) {
    if (arr == NULL || len < 2) return;

    for (size_t i = 0; i < len - 1; i++) {
        *(arr + i) = *(arr + i + 1) - *(arr + i);
    }
}