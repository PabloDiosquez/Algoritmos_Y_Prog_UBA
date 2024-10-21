// Implementar una función que recibe un arreglo de números y su longitud y lo
// ordena mediante el algoritmo de ordenamiento por selección.

#include <stdio.h>

/**
 * Intercambia dos elementos en un arreglo de enteros.
 *
 * @param arr Un puntero al arreglo de enteros.
 * @param s El índice del primer elemento a intercambiar.
 * @param e El índice del segundo elemento a intercambiar.
 */
void swap(int* arr, int s, int e) {
    int aux = arr[s];
    arr[s] = arr[e];
    arr[e] = aux;
}

/**
 * Encuentra el índice del elemento mínimo en el subarreglo que comienza en el índice s.
 *
 * @param arr Un puntero al arreglo de enteros.
 * @param len La longitud del arreglo.
 * @param s El índice inicial desde donde buscar el elemento mínimo.
 * @return El índice del elemento mínimo en el subarreglo.
 */
int obtener_indice_minimo(int* arr, int len, int s) {
    int indice_min = s;
    for (int j = s + 1; j < len; j++) {
        if (arr[j] < arr[indice_min]) {
            indice_min = j;
        }
    }
    return indice_min;
}

/**
 * Ordena un arreglo de enteros en orden ascendente utilizando el algoritmo
 * de ordenamiento por selección.
 *
 * @param arr Un puntero al arreglo de enteros.
 * @param len La longitud del arreglo.
 */
void seleccion(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        // Encuentra el índice del elemento mínimo en el subarreglo [i, len)
        int indice_min = obtener_indice_minimo(arr, len, i);
        // Intercambia el elemento actual con el elemento mínimo encontrado
        swap(arr, i, indice_min);
    }
}

int main(void) {
    int arr[] = {64, 25, 12, 22, 11};
    int len = sizeof(arr) / sizeof(arr[0]);

    seleccion(arr, len);

    printf("Arreglo ordenado: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}