// Escribir una función en C que reciba un arreglo de enteros, su largo, y un número y devuelva la
// cantidad de veces que aparece ese número en el arreglo. Mostrar su correcto funcionamiento escribiendo
// un programa (un main) que permita probarla pidiéndole un entero al usuario para buscar en un arreglo
// predefinido.

#include <stdio.h>
#include <stdlib.h>

#define TAM_ARR 8

/**
 * Cuenta la cantidad de veces que un valor aparece en un arreglo desde una posición dada.
 * 
 * @param arr Puntero al arreglo de enteros.
 * @param len Longitud del arreglo.
 * @param valor Valor a buscar en el arreglo.
 * @param desde Posición inicial desde la cual comenzar la búsqueda.
 * @return Cantidad de veces que el valor aparece en el arreglo desde la posición 'desde'.
 */
int cantidad_apariciones_desde(int *arr, size_t len, int valor, size_t desde) {
    if (desde == len) {
        return 0;
    }

    int cant_actual = cantidad_apariciones_desde(arr, len, valor, desde + 1);

    return arr[desde] == valor ? 1 + cant_actual : cant_actual;
}

/**
 * Cuenta la cantidad de veces que un valor aparece en un arreglo.
 * 
 * @param arr Puntero al arreglo de enteros.
 * @param len Longitud del arreglo.
 * @param valor Valor a buscar en el arreglo.
 * @return Cantidad de veces que el valor aparece en el arreglo.
 */
int cantidad_apariciones(int *arr, size_t len, int valor) {
    return cantidad_apariciones_desde(arr, len, valor, 0);
}

/**
 * Programa principal que solicita al usuario un entero y muestra la cantidad de veces que aparece
 * en un arreglo predefinido.
 * 
 * @return 0 Si el programa se ejecuta correctamente, 1 si ocurre un error.
 */
int main(void) {
    int arr[TAM_ARR] = {12, 4, 5, 4, 4, 65, 4, 7};
    char buffer[20];
    printf("Ingrese un valor: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("Error al leer la entrada.\n");
        return 1;
    }

    int valor = atoi(buffer);
    
    int resultado = cantidad_apariciones(arr, TAM_ARR, valor);
    if (resultado > 0) {
        printf("Cantidad de apariciones de %d: %d\n", valor, resultado);
    } else {
        printf("El valor %d no se encuentra en el arreglo.\n", valor);
    }

    return 0;
}